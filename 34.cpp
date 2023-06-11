//https://www.codingninjas.com/codestudio/problems/palindrome-linked-list_8230717?challengeSlug=striver-sde-challenge&leftPanelTab=3
#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    if(!head) return head;
    LinkedListNode<int>*prev=NULL;
    LinkedListNode<int>*curr=head;
     LinkedListNode<int>*nxt;
     while(curr)
     {
         nxt=curr->next;
         curr->next=prev;
         prev=curr;
         curr=nxt;
     }
     return prev;
}
bool isPalindrome(LinkedListNode<int> *head)
{
    LinkedListNode<int>* slow=head;
    LinkedListNode<int>* fast=head;
    while(fast and fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    slow=reverseLinkedList(slow);
    fast=head;
    while(slow and fast )
    {
        if(slow->data!=fast->data)
        {
                return 0;
        }
        slow=slow->next;
        fast=fast->next;
    }
    return 1;
}
