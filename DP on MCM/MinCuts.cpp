#include <bits/stdc++.h> 
using namespace std;


int f(int i, int j, vector<int> &cuts){
    if(i > j) return 0;
    int minCost = INT_MAX;

    for(int idx = i; idx <= j; idx++){
        int cost = cuts[j+1] - cuts[i-1] + 
            f(i, idx - 1, cuts) + f(idx + 1, j, cuts);
        minCost = min(minCost, cost);
    }

    return minCost;
}

int cost(int n, int c, vector<int> &cuts){
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    return f(1, c, cuts);
}


int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){
    if(i > j) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    int minCost = INT_MAX;

    for(int idx = i; idx <= j; idx++){
        int cost = cuts[j+1] - cuts[i-1] + 
            f(i, idx - 1, cuts, dp) + f(idx + 1, j, cuts, dp);
        minCost = min(minCost, cost);
    }

    return dp[i][j] = minCost;
}

int cost(int n, int c, vector<int> &cuts){
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c + 1, vector<int> (c + 1, -1));
    return f(1, c, cuts, dp);
}

int cost(int n, int c, vector<int> &cuts){
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    int dp[c+2][c+2] = {0};

    for(int i = c; i >= 1; i--){
        for(int j = 1; j <= c; j++){
            if(i > j) continue;
             int minCost = INT_MAX;

            for(int idx = i; idx <= j; idx++){
                int cost = cuts[j+1] - cuts[i-1] + 
                    dp[i][idx - 1] + dp[idx + 1][j];
                minCost = min(minCost, cost);
            }

            dp[i][j] = minCost;
        }
    }

    return dp[1][c];
}