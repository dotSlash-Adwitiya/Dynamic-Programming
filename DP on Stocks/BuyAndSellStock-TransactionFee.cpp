#include<bits/stdc++.h>
using namespace std;

// * Recursive code
int f(int idx, int buy, vector<int> &prices, int fee) {
  	if(idx >= prices.size()) return 0;

	int profit = 0;

	if(buy)
			profit = max(-prices[idx] + f(idx+1, 0, prices, fee),
					0 + f(idx+1, 1, prices, fee));
	else
			profit = max(prices[idx] + f(idx+1, 1, prices, fee) - fee,
						0 + f(idx+1, 0, prices, fee));
	return profit;
}


int maximumProfit(vector<int> &prices, int n, int fee)
{
  	return f(0, 1, prices, fee);
}

// * Optimization using memoization
int f(int idx, int buy, vector<int> &prices, vector<vector<int>> dp, int fee) {
  if(idx >= prices.size()) return 0;

  if(dp[idx][buy] != -1)
      return dp[idx][buy];

  if(buy)
          dp[idx][buy] = max(-prices[idx] + f(idx+1, 0, prices, dp, fee),
                  0 + f(idx+1, 1, prices, dp, fee));
  else
          dp[idx][buy] = max(prices[idx] + f(idx+1, 1, prices, dp, fee) - fee,
                      0 + f(idx+1, 0, prices, dp, fee));
  return dp[idx][buy];
}


int maximumProfit(vector<int> &prices, int n, int fee)
{
  	vector<vector<int>> dp(n, vector<int>(2, -1));
  	return f(0, 1, prices, dp, fee);
}

// * TABULATION

int maximumProfit(vector<int> &prices, int n, int fee)
{
  	vector<vector<int>> dp(n+2, vector<int>(2, 0));

	for(int idx = n-1; idx >= 0; idx--) {
		for(int buy = 0; buy < 2; buy++) {
				if(buy)
					dp[idx][buy] = max(-prices[idx] + dp[idx+1][0],
							0 + dp[idx+1][1]);
			else
				dp[idx][buy] = max(prices[idx] + dp[idx+1][1] - fee, 
						0 + dp[idx+1][0]);
		}
	}
	return dp[0][1];
}


// * TABULATION WITH SPACE OPTIMIZATION
int maximumProfit(vector<int> &prices, int n, int fee)
{
	vector<int> ahead(2, 0), curr(2, 0);

	for(int idx = n-1; idx >= 0; idx--) {
		for(int buy = 0; buy < 2; buy++) {
				
			ahead[1] = max(-prices[idx] + ahead[0],
					0 + ahead[1]);

			ahead[0] = max(prices[idx] + ahead[1] - fee, 
					0 + ahead[0]);
		}
	}
	return ahead[1];
}
