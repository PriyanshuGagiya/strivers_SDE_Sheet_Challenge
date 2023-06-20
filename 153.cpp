#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/kth-largest-element-in-a-stream_8230728?challengeSlug=striver-sde-challenge&leftPanelTab=1
class Kthlargest {
public:
    multiset<int>st;
    Kthlargest(int k, vector<int> &arr) 
    {
       // Write your code here.
       int n=arr.size();
       for(int i=0;i<k;i++)
       {
           st.insert(arr[i]);
       }
    }

    void add(int num) 
    {
        // Write your code here.
        auto it=st.begin();
        if((*it)<num)
        {
            st.erase(it);
            st.insert(num);
        }
    }

    int getKthLargest() 
    {
       // Write your code here.
       return *(st.begin());
    }

};
