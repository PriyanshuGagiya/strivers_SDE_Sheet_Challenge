#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/maximum-xor-with-an-element-from-array_8230839?challengeSlug=striver-sde-challenge&leftPanelTab=1
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
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
	Trie t;
	vector<pair<int,pair<int,int>>>oq;
	for(int i=0;i<queries.size();i++)
	{
		oq.push_back({queries[i][1],{queries[i][0],i}});
	}
    sort(oq.begin(),oq.end());
	sort(arr.begin(),arr.end());
	int j=0;
	vector<int>ans(queries.size());
	for(int i=0;i<queries.size();i++)
	{
		auto it=oq[i];
		int lim=it.first;
		int num=it.second.first;
		int idx=it.second.second;
		while(j<arr.size() and arr[j]<=lim)
		{
			t.insert(arr[j]);
			j++;
		}
		if(j==0) ans[idx]=-1;
		else ans[idx]=t.check(num);
	}
	return ans;
}
