/* 十 聖イシドールスよ、迷えるプログラマを導き給え！ 十 */
// https://atcoder.jp/contests/abc205/tasks/abc205_d
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
    int N, Q;
    std::cin >> N >> Q;
    std::vector<ll> A(N);
    rep(i, N)
    {
        std::cin >> A[i];
    }

    // GoodNum[i] := A[i]までに何個使える(Aに入っていない)数字があるか
    std::vector<ll> GoodNum(N);
    rep(i, N)
    {
        GoodNum[i] = A[i] - (i + 1);
    }

    // std::cout << GoodNum[N - 1] << std::endl;

    rep(q, Q)
    {
        long long K = 0;
        std::cin >> K;

        if (K > GoodNum[N - 1])
        {
            // 大きいとき、A[N]より進んだ値
            std::cout << A[N - 1] + (K - GoodNum[N - 1]) << std::endl;
        }
        else
        {
            // K <= GoodNum[N-1]のとき、
            const int idx = std::lower_bound(GoodNum.begin(), GoodNum.end(), K) - GoodNum.begin(); // ポインタ演算でidxを取得できる
            // GoodNum[idx]がKより大きい最初のGoodNumとなるidx
            // 実際の数は、A[idx]から、GoodNum[idx]でKを超えてしまった分戻るのが正しい
            // GoodNum[idx-1]はKより小さいので、戻りすぎてしまうことはあり得ない
            std::cout << (A[idx]) - (GoodNum[idx] - K + 1) << std::endl;
        }
    }

    return 0;
}