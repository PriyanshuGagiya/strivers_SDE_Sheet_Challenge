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
//https://www.codingninjas.com/codestudio/problems/linked-list-cycle-ii_8230823?challengeSlug=striver-sde-challenge&leftPanelTab=1
Node *firstNode(Node *head)
{
    //    Write your code here.
    Node* slow=head;
    Node* fast=head;
    while(fast and fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            break;
        }
    }
    if(!fast || !fast->next)
    {
        return NULL;
    }
    fast=head;
    while(fast!=slow)
    {
        slow=slow->next;
        fast=fast->next;
    }
    return fast;
}
