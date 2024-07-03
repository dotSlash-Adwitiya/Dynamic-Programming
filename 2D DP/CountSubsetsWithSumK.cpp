#include<bits/stdc++.h>
using namespace std;

// * Recursive Approach
int helperRecrusive(int ind, int target, vector<int>& arr) {
  if (target == 0)
      return 1;

  if (ind == 0)
      return (arr[0] == target) ? 1 : 0;

  int notTaken = helperRecrusive(ind - 1, target, arr);

  int taken = 0;
  if (arr[ind] <= target)
      taken = helperRecrusive(ind - 1, target - arr[ind], arr);

  return notTaken + taken;
}

const int mod = 1e9+7;
int helperMemo(int ind, int target, int arr[], vector<vector<int>>& dp) {
    // * Base case-I : If the target sum is 0, we found a valid subset
    if (target == 0)
        return 1;

    // * Base case -II : If we have considered all elements and the target is still not 0, return 0
    if (ind == 0) 
    return (arr[0] == target) ? 1 : 0;
    

    if (dp[ind][target] != -1)
        return dp[ind][target];


    int notTaken = helperMemo(ind - 1, target, arr, dp);

    int taken = 0;
    if (arr[ind] <= target)
        taken = helperMemo(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = (notTaken + taken) % mod;
}

int perfectSum(int arr[], int n, int sum)
{
    // * Sort the array in DESCENDING Order
    /*
      * {0,0,3,0,1} : target = 4, since we're writing code from (size-1 -> 0th idx)
      * If you're writing code from (0 -> size-1) then sort in ascending order!!
      * Sorting this way helps in: putting all the 0s in either left or right,
      * Allowing them to be included in our subsets!!!!!
    */
    sort(arr, arr+n, greater<int>());
    vector<vector<int>> dp(n, vector<int>(sum+1, -1));
    return helperMemo(n-1, sum, arr, dp);
}
	  
