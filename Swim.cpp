#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int n,m;
vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
int ans=INT_MAX;
void solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dis,int d){
    if(i>=n || i<0 || j>=m || j<0) return;
    int maxi=max(d,grid[i][j]);
    if(dis[i][j]<=maxi) return;
    dis[i][j]=maxi;
    if(i==n-1 && j==m-1){
        ans=min(ans,maxi); return;
    }
    solve(i-1,j,grid,dis,maxi);
    solve(i+1,j,grid,dis,maxi);
    solve(i,j-1,grid,dis,maxi);
    solve(i,j+1,grid,dis,maxi);
}
    int swimInWater(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        solve(0,0,grid,dis,grid[0][0]);
        return ans;
    }
};