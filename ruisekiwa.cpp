/* 十 聖イシドールスよ、迷えるプログラマを導き給え！ 十 */
/* https://qiita.com/drken/items/56a6b68edef8fc605821 */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include <deque>
 
#define rep(i, n) for(int i = 0; i < n; i++)
 
//const long long INF = 1LL << 60;
const int INF = 1e9;

/************************************************************************/
/* <累積和>
/* ・コンテナのうち、ある要素からある要素までの和を求める
/************************************************************************/
/* <イメージ>
/* [0]|[a]|[a]|[a]|[a]|[a]|[a]|[a]|
/*    0   1   2   3   4   5   6   7
/* s0 = 0
/* sn = a0 + a1 + a2 ... + an-1 
/************************************************************************/
/* <例>
/* (入力)
/* [1][3][2][6]
/* ↓
/* (累積和)
/* [0]|[1]|[4]|[6]|[12]|
/*    0   1   2   3    4
/* ruisekiwa(1番目の入力, 3番目の入力)
/* = ruisekiwa[3] - ruisekiwa[1]
/* 6 - 1 = 5 
/************************************************************************/
int main()
{
    int N;
    std::cin >> N;
    std::vector<int> In(N);
    for(int i = 0; i < N; i++)
    {
        std::cin >> In[i];
    }

    // 累積和を準備(O(N)) 
    std::vector<int> ruisekiwa(N+1, 0); // 要素数は1多く取る(0~1の累積和の分) 
                                        // 0~1のため0で初期化する  
    for( int i = 0; i < N; i++)
    {
        // 1つ先の要素 = 今までの合計 + 今回の追加分 
        ruisekiwa[i+1] = ruisekiwa[i] + In[i];
    }

    //  累積和を出す 
    int left = 1; int reight = 3;   // 累積和を見たい(メインの)配列の、
                                    // 見たい始まりと終わりの要素を指定する(つまり0始まり) 
    int val = ruisekiwa[3] - ruisekiwa[1];
    for(auto val : ruisekiwa)
    {
        std::cout << val << ", ";
    }
    std::cout << std::endl;

    std::cout << val << std::endl;

    return 0;
}