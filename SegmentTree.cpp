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
class SegmentTree
{
private:
	int sz;
	std::vector<int> seg;
	std::vector<int> lazy;
	void push(int k)
	{
		if (k < sz)
		{
			lazy[k * 2] = std::max(lazy[k * 2], lazy[k]);
			lazy[k * 2 + 1] = std::max(lazy[k * 2 + 1], lazy[k]);
		}
		seg[k] = std::max(seg[k], lazy[k]);
		lazy[k] = 0;
	}
	void update(int a, int b, int x, int k, int l, int r)
	{
		push(k);
		if (r <= a || b <= l)
			return;
		if (a <= l && r <= b)
		{
			lazy[k] = x;
			push(k);
			return;
		}
		update(a, b, x, k * 2, l, (l + r) >> 1);
		update(a, b, x, k * 2 + 1, (l + r) >> 1, r);
		seg[k] = std::max(seg[k * 2], seg[k * 2 + 1]);
	}
	int range_max(int a, int b, int k, int l, int r)
	{
		push(k);
		if (r <= a || b <= l)
			return 0;
		if (a <= l && r <= b)
			return seg[k];
		int lc = range_max(a, b, k * 2, l, (l + r) >> 1);
		int rc = range_max(a, b, k * 2 + 1, (l + r) >> 1, r);
		return std::max(lc, rc);
	}

public:
	SegmentTree() : sz(0), seg(), lazy(){};
	SegmentTree(int N)
	{
		sz = 1;
		while (sz < N)
		{
			sz *= 2;
		}
		seg = std::vector<int>(sz * 2, 0);
		lazy = std::vector<int>(sz * 2, 0);
	}
	void update(int l, int r, int x)
	{
		update(l, r, x, 1, 0, sz);
	}
	int range_max(int l, int r)
	{
		return range_max(l, r, 1, 0, sz);
	}
};

int main(void)
{
#if 0
	//ファイルから読み込みたいとき
	std::ifstream in();
	std::cin.rdbuf(in.rdbuf());
#endif
	int W, N;
	std::cin >> W >> N;
	SegmentTree seg(W);
	rep(i, N)
	{
		int L, R;
		std::cin >> L >> R;
		int height = seg.range_max(L - 1, R) + 1;
		seg.update(L - 1, R, height);
		std::cout << height << std::endl;
	}

	return 0;
}