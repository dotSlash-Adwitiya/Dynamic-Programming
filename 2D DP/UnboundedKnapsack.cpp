#include<bits/stdc++.h>
using namespace std;

// * Recursively NAIVE Solution :
int fNaive(int idx, int target, vector<int> &profit, vector<int> &weight) {

  if(idx == 0){
      if(weight[idx] <= target)
          profit[idx] + fNaive(idx, target - weight[idx], profit, weight); // * Make recursive calls for this idx
      return 0;
  }
  
  int pick = 0;
  if(weight[idx] <= target)
      pick = profit[idx] + fNaive(idx, target - weight[idx], profit, weight);
  int notPick = fNaive(idx - 1, target, profit, weight);

  return max(pick , notPick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
  return fNaive(n-1, w, profit, weight);
}

// * Recursive Solution
int f(int idx, int target, vector<int> &profit, vector<int> &weight) {

  if(idx == 0){
      if(weight[0] <= target)
          return (target / weight[0]) * profit[0];
      return 0;
  }
  
  int pick = 0;
  if(weight[idx] <= target)
      pick = profit[idx] + f(idx, target - weight[idx], profit, weight);
  int notPick = f(idx - 1, target, profit, weight);

  return max(pick , notPick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
  return f(n-1, w, profit, weight);
}

// * Memoization Solution
int f(int idx, int target, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp) {
  if(idx == 0){
      if(weight[0] <= target)
          return (target / weight[0]) * profit[0];      
      return 0;
  }
  if(dp[idx][target] != -1)
      return dp[idx][target];
  
  int pick = 0;
  if(weight[idx] <= target)
      pick = profit[idx] + f(idx, target - weight[idx], profit, weight, dp);
  int notPick = f(idx - 1, target, profit, weight, dp);

  return dp[idx][target] = max(pick , notPick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
  vector<vector<int>> dp(n, vector<int>(w+1, -1));
  return f(n-1, w, profit, weight, dp);
}

//  * Tabulation Solution
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
  vector<vector<int>> dp(n, vector<int>(w+1, -1));

  //  * For weight[] = {2,4,6}, the range of weights can be in : 2,3,4,5,6
  // * The DP[][weight[idx]] created will be able to store: 0,1,2,3,4,5,6 
  // * From recursive base case, we get: For every 0th index, of weights,
  for(int target = 0; target <= w; target++)
      dp[0][target] = target / weight[0] * profit[0];

  for(int idx = 1; idx < n; idx++) {
      for(int target = 0; target <= w; target++){
          int pick = 0;
          if(weight[idx] <= target)
              pick = profit[idx] + dp[idx][target - weight[idx]];
          int notPick = dp[idx - 1][target];

          dp[idx][target] = max(pick , notPick);
      }
  }
  return dp[n-1][w];
}

// * Tabulation with Two 1-D Arrays :
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
  vector<int> curr(w+1, 0), prev(w+1, 0);

  for(int target = 0; target <= w; target++)
      prev[target] = target / weight[0] * profit[0];

  for(int idx = 1; idx < n; idx++) {
      for(int target = 0; target <= w; target++){
          int pick = 0;
          if(weight[idx] <= target)
              pick = profit[idx] + curr[target - weight[idx]];
          int notPick = prev[target];

          curr[target] = max(pick , notPick);
      }
      prev = curr;
  }
  return prev[w];
}

// * More space optimization
int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
    vector<int> cur(W + 1, 0); 

    // Base Condition
    for (int i = wt[0]; i <= W; i++) {
        cur[i] = (i / wt[0]) * val[0]; 
    }

    for (int ind = 1; ind < n; ind++) {
        for (int cap = 0; cap <= W; cap++) {
          int notTaken = cur[cap];

          int taken = INT_MIN;
          if (wt[ind] <= cap)
            taken = val[ind] + cur[cap - wt[ind]];

          cur[cap] = max(notTaken, taken);
        }
    }
    return cur[W];
}