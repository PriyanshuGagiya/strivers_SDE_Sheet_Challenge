//https://www.codingninjas.com/codestudio/challenges/striver-sde-challenge?activeProblems=true
bool valid(int row,int col,int mat[9][9],int c)
{
    for(int i=0;i<9;i++)
    {
        if(mat[i][col]==c)
        {
            return false;
        }
        if(mat[row][i]==c)
        {
            return false;
        }
        if(mat[3*(row/3)+i/3][3*(col/3)+i%3]==c)
        {
            return false;
        }
    }
    return true;
}
bool solve(int matrix[9][9])
{
    for(int row=0;row<9;row++)
    {
        for(int col=0;col<9;col++)
        {
            if(!matrix[row][col])
            {
                for(int c=1;c<=9;c++)
                {
                    if(valid(row,col,matrix,c))
                    {
                        matrix[row][col]=c;
                        if(solve(matrix))
                        {
                            return true;
                        }
                        else
                        {
                            matrix[row][col]=0;
                        }
                    }
                }
                return false;
                
            }
        }
    }
    return true;
}
bool isItSudoku(int matrix[9][9]) 
{
   return solve(matrix);
}

