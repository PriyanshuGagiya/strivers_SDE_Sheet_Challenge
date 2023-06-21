#include <queue>
//https://www.codingninjas.com/studio/problems/median-in-a-stream_8230765?challengeSlug=striver-sde-challenge
class Median
{
    public:
    priority_queue<int>left;
    priority_queue<int,vector<int>,greater<int>>right;
    int ls=0,rs=0;
    void balance()
    {
        if(rs>ls)
        {
            left.push(right.top());
            ls++;
            right.pop();
            rs--;
        }
    }
    void add(int num) 
    {
      left.push(num);
      ls++;
      right.push(left.top());
      rs++;
      left.pop();
      ls--;
      balance();
    }
    int get()
    {
        if(ls>rs)
        {
            return left.top();
        }
        return (left.top()+right.top())/2;
    }
};
void findMedian(int *arr, int n)
{
    // Write your code here
    Median m;
    for(int i=0;i<n;i++)
    {
        m.add(arr[i]);
        cout<<m.get()<<" ";
    }
    cout<<endl;
    
    
}
