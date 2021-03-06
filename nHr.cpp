/* 十 聖イシドールスよ、迷えるプログラマを導き給え！ 十 */
#include <cstddef>
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>
#include <cstring>
#include <cstdint>
#include <tuple>
#include <fstream>

/*** MACRO and TYPE DEFINES ***/
#define rep(i, n) \
    for (int i = 0; i < n; i++)

using ll = long long;
using P = std::pair<int, int>;

/*** CONST DEFINES ***/
const long long MOD = 998244353;
// const long long MOD = 1000000007;
const ll INF64 = 9000000000000000000;
const int INF32 = 1000000000;

/*** UTILITY CLASS ***/
class Stock
{
public:
    Stock(std::vector<int> stocks) { m_stocks = stocks; };
    int H(int r);

private:
    std::vector<int> m_stocks;
    std::map<P, int> records;
    int H(int n, int r);
    int H_NR2(int n, int r);
};
//n個から個数制限アリで重複を許してr個選ぶ組み合わせの総数
int Stock::H(int r)
{
    return H(m_stocks.size(), r);
}
// n種類めから1つ以上選ぶ場合 + n種類めからは1つも選ばない場合
// n種類目から1 <= i <= r個選ばれ、n-1種類目「まで」から「合計」r-i個選ばれる
// H(n, r) = Σ(0 <= i <= r) H(n - 1, r-i) <-iの範囲に注目すると納得出来る
// H(n, r) = Σ(0 <= i <= stock[i]) H(n - 1, r-i) <-rの代わりに個数制限用のstock個まで考える
// これだと、Σ(0 <= i <= stock[i])の1つ1つでr回考えるので、O(n*r^2)
int Stock::H_NR2(int n, int r)
{
    if (n <= 0 || r < 0)
    {
        return 0; //もう選べないよ
    }
    if (n == 1 || r == 0)
    {
        return 1; //1つしか選べないよ
    }

    return H(n, r - 1) + H(n - 1, r);
}
//Σ(0 <= i <= stock[i])の中身を分解すると
//i = 0のとき: H(n - 1, r)
//i > 0のとき: H(n - 1, r - 1) + H(n - 1, r - 2) + ... + H(n - 1, r - stocks[i]) = H(n, r - 1) - H(n - 1, r - stocks[i] - 1)
//																					↑全部 - いらないところ
//H(n, r) = H(n - 1, r) + H(n, r - 1)　- H(n-1, r - 1 - stocks[i]) に変形すると計算量をO(nr)に落とすことができる。
int Stock::H(int n, int r)
{
    P key = {n, r};

    if (records.count(key) != 0)
    {
        return records[key]; //もう計算済みなのでそちらを使う
    }

    if (n <= 0 || r < 0)
    {
        records[key] = 0;
        return 0;
    }

    if (r == 0)
    {
        records[key] = 1;
        return 1;
    }

    if (n == 1)
    {
        if (m_stocks[n - 1] < r)
        {
            return 0;
        }
        return 1;
    }

    return records[key] = H(n, r - 1) - H(n - 1, r - m_stocks[n - 1] - 1) + H(n - 1, r);
}

/*** FUNCTIONS ***/
int main(void);
int slove(void);

/*** GLOVAL VALIABLES ***/

/*** EXECUTE ***/
int main(void)
{
#ifdef DEB
    std::cout << "test start \n";
    while (true)
#endif
    {
        slove();
    }

    return 0;
}

//階乗を求める関数
int factorial(int n)
{
    int x = 1;
    for (int i = n; i > 0; i--)
    {
        x *= i;
    }
    return x;
}

//n個から制限なく重複を許してr個選ぶ組み合わせの総数
//nHrはn+r-1この枠に入れるn-1個の(種類を分ける用の)区切りの組み合わせの総数と等しい
//-> nHr = (n+r-1)Cr
int H1(int n, int r)
{
    //(n+r-1)Cr
    //= (n+r-1)! / ((n-1)! * r!)
    //(n-1)!は、分子を(n+r-1)...(n-1)のr個の要素にする
    //r!は分母
    return factorial(n + r - 1) / factorial(n - 1) / factorial(r);
}

int slove(void)
{
#if 0
	//ファイルから読み込みたいとき
	std::ifstream in("/tmp/mozilla_anija0/1_07-1");
	std::cin.rdbuf(in.rdbuf());
#endif
    int n = 3;
    int r = 4;

    std::cout << H1(n, r) << std::endl;
    return 0;
}
