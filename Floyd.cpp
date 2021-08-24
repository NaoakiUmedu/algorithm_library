/*
 * フローのアルゴリズム
 * グラフの各2点間の最短距離を求める
*/
#include <cstdio>
#include <iostream>
#include <vector>

const int NO_WAY = -1;

void GetRoute(int p, int q);

int main()
{
/* ===== Declaration ===== */
	int NumOfNode = 0;	// ノードの数
	// Weight[i][j] := i-j間を結ぶ経路の重み
	std::vector<std::vector<int>> Weight(NumOfNode, std::vector<int>(NumOfNode, NO_WAY));
	// Dist[i][j] := i-j間の最短距離
	std::vector<std::vector<int>> Dist(NumOfNode, std::vector<int>(NumOfNode, NO_WAY));
	// 最短路の頂点列を求める際に使う配列
	std::vector<std::vector<int>> PreVertex(NumOfNode, std::vector<int>(NumOfNode, NO_WAY));

/* ===== Execution ===== */
	// 直接の経路で初期化
	for(int i = 0; i < NumOfNode; i++)
	{
		for(int j = 0; j < NumOfNode; j++)
		{
			Dist[i][j] = Weight[i][j];
			PreVertex[i][j] = i;
		}
	}

	// 中継点を利用する場合を考える
	for(int k = 0; k < NumOfNode; k++)
	{
		for(int i = 0; i < NumOfNode; i++)
		{
			for(int j = 0; j < NumOfNode; j++)
			{
				int NowDist = Dist[i][k] + Dist[k][j];
				if(NowDist < Dist[i][j])
				{
					Dist[i][j] = NowDist;
					PreVertex[i][j] = PreVertex[k][i];
				}
			}
		}
	}

	// 経路を求めるアルゴリズム
	const int Stt = 0;
	const int Gol = 3;

	int Pos = Stt;
	printf("%4d ", Pos);
	do{
		Pos = PreVertex[Gol][Pos];
		printf("%4d ", Pos);
	}while(Pos != Gol);
	printf("\n");
	
	return 0;
}

