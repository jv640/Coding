/*
  Descripition:   Imagine a robot sitting on the upper left corner of grid with r rows and c columns. The robot can only move in two directions, 
                  right and down, but certain cells are "off limits" such that the robot cannot step on them. 
                  Design an algorithm to find a path for the robot from the top left to the bottom right.
*/

// code

    int uniquePaths(int m, int n) {
        int dp[m][n];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i = 1;i<m; i++)
            dp[i][0] = 1;
        for(int i = 1;i<n; i++)
            dp[0][i] = 1;
        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
