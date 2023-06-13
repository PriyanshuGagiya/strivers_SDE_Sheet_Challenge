//https://www.codingninjas.com/codestudio/problems/median-of-two-sorted-arrays_8230788?challengeSlug=striver-sde-challenge&leftPanelTab=1
double median(vector<int>& a, vector<int>& b) 
{
	int n=a.size();
	int m=b.size();
	if(n>m) return median(b,a);

	int low=0;
	int high=n;
	while(low<=high)
	{
		int cut1=(low+high)/2;
		int cut2=((n+m+1)/2)-cut1;
		int l1=(cut1==0)?INT_MIN:a[cut1-1];
		int l2=(cut2==0)?INT_MIN:b[cut2-1];
		int r1=(cut1==n)?INT_MAX:a[cut1];
		int r2=(cut2==m)?INT_MAX:b[cut2];
		if(l1<=r2 and l2<=r1 )
		{
			if((n+m)%2)
			{
				return max(l1,l2);
			}
			else
			{
				return (max(l1,l2)+min(r1,r2))/2.0;
			}
		}
		else if(l1>r2)
		{
			high=--cut1;
		}
		else
		{
			low=++cut1;
		}
	}
	return 0.0;

}
