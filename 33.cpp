//https://www.codingninjas.com/codestudio/problems/reverse-nodes-in-k-group_8230709?challengeSlug=striver-sde-challenge&leftPanelTab=1
#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
Node* getListAfterReverseOperation(Node *head, int n, int arr[]) 
{

        if(head == NULL || head->next == NULL)
            return head;

        Node* dummy = new Node(0);
        dummy->next = head;

        Node* prevNode = dummy;
        Node* currNode;
        Node* nextNode;

        for(int i=0; i<n; i++)
        {
            int k = arr[i];

            if(k==0)
                continue;
            if(k==1)
            {
                prevNode = prevNode->next;
                continue;
            }

            int count = k;

            currNode = prevNode->next;
            nextNode = currNode->next;

            while(count!=1)
            {
                if(nextNode == NULL)
                    break;

                currNode->next = nextNode->next;
                nextNode->next = prevNode->next;
                prevNode->next = nextNode;
                nextNode = currNode->next;  

                count--;
            }
            
            prevNode = currNode;    

            if(nextNode == NULL)
                return dummy->next;        
        }
            
        return dummy->next;
}
