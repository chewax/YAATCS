#ifndef __Conflict_H
#define __Conflict_H

#include "math/Vector2.h"
#include "airspace/Drone.h"

struct Conflict {

  Drone traffic;
  Vector2 collision_point;
  double distance_traffic_collision; //signed
  double distance_self_collision; //signed
  bool conflict;

  Conflict(Drone t_traffic, double t_dtraffic_collision, double t_dself_collision);
  Conflict();

  private:
  double m_traffic_collision_distance;
  double m_self_collision_distance;
};


Conflict::Conflict(Drone t_traffic, double t_dtraffic_collision, double t_dself_collision)
{
  this->traffic = t_traffic;
  this->distance_traffic_collision = t_dtraffic_collision; //signed
  this->distance_self_collision = t_dself_collision; //signed
  this->collision_point = t_traffic.get_position() + (t_traffic.get_direction().normalize() * t_dtraffic_collision);
  this->conflict = true;
};

Conflict::Conflict()
{
  this->conflict = false;
}

#endif