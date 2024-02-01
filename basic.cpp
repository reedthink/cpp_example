#include <iostream>

#include "Sales_item.h"
int main()
{
    Sales_item item1, item2;
    //头文件里重载了输入
    
    std::cin >> item1 >> item2;
    if (item1.isbn() == item2.isbn())
    {
        // 重载了输出
        std::cout << item1 + item2 << std::endl;
    }
    else
    {
        std::cerr << "Data must refer to same ISBN" << std::endl;
        return -1;
    }

    return 0;
}