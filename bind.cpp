#include <functional>
#include <iostream>
#include <string>

class Foo {
public:
  void methodA() { std::cout << "called methodA" << std::endl; }
  void methodInt(int a) {
    std::cout << "called methodInt"
              << " " << a << std::endl;
  }
  void methodString(const std::string &str) {
    std::cout << "called methodString"
              << " " << str << std::endl;
  }
};
class Bar {
public:
  void methodB();
};
std::function<void()> f1;

int main() {
  Foo foo;
  f1 = std::bind(&Foo::methodA, &foo);
  f1();

  Bar bar;
  f1 = std::bind(&Foo::methodInt, &foo, 42);
  f1();

  f1 = std::bind(&Foo::methodString, &foo, "hello");
  f1();

  return 0;
}