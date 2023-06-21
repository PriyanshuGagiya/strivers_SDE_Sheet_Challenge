#include <vector>
//https://www.codingninjas.com/studio/problems/ways-to-make-coin-change_8230691?challengeSlug=striver-sde-challenge&leftPanelTab=1
long solve(int i,int j,int *arr,vector<vector<long>>&dp)
{
   
    if(i==0 || j==0)
    {
            return j%arr[i]==0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    long take=0,nontake=0;
    if(j>=arr[i])
    take=solve(i,j-arr[i],arr,dp);
    nontake=solve(i-1,j,arr,dp);
    return dp[i][j]=nontake+take;

}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>>dp(n,vector<long>(value+1,-1));
    solve(n-1,value,denominations,dp);
    return dp[n-1][value];
}
