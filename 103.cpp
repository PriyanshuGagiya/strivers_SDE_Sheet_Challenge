//https://www.codingninjas.com/codestudio/problems/longest-common-prefix_8230847?challengeSlug=striver-sde-challenge&leftPanelTab=1
string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string ans=arr[0];
    for(int i=1;i<n;i++)
    {
        int sz=ans.size();
        for(int j=0;j<sz;j++)
        {
            if(ans[j]!=arr[i][j])
            {
                ans=arr[i].substr(0,j);
                break;
            }
        }
    }
    return ans;
}


