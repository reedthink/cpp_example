class A {
  virtual void fun1() {}
};
class B {
  virtual void fun2() {}
  //如果有同名函数怎么办
};

// class C : public A, public B {
//   virtual void func3() {}
// };

class C {
  virtual void func3() {}
};

class HJK_D : public A, public B, public C {
  virtual void func4() {}
};

int main() {
  HJK_D a;
  return 0;
}