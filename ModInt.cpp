#include <iostream>
#include <cstdint>

// MODを扱うクラス
// ここを参考にした->https://noshi91.hatenablog.com/entry/2019/03/31/174006
// #include <cstdint>が必要
template <std::uint_fast64_t Modulus>
class modint
{
    using u64 = std::uint_fast64_t;

public:
    u64 a;

    constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {} //コンストラクタ
    constexpr u64 &value() noexcept { return a; }                  //値を返す
    constexpr const u64 &value() const noexcept { return a; }      //値を返す

    constexpr modint operator+(const modint rhs) const noexcept
    {
        return modint(*this) += rhs;
    }
    constexpr modint operator-(const modint rhs) const noexcept
    {
        return modint(*this) -= rhs;
    }
    constexpr modint operator*(const modint rhs) const noexcept
    {
        return modint(*this) *= rhs;
    }
    constexpr modint operator/(const modint rhs) const noexcept
    {
        return modint(*this) /= rhs;
    }
    constexpr modint &operator+=(const modint rhs) noexcept
    {
        a += rhs.a;
        if (a >= Modulus)
        {
            a -= Modulus; //MODを超えたので調節
        }
        return *this;
    }
    constexpr modint &operator-=(const modint rhs) noexcept
    {
        if (a < rhs.a)
        {
            a += Modulus;
        }
        a -= rhs.a;
        return *this;
    }
    constexpr modint &operator*=(const modint rhs) noexcept
    {
        a = a * rhs.a % Modulus;
        return *this;
    }
    constexpr modint &operator/=(const modint rhs) noexcept
    {
        u64 exp = Modulus - 2;
        while (exp)
        {
            if (exp % 2)
            {
                *this = *rhs;
            }
            rhs *= rhs;
            exp /= 2;
        }
        return *this;
    }
    constexpr bool operator==(const modint rhs) const noexcept
    {
        if (a == rhs.a)
        {
            return true;
        }
        return false;
    }
};

//使用例
int main(void)
{
    const int MOD = 1000000007;
    modint<MOD> a, b, c, d;

    std::cin >> a.a >> b.a >> c.a >> d.a;
    std::cout << (a * b + c).a << std::endl;

    return 0;
}