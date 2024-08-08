#include<bits/stdc++.h>
using namespace std;

// * RECURSIVE Solution
// * T.C : O(3ⁿ)
int f(int row, int col, vector<vector<int>> &grid, int n, int m) {
  if(col < 0 || col >= m)
      return -1e9;

  if(row == 0) 
      return grid[0][col];

  int up = grid[row][col] + f(row-1, col, grid, n, m);

  int upLeft = grid[row][col] + f(row-1, col-1, grid, n, m);

  int upRight = grid[row][col] + f(row-1, col+1, grid, n, m);
  
  return max(up, (max(upLeft, upRight)));
}


int getMaxPathSumRecursive(vector<vector<int>> &matrix)
{
  int n = matrix.size();
  int m = matrix[0].size();

  int sum = INT_MIN;
  for(int i = 0; i < m; i++)
      sum = max(sum, f(n-1,i, matrix, n, m));
  return sum;
}

// * Optimization using MEMOIZATION
// * T.C : O(N*M)
// * S.C : O(N*M) (For DP[][] array) + O(N) (For stack space)
int f(int row, int col, vector<vector<int>> &grid, int n, int m,  vector<vector<int>> &dp) {
  if(col < 0 || col >= m)
      return -1e9;

  if(row == 0) 
      return grid[0][col];

  if(dp[row][col] != -1)
    return dp[row][col];

  int up = grid[row][col] + f(row-1, col, grid, n, m, dp);

  int upLeft = grid[row][col] + f(row-1, col-1, grid, n, m, dp);

  int upRight = grid[row][col] + f(row-1, col+1, grid, n, m, dp);
  
  return dp[row][col] = max(up, (max(upLeft, upRight)));
}

// * Memoization
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int sum = INT_MIN;
    vector<vector<int>> dp(n, vector<int> (m, -1));

    for(int i = 0; i < m; i++) // * Call the helper f() for every column in LAST ROW
        sum = max(sum, f(n-1,i, matrix, n, m, dp));
    return sum;
}

// * TABULATION
// * T.C : O(N*M) + O(M) (For finding max sum from LAST ROW)
// * S.C : O(N*M) (For DP[][] array) (No Recursive Stack space used anymore) 
int getMaxPathSum(vector<vector<int>> &grid)
{
  int n = grid.size();
  int m = grid[0].size();

  vector<vector<int>> dp(n, vector<int> (m, -1));

  for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++){
          
          if(i == 0) //  * BASE CASE
              dp[i][j] = grid[0][j];
          
          else {
              int up = -1e9, upLeft = -1e9, upRight = -1e9;
              
              // * As we've provided base case for up,
              // * WE CAN BE SURE, that its valid indice will be accessed,
              // * so no need to perform a check
              up = grid[i][j] + dp[i-1][j];

              if(j > 0) // * indices could fall behind 0
                  upLeft = grid[i][j] + dp[i-1][j-1];
              if(j < m-1) // * indices could fall beyond the column SIZE
                  upRight = grid[i][j] + dp[i-1][j+1];
              
              dp[i][j] = max(up, max(upRight, upLeft));
          }
      }
  }
  int sum = INT_MIN;
  
  // * WE KNOW THAT our final answer will be stored in last row of DP[n-1][col];
  int i = n-1; 
  for(int j = 0; j < m; j++) 
      sum = max(sum, dp[i][j]);

  return sum;
}