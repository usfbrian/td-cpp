#include "Tower.hpp"

void Tower::changeHealth(int delta) {
  health = (health + delta < 0) ? 0 : health + delta;
}

int Tower::getHealth(void) {
  return health;
}

std::string Tower::getName(void) {
  return name;
}
