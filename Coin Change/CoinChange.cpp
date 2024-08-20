#include<bits/stdc++.h>
using namespace std;

// * Recursive Solution
// * T.C: Exponential
int f(int idx, int amount, vector<int> &coins) {
  if(idx == 0) 
    return (amount % coins[0] == 0) ? amount / coins[idx] : 1e9;
  
  int notTake = f(idx - 1, amount, coins);
  int take = INT_MAX;
  if(coins[idx] <= amount) 
      take = 1 + f(idx, amount - coins[idx], coins);
  
  return min(take, notTake);
}

int coinChange(vector<int>& coins, int amount) {
  int n = coins.size();
  int ans = f(n - 1, amount, coins);
  return ans >= 1e9 ? -1 : ans;
}

// * MEMOIZATION 
int f(int idx, int amount, vector<int> &coins, vector<vector<int>> &dp) {
  if(idx == 0) 
      return (amount % coins[0] == 0) ? amount / coins[idx] : 1e9;
  
  if(dp[idx][amount] != -1) return dp[idx][amount];

  int take = INT_MAX;
  if(coins[idx] <= amount) 
      take = 1 + f(idx, amount - coins[idx], coins, dp);

  int notTake = f(idx - 1, amount, coins, dp);
  
  return dp[idx][amount] = min(take, notTake);
}

int coinChange(vector<int>& coins, int amount) {
  int n = coins.size();
  vector<vector<int>> dp(n, vector<int> (amount + 1, -1));
  int ans = f(n - 1, amount, coins, dp);
  return ans >= 1e9 ? -1 : ans;
}

// * TABULATION
int coinChange(vector<int>& coins, int amount) {
  int n = coins.size();
  vector<vector<int>> dp(n, vector<int> (amount + 1, 0));

  for(int amt = 0; amt <= amount; amt++)
    dp[0][amt] = (amt % coins[0] == 0 ? amt / coins[0] : 1e9);

  for(int idx = 1; idx < n; idx++) {
      for(int amt = 0; amt <= amount; amt++) {
          int take = INT_MAX;
          if(coins[idx] <= amt) 
              take = 1 + dp[idx][amt - coins[idx]];
          int notTake = dp[idx - 1][amt];
          
          dp[idx][amt] = min(take, notTake);
      }
  }

  int ans = dp[n - 1][amount];
  return ans >= 1e9 ? -1 : ans;
}