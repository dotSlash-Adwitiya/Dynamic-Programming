#include<bits/stdc++.h>
using namespace std;

/*
  * f(i) signify -> from f(i) to f(n-1). Give me the max Sum
*/

// * Recursive Solution
int f(int idx, int k, vector<int> &arr){

  if(idx == arr.size()) return 0;

  int len = 0, maxAns = INT_MIN, maxi = INT_MIN;
  int n = arr.size();
  for(int j = idx; j < min(idx + k, n); j++){
      len++;
      maxi = max(maxi, arr[j]);
      int sum = (len * maxi) + f(j + 1, k, arr);
      maxAns = max(maxAns, sum); 
  }

  return maxAns;

}

int maximumSubarray(vector<int> &arr, int k){
  // int n = arr.size();
  return f(0, k, arr);
}

// * MEMOIZATION OPTIMIZATION - 1D DP
int f(int idx, int k, vector<int> &arr, vector<int> &dp){

  if(idx == arr.size()) return 0;
  if(dp[idx] != -1) return dp[idx];

  int len = 0, maxAns = INT_MIN, maxi = INT_MIN;
  int n = arr.size();
  for(int j = idx; j < min(idx + k, n); j++){
      len++;
      maxi = max(maxi, arr[j]);
      int sum = (len * maxi) + f(j + 1, k, arr, dp);
      maxAns = max(maxAns, sum); 
  }

  return dp[idx] = maxAns;

}

int maximumSubarray(vector<int> &arr, int k){
  int n = arr.size();
  vector<int> dp(n, -1);
  return f(0, k, arr, dp);
}

// * TABULATION SOLUTION
int maximumSubarray(vector<int> &arr, int k){
  int n = arr.size();
  vector<int> dp(n+1, 0);
  dp[n] = 0;
  for(int idx = n-1; idx >= 0; idx--){
        int len = 0, maxAns = INT_MIN, maxi = INT_MIN;
      int n = arr.size();
      for(int j = idx; j < min(idx + k, n); j++){
          len++;
          maxi = max(maxi, arr[j]);
          int sum = (len * maxi) + dp[j + 1];
          maxAns = max(maxAns, sum); 
      }

      dp[idx] = maxAns;
  }

  return dp[0];
}