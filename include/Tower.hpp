#ifndef __TOWER_DEFENSE_TOWER_H
#define __TOWER_DEFENSE_TOWER_H
#include <string>

class Tower {
public:
  void changeHealth(int delta);
  int getHealth(void);
  std::string getName(void);
  enum type {
    A,
    B,
  };
private:
  int health = 100;
  std::string name = "";
};

#endif
