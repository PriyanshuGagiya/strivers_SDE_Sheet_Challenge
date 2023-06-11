//https://www.codingninjas.com/codestudio/problems/remove-duplicates-from-sorted-array_8230811?challengeSlug=striver-sde-challenge&leftPanelTab=1
int removeDuplicates(vector<int> &arr, int n) 
{
	int j=0;
	for(int i=1;i<n;i++)
	{
		if(arr[i]!=arr[i-1])
		{
			arr[j++]=arr[i];
		}
	}
	return j+1;
}
