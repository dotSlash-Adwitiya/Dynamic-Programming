#include<bits/stdc++.h>
using namespace std;

// * Recursive Approach - O(2^n)
/*
  * For every move we have 2 Options : Either Move forward or Downwards
  * Which when implemented in TOP DOWN Approach becomes : Upwards and Backwards
  * So, for every move we have 2 Options, and we do it recursively which results in EXPONENTIAL TIME
*/

int f(int i, int j) {
  if(i == 0 && j == 0) return 1;
  if(i < 0 || j < 0) return 0;
  
  int up = f(i-1, j);
  int left = f(i, j-1);
  
  return up + left;
}

int uniquePaths(int m, int n) {
  return f(m-1, n-1);    
}

// * Memoization - TOP DOWN Optimization
// * Time and Space Complexity : O(N*M)
int f(int i, int j, vector<vector<int>> &dp) {
  if(i == 0 && j == 0) return 1;
  if(i < 0 || j < 0) return 0;
  
  if(dp[i][j] != -1)
  return dp[i][j];
  
  int up = f(i-1, j, dp);
  int left = f(i, j-1, dp);
  
  return dp[i][j] = up + left;
}

int uniquePaths(int m, int n) {
  vector<vector<int>> dp(m, vector<int> (n, -1));
  return f(m - 1,n - 1, dp);
}

// * TABULATION Approach: ITERATIVE Solution (BOTTOM UP)
int uniquePaths(int m, int n) {

  // * OBSERVE The changing parameters for deciding the DP_SIZE
  vector<vector<int>> dp(m, vector<int> (n, -1));
  
  for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
          if(i == 0 && j == 0) dp[0][0] = 1; // * BASE CASE
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