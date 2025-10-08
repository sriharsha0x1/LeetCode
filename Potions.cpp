//2300. Successful Pairs of Spells and Potions
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size(),m=potions.size(),l,h,ans;
        sort(potions.begin(),potions.end());
        vector<int>res(n);
        for(int i=0;i<n;i++){
            l=0,h=m-1,ans=m;
            while(l<=h){
                int mid=(l+h)/2;
                long long prod=1LL*potions[mid]*spells[i];
                if(prod>=success) ans=mid,h=mid-1;
                else l=mid+1;
            }
            res[i]=m-ans;
        }
        return res;
    }
};