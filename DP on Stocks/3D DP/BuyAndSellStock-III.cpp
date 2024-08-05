#include <bits/stdc++.h>
using namespace std;

// * Recursive Solution
// * T.C: O(2ⁿ)

int f(int idx, int buy, int cap, vector<int>& values){
  if(idx == values.size() || cap == 0)
      return 0;
  int profit = 0;
  if(buy){
      profit = max((-values[idx] + f(idx+1, 0, cap, values)),
                    0 + f(idx+1, 1, cap, values));
  } else{
      profit = max((values[idx] + f(idx+1, 1, cap-1, values)),
                    0 + f(idx+1, 0, cap, values));
  }
  return profit;
}

int maxProfit(vector<int>& prices)
{
  return f(0, 1, 2, prices);
}

// * Memoization Optimization using 3D DP
int f(int idx, int buy, int cap, vector<int>& values, vector<vector<vector<int>>> &dp){
  if(idx == values.size() || cap == 0)
      return 0;

  if(dp[idx][buy][cap] != -1)
      return dp[idx][buy][cap];
          
  int profit = 0;
  if(buy){
      profit = max((-values[idx] + f(idx+1, 0, cap, values, dp)),
                    0 + f(idx+1, 1, cap, values, dp));
  } else{
      profit = max((values[idx] + f(idx+1, 1, cap-1, values, dp)),
                    0 + f(idx+1, 0, cap, values, dp));
  }
  return dp[idx][buy][cap] = profit;
}

int maxProfit(vector<int>& prices)
{
  int n = prices.size();
  vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
  return f(0, 1, 2, prices, dp);
}

// * Tabulation
int maxProfit(vector<int>& prices)
{
  int n = prices.size(); 
  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

  // * BASE CASE Will already be initialzed with 0

  for (int ind = n - 1; ind >= 0; ind--) {
      for (int buy = 0; buy <= 1; buy++) {
          for (int cap = 1; cap <= 2; cap++) {
              if (buy)  
                  dp[ind][buy][cap] = max(0 + dp[ind + 1][1][cap],
                                          prices[ind] + dp[ind + 1][0][cap - 1]);
              else  
                  dp[ind][buy][cap] = max(0 + dp[ind + 1][0][cap],
                                          -prices[ind] + dp[ind + 1][1][cap]);
          }
      }
  }

  // * The result is stored in dp[0][0][2] which represents maximum profit after the final transaction.
  return dp[0][0][2];
}

// * TABULATION WITH SPACE OPTIMIZATION

int maxProfit(vector<int>& prices)
{
  int n = prices.size(); 
  // *Create two 2D arrays to store the profit information, one for the current state and one for the ahead state.
  vector<vector<int>> ahead(2, vector<int>(3, 0));
  vector<vector<int>> cur(2, vector<int>(3, 0));

  for (int ind = n - 1; ind >= 0; ind--) {
      for (int buy = 0; buy <= 1; buy++) {
          for (int cap = 1; cap <= 2; cap++) {
              if (buy)
                  cur[buy][cap] = max(0 + ahead[1][cap],
                                      prices[ind] + ahead[0][cap - 1]);
              else 
                  cur[buy][cap] = max(0 + ahead[0][cap], 
                                      -prices[ind] + ahead[1][cap]);
          }
      }
      ahead = cur;
  }
  return ahead[0][2];
}