//https://www.codingninjas.com/studio/problems/0-1-knapsack_8230801?challengeSlug=striver-sde-challenge&leftPanelTab=1
int solve(int i,int w,vector<int> &values, vector<int> &weights,
vector<vector<int>>&dp)
{
	if(i<0)
	{
		return 0;
	}
	if(dp[i][w]!=-1) return dp[i][w];
	int take=0,nontake=0;
	if(w-weights[i]>=0)
	{
		take=values[i]+solve(i-1,w-weights[i],values,weights,dp);
	}
	nontake+=solve(i-1,w,values,weights,dp);
	return dp[i][w]=max(take,nontake);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
	
	vector<vector<int>>dp(n,vector<int>(w+1,-1));
	return solve(n-1,w,values,weights,dp);
}
