//https://www.codingninjas.com/codestudio/problems/reverse-words-in-a-string_8230698?challengeSlug=striver-sde-challenge&leftPanelTab=1
string reverseString(string &str)
{
	string ans="";
	int n=str.size();
	for(int i=n-1;i>=0;i--)
	{
		while(i>=0 and str[i]==' ')
		{
			i--;
		}
		int j=i;
		while(i>=0 and str[i]!=' ')
		{
			i--;
		}
		if(ans=="")
		{
			ans=str.substr(i+1,j-i);
		}
		else
		{
			ans+=(" "+str.substr(i+1,j-i));
		}
		
	}
	return ans;
}
