//https://www.codingninjas.com/codestudio/problems/count-inversions_8230680?challengeSlug=striver-sde-challenge&leftPanelTab=1//https://www.codingninjas.com/codestudio/problems/count-inversions_8230680?challengeSlug=striver-sde-challenge&leftPanelTab=1
#include <bits/stdc++.h>
long long ans;
void merge(long long *arr,long long temp[],int left,int mid,int right)
{
    int i = left,j = mid,k = left;
    while((i <= mid-1) && (j <= right))
    {
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            ans+= abs(mid - i);
        }
    }

    while(i <= mid - 1)
        temp[k++] = arr[i++];

    while(j <= right)
        temp[k++] = arr[j++];

    for(i = left ; i <= right ; i++)
        arr[i] = temp[i];
 
}

void mergeSort(long long *arr,long long temp[],int left,int right)
{
    if(right<=left) return;
    int mid = (left + right)/2;
    mergeSort(arr,temp,left,mid);
    mergeSort(arr,temp,mid+1,right);
    merge(arr,temp,left,mid+1,right);
 
}
long long getInversions(long long *arr, int n)
{
    ans=0;
    long long temp[n];
    mergeSort(arr,temp,0,n-1);
    return ans;
}
