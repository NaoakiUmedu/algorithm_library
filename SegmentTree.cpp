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

// https://atcoder.jp/contests/typical90/tasks/typical90_ac
// 今回は最大値を保持する
class SegmentTree // https://tsutaj.hatenablog.com/entry/2017/03/29/204841
{
private:
	int n;				   // 最下段のノードの数
	std::vector<int> node; // データ
						   // 完全二分木なので全ての葉は以下の関係にある(次の階層は今の階層の2倍の数を持っているので、位置関係は2倍+1(自分がkなので)になる)
						   //     k
						   // 2k+1 2k+2
	const int MIN = 0;

public:
	// コンストラクタ
	SegmentTree(
		std::vector<int> Vec // 要素
	)
	{
		// 完全二分木にするため2の累乗に水増しする
		int sz = Vec.size();
		this->n = 1;
		while (n < sz)
		{
			n *= 2;
		}
		this->node.resize((2 * n - 1), this->MIN);
		// 最下段の要素を入れる
		const int OFFSET = n - 1; // 最下段の最初の要素のインデックス
		rep(i, sz)
		{
			this->node[OFFSET + i] = Vec[i];
		}
		// 親に入れていく
		for (int i = OFFSET - 1; i >= 0; i--)
		{
			// 子を参照する
			this->node[i] = std::max(this->node[i * 2 + 1], this->node[i * 2 + 2]);
		}
	}
	// 値の更新
	void update(
		int Pos, // 位置(インデックス)
		int Val	 // 値
	)
	{
		// 最下段を更新する
		int x = Pos + this->n - 1;
		this->node[x] = std::max(Val, this->node[x]);
		// 親を子の値で更新していく
		while (x > 0)
		{
			x = (x - 1) / 2;
			this->node[x] = std::max(this->node[2 * x + 1], this->node[2 * x + 2]);
		}
	}
	// 値の取得
	int getmax(
		int a,	   // 取得する区間の左
		int b,	   // 取得する区間の右
		int k = 0, // 今見ているノード
		int l = 0, // node[k]がカバーしている区間の左
		int r = -1 // node[k]がカバーしている区間の右
	)
	{
		// 最初の呼び出しなら、区間は0~n
		if (r < 0)
		{
			r = n;
		}

		// 取得する区間を外れてしまった(無駄な再帰はここで止まる)
		if ((r <= a) || (l >= b))
		{
			return MIN;
		}

		// 取得する区間が今見ているノードがカバーしている範囲を完全に被覆
		if ((a <= l) && (b >= r))
		{
			// この区間を代表する値を返す
			return this->node[k];
		}

		// 今見ているノードが取得する区間以外の範囲をカバーしていて、まだ正しい値かわからない
		// 子を見る
		int Lchild = getmax(
			a,			// 取得したいとこ
			b,			// 取得したいとこ
			2 * k + 1,	// 子のインデックス
			l,			// 子がカバーする一番左 = 自分の左
			(l + r) / 2 // 子がカバーする一番右 = 自分の真ん中
		);
		int Rchild = getmax(a, b, 2 * k + 2, (l + r) / 2, r); // 右の子にも同じことをする
		return std::max(Lchild, Rchild);
	}
};

class SegmentTreeLazy // https://tsutaj.hatenablog.com/entry/2017/03/30/224339
{
private:
	int n;
	std::vector<int> node; // データ
	std::vector<int> lazy; // 遅延評価用の一時退避配列
	const int MIN = 0;

public:
	SegmentTreeLazy(std::vector<int> Vec)
	{
		// 完全二分木にするため2の累乗に水増しする
		int sz = Vec.size();
		this->n = 1;
		while (n < sz)
		{
			n *= 2;
		}
		this->node.resize((2 * n - 1), this->MIN);
		this->node.resize(2 * n - 1, this->MIN);
		// 最下段の要素を入れる
		const int OFFSET = n - 1; // 最下段の最初の要素のインデックス
		rep(i, sz)
		{
			this->node[OFFSET + i] = Vec[i];
		}
		// 親に入れていく
		for (int i = OFFSET - 1; i >= 0; i--)
		{
			// 子を参照する
			this->node[i] = std::max(this->node[i * 2 + 1], this->node[i * 2 + 2]);
		}
	}
	// k番目のノードに対して遅延評価を行う k番目のノードの子ノードの遅延評価配列を設定する
	void evaluate(int k, int l, int r)
	{
		// 遅延評価配列に何か入っていれば、自ノード及び子ノードへの値の伝播が起こる
		if (this->lazy[k] != 0)
		{
			this->node[k] = std::max(this->node[k], this->lazy[k]);

			// まだ下があれば、子ノードに伝播させる
			if (r - 1 > 1)
			{
				this->lazy[(2 * k) + 1] = std::max(this->lazy[(2 * k) + 1], this->lazy[k]);
				this->lazy[(2 * k) + 2] = std::max(this->lazy[(2 * k) + 2], this->lazy[k]);
			}
		}

		// 伝播が伝わったので、自ノードの遅延配列を空にする
		this->lazy[k] = this->MIN;
	}
	// 更新処理
	void Update(
		int reqL,		 // 更新する左端
		int reqR,		 // 更新する右端
		int val,		 // 更新する値
		int k = 0,		 // ノードの位置
		int coverL = 0,	 // node[k]のカバーする左端
		int coverR = -1) // node[k]のカバーする右端
	{
		if (coverR < 0)
		{
			// 初回は一番上なので、全体をカバーする
			coverR = this->n;
		}

		// k番目のノードに対して遅延評価を行う
		this->evaluate(k, coverL, coverR);

		// 範囲外チェック
		if ((reqR <= coverL) || (coverR <= reqL))
		{
			return;
		}

		// カバーしている範囲が完全に要求範囲の内側なら、今評価(これ以上下は置いておいてよい)
		if ((reqL <= coverL) && (coverR <= reqR))
		{
			this->lazy[k] = std::max(this->lazy[k], val);
			this->evaluate(k, coverL, coverR);
			return;
		}

		// カバーしている範囲が要求範囲をはみ出ているので、いま評価すると変なとこまで更新してしまう
		// 子ノードを更新してから更新する
		this->Update(reqL, reqR, val, (2 * k) + 1, coverL, (coverL + coverR) / 2);
		this->Update(reqL, reqR, val, (2 * k) + 2, (coverL + coverR) / 2, coverR);
	}

	int GetMax(int reqL,		// 更新する左端
			   int reqR,		// 更新する右端
			   int k = 0,		// ノードの位置
			   int coverL = 0,	// node[k]のカバーする左端
			   int coverR = -1) // node[k]のカバーする右端
	{
		if (coverR < 0)
		{
			// 初回は一番上なので、全体をカバーする
			coverR = this->n;
		}

		// 評価する
		this->evaluate(k, coverL, coverR);
		// 要求範囲の中に収まっている
		if ((reqL <= coverL) && (coverR <= reqR))
		{
			return this->node[k];
		}
		// 要求範囲からはみ出ている
		return std::max(
			this->GetMax(reqL, reqR, (2 * k) + 1, coverL, (coverL + coverR) / 2),
			this->GetMax(reqL, reqR, (2 * k) + 2, (coverL + coverR) / 2, coverR));
	}
};

int main(void)
{
#if 0
	//ファイルから読み込みたいとき
	std::ifstream in();
	std::cin.rdbuf(in.rdbuf());
#endif

	return 0;
}