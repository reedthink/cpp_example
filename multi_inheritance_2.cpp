#include <iostream>
// 基类
class baseA {
public:
  virtual void show() { std::cout << "virtual baseA::show() \n\n"; }

  int _ma = 1;
  int _mb = 2;
};

class baseB {
public:
  virtual void play() { std::cout << "virtual baseB::play() \n\n"; }
  int _mc = 3;
  int _md = 4;
};

// 派生类
class deriveA : public baseA, public baseB {
public:
  virtual void print() { std::cout << "deriveA::print()\n\n"; }
  int _me = 3;
  int _mf = 4;
};

int main() {
  deriveA da;

  return 0;
}