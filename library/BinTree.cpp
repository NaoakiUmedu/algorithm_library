/*
 * BinTree.cpp
 *
 *  Created on: 2020/04/01
 *      Author: Naoaki
 */

#include <iostream>
#include "BinTree.h"

using namespace std;

TreeNode::~TreeNode() {
	// TODO Auto-generated destructor stub
}

/*
 * ノードの追加
 * */
TreeNode *TreeNode::addnode(TreeNode *pts, int dt){
	TreeNode *ptn;
	// 葉ノードの場合
	if(pts == NULL){
		ptn = new TreeNode(0, NULL, NULL);	// 新規領域確保
		// 領域確保エラー
		if(ptn == NULL){
			cout << "メモリを確保できませんでした" << endl;
			return pts;	// 受け取ったポインタをそのまま返す
		}
		ptn->data = dt;
		ptn->left = NULL;
		ptn->right = NULL;

		return ptn;	// 新ノードのポインタを返す
	}
	// データより小さい値を持つノードの場合
	else if(pts->data < dt){
		pts->right = addnode(pts->right, dt); // 右部分木に進む
	}
	// データと同じかより多きい値を持つノードの場合
	else{
		pts->left = addnode(pts->left, dt); // 右部分木に進む
	}
	return pts;
}
