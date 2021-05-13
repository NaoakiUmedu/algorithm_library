#include <iostream>
#include <numeric>
// std::numeric::gcdでも可
/*
↓ 剰余で公約数が求められるわけ
44d - 13d・3 = 5d
13d - 5d・2 = 3d
5d - 3d = 2d
3d - 2d = d
*/

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
		// bがaの最大公約数の場合、それを返す
		// だんだん減らしていっているので、一番最初にここに来たものが全体のGCD
        return b;
    }

	// 剰余なのでどんどん小さくなり、いつかは公約数になる
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
