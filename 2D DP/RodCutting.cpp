#include<bits/stdc++.h>
using namespace std;

// * Recursive solution
int f(int idx, int rodSize, vector<int> &price) {
	if(rodSize < 0)
		return 0;
	
  // * If we're at last index, since its size = 1, it can be taken - rodSize times.
	if(idx == 0) 
		return rodSize * price[idx];
	
	int pick = INT_MIN;
  // * PICK it ONLY if, after picking it, it doesn't exceed rod size.
	if(rodSize - (idx + 1) >= 0)
		pick = price[idx] + f(idx, rodSize-(idx+1), price);

	int notPick = f(idx-1, rodSize, price);

	return max(pick, notPick);
}

int cutRod(vector<int> &price, int n)
{
	return f(price.size() - 1, n, price);
}

// * Memoization Optimization
// * T.C: O(N * Rodsize)
// * S.C: O(N * Rodsize)
int f(int idx, int rodSize, vector<int> &price, vector<vector<int>> &dp) {
	if(rodSize < 0)
		return 0;
	
	if(idx == 0) {
		return rodSize * price[idx];
	}

	if(dp[idx][rodSize] != -1)
		return dp[idx][rodSize];

	int pick = INT_MIN;
	if(rodSize - (idx + 1) >= 0)
		pick = price[idx] + f(idx, rodSize-(idx+1), price, dp);

	int notPick = f(idx-1, rodSize, price, dp);

	return dp[idx][rodSize] = max(pick, notPick);
}

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(price.size(), vector<int> (n+1, -1));
	return f(price.size() - 1, n, price, dp);
}

// * ROD Cutting Problem - OPTIMIZED - Tabulation
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(price.size(), vector<int> (n+1, 0));

	// * BASE_CASE: When idx == 0, The remaining rodSize can vary.
	for(int rodSize = 0; rodSize <= n; rodSize++)
		dp[0][rodSize] = rodSize * price[0];

	for(int idx = 1; idx < price.size(); idx++) {
		for(int rodSize = 0; rodSize <= n; rodSize++) {
			int pick = INT_MIN;

			if(rodSize - (idx + 1) >= 0)
				pick = price[idx] + dp[idx][rodSize-(idx+1)];

			int notPick = dp[idx-1][rodSize];

			dp[idx][rodSize] = max(pick, notPick);
		}
	}

	return dp[price.size() - 1][n];
}

// * Practice - 1
int f(int idx, int rodSize, vector<int> &price) {
	if(rodSize < 0) return 0;
	
	if(idx == 0) return rodSize * price[idx];
	
	int pick = INT_MIN;
  // * PICK it ONLY if, after picking it, it doesn't exceed rod size.
	if(rodSize - (idx + 1) >= 0)
		pick = price[idx] + f(idx, rodSize-(idx+1), price);

	int notPick = f(idx-1, rodSize, price);

	return max(pick, notPick);
}

int cutRod(vector<int> &price, int n)
{
	return f(price.size() - 1, n, price);
}

// * Memoization Optimization
int f(int idx, int rodSize, vector<int> &price, vector<vector<int>> &dp) {
	if(rodSize < 0) return 0;
	
	if(idx == 0) return rodSize * price[idx];

	if(dp[idx][rodSize] != -1)
		return dp[idx][rodSize];

	int pick = INT_MIN;
	if(rodSize - (idx + 1) >= 0)
		pick = price[idx] + f(idx, rodSize-(idx+1), price, dp);

	int notPick = f(idx-1, rodSize, price, dp);

	return dp[idx][rodSize] = max(pick, notPick);
}

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(price.size(), vector<int> (n+1, -1));
	return f(price.size() - 1, n, price, dp);
}

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(price.size(), vector<int> (n+1, 0));

	// * BASE_CASE: When idx == 0, The remaining rodSize can vary.
	for(int rodSize = 0; rodSize <= n; rodSize++)
		dp[0][rodSize] = rodSize * price[0];

	for(int idx = 1; idx < price.size(); idx++) {
		for(int rodSize = 0; rodSize <= n; rodSize++) {
			int pick = INT_MIN;

			if(rodSize - (idx + 1) >= 0)
				pick = price[idx] + dp[idx][rodSize-(idx+1)];

			int notPick = dp[idx-1][rodSize];

			dp[idx][rodSize] = max(pick, notPick);
		}
	}

	return dp[price.size() - 1][n];
}