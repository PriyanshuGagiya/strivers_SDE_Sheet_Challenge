//https://www.codingninjas.com/codestudio/problems/search-in-a-2d-matrix_8230773?challengeSlug=striver-sde-challenge&leftPanelTab=1
bool searchMatrix(vector<vector<int>>& mat, int target) 
{
    int n=mat.size();
    int m=mat[0].size();
    int low=0;
    int high=(n*m)-1;
    while(low<=high)
    {
        int mid=high+(low-high)/2;
        if(mat[mid/m][mid%m]==target)
        {
            return 1;
        }
        else if(mat[mid/m][mid%m]<target)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return 0;
        
}
