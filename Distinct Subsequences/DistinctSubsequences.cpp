#include<bits/stdc++.h>
using namespace std;


// * Recursive Approach
// * T.C: Exponential
int f(int i, int j, string s1, string s2) {
  if(j < 0) return 1;
  if(i < 0) return 0;

  int pick = 0, notPick = 0;

  // * Pick if characters MATCH
  // * 1st Call: Pick directly
  // * 2nd Call: Pick the next character in s1(s[i]), matching with s2's charcter (s[j])
  if(s1[i] == s2[j])
      pick = f(i-1, j-1, s1, s2) + f(i-1, j, s1, s2);
  else
      notPick = f(i-1, j, s1, s2);

  return pick + notPick;
}

int numDistinct(string s, string t) {
  int n = s.size(), m = t.size();
  return f(n-1, m-1, s, t);
}

// * Optimization with MEMOIZATION
int f(int i, int j, string s1, string s2, vector<vector<int>> &dp) {
  if(j < 0) return 1;
  if(i < 0) return 0;

  if(dp[i][j] != -1)
      return dp[i][j];

  int pick = 0, notPick = 0;

  if(s1[i] == s2[j])
      pick = f(i-1, j-1, s1, s2, dp) + f(i-1, j, s1, s2, dp);
  else
      notPick = f(i-1, j, s1, s2, dp);

  return dp[i][j] = pick + notPick;
}

int numDistinct(string s, string t) {
  int n = s.size(), m = t.size();
  vector<vector<int>> dp(n, vector<int> (m, -1));
  return f(n-1, m-1, s, t, dp);
}

// * Optimization with TABULATION
int numDistinct(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<double>> dp(n+1, vector<double> (m+1, 0));

    for(int i = 0; i <= n; i++) dp[i][0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][m];
}