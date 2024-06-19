#include<bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums) {
  int prevIdx = nums[0], prev2Idx = 0, currIdx = 0;

  // * Applying the logic excluding the LAST Element
  for(int i = 1; i < nums.size()-1; i++) {
      int take = nums[i] + prev2Idx;
      int notTake = prevIdx;
      currIdx = max(take, notTake);
      prev2Idx = prevIdx;
      prevIdx = currIdx;
  }
  int ans1 = prevIdx;
  // * If the arr[] size is < 2 then nums[1] will give out of memory error!
  if(nums.size() < 2) return ans1;
  // * Applying the logic excluding the 1st Element
  prevIdx = nums[1], prev2Idx = 0, currIdx = 0;
  for(int i = 2; i < nums.size(); i++) {
      int take = nums[i] + prev2Idx;
      int notTake = prevIdx;
      currIdx = max(take, notTake);
      prev2Idx = prevIdx;
      prevIdx = currIdx;
  }
  int ans2 = prevIdx;

  return (ans1 > ans2 ? ans1 : ans2);
}