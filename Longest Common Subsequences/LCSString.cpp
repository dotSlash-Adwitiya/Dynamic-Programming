#include<bits/stdc++.h>
using namespace std;

// * Recursive Approach
int f(int i, int j, string s, string t) {
	if(i < 0 || j < 0)
		return 0;

	if(s[i] == t[j])
		return 1 + f(i-1, j-1, s, t);
	
	return max(f(i-1, j, s, t), f(i, j-1, s, t));
}

int lcs(string s, string t)
{
	int n = s.size();
	int m = t.size();
	return f(n-1, m-1, s, t);
}

// * Memoization Approach
// * T.C: O (N*M)
// * S.C: O (N*M) + O(N+M)
int f(int i, int j, string s, string t, vector<vector<int>> &dp) {
	if(i < 0 || j < 0)
		return 0;

	if(dp[i][j] != -1)
		return dp[i][j];

	if(s[i] == t[j])
		return dp[i][j] = 1 + f(i-1, j-1, s, t, dp);
	
	return dp[i][j] = max(f(i-1, j, s, t, dp), f(i, j-1, s, t, dp));
}

int lcs(string s, string t)
{
	int n = s.size();
	int m = t.size();
	vector<vector<int>> dp(n, vector<int> (m, -1));
 	return f(n-1, m-1, s, t, dp);
}
// * BOTTOM UP With recursion
// * SHIFTING INDEX Technique to easily convert this solution to tabulation
// * basically, we had -1 in the base case, so we now convert that -1 to 0, and 1 to 2 and so on
// * While doing this, we'll have to declare DP of size n+1 and m+1
// * ENSURE: While accessing the string, since its under the hood using 0 based indexing,
// * We need to subtract 1 from it while accessing the characters  
int fBottomUp(int i, int j, string s, string t, vector<vector<int>> &dp) {
	if(i < 0 || j < 0)
		return 0;

	if(dp[i][j] != -1)
		return dp[i][j];

	if(s[i-1] == t[j-1])
		return dp[i][j] = 1 + fBottomUp(i-1, j-1, s, t, dp);
	
	return dp[i][j] = max(fBottomUp(i-1, j, s, t, dp), fBottomUp(i, j-1, s, t, dp));
}

int lcs(string s, string t)
{
	int n = s.size();
	int m = t.size();
	vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
	return fBottomUp(n, m, s, t, dp);
}

// * TABULATION Approach
int lcs(string s, string t)
{
	int n = s.size();
	int m = t.size();
	vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
	
	// * BASE_CASE : For every 0th idx, the answer is 0
	// * Answer is 0 because, we're treating 0 as -1, and since from the recursive approach,
	// * It can be observed: that negative indices will have a 0.
	for(int i = 0; i <= n; i++)
		dp[i][0] = 0;
	for(int j = 0; j <= n; j++)
		dp[0][j] = 0;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(s[i-1] == t[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	return dp[n][m];
}