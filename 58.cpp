#include <bits/stdc++.h>
//https://www.codingninjas.com/codestudio/problems/m-coloring-problem_8230777?challengeSlug=striver-sde-challenge&leftPanelTab=1
bool check(int node,int col,vector<int>&color,vector<vector<int>> &mat)
{
    for(int i=0;i<mat.size();i++)
    {
        if(i!=node and mat[node][i] and color[i]==col )
        {
            return false;
        }
    }
    return 1;

}
bool solve(int i,vector<int>&color,vector<vector<int>> &mat, int m)
{
    if(i==mat.size())
    {
        return 1;
    }

    for(int col=1;col<=m;col++)
    {
        if(check(i,col,color,mat))
        {
            color[i]=col;
            if(solve(i+1,color,mat,m))
            {
                return 1;
            }
            color[i]=0;

        }
    }
    return 0;
}
string graphColoring(vector<vector<int>> &mat, int m) 
{
    int n=mat.size();
    vector<int>color(n,0);
    if(solve(0,color,mat,m))
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
    
}
