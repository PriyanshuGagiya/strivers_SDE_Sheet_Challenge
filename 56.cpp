//https://www.codingninjas.com/codestudio/problems/n-queens_8230707?challengeSlug=striver-sde-challenge&leftPanelTab=0
bool check(int row, int col,vector<vector<int>>&board,int n) 
{
      int duprow = row;
      int dupcol = col;

      while (row >= 0 && col >= 0) 
      {
        if (board[row][col])
          return false;
        row--;
        col--;
      }

      col = dupcol;
      row = duprow;
      while (col >= 0) 
      {
        if (board[row][col])
          return false;
        col--;
      }

      row = duprow;
      col = dupcol;
      while (row < n && col >= 0) 
      {
        if (board[row][col])
          return false;
        row++;
        col--;
      }
      row = duprow;
      col = dupcol;
      return true;
}
void solve(int col,vector<vector<int>>&board,vector<vector<int>>&ans,int n)
{
    if(col==n)
    {
        vector<int>temp;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                temp.push_back(board[i][j]);
        ans.push_back(temp);
        return;
    }
    for(int row=0;row<n;row++)
    {
            if(check(row,col,board,n))
            {
                board[row][col]=1;
                solve(col+1,board,ans,n);
                board[row][col]=0;   
            }
    }
}
vector<vector<int>> solveNQueens(int n) 
{
    vector<vector<int>>ans;
    vector<vector<int>>board(n,vector<int>(n,0));
    solve(0,board,ans,n);
    return ans;

}
//better time complexity but need more space
vector<vector<int> > ans;
void add(vector<vector<int> >& board, int n){
    vector<int>temp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}
void nQueens(int col, vector<vector<int>>& board, int n, vector<bool>&LR,vector<bool>&LD, vector<bool>&UD){
    // Base Case
    if(col == n){
        add(board, n);
        return;
    }

    // Traversing Each row In Given Column
    for(int row = 0; row < n; row++){
        if(LR[row] == 0 && LD[row+col] ==0 && UD[n-1+col-row] == 0){
            board[row][col] = 1;
            LR[row] = 1;
            LD[row+col] = 1;
            UD[n-1+col-row] = 1;
            nQueens(col + 1, board, n, LR, LD, UD);
            // Backtrack
            board[row][col] = 0;
            LR[row] = 0;
            LD[row+col] = 0;
            UD[n-1+col-row] = 0;
        }
    }
}
vector<vector<int>> solveNQueens(int n) 
{
       vector<vector<int>> board(n, vector<int>(n, 0));  
        // lr = LeftRow, LD = Lower Diagonal, UD = Upper Diagonal
        vector<bool>LR(n, 0);
        vector<bool>LD(2*n-1, 0);
        vector<bool>UD(2*n-1, 0);
        nQueens(0, board, n, LR, LD, UD);
    return ans;
}
