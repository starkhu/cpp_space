#include<iostream>

enum SPORTSTYPE {RUNNING, SWIMMING, SLEEPING};

SPORTSTYPE getSportsTypeInSpring() {
  return RUNNING;
}

SPORTSTYPE getSportsTypeInSummer() {
  return SWIMMING;
}

SPORTSTYPE getSportsTypeInFall() {
  return RUNNING;
}

SPORTSTYPE getSportsTypeInWinter() {
  return SLEEPING;
}

typedef SPORTSTYPE (*callback)();
void showSportsType(callback cb) {
  std::cout << (*cb)() << std::endl;
}

void showSportsType2(SPORTSTYPE (*cb)()) {
  std::cout << cb() << std::endl;
}

int call_back_demo() {
  showSportsType(getSportsTypeInSpring);
  showSportsType2(getSportsTypeInSummer);
  return 0;
}
