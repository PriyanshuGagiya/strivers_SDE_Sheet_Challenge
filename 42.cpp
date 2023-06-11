//https://www.codingninjas.com/codestudio/problems/maximum-consecutive-ones_8230736?challengeSlug=striver-sde-challenge&leftPanelTab=1
int longestSubSeg(vector<int> &arr , int n, int k)
{
    int i=0;
    int j=0;
    int zero=0;
    int ans=0;
    while(i<n)
    {
        if(arr[i]==0)
        {
            zero++;
            if(zero>k)
            {
                    while(arr[j]!=0)
                    {
                        j++;
                    }
                    j++;
            }
        }
        ans=max(ans,i-j+1);
        i++;
    }
    return ans;
}
