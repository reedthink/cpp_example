#include <iostream>
#include <string>

struct Pig
{
    std::string m_name;
    int m_weight;

    // 默认构造函数无参数
    // explicit 显式调用
    // Pig()
    // {
    //     m_name = "pp";
    //     m_weight = 80;
    // }

    // 初始化表达式, 1. 类成员为const或者引用，2. 类成员没有无参构造函数 3.避免重复初始化

    // Pig() : m_name(), m_weight(){}

    Pig() = default;

    Pig(std::string name, int weight)
    {
        m_name = "pp";
        m_weight = 80;
    }
};

int main()
{
    Pig pig;
    std::cout << "name: " << pig.m_name << std::endl;
    std::cout << "weight:" << pig.m_weight << std::endl;
}