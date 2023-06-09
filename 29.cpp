/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/
//https://www.codingninjas.com/codestudio/problems/add-two-numbers-as-linked-lists_8230833?challengeSlug=striver-sde-challenge&leftPanelTab=1
Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    int c=0;
    Node* head=new Node(-1);
    Node* tra=head;
    while(num1 and num2)
    {
        int a=num1->data;
        int b=num2->data;
        num1=num1->next;
        num2=num2->next;
        int sum=(a+b+c)%10;
        c=(a+b+c)/10;
        tra->next=new Node(sum);
        tra=tra->next;
    }
    while(num1)
    {
        int a=num1->data;
        int b=0;
         num1=num1->next;
        int sum=(a+b+c)%10;
        c=(a+b+c)/10;
        tra->next=new Node(sum);
         tra=tra->next;
    }
     while(num2)
    {
        int a=0;
        int b=num2->data;
        num2=num2->next;
        int sum=(a+b+c)%10;
        c=(a+b+c)/10;
        tra->next=new Node(sum);
         tra=tra->next;
    }
    while(c)
    {
        int a=0;
        int b=0;
        int sum=(a+b+c)%10;
        c=(a+b+c)/10;
        tra->next=new Node(sum);
         tra=tra->next;

    }
    return head->next;
}
