#include<bits/stdc++.h>
using namespace std;

// * Recursive Approach
int f(int idx, int amount, vector<int> &coins) {
  if(idx < 0 || amount < 0) return 0;
  if(amount == 0) return 1;

  int take = 0, notTake = 0;
  if(coins[idx] <= amount) 
      take = f(idx, amount - coins[idx], coins);
  
  notTake = f(idx - 1, amount, coins);
  
  return take + notTake;
}

int change(int amount, vector<int>& coins) {
  return f(coins.size() - 1, amount, coins);   
}

// * MEMOIZATION
int f(int idx, int amount, vector<int> &coins, vector<vector<int>> &dp) {
  if(idx < 0 || amount < 0) return 0;
  if(amount == 0) return 1;
  if(dp[idx][amount] != -1) return dp[idx][amount];

  int take = 0, notTake = 0;

  take = f(idx, amount - coins[idx], coins, dp);
  notTake = f(idx - 1, amount, coins, dp);
  
  return dp[idx][amount] = take + notTake;
}

int change(int amount, vector<int>& coins) {
  vector<vector<int>> dp(301,vector<int>(5001,-1));
  return f(coins.size() - 1, amount, coins, dp);   
}

// * TABULATION 
 int change(int amount, vector<int>& coins) {
  int n = coins.size();
  vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

  // * Initialize base cases
  for(int idx = 0; idx <= n; idx++)
      dp[idx][0] = 1; // * 1 way to make amount 0 (by choosing no coins)

  for(int idx = 1; idx <= n; idx++) {
      for(int amt = 1; amt <= amount; amt++) {
          if(coins[idx - 1] <= amt)
              dp[idx][amt] = dp[idx - 1][amt] + dp[idx][amt - coins[idx - 1]];
          else
              dp[idx][amt] = dp[idx - 1][amt];
      }
  }
  return dp[n][amount];
}