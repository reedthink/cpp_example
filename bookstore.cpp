#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item total;

    if (std::cin >> total)
    {
        Sales_item trans;

        while (std::cin >> trans)
        {
            if (total.isbn() == trans.isbn())
                total += trans;
            else
            {
                std::cout << total << std::endl;
                total = trans;
            }
        }
        std::cout << total << std::endl;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}

// test input
/*
9 1 2
9 5 10
9 25 100
8 8 8
*/

// test output
// 第一个数据是书的编号，第二个是售量，第三个是总价，第四个是平均售价
/*
9 31 2597 83.7742
*/