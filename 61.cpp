//https://www.codingninjas.com/codestudio/problems/find-nth-root-of-m_8230799?challengeSlug=striver-sde-challenge&leftPanelTab=1
int NthRoot(int n, int m) 
{
  long long l=1*1ll;
  long long h=m/n;
  while(l<=h)
  {
    long long mid=(l+h)/2;
    double ans=1;
    for(int i=0;i<n;i++)
    {
      ans*=mid;
    }
    if((long long)ans==1ll*m)
    {
      return (int)mid;
    }
    else if(ans<1ll*m)
    {
      l=++mid;
    }
    else
    {
      h=--mid;
    }
  }
  return -1;
}
