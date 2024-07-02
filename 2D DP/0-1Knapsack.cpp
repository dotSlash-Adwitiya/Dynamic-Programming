#include <bits/stdc++.h> 
using namespace std;

// * Recursive Solution
int f(int idx, int weight, vector<int> wt, vector<int> value) {
	if(idx == 0) {
		if(wt[idx] <= weight)
			return value[idx];
		return 0;
	}

	int take = 0, notTake = 0;

	if(wt[idx] <= weight)
		take = value[idx] + f(idx - 1, weight - wt[idx], wt, value);
	
	notTake = f(idx - 1, weight, wt, value);

	return max(take, notTake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return f(n - 1, maxWeight, weight, value);
}


// * Memoization Solution
int f(int idx, int weight, vector<int> wt, vector<int> value, vector<vector<int>> &dp) {
	if(idx == 0) {
		if(wt[idx] <= weight)
			return value[idx];
		return 0;
	}
	
	if(dp[idx][weight] != -1)
		return dp[idx][weight];

	int take = -1e9, notTake = -1e9;

	if(wt[idx] <= weight)
		take = value[idx] + f(idx - 1, weight - wt[idx], wt, value, dp);
	
	notTake = f(idx - 1, weight, wt, value, dp);

	return dp[idx][weight] = max(take, notTake);
}


//  *Tabulation Solution
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));
	
	for(int W = weight[0]; W <= maxWeight; W++)
		dp[0][W] = value[0];

  // * 1. Changing States: Idx and weight
	for(int i = 1; i < n; i++) {
		for(int W = 0; W <= maxWeight; W++) {
			// * Copy the recurrence as it is.
			int take = -1e9, notTake = 0;
			if(weight[i] <= W)
				take = value[i] + dp[i - 1][W - weight[i]];
			notTake = 0 + dp[i - 1][W];
			dp[i][W] = max(take, notTake);
		}
	}
	return dp[n-1][maxWeight];
}

// * SPACE OPTIMISED Solution, because we only need prevRow (idx - 1);
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));
	vector<int> prev(maxWeight+1, 0), curr(maxWeight+1, 0);

	for(int W = weight[0]; W <= maxWeight; W++)
		prev[W] = value[0];

	for(int i = 1; i < n; i++) {
		for(int W = 0; W <= maxWeight; W++) {
			
			int take = -1e9, notTake = 0;
			if(weight[i] <= W)
				take = value[i] + prev[W - weight[i]];
			notTake = 0 + prev[W];
			curr[W] = max(take, notTake);
		}
		prev = curr;
	}


	return prev[maxWeight];
}