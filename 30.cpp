//https://www.codingninjas.com/codestudio/problems/delete-node-in-a-linked-list_8230813?challengeSlug=striver-sde-challenge&leftPanelTab=1
void deleteNode(LinkedListNode<int> *node) 
{
    node->data = node->next->data;
    LinkedListNode<int> *temp = node->next;
    if(temp)
    node->next=temp->next;
    delete temp;
}
