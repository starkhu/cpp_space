#include<iostream>

#define my_int int

#define MACRO_TEST(NAME, ...) \
int year = 2019; \
std::string location##NAME = "haidian"; \
std::string season##__VA_ARGS__ = "winter"; \


int main() {
  MACRO_TEST(_BEIJING, _DEC);
  std::cout << "year is: " << year << std::endl;
  std::cout << "location is: " << location_BEIJING << std::endl;
  std::cout << "season is: " << season_DEC << std::endl;
}

