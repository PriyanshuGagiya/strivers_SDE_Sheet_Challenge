//https://www.codingninjas.com/codestudio/problems/allocate-books_8230810?challengeSlug=striver-sde-challenge&leftPanelTab=1
long long ayushGivesNinjatest(int n, int m, vector<int>& time) 
{
    long long low = time[0];
    long long high = 0;
    for (int i = 0; i < m; i++) 
	{
        low = max(low, 1ll * time[i]);
        high += (1ll * time[i]);
    }
    
    long long result = -1;
    
    while (low <= high) 
	{
        long long mid = (low + high) / 2;
        long long sum = 0;
        int cnt = 1;  
        for (int i = 0; i < m; i++) 
		{
           sum+=(1ll*time[i]);
		   if(sum>mid)
		   {
			   cnt++;
			   sum=time[i];
		   }
        }
        if (cnt <= n) 
		{
            result = mid;
            high = mid - 1;
        } 
		else 
		{
            low = mid + 1;
        }
    }
    
    return result;
}
