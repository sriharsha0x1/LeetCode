#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m=mat.size(),cnt=0,n=mat[0].size();
        vector<int>hcol(n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1) hcol[j]+=1;
                else hcol[j]=0;
            }
            for(int j=0;j<n;j++){
                int mini=hcol[j];
                for(int k=j;k>=0;k--){
                    mini=min(mini,hcol[k]);
                    cnt+=mini;
                }
            }
        }
        return cnt;
    }
};