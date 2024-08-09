#include<bits/stdc++.h>
using namespace std;

// * Recursive CODE
int f(vector<int>& nums, int target) {
  if(target < 0) return 0;
  if(target == 0) return 1;
  int ways = 0;
  for(int i = 0; i < nums.size(); i++)
      ways += f(nums, target - nums[i]);
  return ways;
}
int combinationSum4(vector<int>& nums, int target) {
  return f(nums, target);
}

// * OPTIMIZATION USING MEMOIZATION
int f(vector<int>& nums, int target, vector<int> &dp) {
  if(target < 0) return 0;
  if(target == 0) return 1;
  if(dp[target] != -1) return dp[target];
  int ways = 0;
  for(int i = 0; i < nums.size(); i++)
      ways += f(nums, target - nums[i], dp);
  return dp[target] = ways;
}
int combinationSum4(vector<int>& nums, int target) {
  vector<int> dp(target+1, -1);
  return f(nums, target, dp);
}

// * TABULATION OPTIMIZATION of Recursive STACK SPACE
int combinationSum4(vector<int>& nums, int target) {
    vector<long long> dp(target+1,0);
    int MOD = 1e9+7;
    //base case 
    dp[0]=1;

    for(int t = 1; t <= target; t++) { // * 1st changing state is TARGET
        for(int idx = 0; idx < nums.size(); idx++) { // * 2nd Changing state is Index
            if(t - nums[idx] >= 0)
                  dp[t] += (dp[t - nums[idx]]) % MOD;  // Ensure no overflow
        }
    }

    return dp[target];
}