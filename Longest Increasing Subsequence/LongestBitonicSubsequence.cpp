#include<bits/stdc++.h>
using namespace std;

int longestBitonicSubsequence(vector<int>& arr, int n) {
	vector<int> dp1(n, 1), dp2(n, 1);

    for(int idx = 0; idx < n; idx++){
        for(int prevIdx = 0; prevIdx <= idx-1; prevIdx++){
            if(arr[prevIdx] < arr[idx] && 1 + dp1[prevIdx] > dp1[idx])
                dp1[idx] = 1 + dp1[prevIdx];
        }
    }

    for(int idx = n-1; idx >= 0; idx--){
        for(int prevIdx = n-1; prevIdx > idx; prevIdx--){
            if(arr[prevIdx] < arr[idx] && 1 + dp2[prevIdx] > dp2[idx])
                dp2[idx] = 1 + dp2[prevIdx];
        }
    }

	int maxBitonic = 0;
	for(int i = 0; i < n; i++)
		maxBitonic = max(maxBitonic, dp1[i] + dp2[i] - 1);
	
	return maxBitonic;
}
