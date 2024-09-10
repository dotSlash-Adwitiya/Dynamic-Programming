#include<bits/stdc++.h>
using namespace std;

long long mod = 1000000007;

// * Recursive Approach, T.C: O(3ⁿ)
long long countWays(int n) {
  if(n < 0) return 0;
  if(n == 0) return 1;

  return (countWays(n-1) + countWays(n-2) + countWays(n-3)) % mod; 
}

// * Memoization 1D DP
// * T.C: O(N), S.C: O(N) + O(N) (Recursive STACK_SPACE)
long long f(int n, vector<int> &dp){
  if(n < 0) return 0;
  if(n == 0) return 1;
  if(dp[n] != -1) return dp[n];
  
  return dp[n] = (f(n-1, dp) + f(n-2, dp) + f(n-3, dp)) % mod;
}
long long countWays(int n) {
  vector<int> dp(n + 1, -1);
  return f(n, dp);
}

// * TABULATION
// * T.C: O(N), S.C: O(N)
long long countWays(int n) {
  vector<long long> dp(n+1, 0);
  
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  
  for(int i = 3; i <= n; i++) 
      dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % mod;
  
  return dp[n];
}

// * Simple 3 Variables: T.C: O(N), S.C: O(1)
long long countWays(int n) {      
  if(n <= 1) return 1;
  long long first = 1, sec = 1, third = 2;
  
  for(int i = 3; i <= n; i++) {
      long long temp = (first + sec + third) % mod;
      first = sec;
      sec = third;
      third = temp;
  }
  
  return third;
}