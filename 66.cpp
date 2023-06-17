// got partially accepted so learnt from solution section
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) 
{     
    // If length of first array is smaller then length of second then swap both the arrays.    
    if (m > n) 
    {
        return ninjaAndLadoos(row2, row1, n, m, k);
    }
  
    if (m == 0) 
    {
        return row2[k - 1];
    }
    
    // If k is equal to 1
    if (k == 1) 
    {
        return min(row1[0], row2[0]);
    }
  
    int i = min(m, k / 2);
    int j = min(n, k / 2);
    
    // If row1[i - 1] is greater than row2[j - 1]
    if (row1[i - 1] > row2[j - 1]) 
    {
        vector<int> newRow2;
        newRow2.assign(row2.begin() + j, row2.end());
        
        return ninjaAndLadoos(row1, newRow2, m, n - j, k - j);
    } 

    vector<int> newRow1;
    newRow1.assign(row1.begin() + i, row1.end());
        
    return ninjaAndLadoos(newRow1, row2, m - i, n, k - i);  
} 
// binary search 
#include <bits/stdc++.h>
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int n, int m, int k) 
{
  if (n > m)
    return ninjaAndLadoos(row2, row1, m, n, k);

  int low = max(0, k - m), high = min(n, k); // cannot take all elements 
  while (low <= high) {
    int cut1 = (low + high) >> 1;
    int cut2 = k - cut1;

    int l1 = cut1 == 0 ? INT_MIN : row1[cut1 - 1];
    int l2 = cut2 == 0 ? INT_MIN : row2[cut2 - 1];
    int r1 = cut1 == n ? INT_MAX : row1[cut1];
    int r2 = cut2 == m ? INT_MAX : row2[cut2];

    if (l1 <= r2 and l2 <= r1)
      return max(l1, l2);
    else if (l1 > r2)
      high = cut1 - 1;
    else
      low = cut1 + 1;
  }

  return 1;

}
