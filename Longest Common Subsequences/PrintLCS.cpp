#include<bits/stdc++.h>
using namespace std;

// * T.C: O (N*M)
string lcs(string s, string t)
{
	int n = s.size();
	int m = t.size();
	vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
	
	// * BASE_CASE : For every 0th idx, the answer is 0
	// * Answer is 0 because, we're treating 0 as -1, and since from the recursive approach,
	// * It can be observed: that negative indices will have a 0.
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(s[i-1] == t[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

  int len = dp[n][m];

  string ans = "";
  for(int i = 0; i < len; i++) 
    ans += '$';
  
  int i = n, j = m, index = len - 1;
  while(i > 0 and j > 0) {
    if(s[i-1] == t[j-1]){
      ans[index--] = s[i-1];
      i--, j--;
    }
    else if(dp[i-1][j] > dp[i][j-1]) 
      i--;
    else j--;
  }

  return ans;
}

int main()
{
  cout << lcs("abcdge", "bdgek");
  return 0;
}