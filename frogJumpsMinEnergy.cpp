#include<bits/stdc++.h>
using namespace std;

// * Recursive Approach
// * T.C : Exponential - O(2^n) and S.C : O(N) - Recursive Call Stack space
int helper(int idx, vector<int> &heights) {
  if(idx == 0)
    return 0;

  int left = helper(idx-1, heights) + abs(heights[idx] - heights[idx-1]);
  int right = INT_MAX;
  if(idx > 1)
    right = helper(idx-2, heights) + abs(heights[idx] - heights[idx-2]);

  return min(left,right);
}

int frogJumps(int n, vector<int> heights) {
  return helper(n-1, heights);
}


// * MEMOIZATION -> Saving the Recomputation Time using DP Array
int helper(vector<int> &heights, int i, vector<int> & dp) {
    if(i <= 0)
        return 0;

    if(dp[i] != -1)
        return dp[i];

    int left =  helper(heights, i-1, dp) + abs(heights[i] - heights[i-1]);
    
    int right = INT_MAX;
    if(i > 1)
        right = helper(heights, i-2, dp) + abs(heights[i] - heights[i-2]);
    return dp[i] = min(left, right);
}

int frogJumpMemo(int n, vector<int> &heights)
{
    vector<int> dp(n+1, -1);
    return helper(heights, n-1, dp);
}

// * TABULATION -> BOTTOM UP Approach
int frogJumpsTab(int n, vector<int> &heights) {
    vector<int> dp(n+1, -1);
    dp[0] = 0;

    // * Iterative Solution
    for(int i = 1; i < n; i++) {
      int firstStep = dp[i-1] + abs(heights[i] - heights[i-1]);
      int secondStep = INT_MAX;
      if(i > 1) 
        secondStep = dp[i-2] + abs(heights[i] - heights[i-2]);
      dp[i] = min(firstStep,secondStep);
    }
  return dp[n-1];
}

// * Space Optimization with TABULATION
int frogJumpsTabSpaceOptimized(int n, vector<int> heights) {
  int prevEle = 0, prevEle2 = 0;

    for(int i = 1; i < n; i++) {
      int firstStep = prevEle + abs(heights[i] - heights[i-1]);
      int secondStep = INT_MAX;
      if(i > 1) 
        secondStep = prevEle2 + abs(heights[i] - heights[i-2]);
      int currEle = min(firstStep,secondStep);

      prevEle2 = prevEle;
      prevEle = currEle;
    }
    // * In every turn we need to find the most
  return prevEle; 
}

int main()
{

  cout << "Min Energy required is: " << frogJumpsTabSpaceOptimized(6,{30,10,60,10,60,50}) << endl;
  return 0;
}