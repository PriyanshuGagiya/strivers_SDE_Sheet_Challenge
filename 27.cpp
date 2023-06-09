#include <bits/stdc++.h>
//https://www.codingninjas.com/codestudio/problems/merge-two-sorted-linked-lists_8230729?challengeSlug=striver-sde-challenge&leftPanelTab=1
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    int x=1;
    Node<int>* head=new Node<int>(1);
    Node<int>* tra=head;
    while(first and second)
    {
        if(first->data<second->data)
        {
            tra->next=first;
            first=first->next;
        }
        else
        {
            tra->next=second;
            second=second->next;
        }
        tra=tra->next;
    }
    while(first)
    {
        tra->next=first;
        first=first->next;
        tra=tra->next;
    }
    while(second)
    {
        tra->next=second;
            second=second->next;
               tra=tra->next;
    }
    return head->next;
}
