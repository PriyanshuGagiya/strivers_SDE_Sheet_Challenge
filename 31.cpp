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

//better approach
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

*****************************************************************/
#include <bits/stdc++.h>
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    
   Node* l1=firstHead;
    Node * l2=secondHead;
    int cnt1=0,cnt2=0;
    while (l1 )
    {
        cnt1++;
        l1=l1->next;
    }
    while (l2)
    {
        cnt2++;
        l2=l2->next;
    }
    l1=firstHead;
    l2=secondHead;
    if (cnt1>cnt2)
    {
        int n=cnt1-cnt2;
        while (n--)
        {
            l1=l1->next;
        }
    }
    else if (cnt1<cnt2)
    {

        int n=cnt2-cnt1;
        while (n--)
        {
            l2 = l2->next;
        }

    }
    
    while (l1 && l2)
    {
        if (l1==l2)
        {
            return l1;
        }
        else
        {
            l1=l1->next;
            l2=l2->next;
        }
    }
    return NULL;
}
