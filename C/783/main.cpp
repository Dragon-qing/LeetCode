#include<iostream>
#include<vector>
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
    int minDiffInBST(TreeNode* root) {
        vector<int>v;
        int min=0;
        prev(root,v);
        min=abs(v[0]-v[1]);
        for(int i=0;i<v.size();++i){
            for(int j=i+1;j<v.size();++j){
                int t=abs(v[j]-v[i]);
                if(min>t){
                    min=t;
                }
            }
        }
        return min;
    }
    void prev(TreeNode*root,vector<int>&v){
        if(root==nullptr){
            return;
        }
        v.push_back(root->val);
        prev(root->left,v);
        prev(root->right,v);
    }
};
int main()
{
    TreeNode e(3,nullptr,nullptr);
    TreeNode d(1,nullptr,nullptr);
    TreeNode c(6,nullptr,nullptr);
    TreeNode b(2,&d,&e);
    TreeNode a(4,&b,&c);
    Solution s;
    cout<<s.minDiffInBST(&a);
    getchar();
    return 0;
}