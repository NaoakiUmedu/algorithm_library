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

int main(void)
{
#if 0
	//ファイルから読み込みたいとき
	std::ifstream in();
	std::cin.rdbuf(in.rdbuf());
#endif
	int H, W, N;
	std::cin >> H >> W >> N;
	std::vector<int> X(N);
	std::vector<int> Y(N);
	rep(i, N)
	{
		int x, y;
		std::cin >> x >> y;
		X[i] = x;
		Y[i] = y;
	}

	// unique_copyはソートしてから渡す必要がある
	// 復号のため別の配列にコピーする
	std::vector<int> sX = X;
	std::vector<int> sY = Y;
	std::sort(sX.begin(), sX.end());
	std::sort(sY.begin(), sY.end());

	std::vector<int> uniX;
	std::unique_copy(sX.begin(), sX.end(), std::back_inserter(uniX));
	std::vector<int> uniY;
	std::unique_copy(sY.begin(), sY.end(), std::back_inserter(uniY));

	rep(i, N)
	{
		int nowX = std::lower_bound(uniX.begin(), uniX.end(), X[i]) - uniX.begin();
		int nowY = std::lower_bound(uniY.begin(), uniY.end(), Y[i]) - uniY.begin();
		std::cout << nowX + 1 << " " << nowY + 1 << std::endl;
	}

	return 0;
}