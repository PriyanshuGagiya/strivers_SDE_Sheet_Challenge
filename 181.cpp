//https://www.codingninjas.com/studio/problems/rod-cutting-problem_8230727?challengeSlug=striver-sde-challenge&leftPanelTab=1
int solve(int i,int j,vector<int>&price,vector<vector<int>>&dp)
{
	if(j==0)
	{
		return 0;
	}
	if(i==0)
	{
		return j*price[i];
	}
	if(dp[i][j]!=-1) return dp[i][j];
	int take=0,nontake=0;
	if(j>=(i+1))
	{
		take=price[i]+solve(i,j-i-1,price,dp);
	}
	nontake=solve(i-1,j,price,dp);
	return dp[i][j]=max(take,nontake);
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>>dp(n,vector<int>(n+1,-1));
	return solve(n-1,n,price,dp);
}
