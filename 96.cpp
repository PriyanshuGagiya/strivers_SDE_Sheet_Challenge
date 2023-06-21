#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/maximum-in-sliding-windows-of-size-k_8230772?challengeSlug=striver-sde-challenge&leftPanelTab=1
vector<int> findSpans(vector<int> &price) 
{
   vector<int>ans;
   stack<int>st;
   int n=price.size();
   for(int i=0;i<n;i++)
   {
           while(!st.empty() and price[st.top()]<=price[i])
           {
               st.pop();
           }
           if(st.empty()) ans.push_back(i+1);
           else
           ans.push_back(i-st.top());
           st.push(i);
   }
   return ans;
}
