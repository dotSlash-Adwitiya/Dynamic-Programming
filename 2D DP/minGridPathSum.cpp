#include<bits/stdc++.h>
using namespace std;

// * Recursive Approach 
// * T.C : O (2^N) because there are 2 calls. 
int helper(int row, int col, vector<vector<int>> &grid) {
    if(row == 0 && col == 0){
         return grid[row][col];
    }

    if(row < 0 || col < 0)
        return 1e9;


    int left = grid[row][col] + helper(row, col - 1, grid);
    int up = grid[row][col] + helper(row - 1, col, grid);
    
    return min(left, up);
}

int minSumPath(vector<vector<int>> &grid) {
    return helper(grid.size() - 1, grid[0].size() - 1, grid);
}

// * Memoization Approach
int helper(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp) {
  if(row == 0 && col == 0){
        return grid[row][col];
  }

  if(row < 0 || col < 0)
      return 1e9;
  
// * You can also use: (to avoid integer overflow)
// if(row < 0 || col < 0)
//   return INT_MAX/10;

  if(dp[row][col] != -1) return dp[row][col];
  
  // * I FORGOT TO INCLUDE the current element in the answer.
  int left = grid[row][col] + helper(row, col - 1, grid, dp);
  int up = grid[row][col] + helper(row - 1, col, grid, dp);
  
  return dp[row][col] = min(left, up);
}

int minSumPathMemo(vector<vector<int>> &grid) {
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<int>> dp(n, vector<int>(m,-1));
  return helper(n-1, m-1, grid, dp);
}

// * TABULATION Approach
int minSumPath(vector<vector<int>> &grid) {
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<int>> dp(n, vector<int>(m,0));

  for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
          
          // * 1st step -- BASE_CASE
          if(i == 0 && j == 0)
              dp[i][j] = grid[i][j];
          
          // * 2nd Step -- DO STUFF
          else {
              int left = grid[i][j], up = grid[i][j];
              if(j > 0) 
                  left += dp[i][j-1];
              else 
                  left += 1e9;
              if(i > 0) 
                  up +=  dp[i-1][j];
              else 
                  up += 1e9;
              
              //  * 3rd step - DO WHat's ASKED in the Question!
              dp[i][j] = min(up, left);
          }
      }
  }
  return dp[n-1][m-1];
}