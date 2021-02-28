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
    std::string X;
    ll M;
    std::cin >> X;
    std::cin >> M;

    //コーナーケース
    if (X.size() == 1)
    {
        if (stoi(X) <= M)
        {
            //X <= Mなら、d+1の何進数でも10進数でXになる
            std::cout << 1 << std::endl;
        }
        else
        {
            // X > M かつ1桁なら、かならず X(n) > M
            std::cout << 0 << std::endl;
        }
        return 0;
    }

    int d = 0;
    for (char now : X)
    {
        d = std::max(d, now - '0');
    }

    ll ac = d;          //OKの右端 値=dなら必ずOK
    ll wa = M + 1;      //NGの左端 M以下を探すので、M+1なら必ずNG
    while (wa - ac > 1) //2分しているので、wa == acになっちゃうこともあるので、==ではなく>
    {
        //分岐点が見つかっていないとき
        ll wj = (ac + wa) / 2; //2分した点 (wating jadge)
        ll value = 0;          //値
        for (char c : X)
        {
            if (value > M / wj) //v*wj > MならNG ←のままだと判定式の時点でオーバーフローしちゃう
            {
                // オーバーフローしてしまう
                value = M + 1;
            }
            else
            {
                //上から数字を入れていく
                value = value * wj + (c - '0');
            }
        }

        if (value <= M)
        {
            //OKなら、今見ている値はac
            ac = wj;
        }
        else
        {
            //NGなら、今見ている値はwa
            wa = wj;
        }
    }

    std::cout << ac - d << std::endl;

    return 0;
}
