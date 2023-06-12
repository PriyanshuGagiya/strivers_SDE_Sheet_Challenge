//https://www.codingninjas.com/codestudio/problems/k-th-permutation-sequence_8230822?challengeSlug=striver-sde-challenge&leftPanelTab=0
string kthPermutation(int n, int k) 
{
    int fact=1;
    vector<int>num;
    for(int i=1;i<=n;i++)
    {
        fact*=i;
        num.push_back(i);
    }
    k--;
    fact/=n;
    string ans="";
    while(num.size())
    {
        int idx=k/fact;
        ans+=to_string(num[idx]);
        num.erase(num.begin()+idx);
        if(num.size()==0)
        {
            break;
        }
        k=k%fact;
        fact/=num.size();
        
    }
   return ans;
}
