// /https://www.codingninjas.com/codestudio/problems/delete-kth-node-from-end_8230725?challengeSlug=striver-sde-challenge&leftPanelTab=1
Node *removeKthNode(Node *head, int k) 
{
  // Write your code here.
  if (!head)
    return head;
    int n=0;
    Node* tra=head;
    while(tra)
    {
        n++;
        tra=tra->next;
    }
    tra=head;
    if(k>n) return head;
    if(k==n) return head->next;
    for(int i=0;i<n-k-1;i++)
    {
        tra=tra->next;
    }
    Node* d=tra->next;
    if(tra->next)
    tra->next=tra->next->next;
    delete(d);
    return head;
}
