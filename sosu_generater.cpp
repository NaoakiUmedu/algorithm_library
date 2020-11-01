/* 十 聖イシドールスよ、迷えるプログラマを導き給え！ 十 */
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
using ll = long long;

int main()
{
	std::vector<bool> sosu(100005, true);
	// 素数を100000までかぞえておく 
	// 素数じゃなくて、何らかの数字をかけた数ではない数がほしいときは 
	// 1からループを始める 
	sosu[0] = false;	// 0は素数ではない 
	sosu[1] = false;	// 1は素数ではない 
	for(int i = 2; i < 100005; i++)
	{
		for(int j = 2; i * j < 100005; j++ )
		{
			sosu[i*j] = false;
		}
	}
	

	return 0;
}
