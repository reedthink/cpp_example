#include <vector>
#include <cassert>
#include <iostream>
#include <string>
 
struct President
{
    std::string name;
    std::string country;
    int year;
 
    President(std::string p_name, std::string p_country, int p_year)
        : name(std::move(p_name)), country(std::move(p_country)), year(p_year)
    {
        std::cout << "我正被构造。\n";
    }
    President(President&& other)
        : name(std::move(other.name)), country(std::move(other.country)), year(other.year)
    {
        std::cout << "我正被移动。\n";
    }
    President& operator=(const President& other) = default;
};
 
int main()
{
    std::vector<President> elections;
    std::cout << "emplace_back:\n";
    auto& ref = elections.emplace_back("Nelson Mandela", "South Africa", 1994);
    assert(ref.year == 1994 && "使用到所创建对象的引用 (C++17)");
 
    std::vector<President> reElections;
    std::cout << "\npush_back:\n";
    reElections.push_back(President("Franklin Delano Roosevelt", "the USA", 1936));
 
    std::cout << "\n内容:\n";
    for (President const& president: elections) {
        std::cout << president.name << " 是 "
                  << president.country << " " << president.year << " 年的当选总统。\n";
    }
    for (President const& president: reElections) {
        std::cout << president.name << " 是 "
                  << president.country << " " << president.year << " 年的连任总统。\n";
    }
}