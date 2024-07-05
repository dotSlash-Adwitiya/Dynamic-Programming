#include<bits/stdc++.h>
using namespace std;

//  * Recursive Solution
int f(int m, int n, vector<vector<int>>& grid) {
  if(m < 0 || n < 0) //  * Check for invalid index- 1st
      return 0;

  if(grid[m][n] == 1) // * If idx valid, then access them
      return 0;

  if(m == 0 && n == 0) //  * BASE_CASE - reached destination
      return 1;

  int left = f(m-1, n, grid);
  int right = f(m, n-1, grid);

  return left + right;
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
  int m = obstacleGrid.size(), n = obstacleGrid[0].size();
  return f(m-1, n-1, obstacleGrid);
}

// * Memoization Approach
int f(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
  if(m < 0 || n < 0) //  * Check for invalid index- 1st
      return 0;

  if(grid[m][n] == 1) // * If idx valid, then access them
      return 0;

  if(m == 0 && n == 0) //  * BASE_CASE - reached destination
      return 1;
  
  if(dp[m][n] != -1)
      return dp[m][n];

  int left = f(m-1, n, grid, dp);
  int right = f(m, n-1, grid, dp);

  return dp[m][n] = left + right;
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
  int m = obstacleGrid.size(), n = obstacleGrid[0].size();
  vector<vector<int>> dp(m, (vector<int> (n, -1)));
  return f(m-1, n-1, obstacleGrid, dp);
}


// * Tabulation Approach
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
  int m = obstacleGrid.size(), n = obstacleGrid[0].size();
  vector<vector<int>> dp(m, (vector<int> (n, 0)));

    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
          
          if(obstacleGrid[i][j] == 1)  // * Imp to check first, if the 1st cell is 1, then ans = 0
              dp[i][j] = 0; 

          else if(i == 0 && j == 0) 
              dp[0][0] = 1; // * BASE CASE
          
          else {
              int down = 0, right = 0;
          
              if(i > 0) down = dp[i-1][j]; // * DO STUFF
              if(j > 0) right = dp[i][j-1]; // * DO STUFF
          
              dp[i][j] = down + right; // * PERFORM what's asked in the QUESTION
          }
      }
  }
  return dp[m-1][n-1];
}