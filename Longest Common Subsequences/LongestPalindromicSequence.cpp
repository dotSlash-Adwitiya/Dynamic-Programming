#include<bits/stdc++.h>
using namespace std;


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
int longestPalindromeSubsequence(string s)
{
	string t = s;
	// * Since the palindrome will be read SAME from either END
	// * We can convert this problem into -> LCS
	reverse(t.begin(), t.end());
   	return lcs(s, t);
}