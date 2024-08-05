#include <bits/stdc++.h> 
using namespace std;


int getMaxProfit(vector<int>& prices, int n, int ind, int buy, int cap) {
  
  if (ind == n || cap == 0) return 0;

  int profit;
  if (buy)
      profit = max(0 + getMaxProfit(prices, n, ind + 1, 1, cap),
                    prices[ind] + getMaxProfit(prices, n, ind + 1, 0, cap - 1));
  else
      profit = max(0 + getMaxProfit(prices, n, ind + 1, 0, cap),
                    -prices[ind] + getMaxProfit(prices, n, ind + 1, 1, cap));
  

  return profit;
}

int maximumProfit(vector<int>& prices, int n, int k) {
  return getMaxProfit(prices, n, 0, 0, k);
}

// * Memoization 3D DP
int getAns(vector<int>& Arr, int n, int ind, int buy, int cap, vector<vector<vector<int>>>& dp) {
  if (ind == n || cap == 0) return 0;

  if (dp[ind][buy][cap] != -1)
      return dp[ind][buy][cap];

  int profit;

  if (buy)
      profit = max(0 + getAns(Arr, n, ind + 1, 1, cap, dp),
                    Arr[ind] + getAns(Arr, n, ind + 1, 0, cap - 1, dp));
  
  else
      profit = max(0 + getAns(Arr, n, ind + 1, 0, cap, dp),
                    -Arr[ind] + getAns(Arr, n, ind + 1, 1, cap, dp));
  

  return dp[ind][buy][cap] = profit;
}

int maximumProfit(vector<int>& prices, int n, int k) {
  vector<vector<vector<int>>> dp(n,
                                  vector<vector<int>>(2, vector<int>(k + 1, -1)));

  return getAns(prices, n, 0, 0, k, dp);
}

// * TABULATION 
int maximumProfit(vector<int>& prices, int n, int k) {
  vector<vector<vector<int>>> dp(n + 1,
                                  vector<vector<int>>(2, vector<int>(k + 1, 0)));

  for (int ind = n - 1; ind >= 0; ind--) {
      for (int buy = 0; buy <= 1; buy++) {
          for (int cap = 1; cap <= k; cap++) {
              if (buy) 
                  dp[ind][buy][cap] = max(0 + dp[ind + 1][1][cap],
                              prices[ind] + dp[ind + 1][0][cap - 1]);
              else 
                  dp[ind][buy][cap] = max(0 + dp[ind + 1][0][cap],
                              -prices[ind] + dp[ind + 1][1][cap]);
          }
      }
  }

  return dp[0][0][k];
}

// * TABULATION with SPACE OPTIMIZATION
int maximumProfit(vector<int>& prices, int n, int k) {
  vector<vector<int>> ahead(2, vector<int>(k + 1, 0));
  vector<vector<int>> cur(2, vector<int>(k + 1, 0));

  for (int ind = n - 1; ind >= 0; ind--) {
      for (int buy = 0; buy <= 1; buy++) {
          for (int cap = 1; cap <= k; cap++) {
              if (buy)
                  cur[buy][cap] = max(0 + ahead[1][cap],
                                      prices[ind] + ahead[0][cap - 1]);
              else 
                  cur[buy][cap] = max(0 + ahead[0][cap],
                                      -prices[ind] + ahead[1][cap]);
          }
      }
      // * Update the ahead arr[] with the current values
      ahead = cur;
  }

  return ahead[0][k];
}