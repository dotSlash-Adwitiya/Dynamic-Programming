#include<bits/stdc++.h>
using namespace std;

// * Recursive solution
int f(int i, string& s, unordered_map<string, int>& mp) {
  if (i >= s.size()) return 0;

  string currStr = "";
  int minExtra = s.size();
  for (int j = i; j < s.size(); j++) {
      currStr.push_back(s[j]);
      int currExtra = (mp.count(currStr)) ? 0 : currStr.size();
      int nextExtra = f(j + 1, s, mp);
      int totalExtra = currExtra + nextExtra;

      minExtra = min(minExtra, totalExtra);
  }
  return minExtra;
}

int minExtraChar(string s, vector<string>& dictionary) {
  unordered_map<string, int> mp;
  for (string& word : dictionary) 
      mp[word]++;
  return f(0, s, mp);
}

// * Memoization Code:
int f(int i, string& s, unordered_map<string, int>& mp, vector<int>& dp) {
  if (i >= s.size()) return 0;

  if (dp[i] != -1) return dp[i];

  string currStr = "";
  int minExtra = s.size();
  for (int j = i; j < s.size(); j++) {
      currStr.push_back(s[j]);
      int currExtra = (mp.count(currStr)) ? 0 : currStr.size();
      int nextExtra = f(j + 1, s, mp, dp);
      int totalExtra = currExtra + nextExtra;

      minExtra = min(minExtra, totalExtra);
  }
  return dp[i] = minExtra;
}

int minExtraChar(string s, vector<string>& dictionary) {
  unordered_map<string, int> mp;
  for (string& word : dictionary) 
      mp[word]++;
  int n = s.size();
  vector<int> dp(n, -1);
  return f(0, s, mp, dp);
}

// * Tabulation code: 
int minExtraChar(string s, vector<string>& dictionary) {
  unordered_map<string, int> mp;
  for (string& word : dictionary) 
      mp[word]++;
  
  int n = s.size();
  vector<int> dp(n + 1, 0);  // dp[i] represents the min extra chars for substring s[i:]

  for (int i = n - 1; i >= 0; i--) {
      string currStr = "";
      int minExtra = s.size();
      for (int j = i; j < s.size(); j++) {
          currStr.push_back(s[j]);
          int currExtra = (mp.count(currStr)) ? 0 : currStr.size();
          int nextExtra = dp[j + 1];
          int totalExtra = currExtra + nextExtra;

          minExtra = min(minExtra, totalExtra);
      }
      dp[i] = minExtra;
  }

  return dp[0];
}




