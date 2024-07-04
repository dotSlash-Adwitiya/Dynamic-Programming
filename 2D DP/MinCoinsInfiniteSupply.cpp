#include <bits/stdc++.h> 
using namespace std;


int f(int idx, vector<int> &num, int target) {
    if(idx == 0) {
        if(target % num[0] == 0)
            return target/num[0];
        else return INT_MAX/10;
    }

    int notTake = f(idx - 1, num, target);
    int take = INT_MAX/10; //  *To avoid overflow
    if(num[idx] <= target) //  *Since there's an infinite supply, we make a call for same index repeatedly.
        take = 1 + f(idx, num, target - num[idx]);

    return min(take, notTake);
}

int minimumElements(vector<int> &num, int x)
{
   int ans = f(num.size() - 1, num, x);
   if(ans >= INT_MAX/10)
    return -1;
   else return ans; 
}

// * Memoization
// * T.C: O(N*Target)
// * S.C: O(N*Target) + O(N)
int fMemo(int idx, vector<int> &num, int target, vector<vector<int>> &dp) {
    if(idx == 0) {
        if(target % num[0] == 0)
            return target/num[0];
        else return INT_MAX/10;
    }
    if(dp[idx][target] != -1)
        return dp[idx][target];

    int notTake = fMemo(idx - 1, num, target, dp);
    int take = INT_MAX/10;
    if(num[idx] <= target)
        take = 1 + fMemo(idx, num, target - num[idx], dp);

    return dp[idx][target] = min(take, notTake);
}

int minimumElements(vector<int> &num, int x)
{
   int n = num.size();
   vector<vector<int>> dp(n, vector<int> (x+1, -1));
   int ans = fMemo(num.size() - 1, num, x, dp);
   if(ans >= INT_MAX/10)
    return -1;
   else return ans; 
}

// * Tabulation Approach:
int minimumElements(vector<int> &num, int x)
{
  int n = num.size();
  vector<vector<int>> dp(n, vector<int> (x+1, 0));
  
  for(int target = 0; target <= x; target++){
      if(target % num[0] == 0) dp[0][target] = target/num[0];
      else dp[0][target] = INT_MAX/10;
  }

  for(int idx = 1; idx < n; idx++) {
      for(int target = 0; target <= x; target++){
          int notTake = dp[idx - 1][target];
          int take = INT_MAX/10;
          if(num[idx] <= target)
              take = 1 + dp[idx][target - num[idx]];

          dp[idx][target] = min(take, notTake);
      }
  }
  int ans = dp[n-1][x];
  if(ans == INT_MAX/10)
      return -1;
  return ans;
}

// * Tabulation with SPACE OPTIMIZATION
int minimumElements(vector<int> &num, int x)
{
  int n = num.size();
  vector<int> curr(x+1, 0), prev(x+1, 0);
  
  for(int target = 0; target <= x; target++){
      if(target % num[0] == 0) prev[target] = target/num[0];
      else prev[target] = INT_MAX/10;
  }

  for(int idx = 1; idx < n; idx++) {
      for(int target = 0; target <= x; target++){
          int notTake = prev[target];
          int take = INT_MAX/10;
          if(num[idx] <= target)
              take = 1 + curr[target - num[idx]];

          curr[target] = min(take, notTake);
      }
      prev = curr;
  }
  int ans = prev[x];
  if(ans == INT_MAX/10)
      return -1;
  return ans;
}