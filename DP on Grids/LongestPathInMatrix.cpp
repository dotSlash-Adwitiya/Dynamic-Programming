#include<bits/stdc++.h>
using namespace std;

// * Recursive Code
// * T.C : O(N*M*4ⁿᵐ)
int f(int row, int col, vector<vector<int>>& grid, int n, int m) {
 
  if(row < 0 || col < 0 || row >= n || col >= m)
      return 0;
  
  int up = 0, down = 0, left = 0, right = 0;
  if(row - 1 >= 0 and grid[row-1][col] > grid[row][col])
      up = 1 + f(row - 1, col, grid, n, m);
  
  if(col + 1 < m and grid[row][col + 1] > grid[row][col])
      right = 1 + f(row, col + 1, grid, n, m);
  
  if(row + 1 < n and grid[row][col] < grid[row + 1][col])
      down = 1 + f(row + 1, col, grid, n, m);
      
  if(col - 1 >= 0 and grid[row][col - 1] > grid[row][col])
      left = 1 + f(row, col - 1, grid, n, m);
  
  return max({left, down, up, right, 1});
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
  int n = matrix.size(), m = matrix[0].size();
  int result = 0;
  for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
          result = max(result, f(i, j, matrix, n, m));
      }
  }
  return result;
}


// * Memoization Code
// * T.C and S.C : O(N*M)
int f(int row, int col, vector<vector<int>>& grid, int n, int m, vector<vector<int>> &dp) {
  
  if(row < 0 || col < 0 || row >= n || col >= m)
      return 0;
  
  if(dp[row][col] != -1) return dp[row][col];
  
  int up = 0, down = 0, left = 0, right = 0;
  
  if(row - 1 >= 0 and grid[row-1][col] > grid[row][col])
      up = 1 + f(row - 1, col, grid, n, m, dp);
  
  if(col + 1 < m and grid[row][col + 1] > grid[row][col])
      right = 1 + f(row, col + 1, grid, n, m, dp);
  
  if(row + 1 < n and grid[row][col] < grid[row + 1][col])
      down = 1 + f(row + 1, col, grid, n, m, dp);
      
  if(col - 1 >= 0 and grid[row][col - 1] > grid[row][col])
      left = 1 + f(row, col - 1, grid, n, m, dp);
  

  // * Because if ALL VALUES ARE SAME, 
  // * then the maxLength of PATH will be 1 at LEAST.
  return dp[row][col] = max({left, down, up, right, 1});
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
  int n = matrix.size(), m = matrix[0].size();
  int result = 0;
  vector<vector<int>> dp(n, vector<int> (m, -1));
  for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
          result = max(result, f(i, j, matrix, n, m, dp));
      }
  }
  return result;
}