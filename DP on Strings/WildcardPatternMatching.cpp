#include<bits/stdc++.h>
using namespace std;

// * Recurisive Approach
// * T.C: O(Exponential)
// * S.C: O(N+M)
bool f(int i, int j, string wild, string text) {
  if(i < 0 and j < 0)
    return true;

  if(i < 0 and j >= 0)
    return false;

  // * If the text string EXHAUSTS, then we need to loop over PATTERN String,
  // * and check if there exists anything other than '*'
  if(j < 0 and i >= 0){
    for(int k = 0; k <= i; k++)
        if(wild[k] != '*')
          return false;
    return true;
  }

  if(wild[i] == text[j] || (wild[i] == '?'))
    return f(i-1, j-1, wild, text);


  if(wild[i] == '*')
        return f(i-1, j, wild, text) or f(i, j-1, wild, text);
  
  return false;
}

bool wildcardMatching(string pattern, string text)
{
  int n = pattern.size(), m = text.size();
  return f(n-1, m-1, pattern, text);
}


// * Memoization
bool f(int i, int j, string wild, string text, vector<vector<int>> &dp) {
   if(i < 0 and j < 0)
      return true;

   if(i < 0 and j >= 0)
      return false;

   // * If the text string EXHAUSTS, then we need to loop over PATTERN String,
   // * and check if there exists anything other than '*'
   if(j < 0 and i >= 0){
      for(int k = 0; k <= i; k++)
         if(wild[k] != '*')
            return false;
      return true;
   }
   if(dp[i][j] != -1)
      return dp[i][j];

   if(wild[i] == text[j] || (wild[i] == '?'))
      return dp[i][j] = f(i-1, j-1, wild, text, dp);


   if(wild[i] == '*')
         return dp[i][j] = f(i-1, j, wild, text, dp) or f(i, j-1, wild, text, dp);
   
   return false;
}

bool wildcardMatching(string pattern, string text)
{
   int n = pattern.size(), m = text.size();
   vector<vector<int>> dp(n, vector<int> (m, -1));
   return f(n-1, m-1, pattern, text, dp);
}

// * Memoization on 1-based indexing
bool f(int i, int j, string wild, string text, vector<vector<int>> &dp) {
  if(i == 0 and j == 0)
    return true;

  if(i == 0 and j > 0)
    return false;

  // * If the text string EXHAUSTS, then we need to loop over PATTERN String,
  // * and check if there exists anything other than '*'
  if(j == 0 and i > 0){
    for(int k = 1; k <= i; k++)
        if(wild[k-1] != '*')
          return false;
    return true;
  }
  if(dp[i][j] != -1)
    return dp[i][j];

  if(wild[i-1] == text[j-1] || (wild[i-1] == '?'))
    return dp[i][j] = f(i-1, j-1, wild, text, dp);


  if(wild[i-1] == '*')
        return dp[i][j] = f(i-1, j, wild, text, dp) or f(i, j-1, wild, text, dp);
  
  return false;
}

bool wildcardMatching(string pattern, string text)
{
  int n = pattern.size(), m = text.size();
  vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
  return f(n, m, pattern, text, dp);
}

// * TABULATION Approach
bool isAllStars(string &S1, int i) {
  // S1 is taken in 1-based indexing
  for (int j = 1; j <= i; j++) {
      if (S1[j - 1] != '*')
          return false;
  }
  return true;
}

// Function to perform wildcard pattern matching between S1 and S2
bool wildcardMatching(string &S1, string &S2) {
  int n = S1.size();
  int m = S2.size();

  vector<vector<bool>> dp(n + 1, vector<bool>(m, false));

  dp[0][0] = true;
  for (int j = 1; j <= m; j++) dp[0][j] = false;
  
  for (int i = 1; i <= n; i++) dp[i][0] = isAllStars(S1, i);

  for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
          if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?') 
              dp[i][j] = dp[i - 1][j - 1];
          else {
              if (S1[i - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
              else
                dp[i][j] = false;
          }
      }
  }

  return dp[n][m];

}

// * Practice - 1
bool f(int i, int j, string wild, string text) {
  if(i < 0 and j < 0)
    return true;

  if(i < 0 and j >= 0)
    return false;

  // * If the text string EXHAUSTS, then we need to loop over PATTERN String,
  // * and check if there exists anything other than '*'
  if(j < 0 and i >= 0){
    for(int k = 0; k <= i; k++)
        if(wild[k] != '*')
          return false;
    return true;
  }

  if(wild[i] == text[j] || (wild[i] == '?'))
    return f(i-1, j-1, wild, text);


  if(wild[i] == '*')
        return f(i-1, j, wild, text) or f(i, j-1, wild, text);
  
  return false;
}

bool wildcardMatching(string pattern, string text)
{
  int n = pattern.size(), m = text.size();
  return f(n-1, m-1, pattern, text);
}

// * Memoization
bool f(int i, int j, string wild, string text, vector<vector<int>> &dp) {
   if(i < 0 and j < 0)
      return true;

   if(i < 0 and j >= 0) return false;

   if(j < 0 and i >= 0){
      for(int k = 0; k <= i; k++)
         if(wild[k] != '*')
            return false;
      return true;
   }
   if(dp[i][j] != -1)
      return dp[i][j];

   if(wild[i] == text[j] || (wild[i] == '?'))
      return dp[i][j] = f(i-1, j-1, wild, text, dp);


   if(wild[i] == '*')
         return dp[i][j] = f(i-1, j, wild, text, dp) or f(i, j-1, wild, text, dp);
   
   return false;
}

bool wildcardMatching(string pattern, string text)
{
   int n = pattern.size(), m = text.size();
   vector<vector<int>> dp(n, vector<int> (m, -1));
   return f(n-1, m-1, pattern, text, dp);
}

// * 1-based indexing
bool f(int i, int j, string wild, string text, vector<vector<int>> &dp) {
  if(i == 0 and j == 0)
    return true;

  if(i == 0 and j > 0)
    return false;

  if(j == 0 and i > 0){
    for(int k = 1; k <= i; k++)
        if(wild[k-1] != '*')
          return false;
    return true;
  }
  if(dp[i][j] != -1)
    return dp[i][j];

  if(wild[i-1] == text[j-1] || (wild[i-1] == '?'))
    return dp[i][j] = f(i-1, j-1, wild, text, dp);


  if(wild[i-1] == '*')
        return dp[i][j] = f(i-1, j, wild, text, dp) or f(i, j-1, wild, text, dp);
  
  return false;
}

bool wildcardMatching(string pattern, string text)
{
  int n = pattern.size(), m = text.size();
  vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
  return f(n, m, pattern, text, dp);
}

// * TABULATION Approach
bool isAllStars(string &S1, int i) {
  for (int j = 1; j <= i; j++) {
      if (S1[j - 1] != '*')
          return false;
  }
  return true;
}

bool wildcardMatching(string &S1, string &S2) {
  int n = S1.size();
  int m = S2.size();

  vector<vector<bool>> dp(n + 1, vector<bool>(m, false));

  dp[0][0] = true;
  for (int j = 1; j <= m; j++) dp[0][j] = false;
  
  for (int i = 1; i <= n; i++) dp[i][0] = isAllStars(S1, i);

  for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
          if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?') 
              dp[i][j] = dp[i - 1][j - 1];
          else {
              if (S1[i - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
              else
                dp[i][j] = false;
          }
      }
  }

  return dp[n][m];

}