#include <bits/stdc++.h> 
using namespace std;

// * Brute Force O(n²)
int maximumProfit(vector<int> &prices){
  int maxProfit = 0, n = prices.size();

  for(int i = 0; i < n; i++) {
      int buyStock = prices[i];
      int currProfit = 0;
      for(int j = i+1; j < n; j++) {
          currProfit = max(currProfit, prices[j] - buyStock);
      }
      maxProfit = max(currProfit, maxProfit);
  }
  return maxProfit;
}

// * Optimised Approach - O(N), T.C
int maximumProfit(vector<int> &prices){
    int maxProfit = 0, n = prices.size();
    int minStock = prices[0];
    for(int i = 0; i < n; i++) {
        int cost = prices[i] - minStock;

        maxProfit = max(maxProfit, cost);
        minStock = min(minStock, prices[i]);
    }
    return maxProfit;
}