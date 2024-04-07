#include <iostream>

class A {
public:
  A(int x = 0) : private_(x) {}
  void print() { std::cout << private_ << std::endl; }
  auto retPrivateVal() { return &A::private_; }
  auto retPrivateFunc() { return &A::privateFunc; }

private:
  void privateFunc() { std::cout << "JKJK" << "A::privateFunc()" << std::endl; }
  int private_;
};

int main()
{
    A a{3434};
    // a.print();
    // std::cout << "jkjk:" << a.retPrivateVal() << std::endl;
    // auto func = a.retPrivateFunc();
    // (a.*func)();

    // // 试图通过指针方式强行获取对象a的private成员
    void* ptr = &a;
    // std::cout << &a << sizeof(a) << std::endl;
    // // std::cout << func << std::endl;
    std::cout << *(int*)(ptr) << std::endl;

    return 0;
}