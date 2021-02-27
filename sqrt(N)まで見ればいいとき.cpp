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
#include <set>
#include <unordered_set>

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

int slove(void)
{
#if 0
	//ファイルから読み込みたいとき
	std::ifstream in("/tmp/mozilla_anija0/1_07-1");
	std::cin.rdbuf(in.rdbuf());
#endif
    ll N;
    std::cin >> N;
    std::unordered_set<ll> s;

    //条件はsqrtよりi^2のほうが簡単
    for (ll i = 2; i * i <= N; i++)
    {
        ll x = i * i;
        //条件は上のforと同じ
        while (x <= N)
        {
            s.insert(x);
            x *= i;
        }
    }

    std::cout << N - s.size() << std::endl;

    return 0;
}
