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
#include <numeric>
#include <set>
#include <unordered_set>

/*** MACRO and TYPE DEFINES ***/
#define rep(i, n) \
    for (int i = 0; i < n; i++)

using ll = long long;
using P = std::pair<ll, ll>;

/*** CONST DEFINES ***/
const long long MOD = 998244353;
// const long long MOD = 1000000007;
const ll INF64 = 9000000000000000000;
const int INF32 = 1000000000;

/*** FUNCTIONS ***/

//-------------------------------------------------------
// 桁数を数える
// Nketaを返すようにすると、10^桁数を返す
//-------------------------------------------------------
ll GetKeta(ll n, ll &rNketa)
// ll GetKeta(ll n) //ll rNketa&)
{
    ll ret = 0;
    ll Nketa = 0;
    while (Nketa <= n)
    {
        if (Nketa == 0)
        {
            Nketa = 1;
        }
        else
        {
            Nketa *= 10;
        }
        ret++;
    }
    rNketa = Nketa / 10;
    return ret;
}

//-------------------------------------------------------
// NNN から NNNNNNを生成する
// 例: 121 -> 121121
//-------------------------------------------------------
ll GetNNN_NNN(ll nnn)
{
    ll ret = 0;

    ll Nketa = 0;
    int keta = 0;
    while (Nketa <= nnn)
    {
        if (Nketa == 0)
        {
            Nketa = 1;
        }
        else
        {
            Nketa *= 10;
            keta++;
        }
    }

    ret = (nnn * Nketa) + nnn;
    return ret;
}

//-------------------------------------------------------
// テスト
//-------------------------------------------------------
int main(void)
{
    std::cout << GetNNN_NNN(121) << std::endl;
    ll Nketa = 0;
    std::cout << GetKeta(9999, Nketa) << std::endl;
    std::cout << Nketa << std::endl;
    return 0;
}