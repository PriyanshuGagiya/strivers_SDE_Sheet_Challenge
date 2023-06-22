#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/number-of-distinct-substring_8230842?challengeSlug=striver-sde-challenge&leftPanelTab=1
struct Node
{
    Node* link[26];
    bool flag=false;
    bool containkey(char ch)
    {
        return link[ch-'a'];
    }
    Node* get(char ch)
    {
        return link[ch-'a'];
    }
    void put(char ch,Node* n)
    {
        link[ch-'a']=n;
    }
    void setend()
    {
        flag=true;
    }

};

int distinctSubstring(string &word) 
{
    //  Write your code here.
    int cnt=0;
    Node* root=new Node();
    int n=word.size();
    for(int i=0;i<n;i++)
    {
        Node* trav=root;
        for(int j=i;j<n;j++)
        {
           if(trav->containkey(word[j]))
           {
               trav=trav->get(word[j]);
           }
           else
           {
               cnt++;
               trav->put(word[j],new Node());
               trav=trav->get(word[j]);
           }
        }
    }
    return cnt;
}
