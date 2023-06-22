#include<bits/stdc++.h>
//https://www.codingninjas.com/studio/problems/lru-cache-implementation_8230697?challengeSlug=striver-sde-challenge&leftPanelTab=1
struct Node
{
    
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int k,int v)
    {
        key=k;
        value=v;
    }
};
class LRUCache
{
    Node* head;
    Node* tail;
    int size;
    map<int,Node*>mp;
public:
    LRUCache(int capacity)
    {
        // Write your code here
        size=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        head->prev=NULL;
        tail->next=NULL;
        tail->prev=head;
    }

    int get(int key)
    {
        // Write your code here
        if(mp.find(key)==mp.end())
        {
            return -1;
        }
        Node* node=mp[key];
        node->prev->next=node->next;
        node->next->prev=node->prev;
        Node *nxt=head->next;
        head->next=node;
        node->next=nxt;
        nxt->prev=node;
        node->prev=head;
        return node->value;
    }

    void put(int key, int value)
    {
        // Write your code here
        if (mp.find(key) != mp.end()) 
        {
          Node* node=mp[key];
          node->prev->next=node->next;
          node->next->prev=node->prev;
          mp.erase(key);
          delete(node);
        }
        if(mp.size()==size)
        {
            Node* p=tail->prev;
            p->prev->next=tail;
            tail->prev=p->prev;
            mp.erase(p->key);
            delete(p);
        }
        mp[key]=new Node(key,value);
        Node* nxt=head->next;
        head->next=mp[key];
        mp[key]->prev=head;
        mp[key]->next=nxt;
        nxt->prev=mp[key];
    }
};
