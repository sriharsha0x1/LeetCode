
//1793. Maximum Score of a Good Subarray
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
using ll=long long;
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        ll p1=k,p2=k,mini=nums[k],ans=0,maxi=mini;
        while(p1>0 or p2<n-1){
            if(p1==0) p2++;
            else if(p2==n-1) p1--;
            else if(nums[p1-1]>nums[p2+1]) p1--;
            else p2++;
            mini=min(mini,(ll)nums[p1]);
            mini=min((ll)nums[p2],mini);
            //p1--; p2++;
            ans=mini*(p2-p1+1);
            maxi=max(maxi,ans);
        }
        return maxi;
    }
};