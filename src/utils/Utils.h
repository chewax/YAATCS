#pragma once
#include <string>
#include <iostream>
#include "Constants.h"

struct Utils {

  Utils(){}

  static double to_rad(int deg)
  {
    return deg * DEG2RAD;
  }

  static double kts_to_ftm(int kts)
  {
    return kts * KT2FTM;
  }

  static double nms_to_fts(int nm)
  {
    return nm * NM2FT;
  }

  static void log(std::string& text)
  {
    std::cout << text << std::endl;
  }
  
};