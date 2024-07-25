#include<bits/stdc++.h>
using namespace std;

// * Recursive Approach
// * T.C: O(3ⁿ)
// * S.C: O(N+M)
int f(int i, int j, string s1, string s2) {
    if(i < 0) return j+1;
    if(j < 0) return i+1;

    int insert = 1e9, del = 1e9, replace = 1e9;

    if(s1[i] == s2[j])
        return 0 + f(i-1, j-1, s1, s2);

    else {
        insert = 1 + f(i, j-1, s1, s2);
        del = 1 + f(i-1, j, s1, s2);
        replace = 1 + f(i-1, j-1, s1, s2); 
    }
    return min(insert, min(del, replace));
}

int editDistance(string str1, string str2)
{
    int n = str1.size(), m = str2.size();
    return f(n-1, m-1, str1, str2);
}

// * Memoization
// * T.C: O()
int f(int i, int j, string s1, string s2, vector<vector<int>> &dp) {
    if(i < 0) return j+1;
    if(j < 0) return i+1;

    if(dp[i][j] != -1)
        return dp[i][j];

    int insert = 1e9, del = 1e9, replace = 1e9;

    if(s1[i] == s2[j])
        return dp[i][j] = 0 + f(i-1, j-1, s1, s2, dp);

    else {
        insert = 1 + f(i, j-1, s1, s2, dp);
        del = 1 + f(i-1, j, s1, s2, dp);
        replace = 1 + f(i-1, j-1, s1, s2, dp); 
    }
    return dp[i][j] = min(insert, min(del, replace));
}

int editDistance(string str1, string str2)
{
    int n = str1.size(), m = str2.size();
    vector<vector<int>> dp(n, vector<int> (m, -1));
    return f(n-1, m-1, str1, str2, dp);
}

// * Memoization AFTER SHIFTING Indices (Starting from nth and mth INDEX)
int f(int i, int j, string s1, string s2, vector<vector<int>> &dp) {
    
    // * When I am at 0th index, I would've already accessed it at 1st index by doing
    // * 1-0 = 0, and at 0, I would be accessing 0-1 = -1, so we use this as the BASE_CASE
    if(i == 0) return j;
    if(j == 0) return i;

    if(dp[i][j] != -1)
        return dp[i][j];

    int insert = 1e9, del = 1e9, replace = 1e9;

    // * Access elements by subtracting 1.
    if(s1[i-1] == s2[j-1])
        return dp[i][j] = 0 + f(i-1, j-1, s1, s2, dp);

    else {
        insert = 1 + f(i, j-1, s1, s2, dp);
        del = 1 + f(i-1, j, s1, s2, dp);
        replace = 1 + f(i-1, j-1, s1, s2, dp); 
    }
    return dp[i][j] = min(insert, min(del, replace));
}

int editDistance(string str1, string str2)
{
    int n = str1.size(), m = str2.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    return f(n, m, str1, str2, dp);
}

// * TABULATION
int editDistance(string s1, string s2)
{
  int n = s1.size(), m = s2.size();
  vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
  
  // * BASE_CASE
  for(int i = 0; i <= n; i++)  dp[i][0] = i;
  for(int j = 0; j <= m; j++)  dp[0][j] = j;

  for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
          if(s1[i-1] == s2[j-1])
              dp[i][j] = 0 + dp[i-1][j-1];

          else
            dp[i][j] = min(1 + dp[i][j-1], 
              min(1 + dp[i-1][j], 1 + dp[i-1][j-1])); 
      }
  }
  return dp[n][m];
}