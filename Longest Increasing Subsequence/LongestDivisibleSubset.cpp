#include<bits/stdc++.h>
using namespace std;

void f(int idx, vector<int> &arr, vector<int> &temp, vector<int> &subset) {
  if(idx == arr.size()) {
      if(temp.size() > subset.size()) {
          subset = temp;
      }
      return;
  }

  if(temp.size() == 0 || arr[idx] % temp.back() == 0) {
      temp.push_back(arr[idx]);
      f(idx + 1, arr, temp, subset);
      temp.pop_back();
  }
  
  f(idx + 1, arr, temp, subset);
}

vector<int> divisibleSet(vector<int> &arr) {   
  sort(arr.begin(), arr.end());
  vector<int> subset, temp;
  
  f(0, arr, temp, subset);
  return subset;
}

// * DP on LIS Approach :
vector<int> divisibleSet(vector<int> &arr) {   
  int n = arr.size();
  sort(arr.begin(), arr.end());

  vector<int> dp(n, 1);
  vector<int> hash(n);

  for (int i = 0; i < n; i++) {
      hash[i] = i;
      for (int prev_index = 0; prev_index < i; prev_index++) {
          if (arr[i] % arr[prev_index] == 0 && 1 + dp[prev_index] > dp[i]) {
              dp[i] = 1 + dp[prev_index];
              hash[i] = prev_index;
          }
      }
  }

  int ans = -1;
  int lastIndex = -1;

  for (int i = 0; i < n; i++) {
      if (dp[i] > ans) {
          ans = dp[i];
          lastIndex = i;
      }
  }

  vector<int> temp;
  temp.push_back(arr[lastIndex]);

  while (hash[lastIndex] != lastIndex) {
      lastIndex = hash[lastIndex];
      temp.push_back(arr[lastIndex]);
  }

  reverse(temp.begin(), temp.end());

  return temp;
}
