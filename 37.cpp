/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */
//https://www.codingninjas.com/codestudio/problems/rotate-linked-list_8230752?challengeSlug=striver-sde-challenge&leftPanelTab=1
Node *rotate(Node *head, int k) 
{
     // Write your code here.
     if(k==0) return head;
     Node* tail=head;
     Node* tra=head;
     int n=0;
     while(tra)
     {
          tra=tra->next;
          n++;
     }
     tra=head;
     k=n-k;
     while(k<0) k+=n;
     if(n<k) k=k%n;
     if(k==0) return head;
     for(int i=0;i<k-1;i++)
     {
          tra=tra->next;
     }
     head=tra->next;
     tra->next=NULL;
     tra=head;
     while(tra->next)
     {
          tra=tra->next;
     }
     tra->next=tail;
     return head;

}
