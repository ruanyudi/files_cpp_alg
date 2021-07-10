#include <iostream>
#include <stack>
#include <vector>
using namespace std;
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
    vector<int> postorderTraversal(TreeNode* root) {
		if(root==nullptr)return vector<int>();
		vector<int> ans;
		stack <TreeNode*> s1;
		stack <int> s2;
		s1.push(root);s2.push(0);
		while(!s1.empty()){
			int status=s2.top().pop();
			switch(status){
				case 0 : {
					s2.push(1);
					if(s1.top()->left!=nullptr){
						s1.push(s1.top()->left);
						s2.push(0);
					}					
				}case 1 : {
					s2.push(2);
					if(s1.top()->right!=nullptr){
						s1.push(s1.top()->right);
						s2.push(0);
					}
				}case 2 : {
					ans.push_back(s1.top());
					s1.pop();
				}
			}
		}
		return ans;
    }
};
int main(){

}