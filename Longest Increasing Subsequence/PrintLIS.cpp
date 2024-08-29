#include<bits/stdc++.h>
using namespace std;


vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
    vector<int> dp(n, 1), hash(n);
    int lastIdx = 0, maxLen = 1;

    for(int idx = 0; idx < n; idx++){
      hash[idx] = idx;
    
      for(int prevIdx = 0; prevIdx <= idx-1; prevIdx++){
        if(arr[prevIdx] < arr[idx] && 1 + dp[prevIdx] > dp[idx]){
            dp[idx] = 1 + dp[prevIdx];
            hash[idx] = prevIdx;
        }
      }
      if(dp[idx] > maxLen){
          maxLen = dp[idx];
          lastIdx = idx; // * Store the last index of maximum dp[idx]
      }
  }

  vector<int> lis;
  lis.push_back(arr[lastIdx]);
  
  while(lastIdx != hash[lastIdx]){
      lastIdx = hash[lastIdx];
      lis.push_back(arr[lastIdx]);
  }

  reverse(lis.begin(), lis.end());
  return lis;
}
