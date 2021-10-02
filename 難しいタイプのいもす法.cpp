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

/*** MACRO and TYPE DEFINES ***/
#define rep(i, n) \
	for (int i = 0; i < n; i++)

using ll = long long;
using P = std::pair<int, int>;

/*** CONST DEFINES ***/
//const long long MOD = 998244353;
// const long long MOD = 1000000007;
const ll INF64 = 9000000000000000000;
const int INF32 = 1000000000;

/*** UTILITY CLASS ***/

/*** FUNCTIONS ***/

/*** GLOVAL VALIABLES ***/

/*** EXECUTE ***/

// https://atcoder.jp/contests/abc221/tasks/abc221_d
int main(void)
{
#if 0
	//ファイルから読み込みたいとき
	std::ifstream in();
	std::cin.rdbuf(in.rdbuf());
#endif
	int N;
	std::cin >> N;
	std::vector<std::pair<int, int>> Event;
	rep(i, N)
	{
		int A, B;
		std::cin >> A >> B;
		Event.push_back({A, 1});
		Event.push_back({A + B, -1});
	}

	std::sort(Event.begin(), Event.end());

	std::vector<int> Ans(N + 1);
	int population = 0;
	rep(i, Event.size())
	{
		population += Event[i].second;
		Ans[population] += Event[i + 1].first - Event[i].first; // 1日に何回かイベントがある場合、ここで足される期間が0になる
	}

	for (int i = 1; i <= N; i++)
	{
		std::cout << Ans[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}