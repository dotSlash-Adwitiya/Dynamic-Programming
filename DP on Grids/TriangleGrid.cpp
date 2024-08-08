#include<bits/stdc++.h>
using namespace std;

// * RECURSIVE CODE
int f(int row, int col, vector<vector<int>>& triangle, int n) {
	if(row >= n || row < 0 || col < 0 || col >= n)
		return 0;
	if(row == n-1)
		return triangle[row][col];
	
	int down = triangle[row][col] + f(row + 1, col, triangle, n);
	int right = triangle[row][col] + f(row + 1, col+1, triangle, n);
	// int left = triangle[row][col] + f(row + 1, col-1, triangle, n);

	return min(down, right);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	return f(0, 0, triangle, n);
}

// * MEMOIZATION CODE
int f(int row, int col, vector<vector<int>>& triangle, int n, vector<vector<int>> &dp) {
	if(row >= n || row < 0 || col < 0 || col >= n)
		return 0;
	if(row == n-1)
		return triangle[row][col];
	
	if(dp[row][col] != -1)
		return dp[row][col];

	int down = triangle[row][col] + f(row + 1, col, triangle, n, dp);
	int right = triangle[row][col] + f(row + 1, col+1, triangle, n, dp);

	return dp[row][col] = min(down, right);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>> dp(n, vector<int> (n, -1));
	return f(0, 0, triangle, n, dp);
}

// * TABULATION CODE :

int minimumPathSum(vector<vector<int>>& triangle, int n){
  vector<vector<int>> dp(n, vector<int>(n, 0));

  // * Fill the last row of dp with the values from the last row of the triangle
  for(int col = 0; col < n; col++) 
      dp[n-1][col] = triangle[n-1][col];
  
  // * Build the dp table from the second last row to the top
  for(int row = n-2; row >= 0; row--) {
      for(int col = 0; col <= row; col++) {
          int down = triangle[row][col] + dp[row + 1][col];
          int right = triangle[row][col] + dp[row + 1][col + 1];
          dp[row][col] = min(down, right);
      }
  }

  return dp[0][0];
}