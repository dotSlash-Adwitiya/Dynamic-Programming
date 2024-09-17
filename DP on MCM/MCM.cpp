#include <bits/stdc++.h> 
using namespace std;

int f(vector<int>& arr, int i, int j){
  if(i == j) return 0;
      
  int mini = INT_MAX;
  
  // * partioning loop
  for(int k = i; k<= j-1; k++){
      int ans = f(arr,i,k) + f(arr, k+1,j) + arr[i-1]*arr[k]*arr[j];
      mini = min(mini,ans);
  }
  return mini;
}


int matrixMultiplication(vector<int>& arr, int N){
  int i =1;
  int j = N-1;
  return f(arr,i,j);
}

// * Memoization OPTIMIZATION
int f(int arr[], int i, int j, vector<vector<int>>& dp){
  if(i == j) return 0;
      
  if(dp[i][j]!=-1) return dp[i][j];
  
  int mini = INT_MAX;
  
  // * PARTITIONING LOOP
  for(int k = i; k<= j-1; k++){
      int ans = f(arr,i,k,dp) + f(arr, k+1,j,dp) + arr[i-1]*arr[k]*arr[j];
      mini = min(mini,ans);
  }
  return dp[i][j] = mini;
}
int matrixMultiplication(int N, int arr[]) {
  vector<vector<int>> dp(N,vector<int>(N,-1));
  int i =1;
  int j = N-1;
  return f(arr,i,j,dp);
}

// * TABULATION APPROACH
int matrixMultiplication(vector<int>& arr, int N){
  vector<vector<int>> dp(N,vector<int>(N,0));

  for(int i = N-1; i >= 1; i--) {
      for(int j = i + 1; j < N; j++) { // * j cannot be less than i
          int mini = INT_MAX;
          
          // * PARTITIONING LOOP
          for(int k = i; k<= j-1; k++){
              int ans = dp[i][k]+ dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
              mini = min(mini,ans);
          }
          dp[i][j] = mini;
      }
  }
  return dp[1][N-1];
}

// * PRACTICE - 1
int f(vector<int>& arr, int i, int j){
  if(i == j) return 0;
      
  int mini = INT_MAX;
  
  // * partioning loop
  for(int k = i; k<= j-1; k++){
      int ans = f(arr,i,k) + f(arr, k+1,j) + arr[i-1]*arr[k]*arr[j];
      mini = min(mini,ans);
  }
  return mini;
}


int matrixMultiplication(vector<int>& arr, int N){
  int i =1;
  int j = N-1;
  return f(arr,i,j);
}

// * Memoization OPTIMIZATION
int f(int arr[], int i, int j, vector<vector<int>>& dp){
  if(i == j) return 0;
      
  if(dp[i][j]!=-1) return dp[i][j];
  
  int mini = INT_MAX;
  
  // * PARTITIONING LOOP
  for(int k = i; k<= j-1; k++){
      int ans = f(arr,i,k,dp) + f(arr, k+1,j,dp) + arr[i-1]*arr[k]*arr[j];
      mini = min(mini,ans);
  }
  return dp[i][j] = mini;
}
int matrixMultiplication(int N, int arr[]) {
  vector<vector<int>> dp(N,vector<int>(N,-1));
  int i =1;
  int j = N-1;
  return f(arr,i,j,dp);
}