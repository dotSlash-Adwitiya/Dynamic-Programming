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
    // * Storing -1 at 0th index, 0 at 1, 1 at 2, 2 at 3rd index and so on.......
    // * Thats why we create dp of size n+1
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

// * This is the final approach I learnt.
// * This is the 2nd most optimized solution for this problem.
// * T.C: O(N), S.C: O(N) Single Array
int longestIncreasingSubsequence(int arr[], int n) {
    vector<int> dp(n, 1);
    int maxLen = 1;
    for(int idx = 0; idx < n; idx++){
        for(int prevIdx = 0; prevIdx <= idx-1; prevIdx++){
            if(arr[prevIdx] < arr[idx])
                dp[idx] = max(dp[idx], 1 + dp[prevIdx]);
        }
        maxLen = max(maxLen, dp[idx]);
    }
    return maxLen;
}


// * BINARY SEARCH APPROACH
// * This is the most optimized solution for this problem.
int longestIncreasingSubsequence(int arr[], int n) {
    vector<int> temp;
    temp.push_back(arr[0]);

    for (int i = 1; i < n; i++) {
       if(arr[i] > temp.back()) 
            temp.push_back(arr[i]);
        else{
            int idx = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[idx] = arr[i];
        }
    }

    return temp.size();
}