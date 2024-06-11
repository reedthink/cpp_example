#include <cmath>
#include <iostream>
using namespace std;

class A {
public:
    A() { cout << "Construct A" << endl; }
    ~A() { cout << "Destruct A" << endl; }
};

class C {
public:
    C() { cout << "Construct C" << endl; }
    ~C() { cout << "Destruct C" << endl; }
};

// class B {
// public:
//     // Notice
//     B()
//         : a(A())
//         , c(C())
//     {
//         cout << "Construct B" << endl;
//     }
//     ~B() { cout << "Destruct B" << endl; }
//     C c;
//     A a;
// };

class B : public A, public C {
public:
    // Notice
    B()
    // : a(A())
    // , c(C())
    {
        cout << "Construct B" << endl;
    }
    ~B() { cout << "Destruct B" << endl; }
    // C c;
    // A a;
};

int main(int argc, char const* argv[])
{
    B b;
    return 0;
}