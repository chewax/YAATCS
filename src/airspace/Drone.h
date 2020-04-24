#ifndef __Drone_H
#define __Drone_H

#include <string>
#include <math.h>
#include "math/Vector2.h"

//Forward declaration of Conflict
struct Conflict;

enum class DroneState
{
  NORMAL, MONITORING_TRAFFIC, RESOLVING_CONFLICT
};

class Drone
{
  DroneState state;
  
protected:
  Vector2 m_position;
  Vector2 m_direction;
  double m_lat;
  double m_lon;

public:
  Drone();
  Drone(double t_lat, double t_lon, int t_alt, int t_hdg, int t_climb_rate, int t_speed);
  
  Vector2 get_direction() const;
  Vector2 get_position() const;

  bool in_violation(const Conflict& conflict) const;
  bool theats_ahead(const Conflict& conflict) const;
  Conflict get_conflict_details(const Drone& a2) const;
  void check_conflict(const Drone& a2) const;

  //Equivalent to resolution advisory on TCAS but instead of advising an action, execute it
  void resolution_actions(const Conflict& conflict) const;
  void traffic_advisory (const Conflict& conflict) const;
  void resolve_conflict(const Conflict& conflict) const;

  int speed;
  int hdg;
  int alt;
  int climb_rate;
};

#endif