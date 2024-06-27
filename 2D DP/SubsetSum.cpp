#include<bits/stdc++.h>
using namespace std;

// * Recursion - O(2ⁿ)
bool f(int idx, vector<int> &arr, int k) {
  if(k == 0)
      return true;
  if(idx == 0) {
      if(arr[idx] == k)
          return true;
      return false;
  }

  bool take = false, notTake = false;

  if(k >= arr[idx])
      take = f(idx-1, arr, k - arr[idx]);
  notTake = f(idx-1, arr, k);

  return take || notTake;
}

bool isSubsetSum(vector<int>arr, int sum){
    // vector<int> dp(arr.size(), -1);
    return f(arr.size() - 1, arr, sum);
}

// * MEMOIZATION Approach: 
// * T.C: O(N*SUM)
// * S.C: O(N*SUM)
bool f(int idx, vector<int> &arr, int k, vector<vector<int>> &dp) {
    if(k == 0)
        return true;
    if(idx == 0) {
        if(arr[idx] == k)
            return true;
        return false;
    }

    if(dp[idx][k] != -1) return dp[idx][k];

    bool take = false, notTake = false;

    if(k >= arr[idx])
        take = f(idx-1, arr, k - arr[idx], dp);
    notTake = f(idx-1, arr, k, dp);

    return dp[idx][k] = take || notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return f(n-1, arr, k, dp);
}

// * Tabulation Approach:
bool subsetSumToK(int n, int k, vector<int> &arr) {
  // Initialize a 2D DP array with dimensions (n x k+1) to store subproblem results
  vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

  // Base case: If the target sum is 0, we can always achieve it by taking no elements
  for (int i = 0; i < n; i++) 
      dp[i][0] = true;
  

  // Base case: If the first element of 'arr' is less than or equal to 'k', set dp[0][arr[0]] to true
  if (arr[0] <= k) dp[0][arr[0]] = true;
  

  // Fill the DP array iteratively
  for (int idx = 1; idx < n; idx++) {
      for (int target = 1; target <= k; target++) {
          // If we don't take the current element, the result is the same as the previous row
          bool notTaken = dp[idx - 1][target];

          // If we take the current element, subtract its value from the target and check the previous row
          bool taken = false;
          if (arr[idx] <= target) {
              taken = dp[idx - 1][target - arr[idx]];
          }

          // Store the result in the DP array for the current subproblem
          dp[idx][target] = notTaken || taken;
      }
  }
  return dp[n - 1][k];
}

