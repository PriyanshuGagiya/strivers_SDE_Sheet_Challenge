#include <bits/stdc++.h>
//https://www.codingninjas.com/codestudio/problems/intersection-of-two-linked-lists_8230688?challengeSlug=striver-sde-challenge&leftPanelTab=1
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    unordered_map<Node*,int>mp;
    Node* tra1=firstHead;
    Node* tra2=secondHead;
    while(tra1)
    {
        mp[tra1]++;
        tra1=tra1->next;
    }
    while(tra2)
    {
        if(mp.find(tra2)!=mp.end())
        {
            return tra2;
        }
        tra2=tra2->next;
    }
    return NULL;
}
