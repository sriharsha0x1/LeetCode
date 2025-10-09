//958. Check Completeness of a Binary Tree


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
    int Cnt(TreeNode* root){
        if(!root) return 0;
        return 1+Cnt(root->left)+Cnt(root->right);
    }
    bool solve(TreeNode* root,int idx,int total){
        if(!root) return true;
        if(idx>=total) return false;
        return solve(root->left,2*idx+1,total) and solve(root->right,2*idx+2,total);
    }
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;
        int total=Cnt(root);
        return solve(root,0,total);
    }
};