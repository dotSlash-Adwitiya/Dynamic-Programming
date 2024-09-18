
#include<bits/stdc++.h>
using namespace std;

#define ll long long

int mod = 1000000007;

ll f(int i, int j, bool isTrue, string & exp) {
  if(i > j) return 0;

  if(i == j) {
      if(isTrue) return exp[i] == 'T';
      else return exp[i] == 'F';
  }

  ll ways = 0;
  for(int idx = i+1; idx <= j - 1; idx += 2) {
      
      ll leftTrue = f(i, idx - 1, 1, exp);
      ll leftFalse = f(i, idx - 1, 0, exp);
      ll rightTrue = f(idx + 1, j, 1, exp);
      ll rightFalse = f(idx + 1, j, 0, exp);

      if(exp[idx] == '&'){
          if(isTrue)  ways = (ways + (leftTrue * rightTrue) % mod) % mod;
          else ways = (ways + (leftTrue * rightFalse) % mod + (leftFalse * rightTrue) % mod 
                      + (leftFalse * rightFalse) % mod) % mod;
      }

      else if(exp[idx] == '|'){
          if(isTrue){
              ways = (ways + (leftTrue * rightTrue) % mod + (leftTrue * rightFalse) % mod +
                      (leftFalse * rightTrue) % mod) % mod;
          }
          else ways = (ways + (leftFalse * rightFalse) % mod) % mod;
      }
      
      else {
          if(isTrue) 
              ways = (ways + (leftTrue * rightFalse) % mod + (leftFalse * rightTrue) % mod) % mod;
          else 
              ways = (ways + (leftTrue * rightTrue) % mod + (leftFalse * rightFalse) % mod) % mod;
      }
  }

  return ways;
}

int evaluateExp(string & exp) {
  return f(0, exp.size() - 1, 1, exp);
}

// * Memoization Optimization - 3D DP (N*N*2)

ll f(int i, int j, bool isTrue, string & exp, 
  vector<vector<vector<ll>>> 
      &dp) {
  if(i > j) return 0;

  if(i == j) {
      if(isTrue) return exp[i] == 'T';
      else return exp[i] == 'F';
  }

  if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

  ll ways = 0;
  for(int idx = i+1; idx <= j - 1; idx += 2) {
      
      ll leftTrue = f(i, idx - 1, 1, exp, dp);
      ll leftFalse = f(i, idx - 1, 0, exp, dp);
      ll rightTrue = f(idx + 1, j, 1, exp, dp);
      ll rightFalse = f(idx + 1, j, 0, exp, dp);

      if(exp[idx] == '&'){
          if(isTrue)  ways = (ways + (leftTrue * rightTrue) % mod) % mod;
          else ways = (ways + (leftTrue * rightFalse) % mod + (leftFalse * rightTrue) % mod 
                      + (leftFalse * rightFalse) % mod) % mod;
      }

      else if(exp[idx] == '|'){
          if(isTrue){
              ways = (ways + (leftTrue * rightTrue) % mod + (leftTrue * rightFalse) % mod +
                      (leftFalse * rightTrue) % mod) % mod;
          }
          else ways = (ways + (leftFalse * rightFalse) % mod) % mod;
      }
      
      else {
          if(isTrue) 
              ways = (ways + (leftTrue * rightFalse) % mod + (leftFalse * rightTrue) % mod) % mod;
          else 
              ways = (ways + (leftTrue * rightTrue) % mod + (leftFalse * rightFalse) % mod) % mod;
      }
  }

  return dp[i][j][isTrue] = ways;
}

int evaluateExp(string & exp) {
  int n = exp.size();
  vector<vector<vector<ll>>> 
      dp(n, vector<vector<ll>> (n, vector<ll> (2, -1)));
  return f(0, exp.size() - 1, 1, exp, dp);
}
