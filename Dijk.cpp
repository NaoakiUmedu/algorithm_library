/* 十 聖イシドールスよ、迷えるプログラマを導き給え！ 十 */
/* 数え上げつきダイクストラ */
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
	for (long long i = 0; i < n; i++)

using ll = long long;
using P = std::pair<long long, long long>;

/*** CONST DEFINES ***/
// const long long MOD = 998244353;
const long long MOD = 1000000007;
const ll INF64 = 9000000000000000000;
const long long INF32 = 1000000000;

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
	long long N, M;
	std::cin >> N >> M;
	std::vector<std::vector<long long>> Route(N);
	rep(i, M)
	{
		long long A, B;
		std::cin >> A >> B;
		A--;
		B--;
		Route[A].push_back(B);
		Route[B].push_back(A);
	}

	const long long COST = 1;

	// P[時間][場所] 早い方から見るので昇順にする
	std::priority_queue<P, std::vector<P>, std::greater<P>> que;

	// 最短距離
	std::vector<long long> MinDist(N, INF64);
	MinDist[0] = 0;

	// 最短経路数
	std::vector<long long> KeiroNum(N);
	KeiroNum[0] = 1;

	que.push(std::make_pair(0, 0));
	while (!que.empty())
	{
		P now = que.top();
		que.pop();
		long long NowTime = now.first;
		long long NowPos = now.second;

		for (long long NextPos : Route[NowPos])
		{
			long long NextTime = NowTime + COST; // COSTを変えると重みづけになる
			if (NextTime < MinDist[NextPos])
			{
				MinDist[NextPos] = NextTime;
				que.push(std::make_pair(NextTime, NextPos));
				KeiroNum[NextPos] = KeiroNum[NowPos];
				KeiroNum[NextPos] %= MOD;
			}
			else if (NextTime == MinDist[NextPos])
			{
				// もう探索済みだが、ここに来るまでの経路が増える
				KeiroNum[NextPos] += KeiroNum[NowPos];
				KeiroNum[NextPos] %= MOD;
			}
		}
	}

	std::cout << KeiroNum[N - 1] << std::endl;

	return 0;
}