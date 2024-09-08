#include<bits/stdc++.h>
using namespace std;


/*
  * DERIVE A Recurrence Relation by :
  * I. -> Try to break down the problem into indices. (Try to map certain parameters into indices)
  * II. -> Do STUFF on those INDICES
  * III. -> Perform Operations, what's asked in the Question. Ex : Maximize or Minimize.
  * 
  * Example for this Question:-
  * 
  * I. Index -> (Day, LastTask), Where day signify the current Day, and LastTask is the task performed on previous day.
  * II. Do Stuff -> Add the current Day's points with subsequent Days using Recursion
  * II. Maximize the Answer
 */

int helper(int day, int lastTask, vector<vector<int>> &points) {
  if(day == 0){
      int maxi = 0;
      for(int task = 0; task < 3; task++) {
          if(task != lastTask)
              maxi = max(maxi, points[0][task]); // * Since this is the last task, take the max.
      }
      return maxi;
  }
  int maxi = 0;

  for(int task = 0; task < 3; task++) {
      if(task != lastTask) {
          int point = points[day][task] + helper(day - 1, task, points);
          maxi = max(maxi, point);
      }
  }
  return maxi;
}

int ninjaTrainingRecursive(int n, vector<vector<int>> &points)
{
  return helper(n-1, 3, points);
}

// * 2D DP Optimized Memoization Solution
// & T.C : O(N*4)*3 
// & S.C : O(N) + O(N*4) 
int helper(int day, int lastTask, vector<vector<int>> &points, vector<vector<int>> &dp) {
    if(day == 0){
        int maxi = 0;
        for(int task = 0; task < 3; task++) {
            if(task != lastTask)
                maxi = max(maxi, points[0][task]);
        }

        cout << "Max is : " << maxi << endl;  
        return dp[day][lastTask] = maxi;
    }

    if(dp[day][lastTask] != -1)
        return dp[day][lastTask];

    int maxi = 0;

    for(int task = 0; task < 3; task++) {
        if(task != lastTask) {
            int point = points[day][task] + helper(day - 1, task, points, dp);
            // cout << "Points Returned: " << point << endl;
            maxi = max(maxi, point);
        }
    }

    cout << "Max is : " << maxi << endl;
    return dp[day][lastTask] = maxi;
}

int ninjaTrainingMemoization(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4,-1));

    return helper(n-1, 3, points, dp);
}

/*
  * Tabulation Approach Derivation
  * Look for the EXACT BASE Case.
  * 
  * BOTTOM - UP Approach
  * I. Create auxillary space as it is from memoization
  * II. Initialize the auxillary space with BASE_CASE
  * 
*/

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4,-1));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][1], points[0][0]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int day = 1; day < n; day++){
        for(int last = 0; last < 4; last++){
            dp[day][last] = 0;
            
            for(int task = 0; task < 3; task++){
                if(task != last){
                    int point = points[day][task] + dp[day-1][task]; 
                    dp[day][last] = max(dp[day][last], point);
                    cout << point << endl;
                }
            }
        }
    }
  return dp[n-1][3];
}

// * SPACE OPTIMIZATION --> CONSTANT SPACE Approach
int ninjaTraining(int n, vector<vector<int>> &points) {
    vector<int> prev(3, 0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][1], points[0][0]);

    for(int day = 1; day < n; day++) {
        vector<int> curr(4, 0);
        for(int last = 0; last < 4; last++) {

            for(int task = 0; task < 3; task++) {
                if(task != last)
                 curr[last] = max(curr[last], points[day][task] + prev[task]);
            }
        }
        prev = curr;
    }
    return prev[3];
}