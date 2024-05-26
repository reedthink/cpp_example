#include <iostream>
// 同时用函数和lambda实现a+b

int add(int a, int b)
{
    return a + b;
}

int main()
{
    int x, y;
    x = 10;
    y = 20;
    int z = 100;
    std::cout << add(x, y) << std::endl;

    // 全部捕获，不加参数
    auto addByLambda = [&] {
        return x + y;
    };

    // 捕获指定的参数，加参数
    auto add2ByLambda = [x, &y](int a, int b) {
        std::cout << x + y << std::endl; // 不仅可以用捕获的参数，还能用传入的
        return a + b;
    };

    std::cout << [&] { return x + y; }() << std::endl;
    std::cout << addByLambda() << std::endl;
    std::cout << add2ByLambda(x, z) << std::endl; // 不仅可以用捕获的参数，还能用传入的

    return 0;
}