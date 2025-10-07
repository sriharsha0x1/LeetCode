//501. Find Mode in Binary Search Tree



struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
unordered_map<int,int>mp;
    void solve(TreeNode* root){
        if(!root) return;
        mp[root->val]++;
        solve(root->left);
        solve(root->right);
    }
    vector<int> findMode(TreeNode* root) {
       if(!root) return {};
       solve(root);
       vector<int> ans; int maxi=INT_MIN;
       for(auto i:mp){
        maxi=max(maxi,i.second);
       }
       for(auto i:mp){
        if(i.second==maxi){
            ans.push_back(i.first);
        }
       }
       return ans; 
    }
};