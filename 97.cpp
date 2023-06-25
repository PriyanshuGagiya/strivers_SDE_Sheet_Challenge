#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/maximum-of-minimum-for-every-window-size_8230783?challengeSlug=striver-sde-challenge&leftPanelTab=1
vector<int> maxMinWindow(vector<int> a, int n) 
{
    if(n==0)
      return {};
   stack<int>st;
   vector<int>prevsmaller(n,-1),nextsmaller(n,n);
   for(int i=0;i<n;i++)
   {
       while(!st.empty() and a[st.top()]>=a[i])
       {
         st.pop();
       }
       if(!st.empty())
       {
         prevsmaller[i]=(st.top());
         st.push(i);
       }
       else
       {
         st.push(i);
       }
   }
   while(!st.empty())st.pop();
   for(int i=n-1;i>=0;i--)
   {
       while(!st.empty() and a[st.top()]>=a[i])
       {
         st.pop();
       }
       if(!st.empty())
       {
         nextsmaller[i]=(st.top());
         st.push(i);
       }
       else
       {
         st.push(i);
       }
   }
   vector<int>ans(n,INT_MIN);
   for(int i=0;i<n;i++)
   {
        int len=nextsmaller[i]-prevsmaller[i]-1;
        ans[len-1]=max(ans[len-1],a[i]);
   }
   for(int i=n-2;i>=0;i--)
   {
       ans[i]=max(ans[i],ans[i+1]);
   }
   return ans;
}
