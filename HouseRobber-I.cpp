#include<bits/stdc++.h>
using namespace std;

// * Recursive Approach
// * T.C : O(2^n)
int helper(int idx, vector<int>& nums, int sum) {
    if(idx >= nums.size())
        return sum;

    int pick = helper(idx+2, nums, sum + nums[idx]);
    
    int notPick = helper(idx+1, nums, sum);

    return max(pick, notPick);
}

// * Memoization Approach : 
// * T.C : O(N), S.C :O(N)
int helper(int idx, vector<int>& nums, vector<int> &dp) {
    
    if(idx >= nums.size()) return 0;

    if(dp[idx] != -1) return dp[idx];

    int pick = helper(idx+2, nums, dp) + nums[idx];
    
    int notPick = helper(idx+1, nums, dp);

    return dp[idx] = max(pick, notPick);
}



// * Tabulation - BOTTOM UP Approach
// * T.C : O(N), S.C :O(N)
int rob(vector<int>& nums) {
  vector<int> dp(nums.size(), -1);

  dp[0] = nums[0];
  int neg = 0;

  for(int i = 1; i < nums.size(); i++) {
      int take = nums[i];
      if(i > 1)
          take += dp[i-2];
      int notTake = dp[i-1];
      dp[i] = max(take, notTake);
  }
  return dp[nums.size() - 1];
}

// * Tabulation with Space Optimised
// * T.C : O(N), S.C :O(1)
int rob(vector<int>& nums) {

  int prevIdx = nums[0], prev2Idx = 0, currIdx = 0;

  for(int i = 1; i < nums.size(); i++) {
      int take = nums[i] + prev2Idx;
      int notTake = prevIdx;
      currIdx = max(take, notTake);
      prev2Idx = prevIdx;
      prevIdx = currIdx;
  }
  return prevIdx;
}

// * PRACTICE - 1
// * Recursive Approach
// * T.C : O(2^n)
int helper(int idx, vector<int>& nums, int sum) {
    if(idx >= nums.size())
        return sum;

    int pick = helper(idx+2, nums, sum + nums[idx]);
    
    int notPick = helper(idx+1, nums, sum);

    return max(pick, notPick);
}

int helper(int idx, vector<int>& nums, vector<int> &dp) {
    
    if(idx >= nums.size()) return 0;

    if(dp[idx] != -1) return dp[idx];

    int pick = helper(idx+2, nums, dp) + nums[idx];
    
    int notPick = helper(idx+1, nums, dp);

    return dp[idx] = max(pick, notPick);
}


int rob(vector<int>& nums) {
  vector<int> dp(nums.size(), -1);

  dp[0] = nums[0];
  int neg = 0;

  for(int i = 1; i < nums.size(); i++) {
      int take = nums[i];
      if(i > 1)
          take += dp[i-2];
      int notTake = dp[i-1];
      dp[i] = max(take, notTake);
  }
  return dp[nums.size() - 1];
}

int rob(vector<int>& nums) {

  int prevIdx = nums[0], prev2Idx = 0, currIdx = 0;

  for(int i = 1; i < nums.size(); i++) {
      int take = nums[i] + prev2Idx;
      int notTake = prevIdx;
      currIdx = max(take, notTake);
      prev2Idx = prevIdx;
      prevIdx = currIdx;
  }
  return prevIdx;
}
