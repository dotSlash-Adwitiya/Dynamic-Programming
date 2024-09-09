#include<bits/stdc++.h>
using namespace std;

// * RECURSIVE Approach
int f(int left, int right, string str){
  if(left >= right)
      return 0;

  int removeLeft = 1e9, removeRight = 1e9, match = 1e9;

  if(str[left] == str[right])
      match = f(left + 1, right - 1, str);

  else {
      removeLeft = 1 + f(left + 1, right, str);
      removeRight = 1 + f(left, right - 1, str);
  }
  return min(match, min(removeLeft, removeRight));
  
}

bool isPalindrome(int k, string str) {
  int n = str.size();
  return (f(0, n-1, str) <= k);
}

// * MEMOIZATION Approach
int f(int left, int right, string str, vector<vector<int>> &dp){
  if(left >= right) return 0;

  int removeLeft = 1e9, removeRight = 1e9, match = 1e9;

  if(dp[left][right] != -1) return dp[left][right];

  if(str[left] == str[right]) 
    match = f(left + 1, right - 1, str, dp);

  else {
      removeLeft = 1 + f(left + 1, right, str, dp);
      removeRight = 1 + f(left, right - 1, str, dp);
  }
  return dp[left][right] = min(match, min(removeLeft, removeRight));
}

bool isPalindrome(int k, string str) {
  int n = str.size();
  vector<vector<int>> dp(n, vector<int> (n, -1));
  return (f(0, n-1, str, dp) <= k);
}
