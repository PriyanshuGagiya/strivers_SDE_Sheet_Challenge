#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/maximum-xor-of-two-numbers-in-an-array_8230852?challengeSlug=striver-sde-challenge&leftPanelTab=1
struct Node
{
    Node* link[2];
    bool containkey(int num)
    {
        return link[num];
    }
    Node* get(int bit)
    {
        return link[bit];
    }
    void put(int bit,Node* n)
    {
        link[bit]=n;
    }

};
class Trie 
{
private:
Node* root;

public:

    /** Initialize your data structure here. */
    Trie() 
    {
        root=new Node();
    }

    /** Inserts a word into the trie. */
    void insert(int num) 
    {
        Node* trav=root;
        for(int i=31;i>=0;i--)
        {
            int bit=((num>>i)&(1));
            if(trav->containkey(bit))
            {
                trav=trav->get(bit);
            }            
            else
            {
                trav->put(bit,new Node());
                trav=trav->get(bit);
            }
        }
        
    }

    int check(int num)
    {
        int ans=0;
        Node* trav=root;
        for(int i=31;i>=0;i--)
        {
            int bit=((num>>i)&(1));
            if(trav->containkey(!bit))
            {
                ans=ans|(1<<i);
                trav=trav->get(!bit);
            }
            else
            {
                trav=trav->get(bit);
            }
        }
        return ans;
    }
};
int maximumXor(vector<int> A)
{
    // Write your code here. 
    Trie t;
    for(int i=0;i<A.size();i++)
    {
        t.insert(A[i]);
    }  
    int ans=0;
    for(int i=0;i<A.size();i++)
    {
        ans=max(ans,t.check(A[i]));
    }
    return ans;
}
