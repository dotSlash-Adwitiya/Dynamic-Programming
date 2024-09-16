#include<bits/stdc++.h>
using namespace std;

// * Recursive Approach
int f(int i, int j, vector<int>& A){
	if(i > j) return 0;

	int maxCoins = INT_MIN;
	for(int idx = i; idx <= j; idx++) {
		int coins = A[i-1] * A[idx] * A[j+1] 
					+ f(i, idx - 1, A) + f(idx + 1, j, A);
		maxCoins = max(maxCoins, coins);
	}
	return maxCoins;
}

int maxCoins(vector<int>& a)
{
	// * Extract before to ensure, n-1th idx is passed to the f()
	int n = a.size();
	a.push_back(1);
	a.insert(a.begin(), 1);
	return f(1, n, a);
}

// * Memoization Approach
int f(int i, int j, vector<int>& A, vector<vector<int>> &dp){
	if(i > j) return 0;

	if(dp[i][j] != -1) return dp[i][j];

	int maxCoins = INT_MIN;
	for(int idx = i; idx <= j; idx++) {
		int coins = A[i-1] * A[idx] * A[j+1] 
					+ f(i, idx - 1, A, dp) + f(idx + 1, j, A, dp);
		maxCoins = max(maxCoins, coins);
	}
	return dp[i][j] = maxCoins;
}

int maxCoins(vector<int>& a)
{
	// * Extract before to ensure, n-1th idx is passed to the f()
	int n = a.size();
	a.push_back(1);
	a.insert(a.begin(), 1);
	vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
	return f(1, n, a, dp);
}

// * Tabulation Approach
int maxCoins(vector<int>& A)
{
	// * Extract before to ensure, n-1th idx is passed to the f()
	int n = A.size();
	A.push_back(1);
	A.insert(A.begin(), 1);
	vector<vector<int>> dp(n+2, vector<int> (n+2, 0));

	for(int i = n; i >= 1; i--) {
		for(int j = 1; j <= n; j++){
				if(i > j) continue;
				int maxCoins = INT_MIN;
			for(int idx = i; idx <= j; idx++) {
				int coins = A[i-1] * A[idx] * A[j+1] 
							+ dp[i][idx - 1] + dp[idx + 1][j];
				maxCoins = max(maxCoins, coins);
			}
			dp[i][j] = maxCoins;
		}
	}

	return dp[1][n];
}