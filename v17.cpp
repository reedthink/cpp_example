#include <vector>
#include <iostream>
#include <numeric>

int main()
{
    std::vector v = {4, 5, 3, 1};
    int sum = std::reduce(v.begin(), v.end());

    std::cout << sum << std::endl;
}