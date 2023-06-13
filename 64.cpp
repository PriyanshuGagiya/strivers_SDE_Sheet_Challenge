//https://www.codingninjas.com/codestudio/problems/search-in-rotated-sorted-array_8230687?challengeSlug=striver-sde-challenge&leftPanelTab=3
int search(int* arr, int n, int key) 
{
    // Write your code here.
    int rot=0;
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if((mid==0 || arr[mid-1]>arr[mid]) and 
        (mid==n-1 || arr[mid+1]>arr[mid]))
        {
            rot=mid;
            break;
        }
        else if(arr[low]<=arr[mid])
        {
            low=++mid;
        }
        else
        {
            high=--mid;
        }
    }
    low=0;
    high=rot-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]<key)
        {
            low=++mid;
        }
        else
        {
            high=--mid;
        }
    }
    low=rot;
    high=n-1;
     while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]<key)
        {
            low=++mid;
        }
        else
        {
            high=--mid;
        }
    }
    return -1;
}
