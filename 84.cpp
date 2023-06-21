#include <bits/stdc++.h> 
//
class Stack {

	// Define the data members.
    queue<int> q1;
    queue<int> q2;
    int size;
   public:
    Stack() {
        // Implement the Constructor.
        size=0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return size==0;
    }

    void push(int element) {
        // Implement the push() function.
        q2.push(element);
        while(q1.size())
        {
            q2.push(q1.front());
            q1.pop();
        }
        while(q2.size())
        {
            q1.push(q2.front());
            q2.pop();
        }
        size++;
    }

    int pop() {
        // Implement the pop() function.
        if(size==0) return -1;
        int ans=q1.front();
        q1.pop();
        size--;
        return ans;
    }

    int top() {
        // Implement the top() function.
        if(size) return q1.front();
        return -1;
    }
};
