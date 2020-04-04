/*
 * BinTree.h
 *
 *	二分探索木
 *	同じ値は右ノードに格納する
 *
 *  Created on: 2020/04/01
 *      Author: Naoaki
 */

#ifndef BINTREE_H_
#define BINTREE_H_

class TreeNode {
private:
	int data;			// データ部
	TreeNode *left;		// 左子ノード
	TreeNode *right;	// 右子ノード

public:
	TreeNode(int idata, TreeNode *lptr, TreeNode *rptr)
		{data = idata; left=lptr;right=rptr;};	// 引数付きコンストラクタ
	virtual ~TreeNode();						// 仮想デストラクタ
	TreeNode *addnode(TreeNode *, int);		// ノードの追加
	void delnode(TreeNode **);					// ノードの削除
	TreeNode **search(TreeNode **,int);		// ノードの探索
	TreeNode *headleft(TreeNode *);			// head ノードの左ポインタの中身
	void pre_tree(TreeNode *);				// 先行順訪問でkey値の表示
	void in_tree(TreeNode *);					// 中間順訪問でkey値の表示
	void post_tree(TreeNode *);				// 後行順訪問でkey値の表示
	void print_tree(TreeNode *);				// 2分木の表示
	void free_tree(TreeNode *);				// 2分木の初期化
};

#endif /* BINTREE_H_ */
