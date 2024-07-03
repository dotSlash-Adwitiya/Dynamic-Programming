#include<bits/stdc++.h>
using namespace std;

// * Recursive Approach
int helperRecrusive(int ind, int target, vector<int>& arr) {
  if (target == 0)
      return 1;

  if (ind == 0)
      return (arr[0] == target) ? 1 : 0;

  int notTaken = helperRecrusive(ind - 1, target, arr);

  int taken = 0;
  if (arr[ind] <= target)
      taken = helperRecrusive(ind - 1, target - arr[ind], arr);

  return notTaken + taken;
}

int helperMemo(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
  // * Base case-I : If the target sum is 0, we found a valid subset
  if (target == 0)
      return 1;

  // * Base case -II : If we have considered all elements and the target is still not 0, return 0
  if (ind == 0)
      return (arr[0] == target) ? 1 : 0;

  if (dp[ind][target] != -1)
      return dp[ind][target];


  int notTaken = helperMemo(ind - 1, target, arr, dp);

  int taken = 0;
  if (arr[ind] <= target)
      taken = helperMemo(ind - 1, target - arr[ind], arr, dp);

  return dp[ind][target] = notTaken + taken;
}

int findWays(vector<int>& num, int k) {
  int n = num.size();
  vector<vector<int>> dp(n, vector<int>(k + 1, -1));
  return helperMemo(n - 1, k, num, dp);
}
