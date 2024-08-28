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

// * Practice - 1
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

// * Tabulation Appraoch
 int equalPartition(int N, int arr[]) {
    int sum = 0;
    for(int i = 0; i < N; i++)
        sum += arr[i];
        
    if(sum % 2)
        return 0;
    int target = sum / 2;
    vector<vector<bool>> dp(N + 1, vector<bool>(target + 1, false));

    for (int idx = 0; idx <= N; idx++) {
        for (int tar = 0; tar <= target; tar++) {
            if (idx == 0)
                dp[idx][tar] = false;
            if (tar == 0)
                dp[idx][tar] = true;
        }
    }

    for (int idx = 1; idx <= N; idx++) {
        for (int tar = 1; tar <= target; tar++) {
            if (arr[idx - 1] <= tar) {
                dp[idx][tar] = dp[idx - 1][tar - arr[idx - 1]] || dp[idx - 1][tar];
            } else {
                dp[idx][tar] = dp[idx - 1][tar];
            }
        }
    }

    return dp[N][target];
}