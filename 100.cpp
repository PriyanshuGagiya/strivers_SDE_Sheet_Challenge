//https://www.codingninjas.com/codestudio/problems/day-12-longest-palindromic-substring_8230702?challengeSlug=striver-sde-challenge&leftPanelTab=1
string longestPalinSubstring(string A)
{
     int ans=0;
    int n=A.size();
    string res="";
    for(int i=0;i<n;i++)
    {
        int l=i,r=i;
        while(l>=0 and r<n and A[l]==A[r])
        {
            if((r-l+1)>ans)
            {
                ans=r-l+1;
                res=A.substr(l,r-l+1);
            }
            l--;
            r++;
        }
        l=i,r=i+1;
         while(l>=0 and r<n and A[l]==A[r])
        {
            if((r-l+1)>ans)
            {
                ans=r-l+1;
                res=A.substr(l,r-l+1);
            }
            l--;
            r++;
        }
    }
    return res;
}
