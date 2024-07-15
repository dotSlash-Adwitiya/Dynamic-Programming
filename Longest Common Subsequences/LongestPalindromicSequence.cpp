#include<bits/stdc++.h>
using namespace std;


// * Approach - 1
// * Memoization Approach :
int longestPalindromicSubseqUtil(string &s, int start, int end, vector<vector<int>> &dp) {
    if (start > end) {
        return 0;
    }
    if (start == end) {
        return 1;
    }
    if (dp[start][end] != -1) {
        return dp[start][end];
    }
    if (s[start] == s[end]) {
        dp[start][end] = 2 + longestPalindromicSubseqUtil(s, start + 1, end - 1, dp);
    } else {
        dp[start][end] = max(longestPalindromicSubseqUtil(s, start + 1, end, dp),
                            longestPalindromicSubseqUtil(s, start, end - 1, dp));
    }
    return dp[start][end];
}
int longestPalindromeSubsequence(string s)
{
  int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return longestPalindromicSubseqUtil(s, 0, n - 1, dp);
}

// * Approach - 2
// * Converted the problem to LCS by reversing the given string
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