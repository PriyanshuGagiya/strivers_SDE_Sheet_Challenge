#include<stack>
//https://www.codingninjas.com/studio/problems/day-25-queue-using-stack_8230722?challengeSlug=striver-sde-challenge&leftPanelTab=1
class Queue {
    // Define the data members(if any) here.
    stack<int>s1;
    stack<int>s2;
    int size;
    public:
    Queue() 
    {
        // Initialize your data structure here.
        size = 0;
    }

    void enQueue(int val) 
    {
        // Implement the enqueue() function
        while(!s1.empty())
        {
           int val = s1.top();
           s1.pop();
           s2.push(val);
        }
        s1.push(val);
        while(!s2.empty())
        {
           int val = s2.top();
           s2.pop();
           s1.push(val);
        }

        size++;

    }

    int deQueue() 
    {
        // Implement the dequeue() function.
        if(s1.empty())
            return -1;
        int ans=s1.top();
        s1.pop();
        size--;
        return ans;
    }

    int peek() {
        // Implement the peek() function here.
        if(s1.empty()) return -1;
        return s1.top();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return s1.empty();
    }
};
