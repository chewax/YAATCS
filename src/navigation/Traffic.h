
#ifndef __Traffic_H
#define __Traffic_H

#include "airspace/Drone.h"
#include "core/GameObject.h"
#include "math/Vector2.h"
#include "navigation/Geo.h"
#include "utils/Utils.h"
#include <iostream>
#include <string>

class Traffic : public GameObject
{
public:
  std::string label;
  Vector2 position;
  Vector2 direction;
  double lat;
  double lon;
  int alt;
  int hdg;
  int climb_rate;
  int spd;
  bool _void;

  Traffic();
  Traffic(std::string t_label, double t_lat, double t_lon, int t_alt, int t_hdg, int t_climb_rate, int t_speed);
  Vector2 get_direction() const;
  Vector2 get_position() const;
  void loop();
};

Traffic::Traffic() : GameObject()
{
  lat = 0.0;
  lon = 0.0;
  spd = 0;
  hdg = -1;
  alt = -1;
  climb_rate = 1;
  _void = true;
}

Traffic::Traffic(std::string t_label, double t_lat, double t_lon, int t_alt, int t_hdg, int t_climb_rate, int t_speed)
  : GameObject()
{
  lat = Coord::to_fts(t_lat);
  lon = Coord::to_fts(t_lon);
  position = Vector2(lat, lon);
  double rads = Utils::to_rad(t_hdg);
  direction = Vector2(sin(rads), cos(rads));
  _void = false;
}

void Traffic::loop()
{
  GameObject::loop();
}

Vector2 Traffic::get_direction() const
{
  return direction;
}

Vector2 Traffic::get_position() const
{
  return position;
}

#endif