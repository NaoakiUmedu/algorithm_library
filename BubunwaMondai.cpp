/* 十 聖イシドールスよ、迷えるプログラマを導き給え！ 十 */
// https://atcoder.jp/contests/abc204/tasks/abc204_d
// 2つのオーブンを使ってNコの料理を作る最小時間
// Nコからxコを選んでTime分にできるかをDPする
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
#include <numeric>

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

/*** GLOVAL VALIABLES ***/

/*** EXECUTE ***/

int main(void)
{
#if 0
    //ファイルから読み込みたいとき
    std::ifstream in();
    std::cin.rdbuf(in.rdbuf());
#endif
    int N;
    std::cin >> N;
    std::vector<int> T(N);
    ll TOT = 0;
    rep(i, N)
    {
        std::cin >> T[i];
        TOT += T[i];
    }
    const ll HALF = TOT / 2;

    // dp[i][j] := iコの料理をj分で作れる
    std::vector<std::vector<bool>> dp(N + 1, std::vector<bool>(HALF + 1, false));

    // 初期化
    for (int i = 0; i < N + 1; i++)
    {
        dp[i][0] = true;
    }

    // 探索
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= HALF; j++)
        {
            if (j - T[i] >= 0)
            {
                // その時間でiを作れる場合を計算
                // バニラだとvector<vector<bool>のOR代入は使えない...
                dp[i + 1][j] = ((dp[i + 1][j]) | (dp[i][j - T[i]]));
            }
            // iを別のオーブンで作る場合を計算
            // こちらで作らない(jに余裕ができる)代わりに、
            // dp[N][i]のiが大きくならない(TOT - Ansが大きくなる)
            dp[i + 1][j] = ((dp[i + 1][j]) | (dp[i][j]));
        }
    }

    ll Ans = 0;
    for (int i = 1; i <= HALF; i++)
    {
        if (dp[N][i])
        {
            Ans = i;
        }
    }

    std::cout << (TOT - Ans) << std::endl;

    return 0;
}