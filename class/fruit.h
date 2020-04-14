#include<string>

class Fruit {
 public:
  Fruit();
  Fruit(std::string color);
  ~Fruit();
  void setColor(std::string color);
 private:
  std::string color_;
};
