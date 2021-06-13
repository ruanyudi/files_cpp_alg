#include <iostream>
#include <vector>
using namespace std;

 //Definition for a binary tree node.
 struct TreeNode {
 	int val;
 	TreeNode *left;
 	TreeNode *right;
 	TreeNode() : val(0), left(nullptr), right(nullptr) {}
 	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
	vector<int> q;int ans=0;
	bool isTrue(vector<int> &q){

	}
	void dfs(TreeNode * now){
		if(!now->left&&!now->right){
			//到达叶节点
			if(isTrue(q)){
				ans++;
			}
		}
		else{
			if(now->left){
				q.push_back(now->left->val);
				dfs(now->left);
				q.pop_back();
			}
			else{
				q.push_back(now->right->val);
				dfs(now->right);
				q.pop_back();
			}
		}
	}
    int pseudoPalindromicPaths (TreeNode* root) {
		dfs(root);return ans;
    }
};