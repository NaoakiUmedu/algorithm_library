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

/*** MACRO and TYPE DEFINES ***/
#define rep(i, n) \
	for (int i = 0; i < n; i++)

using ll = long long;
using P = std::pair<int, int>;

/*** CONST DEFINES ***/
// const long long MOD = 998244353;
//  const long long MOD = 1000000007;
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
	int N, X, Y;
	std::cin >> N >> X >> Y;
	X--;
	Y--;
	std::vector<std::vector<int>> Graph(N);
	rep(i, N - 1)
	{
		int u, v;
		std::cin >> u >> v;
		u--;
		v--;
		Graph[u].push_back(v);
		Graph[v].push_back(u);
	}

	std::vector<int> dist(N, -1); // その点までの距離
	std::vector<int> prev(N);	  // その点に到達する前にいた点
	std::queue<int> todo;

	// 初期条件
	dist[X] = 0;
	prev[X] = -1;
	todo.push(X);
	while (!todo.empty())
	{
		int from = todo.front();
		// printf("Searching from = %d\n", from);
		todo.pop();
		for (int to : Graph[from])
		{
			if (to == Y)
			{
				// printf("    %d is found\n", to);
				dist[to] = dist[from] + 1;
				prev[to] = from;
				break;
			}

			if (dist[to] != -1)
			{
				continue;
			}

			dist[to] = dist[from] + 1;
			prev[to] = from;
			// printf("    %d pushed!\n", to);
			todo.push(to);
		}
	}

	// printf("Search ended!\n");

	int now = Y;
	std::vector<int> route;
	while (true)
	{
		route.push_back(now);
		now = prev[now];
		if (now == X)
		{
			route.push_back(now);
			break;
		}
	}
	std::reverse(route.begin(), route.end());

	// printf("Route construction ended!\n");

	for (int point : route)
	{
		std::cout << point + 1 << " ";
	}
	std::cout << std::endl;

	return 0;
}