//1488. Avoid Flood in The City
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int,int>mp;
        int n=rains.size();
        vector<int>ans(n,1);
        set<int>s;
        for(int i=0;i<n;i++){
            if(rains[i]==0){
                s.insert(i);
            }
            else{
                int lake=rains[i];
                ans[i]=-1;
                if(mp.count(lake)){
                    auto it=s.lower_bound(mp[lake]);
                    if(it==s.end()) return {};
                    ans[*it]=lake;
                    s.erase(it);
                }
                mp[lake]=i;
            }
        }
        return ans;
    }
};