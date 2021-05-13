/* 十 聖イシドールスよ、迷えるプログラマを導き給え！ 十 */

//************************************************
// 元ネタ: https://youtu.be/TdR816rqc3s?t=6822
//************************************************
// <Union_Find>
// 以下の2つのqueryを処理する
// ・Unite 要素をくっつける
// ・Find  どのグループにいる?
// 計算量・・・O(logN)
//************************************************
#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < n; i++)

//const long long INF = 1LL << 60;
const int INF = 1e9;
using ll = long long;

struct UnionFind
{
    // 配列 value = 子なら親の番号、親ならグループのサイズ(判定のため-1 * size()の形で保持)
    std::vector<int> d;
    // コンストラクタ サイズを初期化する
    UnionFind(int n = 0) : d(n, -1) {}
    // find インデックスxの要素の根っこ(=所属グループ)をみつける
    int find(int x)
    {
        if (d[x] < 0)
            return x;
        return d[x] = find(d[x]);
    }
    // Unite 貰った2要素を追加してくっつけていく
    bool unite(int x, int y)
    {
        x = find(x);
        y = find(y); // 両方の根っこを扱う
        if (x == y)
            return false; // おんなじのはつながらない(同じ要素じゃん)
        if (d[x] > d[y])
            std::swap(x, y); // 小さい方につなげる
        d[x] += d[y];        // 連結のサイズを合算する
        d[y] = x;            // yの親をxの親に更新する
        return true;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) { return -d[find(x)]; } //  サイズは-で持っている
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 使用例
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main()
{
    // 経路探索の問題にする
    // 一番人数の多い仲良しグループ人数分の新グループがあればよい
    int N, M;
    std::cin >> N >> M;

    UnionFind uf(N);

    rep(i, M)
    {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        uf.unite(a, b); // 友達の情報なので必ずつながる
    }

    int ans = 0;
    rep(i, N)
    {
        ans = std::max(ans, uf.size(i));
    }

    std::cout << ans << std::endl;

    return 0;
}