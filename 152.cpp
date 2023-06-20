#include <bits/stdc++.h>
//https://www.codingninjas.com/studio/problems/median-in-a-stream_8230765?challengeSlug=striver-sde-challenge&leftPanelTab=1
class Median
{

public:
  priority_queue<int> maxi;
  priority_queue<int, vector<int>, greater<int>> mini;
  int maxisz = 0, minisz = 0;

  void balance() 
  {
    if (minisz > maxisz) {
      maxi.push(mini.top());
      maxisz++;

      mini.pop();
      minisz--;
    }
  }

  void push(int num) 
  {
    maxi.push(num);
    maxisz++;

    mini.push(maxi.top());
    minisz++;

    maxi.pop();
    maxisz--;

    balance();
  }

  int getMedian() {
    if (maxisz > minisz)
      return maxi.top();
    return (maxi.top() + mini.top()) / 2;
  }
};

vector<int> findMedian(vector<int> &arr, int n) 
{
	Median m;
	vector<int> ans;

	for(int i=0;i<n;i++) 
	{
		m.push(arr[i]);
		ans.push_back(m.getMedian());
	}

	return ans;
}
