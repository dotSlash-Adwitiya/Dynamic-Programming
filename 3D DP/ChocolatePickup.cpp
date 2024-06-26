#include<bits/stdc++.h>
using namespace std;

/*
 * Intuition: We have two people here : Alice and BOB (Or two robots)
 * Who can move only 3 directions
 * Both will move simultaneously in the next ROW --- This is hard to think about
 * That's why, we take only 1 row, not i1 and i2 
*/

// * T.C : O(3ⁿ * 3ⁿ)
// * S.C: O(N) - Stack Space
int f(int i, int j1, int j2, int r, int c, vector<vector<int>>& grid) {
  // * Out OF Bound BASE_CASE
  if(j1 < 0 || j2 < 0 || j1 >= c || j2 >= c)
      return -1e9;
  
  // * DESTINATION BASE CASE
  if(i == r-1){
      if(j1 == j2) // * SAME CELL
          return grid[i][j1];
          
      else // * DIFF CELL 
          return grid[i][j1] + grid[i][j2];
  }
  
  int maxi = 0;
  for(int dj1 = -1; dj1 <= +1; dj1++) {
      for(int dj2 = -1; dj2 <= +1; dj2++) {
          int value = 0;
          if(j1 == j2)
              value = grid[i][j1];
          else
              value = grid[i][j1] + grid[i][j2];
              
          //  *ADD The remaining to value w/ recursion                    
          value += f(i + 1, j1 + dj1, j2 + dj2, r, c, grid);
          
          maxi = max(value, maxi);
      }
  }
  return maxi;
}

int solve(int n, int m, vector<vector<int>>& grid) {
  return f(0, 0, m - 1, n, m, grid);
}

// * T.C: O (N*M*M)
// * S.C: O (N*M*M) + O(N)
int f(int i, int j1, int j2, int r, int c, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp) {
  // * Out OF Bound BASE_CASE
  if(j1 < 0 || j2 < 0 || j1 >= c || j2 >= c)
      return -1e9;
  
  if(dp[i][j1][j2] != - 1)
      return dp[i][j1][j2];

  // * DESTINATION BASE CASE
  if(i == r-1){
      if(j1 == j2) // * SAME CELL
          return grid[i][j1];
          
      else // * DIFF CELL 
          return grid[i][j1] + grid[i][j2];
  }
  
  int maxi = 0;
  for(int dj1 = -1; dj1 <= +1; dj1++) {
      for(int dj2 = -1; dj2 <= +1; dj2++) {
          int value = 0;
          if(j1 == j2)
              value = grid[i][j1];
          else
              value = grid[i][j1] + grid[i][j2];
              
          //  *ADD The remaining to value w/ recursion                    
          value += f(i+1, j1 + dj1, j2 + dj2, r, c, grid, dp);
          
          maxi = max(value, maxi);
      }
  }
  return dp[i][j1][j2] = maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
  vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int> (c, - 1)));
  return f(0, 0, c - 1, r, c, grid, dp);
}