#include <functional>
#include <iostream>

class Penguin {
public:
    void run()
    {
    }
    void swim()
    {
    }
};
class Sparrow {
public:
    void fly()
    {
    }
    void run()
    {
    }
};

typedef std::function<void()> FlyCallback;
typedef std::function<void()> RunCallback;
typedef std::function<void()> SwimCallback;

class Foo {
public:
    Foo(FlyCallback flyCb, RunCallback runCb)
        : flyCb_(flyCb)
        , runCb_(runCb)
    {
    }

private:
    FlyCallback flyCb_;
    RunCallback runCb_;
};

class Bar {
public:
    Bar(SwimCallback swimCb, RunCallback runCb)
        : swimCb_(swimCb)
        , runCb_(runCb)
    {
    }

private:
    SwimCallback swimCb_;
    RunCallback runCb_;
};

int main()
{
    Sparrow s;
    Penguin p;

    //组合优于继承
    Foo foo(std::bind(&Sparrow::fly, &s), std::bind(&Sparrow::run, &s));
    Bar bar(std::bind(&Penguin::swim, &p), std::bind(&Penguin::run, &p));

    // 是否可以实现替代虚函数？
    return 0;
}