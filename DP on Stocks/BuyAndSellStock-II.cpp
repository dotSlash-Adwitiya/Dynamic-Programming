#include <bits/stdc++.h>
using namespace std;

// * Recursive Solution
// * T.C: O(2ⁿ)
long f(long idx, bool buy, long *values, int n){
    
    // * If we reach the end, 2 cases: Still stock is to be sold
    // * Nothing was bought (No stock purchased)
    // * In either  case, if we're reaching the end, that means, we didn't find any day
    // * Where it would profit us to sell it. So, simply return 0;
    if(idx == n) return 0;
    
    long profit = 0;
    if(buy){
        profit = max((-values[idx] + f(idx+1, 0, values, n)),
                     0 + f(idx+1, 1, values, n));
    } else{
        profit = max((values[idx] + f(idx+1, 1, values, n)),
                     0 + f(idx+1, 0, values, n));
    }
    return profit;
}

long getMaximumProfit(long *values, int n)
{
    return f(0, 1, values, n);
}

// * Memoization Optimization
// * T.C: O(N), S.C: O(N)
long f(long idx, bool buy, long *values, int n,  vector<vector<long>> &dp){
  
  // * BASE CASE
  if(idx == n) return 0;
  
  if(dp[idx][buy] != -1) return dp[idx][buy];

  // * Buy Stock or don't BUY it.
  if(buy)
      dp[idx][buy] = max((-values[idx] + f(idx+1, 0, values, n, dp)),
                    0 + f(idx+1, 1, values, n, dp));
  
  // * Sell Stock or Don't SELL it.
  else
      dp[idx][buy] = max((values[idx] + f(idx+1, 1, values, n, dp)),
                    0 + f(idx+1, 0, values, n, dp));
  
  return dp[idx][buy];
}

long getMaximumProfit(long *values, int n)
{   
  // * Buy part will only remain either 1 or 0
  vector<vector<long>> dp(n+1, vector<long>(2, -1));

  return f(0, 1, values, n, dp);
}

// * Tabulation Approach
// * T.C: O(N), S.C: O(N)
long getMaximumProfit(long *values, int n)
{   
  // * Buy part will only remain either 1 or 0
  vector<vector<long>> dp(n+1, vector<long>(2, 0));

  dp[n][0] = dp[n][1] = 0;

  for(int idx = n-1; idx >= 0; idx--){
      for(int buy = 0; buy <= 1; buy++) {
          if(buy)
              dp[idx][buy] = max((-values[idx] + dp[idx+1][0]), 0 + dp[idx+1][1]);
          
          // * Sell Stock or Don't SELL it.
          else
              dp[idx][buy] = max((values[idx] + dp[idx+1][1]), 0 + dp[idx+1][0]);
      }
  }

  return dp[0][1];
}

// * Tabulation WITH SPACE OPTIMIZATION
// * O(N) T.C, S.C: O(1) 
long getMaximumProfit(long *values, int n)
{   
    vector<long> ahead(2, 0), curr(2, 0);

    // * Because, we're only worried about
    // * idx+1's VALUE, so we store ONLY that value in arr[] of size 2
    // dp[n][0] = dp[n][1] = 0;

    for(int idx = n-1; idx >= 0; idx--){
        for(int buy = 0; buy <= 1; buy++) {
            if(buy)
                curr[buy] = max((-values[idx] + ahead[0]), 0 + ahead[1]);
            
            // * Sell Stock or Don't SELL it.
            else
                curr[buy] = max((values[idx] + ahead[1]), 0 + ahead[0]);
        }
        ahead = curr;
    }

    return ahead[1];
}