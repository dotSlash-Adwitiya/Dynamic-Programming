#include<bits/stdc++.h>
using namespace std;

//  * Recursive Solution
int helper(int idx, int arr[], int n, int prevEle){
  if(idx == n)
      return 0;
  
  int notPick = helper(idx + 1, arr, n, prevEle);
  int pick = 0;
  if(prevEle == -1 || arr[idx] > arr[prevEle])
      pick = 1 + helper(idx + 1, arr, n, idx);
      
  return max(pick, notPick);
}

int longestSubsequence(int n, int a[])
{
  return helper(0, a, n, -1);
}

// * Memoizaiton Solution
int helper(int idx, int arr[], int n, int prevEle, vector<vector<int>> &dp){
  if(idx == n)
      return 0;
  
  if(dp[idx][prevEle + 1] != -1)
      return dp[idx][prevEle + 1];
      
  int notPick = helper(idx + 1, arr, n, prevEle, dp);
  int pick = 0;
  if(prevEle == -1 || arr[idx] > arr[prevEle])
      pick = 1 + helper(idx + 1, arr, n, idx, dp);
      
  return dp[idx][prevEle + 1] = max(pick, notPick);
}

int longestSubsequence(int n, int a[])
{
    vector<vector<int>> dp(n, vector<int> (n+1, -1));
    return helper(0, a, n, -1, dp);
}

// * Tabulation Solution
int longestSubsequence(int n, int arr[])
{
  vector<vector<int>> dp(n + 1, vector<int> (n+1, 0));
  for(int idx = n-1; idx >= 0; idx--) {
      for(int prev = idx-1; prev >= -1; prev--) {
          int notPick = dp[idx + 1][prev + 1];
          int pick = 0;
          if(prev == -1 || arr[idx] > arr[prev])
              pick = 1 + dp[idx + 1][idx + 1];
              
          dp[idx][prev + 1] = max(pick, notPick);
      }
  }
  return dp[0][0];
}