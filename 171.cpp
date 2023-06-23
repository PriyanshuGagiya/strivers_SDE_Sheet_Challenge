#include <bits/stdc++.h> 
//https://www.codingninjas.com/studio/problems/maximum-product-subarray_8230828?challengeSlug=striver-sde-challenge&leftPanelTab=1
int maximumProduct(vector<int> &arr, int n)
{
    int maxLeft = arr[0];
    int maxRight = arr[0];
    
    int prod = 1;
    
    bool zero =  false;
    
    for(int i=0;i<n;i++) {
        prod *= arr[i];
        if(arr[i] == 0) 
        {
            zero = true;
            prod = 1;
            continue;
        }
        maxLeft = max(maxLeft,prod);
    }
    
    prod = 1;
    
    for(int i=n-1;i>=0;i--) 
    {
        prod *= arr[i];
        if(arr[i] == 0) {
            zero = true;
            prod = 1;
            continue;
        }
        maxRight = max(maxRight,prod);
    }
    
    if(zero) return max(max(maxLeft,maxRight),0);
    return max(maxLeft,maxRight);
	
}
