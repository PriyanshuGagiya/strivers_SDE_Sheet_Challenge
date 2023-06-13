//https://www.codingninjas.com/codestudio/problems/single-element-in-a-sorted-array_8230826?challengeSlug=striver-sde-challenge
int singleNonDuplicate(vector<int>& arr)
{
	int n=arr.size();
	int low=0;
	int high=n-1;
	while(low<high)
	{
		int mid=low+(high-low)/2;
		if(mid%2)
		{
			mid--;
		}
		if(arr[mid+1]==arr[mid])
		{
			low=mid+2;
		}
		else
		{
			high=mid;
		}
	}
	return arr[low];
}
