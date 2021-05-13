#include <iostream>
#include <numeric>
// std::numeric::gcdでも可

unsigned long long Euc(unsigned long long a, unsigned long long b)
{
    // a >= bの自然数a, bについて、
    // r := a % bとすると、aとbの最大公約数はbとrの最大公約数に等しい
    if (b > a)
    {
        unsigned long long tmp = a;
        a = b;
        b = tmp;
    }

    if (a % b == 0)
    {
        return b;
    }

    return Euc(b, (a % b));
}

// 使用例
int main(void)
{
    std::cout << Euc(8888, 2134) << std::endl;
    std::cout << Euc(2134, 8888) << std::endl;
    std::cout << std::gcd(8888, 2134) << std::endl;
    return 0;
}