#include <bits/stdc++.h>
using namespace std;
struct Node {
    int key;
    int val;
    int freq=1;
    Node* prev=NULL;
    Node* next=NULL;
};
struct DLL {
    Node *head;
    Node *tail;
    int size;
    DLL() {
        head = new Node();
        tail = new Node();
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    void addFront(Node *node) {
        node->next=head->next;
        head->next->prev=node;
        head->next=node;
        node->prev=head;
        size++;
    }
    void remove(Node *node) {
        Node* temp = node->prev;
        temp->next=node->next;
        node->next->prev=temp;
        size--;
    }
    Node* remove_last() {
        Node *temp=tail->prev;
        remove(temp);
        return temp;
    }
};
class LFUCache {
private:
    unordered_map<int,Node*> m;
    unordered_map<int,DLL*> freq;
    int cnt=0;
    int size;
    int lf=0;
public:
    LFUCache(int capacity) {
        size=capacity;
    }
    int get(int key) {
        if(m.find(key)==m.end() or m[key]==NULL) return -1;
        Node *node = m[key];
        updateFreq(node);
        return node->val;
    }
    void put(int key, int value) {
        if(m.find(key)!=m.end() and m[key]!=NULL) {
            Node *node = m[key];
            node->val=value;
            updateFreq(node);
            return;
        }
        if(cnt>=size) {
            Node *temp=freq[lf]->remove_last();
            m[temp->key]=NULL;
            delete(temp);
            cnt--;
        }
        Node *newNode=new Node();
        newNode->val=value;
        newNode->key=key;
        lf=1;
        m[key]=newNode;
        if(freq.find(1)==freq.end()) {
            freq[1]=new DLL();
        }
        freq[1]->addFront(newNode);
        cnt++;
    }
    void updateFreq(Node *node) {
        int oldFreq=node->freq;
        freq[oldFreq]->remove(node);

        if(oldFreq==lf and freq[oldFreq]->size==0) {
            lf++;
        }
        node->freq++;
        if(freq.find(node->freq)==freq.end()) {
            freq[node->freq] = new DLL();
        }
        freq[node->freq]->addFront(node);
    }
};
