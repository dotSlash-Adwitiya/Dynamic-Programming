#include<bits/stdc++.h>
using namespace std;

// * Recursive code


// * Memoization
int f(int idx, int buy, vector<int> &prices, vector<vector<int>> dp) {
  if(idx >= prices.size()) return 0;

  if(dp[idx][buy] != -1)
      return dp[idx][buy];

  if(buy)
          dp[idx][buy] = max(-prices[idx] + f(idx+1, 0, prices, dp),
                  0 + f(idx+1, 1, prices, dp));
  else
          dp[idx][buy] = max(prices[idx] + f(idx+2, 1, prices, dp),
                      0 + f(idx+1, 0, prices, dp));
  return dp[idx][buy];
}

int stockProfit(vector<int> &prices){
  int n = prices.size();
  vector<vector<int>> dp(n, vector<int>(2, -1));
  return f(0, 1, prices, dp);
}

// * Tabulation
int stockProfit(vector<int> &prices){
  int n = prices.size();

  // * n+2, for accessing index at idx+2 when at the last element(day)
  vector<vector<int>> dp(n+2, vector<int>(2, 0));

  for(int idx = n-1; idx >= 0; idx--) {
      for(int buy = 0; buy < 2; buy++) {
            if(buy)
                  dp[idx][buy] = max(-prices[idx] + dp[idx+1][0],
                          0 + dp[idx+1][1]);
          else
              dp[idx][buy] = max(prices[idx] + dp[idx+2][1], 
                    0 + dp[idx+1][0]);
      }
  }
  return dp[0][1];
}

// * Tabulation with SPACE OPTIMIZATION
int stockProfit(vector<int> &prices){
  int n = prices.size();
  vector<int> ahead1(2, 0);
  vector<int> ahead2(2, 0);
  vector<int> curr(2, 0);

  for(int idx = n-1; idx >= 0; idx--) {
            
      curr[1] = max((-prices[idx] + ahead1[0]), 0 + ahead1[1]);
              
      curr[0] = max((prices[idx] + ahead2[1]), 0 + ahead1[0]);

      ahead2 = ahead1;
      ahead1 = curr;
  }
  return curr[1];
}