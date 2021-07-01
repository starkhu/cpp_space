#include<iostream>
#include<vector>
#include<numeric>  // std::accumulate
#include<string>

void accumulate_demo() {
  std::vector<int> vec = {1,2,3,4,5,6};

  // case1: default usage
  std::cout << std::accumulate(vec.begin(), vec.end(), 0) << std::endl;

  // case2
  auto dash_fold = [](std::string a, int b) {
    return a + "-" + std::to_string(b);
  };
  std::cout << std::accumulate(std::next(vec.begin()), vec.end(), std::to_string(vec.at(0)), dash_fold) << std::endl;
}

int main() {
  accumulate_demo();
}
