#ifndef __Geo_H
#define __Geo_H

#include <math.h>
#include <string>

const double COORDTOFT = (10000 / 90) * 3280.4f;

double to_rad(int deg);
double kts_to_ftm(int kts);
double nms_to_fts(int nm);

class Coord
{
  double lat, lon;

public:
  static double to_fts(double value)
  {
    return value * COORDTOFT;
  }

  static double to_coord(double value)
  {
    return value / COORDTOFT;
  }

  Coord(double lat, double lon)
  {
    this->lat = COORDTOFT * lat;
    this->lon = COORDTOFT * lon;
  }

  std::string to_string()
  {
    return "( " + std::to_string(lat) + ", " + std::to_string(lon) + " )";
  }
  
};

#endif