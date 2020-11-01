#include <iostream>
#include <thread>

class Add {
 public:
  void printHello() {
    std::cout << "Hello" << std::endl;
  }
  int AddOp(int a, int b) {
    value = a+b;
    return a+b;
  }
  void operator()(int n) {
    std::cout << "from Add, n is: " << n << std::endl;
  }

  int value;
};

void printHello() {
  std::cout << "Hello" << std::endl;
}

int addOne(int n) {
   return n+1;
}

void addOneRef(int& n) {
  n += 1;
}

std::thread::id getThreadId(const std::thread& t) {
  std::cout << "thread id is : " << t.get_id() << std::endl; 
  return t.get_id();
}

void ThreadConstructor() {
  int n = 0;
  
  // method1
  std::thread t1;

  // method2
  std::thread t2(printHello);
  getThreadId(t2);

  // method3
  std::thread t3(addOne, n);
  getThreadId(t3);

  // method4
  std::thread t4(addOneRef, std::ref(n));

  // method5
  std::thread t5(std::move(t4));

  // method6
  std::thread t6([&]{
      std::cout << "this is thread 6" << std::endl;});

  // method7
  Add add;
  std::thread t7(add, 1);
  t7.join();
  std::cout << "value: " << add.value << std::endl;

  // method8
  std::thread t8(&Add::AddOp, &add, 1, 2);
  t8.join();
  
  t2.join();
  t3.join();
  t5.join();
  t6.join();
  std::cout << "n is: " << n << std::endl;
}


int main() {
  ThreadConstructor();
}
