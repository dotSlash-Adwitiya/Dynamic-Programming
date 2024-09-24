#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
  int n = heights.size();
  stack<int> st;
  vector<int> leftsmall(n), rightsmall(n);

  for (int i = 0; i < n; i++) {
      while (!st.empty() && heights[st.top()] >= heights[i]) {
          st.pop();
      }
      if (st.empty())
          leftsmall[i] = 0;
      else
          leftsmall[i] = st.top() + 1;
      st.push(i);
  }

  while (!st.empty())
      st.pop();

  for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && heights[st.top()] >= heights[i]) {
          st.pop();
      }
      if (st.empty())
          rightsmall[i] = n - 1;
      else
          rightsmall[i] = st.top() - 1;
      st.push(i);
  }

  int maxA = 0;
  for (int i = 0; i < n; i++) {
      maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
  }
  return maxA;
}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>>& mat, int n, int m) {
  int maxArea = 0;
  vector<int> height(m, 0);

  for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
          if (mat[i][j] == 1)
              height[j]++;
          else
              height[j] = 0;
      }
      int area = largestRectangleArea(height);
      maxArea = max(area, maxArea);
  }
  return maxArea;
}