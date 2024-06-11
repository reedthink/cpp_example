#include <iostream>
using namespace std;

struct my_data
{
    int i;
    double d;
    unsigned bf1;
    int bf2;
    int bf3;
    int bf4;
    int i2;
    char c1, c2;
    string s; // 占32个字节，因为内部很大
};
// my: 72

struct char_data
{
    // char c1,c2,c3;
    class cls{
        string n[4];
    } a;
};

struct char_data_with_ptr
{
    // char c1,c2,c3;
    // char c1,c2,c3,c4,c5,c6,c7,c8;
    char ch[3];
    int kk;
    char *ptr;
};
// struct (class)对齐的逻辑：对齐标准是最长的那个变量，但是最大值也就是平台位数/8。所以大小永远是最大值的倍数，至于其他变量则是尽可能紧凑的放置。
// 能放就放，在对齐的前提下，尽可能保证空洞数量少
// 查看内存布局： clang++ -Xclang -fdump-record-layouts -c mem_align.cpp

//union 的大小至少足以保有其最大的数据成员，但通常不会更大。
union my_union{
    int a;
    string s;
};

int main()
{
    // cout << sizeof(my_data) << endl;
    // cout << sizeof(char_data) << endl;
    // cout << sizeof(char_data_with_ptr) << endl;

    cout << sizeof(my_union) << endl;
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