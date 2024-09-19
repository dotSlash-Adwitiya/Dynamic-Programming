#include<bits/stdc++.h>
using namespace std;

/*
  * 1. Express everything in terms of indexes (changing states)
  * 2. Express ALL Possibilities
  * 3. Use a loop to iterate through all possibilities
  * 4. Take the minimum of all possibilities
  * 5. Write the base case.
*/

// * Recursive Approach: 


bool isPalindrome(int i, int j, string str){
  while(i < j){
      if(str[i] != str[j])
          return false;
      i++;
      j--;
  }
  return true;
}

int f(int i, string &str, int n){
  if(i == n) return 0;

  int minCost = INT_MAX, cost = 0;
  for(int j = i; j < n; j++){
      if(isPalindrome(i, j, str)){
          cost = 1 + f(j+1, str, n);
          minCost = min(minCost, cost);
      }
  }
  return minCost;
}

int palindromePartitioning(string str)
{
  int n = str.size();
  return f(0, str, n) - 1;
}

// * Memoization optimization - 1D DP
int f(int i, string &str, int n, vector<int> &dp){
  if(i == n) return 0;
  if(dp[i] != -1) return dp[i];
  int minCost = INT_MAX, cost = 0;
  for(int j = i; j < n; j++){
      if(isPalindrome(i, j, str)){
          cost = 1 + f(j+1, str, n, dp);
          minCost = min(minCost, cost);
      }
  }
  return dp[i] = minCost;
}

int palindromePartitioning(string str)
{
  int n = str.size();
  vector<int> dp(n, -1);
  return f(0, str, n, dp) - 1;
}
