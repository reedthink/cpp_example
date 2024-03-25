#include <iostream>
using namespace std;
class A
{
public:
    // int a;
    static int b; // 存在堆上，所以计算大小不算
    // char str[3];
    // void func()
    // {
    // }

    void my_func()
    {
        
    }
};

class A_Virtual
{
    char a;
    virtual void test()
    {
        cout << "Test" << endl;
    }
    virtual void test2()
    {
        cout << "Test" << endl;
    }
};

int A::b = 0;

int main()
{
    cout << sizeof(A) << endl;
    A a;

    // cout << sizeof(a) <<endl;

    // A_Virtual a_v;
    // char *str;

    // cout << sizeof(A_Virtual) << endl; // 存在虚函数则是8字节，对齐
    // cout << sizeof(a_v) << endl;

    // cout << sizeof(str) << endl; // 一个64bit指针，8个字节，64位

    return 0;
}

/*
1.类的大小为类的非静态成员数据的类型大小之和，也就是说静态成员数据不作考虑。

2.普通成员函数与sizeof无关。

3.虚函数由于要维护在虚函数表，所以要占据一个指针大小，也就是4字节。（64位系统上是8字节）

4.类的总大小也遵守类似class字节对齐的，调整规则。

5、不占空间的有：普通函数，静态数据成员，静态成员函数。

6、无论多少个，只相当于一个所占的空间：虚函数。

7、空类占1个字节。

8、既有字符型又有整型，要考虑字节对齐。

9、普通数据成员、const数据成员占空间；静态成员不占空间。
*/