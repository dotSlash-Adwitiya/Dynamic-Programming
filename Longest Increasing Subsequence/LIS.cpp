#include<bits/stdc++.h>
using namespace std;

// * Recursive Code
int getAns(int arr[], int n, int ind, int prev_index) {
  if (ind == n) return 0;
  
  int notTake = getAns(arr, n, ind + 1, prev_index);
  
  int take = 0;
  if (prev_index == -1 || arr[ind] > arr[prev_index]) 
      take = 1 + getAns(arr, n, ind + 1, ind);

  return max(notTake, take);
}

int longestIncreasingSubsequence(int arr[], int n) {
  return getAns(arr, n, 0, -1);
}

// * Memoization Optimization - 2D DP
int getAns(int arr[], int n, int ind, int prev_index, vector<vector<int>>& dp) {
    if (ind == n) return 0;
        
    if (dp[ind][prev_index + 1] != -1) return dp[ind][prev_index + 1];
    
    int notTake = 0 + getAns(arr, n, ind + 1, prev_index, dp);
    
    int take = 0;
    
    if (prev_index == -1 || arr[ind] > arr[prev_index]) 
        take = 1 + getAns(arr, n, ind + 1, ind, dp);
    
    return dp[ind][prev_index + 1] = max(notTake, take);
}

int longestIncreasingSubsequence(int arr[], int n) {
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return getAns(arr, n, 0, -1, dp);
}

// * Tabulation
int longestIncreasingSubsequence(int arr[], int n) {
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

  for (int idx = n - 1; idx >= 0; idx--) {
      for (int prev_idx = idx - 1; prev_idx >= -1; prev_idx--) {
          int notTake = dp[idx + 1][prev_idx + 1];

          int take = 0;
          if (prev_idx == -1 || arr[idx] > arr[prev_idx])
              take = 1 + dp[idx + 1][idx + 1];

          dp[idx][prev_idx + 1] = max(notTake, take);
      }
  }
  return dp[0][0];
}


// * Tabulation with Space optimization
int longestIncreasingSubsequence(int arr[], int n) {
  vector<int> next(n + 1, 0), curr(n + 1, 0);

  for (int idx = n - 1; idx >= 0; idx--) {
      for (int prev_idx = idx - 1; prev_idx >= -1; prev_idx--) {
          int notTake = next[prev_idx + 1];

          int take = 0;
          if (prev_idx == -1 || arr[idx] > arr[prev_idx]) {
              take = 1 + next[idx + 1];
          }

          curr[prev_idx + 1] = max(notTake, take);
      }
      next = curr;
  }

  return next[0];
}