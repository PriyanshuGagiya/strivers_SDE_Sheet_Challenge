//https://www.codingninjas.com/studio/problems/edit-distance_8230685?challengeSlug=striver-sde-challenge&leftPanelTab=1
int solve(int i,int j,string &str1, string &str2,vector<vector<int>>&dp)
{
    if(i<0 and j<0) return 0;
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(dp[i][j]!=-1) return dp[i][j];
    if(str1[i]==str2[j])
    {
        return dp[i][j]=solve(i-1,j-1,str1,str2,dp);
    }
    int ic=1+solve(i-1,j,str1,str2,dp);
    int dc=1+solve(i,j-1,str1,str2,dp);
    int rc=1+solve(i-1,j-1,str1,str2,dp);
    return dp[i][j]=min(ic,min(dc,rc));
}
int editDistance(string str1, string str2)
{
    //write you code here
    int n=str1.size(),m=str2.size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return solve(n-1,m-1,str1,str2,dp);
}
