#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
using ll=long long;
   vector<int> RightSmaller( vector<int> &arr,int n){
    stack<int>st;
    vector<int>ans(n,n);
    for(int i=0;i<n;i++){
        while(!st.empty() and arr[i]<arr[st.top()]){
            ans[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
vector<int> LeftSmaller(vector<int> &arr,int n){
    stack<int>st;
    vector<int>ans(n,-1);
   for(int i=n-1;i>=0;i--){
        while(!st.empty() and arr[i]<arr[st.top()]){
            ans[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>ltr(n),rtl(n);
        ltr=LeftSmaller(heights,n);
        rtl=RightSmaller(heights,n);
        ll ans=LLONG_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,1LL*heights[i]*(rtl[i]-ltr[i]-1));
        }
        return ans;

    }
};