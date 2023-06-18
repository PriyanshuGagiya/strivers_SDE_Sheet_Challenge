#include <bits/stdc++.h> 
// Stack class.
//https://www.codingninjas.com/codestudio/problems/stack-implementation-using-array_8230854?challengeSlug=striver-sde-challenge&leftPanelTab=1
class Stack {
    
public:
    int *arr;
    int last;
    int size;
    Stack(int capacity) {
        // Write your code here.
        arr=new int[capacity];
        size=capacity;
        last=-1;
    }

    void push(int num) {
        // Write your code here.
        if(last==size-1)
        {
            return;
        }
        last++;
        arr[last]=num;
    }

    int pop() 
    {
        // Write your code here.
        if(last==-1)
        {
            return -1;
        }
        int x=arr[last--];
        return x;
    }
    
    int top() 
    {
        // Write your code here.
        if(last==-1)
        {
            return -1;
        }
        return arr[last];
    }
    
    int isEmpty() {
        // Write your code here.
        return last==-1;
    }
    
    int isFull() {
        return last==size-1;
        // Write your code here.
    }
    
};
