#ifndef __UIRadar_H
#define __UIRadar_H

#include <iostream>
#include <ncurses.h>
#include <vector>
#include <string>
#include <functional>
#include "utils/VirtualATC.h"
#include "ui/UIController.h"
#include "math/Vector2.h"

class UIRadar: public UIController {

  private:
  VirtualATC &atc;
  Vector2 boundary_start;
  Vector2 boundary_end;
  Vector2 to_screen_point(double lat, double lon);

  public:
  UIRadar(WINDOW* t_window, VirtualATC &atc);
  void define_boundaries(Vector2 start, Vector2 end);
  void loop();
};

UIRadar::UIRadar(WINDOW* t_window, VirtualATC &t_atc)
:UIController(t_window),  atc(t_atc)
{
  wrefresh(_window);
}

void UIRadar::define_boundaries(Vector2 start, Vector2 end)
{
  boundary_start = start;
  boundary_end = end;
}

void UIRadar::loop()
{ 
  wclear(_window);

  std::vector<Traffic> traff = atc.get_all();
  // _print("%d", traff.size());

  for (auto &t:traff) 
  {
    Vector2 pos = to_screen_point(t.lat, t.lon);

    wattron(_window, A_ALTCHARSET);
    mvwprintw(_window, pos.y, pos.x, "%c", ACS_DIAMOND);
    wattroff(_window, A_ALTCHARSET);

    mvwprintw(_window, pos.y+1, pos.x, "%s", t.label.c_str());
    mvwprintw(_window, pos.y+2, pos.x, "%d %d", t.alt/100, t.hdg);
    mvwprintw(_window, pos.y+3, pos.x, "%d V%d", t.spd, t.climb_rate);
  }

  wrefresh(_window);
}


Vector2 UIRadar::to_screen_point(double lat, double lon)
{

  // wclear(_window);
  // wmove(_window, 0, 0);
  // wprintw(_window, "lat: %f, lon: %f \n", lat, lon);
  // wprintw(_window, "boundary_start: %f,%f | boundary_end: %f,%f \n", boundary_start.x, boundary_start.y, boundary_end.x, boundary_end.y);


  // _print("lat: %f, y: %f \n", lat, lon);
  // _print("boundary_start: %f,%f | boundary_end: %f,%f", boundary_start.x, boundary_start.y, boundary_end.x, boundary_end.y);

  if (lon > boundary_end.y || lon < boundary_start.y || lat > boundary_end.x || lat < boundary_start.x) 
    return Vector2::zero();

  int height, width;
  getmaxyx(_window, height, width);

  // wprintw(_window, "width: %d, height: %d \n", width, height);

  double pjx = (lat - boundary_start.x) / (boundary_end.x - boundary_start.x);
  double pjy = (lon - boundary_start.y) / (boundary_end.y - boundary_start.y);

  // wprintw(_window, "pjx: %f, pjy: %f \n", pjx, pjy);

  double y = pjy * height;
  double x = pjx * width;

  // wprintw(_window, "x: %f, y: %f \n", x, y);

  // wrefresh(_window);
  return Vector2(x,y);
}

#endif