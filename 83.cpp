#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/implement-a-queue_8230848?challengeSlug=striver-sde-challenge&leftPanelTab=1
class Node{
  public:
  int data;
  Node* next;
  Node(int x)
  {
      data=x;
      next=NULL;
  }  
};
class Queue {
public:
    Node* root;
    Node* tail;
    Queue() {
        // Implement the Constructor'
        root=NULL;
        tail=NULL;
        
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return root==NULL;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(root==NULL)
        {
            root=new Node(data);
            tail=root;
        }
        else
        {
            tail->next=new Node(data);
            tail=tail->next;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(root==NULL) return -1;
        Node* temp=root;
        int ans=temp->data;
        root=root->next;
        if(root==NULL) tail=NULL;
        delete(temp); 
        return ans;
    }

    int front() {
        // Implement the front() function
        if(root==NULL) return -1;
        return root->data;
    }
};
