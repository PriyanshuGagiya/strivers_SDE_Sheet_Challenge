#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/implement-trie-ll_8230840?challengeSlug=striver-sde-challenge&leftPanelTab=1
struct Node
{
    Node* link[26];
    int prefix=0;
    int word=0;
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
    void setword()
    {
        word++;
    }
    void setprefix()
    {
        prefix++;
    }
    void eraseprefix()
    {
        prefix--;
    }
    void eraseword()
    {
        word--;
    }

};

class Trie{
    Node* root;
    public:

    Trie(){
        // Write your code here.
        root=new Node();
    }

    void insert(string &word)
    {
        // Write your code here.
        int n=word.size();
        Node* trav=root;
        for(int i=0;i<n;i++)
        {
            if(trav->containkey(word[i]))
            {
                trav=trav->get(word[i]);
            }
            else
            {
                trav->put(word[i],new Node());
                trav=trav->get(word[i]);
            }
            trav->setprefix();
        }
        trav->setword();
    }

    int countWordsEqualTo(string &word)
    {
        // Write your code here.
        int n=word.size();
        Node* trav=root;
        for(int i=0;i<n;i++)
        {
            if(trav->containkey(word[i]))
            {
                trav=trav->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return trav->word;
    }

    int countWordsStartingWith(string &word)
    {
        // Write your code here.
        int n=word.size();
        Node* trav=root;
        for(int i=0;i<n;i++)
        {
            if(trav->containkey(word[i]))
            {
                trav=trav->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return trav->prefix;

    }

    void erase(string &word)
    {
        // Write your code here.
        if(countWordsEqualTo(word))
        {
            int n=word.size();
            Node* trav=root;
            for(int i=0;i<n;i++)
            {
                if(trav->containkey(word[i]))
                {
                    trav=trav->get(word[i]);
                }
                trav->eraseprefix();
            }
            trav->eraseword();
        }
        else
        {
            return;
        }
    }
};
