#ifndef __GameObject_H
#define __GameObject_H

#include <chrono>

using Timestamp = std::chrono::time_point<std::chrono::steady_clock>;

class GameObject
{
protected:
  Timestamp last_loop;
  int elapsed_loop;

public:
  void start();
  void loop();
  GameObject();
};

GameObject::GameObject()
{
  last_loop = std::chrono::steady_clock::now();
  elapsed_loop = 0;
}

void GameObject::start()
{
}

void GameObject::loop()
{
  Timestamp now = std::chrono::steady_clock::now();
  elapsed_loop = std::chrono::duration_cast<std::chrono::milliseconds>(now - last_loop).count();
  last_loop = now;
}

#endif
