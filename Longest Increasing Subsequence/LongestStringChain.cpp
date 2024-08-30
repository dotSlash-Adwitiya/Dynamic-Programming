#include<bits/stdc++.h>
using namespace std;

inline bool comp(string &s1, string &s2){
  return s1.size() < s2.size();
}

inline bool compareString(string &s1, string &s2) {
  if(s1.size() != s2.size() + 1) return false;

  int i = 0, j = 0;
  while(i < s1.size()){
    if(j < s2.size() && s1[i] == s2[j]){
      j++;
    }
    i++;
  }
  return j == s2.size();
}

int longestStrChain(vector<string> &arr) {
    sort(arr.begin(), arr.end(), comp);
    int n = arr.size();
    vector<int> dp(n, 1);
    int maxLen = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(compareString(arr[i], arr[j]) && 1 + dp[j] > dp[i])
                dp[i] = 1 + dp[j];
        }
        maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
}