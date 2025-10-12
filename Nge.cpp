 #include <bits/stdc++.h>
 using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* rev(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=nullptr;
        while(curr!=nullptr){
            ListNode* nxt=curr->next;
            curr->next=prev;
            //nxt->next=curr;
            prev=curr;
            curr=nxt;

        }
        return prev;
    }
    int findLen(ListNode* head){
        ListNode* temp=head;
        int cnt=0;
        while(temp!=nullptr){
            cnt++; temp=temp->next;
        }
        return cnt;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* temp=head;
        int n=findLen(head);
        ListNode* t=rev(temp);
        vector<int>nge(n,0);
        stack<int>s;int i=0;
        while(t!=nullptr){
            while(!s.empty() and s.top()<=t->val) s.pop();
            if(!s.empty()) nge[n-i-1]=s.top();
            s.push(t->val); i++;
            t=t->next;
        }
        return nge;
    }
};