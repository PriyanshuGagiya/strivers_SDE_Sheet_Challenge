//https://www.codingninjas.com/codestudio/problems/minimum-number-of-platforms_8230720?challengeSlug=striver-sde-challenge&leftPanelTab=3
int calculateMinPatforms(int at[], int dt[], int n) 
{
   vector<pair<int,int>>interval;
   for (int i = 0; i < n; i++) 
   {
       interval.push_back({at[i],dt[i]});
   }
   sort(interval.begin(),interval.end());
   int ans=1;
   priority_queue<int,vector<int>,greater<int>>pq;
   pq.push(interval[0].second);
   for(int i=1;i<n;i++)
   {
       if(pq.top()>=interval[i].first)
       {
            pq.push(interval[i].second);
       }
       else
       {
           pq.pop();
           pq.push(interval[i].second);
       }
       int sz=pq.size();
       ans=max(ans,sz);
   }
   return ans;

}
