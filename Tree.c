# include "node.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct _treenode{
	struct _treenode * l_node;
	struct _treenode * r_node;
	int value;
}TreeNode;

typedef struct{
	TreeNode * root;
	int len;
	int depth;
	
}BinTree;

void initBinTree(BinTree * tree){
	tree->root = NULL;
	tree->len = 0
	tree-> depth = 0;
	
}

int CreateBinTree(BinTree * tree){
	if(! tree->root){
		return -1;
	}
	
}

int main(){
	TreeNode t;
	
	
	
	retrun 0;
}
