#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/next-greater-element_8230718?challengeSlug=striver-sde-challenge&leftPanelTab=0
vector<int> nextGreater(vector<int> &arr, int n) 
{
    stack<int>st;
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--)
    {
        if(st.empty())
        {
            st.push(arr[i]);
            ans[i]=-1;
        }
        else
        {
            while(st.size() and st.top()<=arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                st.push(arr[i]);
                ans[i]=-1;
            }
            else
            {
                 ans[i]=st.top();
                st.push(arr[i]);
               
            }
        }
    }
    return ans;

}
