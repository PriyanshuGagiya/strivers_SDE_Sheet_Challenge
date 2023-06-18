//https://www.codingninjas.com/codestudio/problems/longest-common-prefix_8230847?challengeSlug=striver-sde-challenge&leftPanelTab=1
vector<int> stringMatch(string text, string pattern) 
{
	// Write your code here.
	int n=text.size();
	int m=pattern.size();
	vector<int>ans;
	for(int i=0;i<n;i++)
	{
		int j=0;
		int k=i;
		while(j<m)
		{
			if(text[k]!=pattern[j])
			{
				break;
			}
			k++;
			j++;
		}
		if(j==m)
		{
			ans.push_back(i+1);
		}
	}
	return ans;
}
