#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <set>
#include <cassert>
#include <unordered_set>
#include <functional>

using namespace std;

typedef int Key;
typedef double Value;
typedef pair<Key,Value> KeyValue;

class TreeNode{
public:
	TreeNode *left,*right,*parent;
	Key key;
	Value value;
	TreeNode(Key k, Value v):key(k),value(v),left(NULL),right(NULL),parent(NULL){}
};


class SplayTree{
private:
	TreeNode* root;
public:
	void insert(const KeyValue& kv){
		
	}
	
	void find(const Key& k){
	
	}
	
	void delete(const Key& k){
	
	}
	
	void min(){
	
	}
	
	void max(){
	
	}
	
	void splay(TreeNode* node){
		if(!root||!node||node==root)
			return;
		if(node==root->left){
			rotateright(root);
		}
		else if(root==root->right){
			rotateleft(root);
		}
		else{
			
		}
	}
};

int main(int argc, char** argv){	
	
    return 0;
}

