#include <iostream>
using namespace std;

int main()
{
    int ival = 42;
    int *p = &ival;
    double dVal;
    double *pd = &dVal;
    double *pd2 = pd;

    // int *pi = pd; // 类型不匹配
    // pi = &dVal;   // 类型不匹配
    *p = 0;
    cout << *p << endl;

    

    return 0;
}

// 指针和引用的区别
// 1. 指针可以进行运算
// 2. 指针可以修改本身的值, 引用初始化后不能更改
// 3. 指针是一个变量，它保存了另一个变量的内存地址；引用是另一个变量的别名，与原变量共享内存地址
// 4. 指针可以指向nullptr，引用必须绑定到一个变量