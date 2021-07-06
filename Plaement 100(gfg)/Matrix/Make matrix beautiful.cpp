/*
  A beautiful matrix is a matrix in which the sum of elements in each row and column is equal.
  Given a square matrix of size NxN. Find the minimum number of operation(s) that are required to make the matrix beautiful. In one operation you can increment the value of any one cell by 1.

  Example 1:

  Input:
  N = 2
  matrix[][] = {{1, 2},
                {3, 4}}
  Output: 4
  Explanation:
  Updated matrix:
  4 3
  3 4
  1. Increment value of cell(0, 0) by 3
  2. Increment value of cell(0, 1) by 1
  Hence total 4 operation are required.
  Example 2:

  Input:
  N = 3
  matrix[][] = {{1, 2, 3},
                {4, 2, 3},
                {3, 2, 1}}
  Output: 6
  Explanation:
  Original matrix is as follows:
  1 2 3
  4 2 3
  3 2 1
  We need to make increment in such a way 
  that each row and column has one time 2, 
  one time 3 , one time 4. For that we 
  need 6 operations.

  Your Task: 
  You don't need to read input or print anything. Complete the function findMinOpeartion() that takes matrix and n as input parameters and returns the minimum number of operations.

  Expected Time Complexity: O(N * N)
  Expected Auxiliary Space: O(N)

  Constraints:
  1 <= N <= 100
  1 <= matrix[i][j] <= 200
*/

// code
int findMinOpeartion(vector<vector<int> > matrix, int n){
        vector<int> rsum(n, 0), csum(n, 0);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                rsum[i] += matrix[i][j];
                csum[j] += matrix[i][j];
            }
        }
        int maxx = INT_MIN;
        for(int i = 0; i<n; i++){
            maxx = max(maxx, rsum[i]);
            maxx = max(maxx, csum[i]);
        }
        int ans = 0;
        for(int i = 0, j = 0; i<n && j<n;){
            int diff = min(maxx-rsum[i], maxx-csum[j]);
            matrix[i][j] += diff;
            rsum[i] += diff;
            csum[j] += diff;
            ans += diff;
            if(rsum[i] == maxx)
                i++;
            if(csum[j] == maxx)
                j++;
        }
        return ans;
    } 
