https://www.codingninjas.com/codestudio/problems/reverse-linked-list_8230724?challengeSlug=striver-sde-challenge&leftPanelTab=1
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
