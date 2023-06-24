 #include <stack>
//https://www.codingninjas.com/studio/problems/largest-rectangle-in-a-histogram_8230792?challengeSlug=striver-sde-challenge&leftPanelTab=1
 int largestRectangle(vector < int > & heights) 
 {
   // Write your code here.
   int n=heights.size();
   stack<int>st;
   vector<int>prevsmaller;
   for(int i=0;i<n;i++)
   {
     if(st.empty())
     {
       prevsmaller.push_back(-1);
       st.push(i);
     }
     else
     {
       while(st.size() and heights[st.top()]>=heights[i])
       {
         st.pop();
       }
       if(st.size())
       {
         prevsmaller.push_back(st.top());
         st.push(i);
       }
       else
       {
         prevsmaller.push_back(-1);
         st.push(i);
       }
     }
   }
   while(st.size())st.pop();
   vector<int>nextsmaller;
   for(int i=n-1;i>=0;i--)
   {
     if(st.empty())
     {
       nextsmaller.push_back(-1);
       st.push(i);
     }
     else
     {
       while(st.size() and heights[st.top()]>=heights[i])
       {
         st.pop();
       }
       if(st.size())
       {
         nextsmaller.push_back(st.top());
         st.push(i);
       }
       else
       {
         nextsmaller.push_back(-1);
         st.push(i);
       }
     }
   }
   reverse(nextsmaller.begin(),nextsmaller.end());
   int ans=0;
   for(int i=0;i<n;i++)
   {
     int next=nextsmaller[i];
     int prev=prevsmaller[i];
     if(next==-1) next=n;
     ans=max(ans,(next-prev-1)*heights[i]);
   }
   return ans;
   
 }
