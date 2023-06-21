#include <bits/stdc++.h> 
// Implement class for minStack.
//https://www.codingninjas.com/studio/problems/min-stack_8230861?challengeSlug=striver-sde-challenge&leftPanelTab=1
class minStack
{
	// Write your code here.
	stack<int>st;
	int mini;
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
			if(st.empty())
			{
				mini=num;
				st.push(num);
				return;
			}
			if(num<mini)
			{
				st.push(2*num-mini);
				mini=num;
			}
			else
			{
				st.push(num);
			}
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
			if(st.empty()) return -1;
			if(st.top()>mini)
			{
				int ans=st.top();
				st.pop();
				return ans;
			}
			else
			{
				int ans=mini;
				mini=2*mini-st.top();
				st.pop();
				return ans;
			}
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
			if(st.empty()) return -1;
			if(st.top()>mini)
			{
				return st.top();
			}
			return mini;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
			if(st.empty()) return -1;
			return mini;
		}
};
