#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/sort-a-stack_8230787?challengeSlug=striver-sde-challenge&leftPanelTab=1
void  sort(stack<int> &stack,int num1)
{    
	if(stack.empty()||stack.top()<num1)
	{        
		stack.push(num1);        
		return;    
	}    
	int n = stack.top();    
	stack.pop();    
	sort(stack,num1);   
	stack.push(n); 
}

void sortStack(stack<int> &stack) 
{ 
	if(stack.empty())
	{       
		 return;   
	}    
	int num=stack.top();    
	stack.pop();    
	sortStack(stack);    
	sort(stack,num); 
}
