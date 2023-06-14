#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/
//https://www.codingninjas.com/codestudio/problems/copy-list-with-random-pointer_8230734?challengeSlug=striver-sde-challenge&leftPanelTab=1
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    unordered_map<LinkedListNode<int>*,LinkedListNode<int>*>mp;
    LinkedListNode<int> *tra=head;
    while(tra)
    {
        mp[tra]=new LinkedListNode<int>(tra->data);
        tra=tra->next;
    }
    tra=head;
    while(tra)
    {
        LinkedListNode<int>* curr=mp[tra];
        curr->next=mp[tra->next];
        curr->random=mp[tra->random];
        tra=tra->next;
    }
    return mp[head];

}
