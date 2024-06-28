#include<bits/stdc++.h>
using namespace std;

bool f(int idx, vector<int> &arr, int k, vector<vector<int>> &dp) {
    if(k == 0)
        return true;
    if(idx == 0) {
        if(arr[idx] == k)
            return true;
        return false;
    }

    if(dp[idx][k] != -1) return dp[idx][k];

    bool take = false, notTake = false;

    if(k >= arr[idx])
        take = f(idx-1, arr, k - arr[idx], dp);
    notTake = f(idx-1, arr, k, dp);

    return dp[idx][k] = take || notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return f(n-1, arr, k, dp);
}

bool canPartition(vector<int> &arr, int n)
{
	int totSum = 0;
	for(int i = 0; i < n; i++) totSum += arr[i];

  // * If sum is odd, then it can't be partitioned.
	if(totSum & 1) return false;

	return subsetSumToK(n, totSum/2, arr);
}