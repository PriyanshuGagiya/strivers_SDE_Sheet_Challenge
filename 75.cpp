/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
//https://www.codingninjas.com/studio/problems/implement-trie_8230696?challengeSlug=striver-sde-challenge&leftPanelTab=1
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
    void insert(string word) 
    {
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
        }
        trav->setend();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
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
        return trav->flag;

    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        int n=prefix.size();
        Node* trav=root;
        for(int i=0;i<n;i++)
        {
            if(trav->containkey(prefix[i]))
            {
                trav=trav->get(prefix[i]);
            }
            else
            {
                return 0;
            }
        }
        return 1;

    }
};
