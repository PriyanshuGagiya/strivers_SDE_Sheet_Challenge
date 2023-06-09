//https://www.codingninjas.com/codestudio/problems/middle-of-linked-list_8230764?challengeSlug=striver-sde-challenge&leftPanelTab=1
Node *findMiddle(Node *head) 
{
    Node* slow=head;
    Node* fast=head;
    while(fast and fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
