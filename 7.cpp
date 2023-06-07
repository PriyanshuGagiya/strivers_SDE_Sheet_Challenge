//https://www.codingninjas.com/codestudio/problems/rotate-matrix_8230774?challengeSlug=striver-sde-challenge
// #include <bits/stdc++.h>
//own approach
// void rotateMatrix(vector<vector<int>> &mat, int n, int m)
// {
//      int left=0,right=m-1,top=0,bottom=n-1;
//      while(top<bottom&&left<right)
//      {
//          int temp=mat[top][left];
//          for(int i=left+1;i<=right;i++)
//          {
//              int k= mat[top][i];
//              mat[top][i]=temp;
//              temp=k;
//          }
//          top++;
//          for(int i=top;i<=bottom;i++)
//          {
//             int k=mat[i][right];
//             mat[i][right]=temp;
//             temp=k;
//          }
//          right--;
//          for(int i=right;i>=left;i--)
//          {
//              int k=mat[bottom][i];
//              mat[bottom][i]=temp;
//              temp=k;
//          }
//          bottom--;
//          for(int i=bottom;i>=top;i--)
//          {
//              int k=mat[i][left];
//              mat[i][left]=temp;
//              temp=k;
//          }
//          left++;
//          mat[top-1][left-1]=temp;
//      }
// }
//better approach from solution 
#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    if(n==1 || m==1) return;
    int top = 0, bot = n-1, left = 0, right = m-1;
    while(top<bot && left < right){
        int temp = mat[left][top];

        for(int i = top;i<bot;i++)
            mat[i][left] = mat[i+1][left];

        for(int i=left;i<right;i++)
            mat[bot][i] = mat[bot][i+1];

        for(int i=bot;i>top;i--)
            mat[i][right] = mat[i-1][right];
            
        for(int i=right;i>left+1;i--)
            mat[top][i] = mat[top][i-1];

        mat[top][left+1] = temp;
        top++, bot--,left++,right--;
    }
}
