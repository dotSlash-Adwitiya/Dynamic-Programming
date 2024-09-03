#include<bits/stdc++.h>
using namespace std;

// * Recursive Solution using LCS Approach
int f(string& str1,string& str2,int i,int j){
  if(i < 0 or j < 0) 
      return 0;
  
  if(str1[i] == str2[j]) 
      return 1 + f(str1,str2,i-1,j-1);
  else
      return max(f(str1, str2, i-1, j), f(str1, str2, i, j-1));
}
int lcs(string& str1, string& str2){
  return f(str1,str2,str1.length()-1,str2.length()-1);
}

int minOperations(string str1, string str2) { 
  return str1.length()+str2.length()-2*lcs(str1, str2);
}  

// * Memoization Optimization
int f(string& str1,string& str2,int i,int j,vector<vector<int>>&dp){
  if(i<0 or j<0) return 0;
  if(dp[i][j]!=-1) return dp[i][j];
  if(str1[i]==str2[j]) return dp[i][j]=1+f(str1,str2,i-1,j-1,dp);
  else
      return dp[i][j]=max(f(str1,str2,i-1,j,dp), f(str1,str2,i,j-1,dp));
}
int lcs(string& str1, string& str2){
  vector<vector<int>> dp(str1.length(),vector<int>(str2.length(),-1));
  return f(str1,str2,str1.length()-1,str2.length()-1,dp);
}

int minOperations(string str1, string str2) { 
  return str1.length()+str2.length()-2*lcs(str1, str2);
}  

// * Tabulation Approach
int lcs(string& str1, string& str2) {
  int n = str1.length();
  int m = str2.length();
  
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  
  for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
          if (str1[i - 1] == str2[j - 1]) 
              dp[i][j] = 1 + dp[i - 1][j - 1];
          else
              dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
  }
  
  return dp[n][m];
}

int minOperations(string str1, string str2) {
  return str1.length() + str2.length() - 2 * lcs(str1, str2);
}