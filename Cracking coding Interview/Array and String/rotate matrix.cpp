// one simple approach is transpose the matrix and reverse each row or col on condition of given rotation if clockwise then reverse rows else cols
// other approach is below coded
   
   void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int x = 0; x<n/2; x++){
            for(int y = x; y<n-x-1; y++){
                int temp = matrix[x][y];
                matrix[x][y] = matrix[n-y-1][x];
                matrix[n-y-1][x] = matrix[n-x-1][n-y-1];
                matrix[n-x-1][n-y-1] = matrix[y][n-x-1];
                matrix[y][n-x-1] = temp;
            }
        }
        for(int i = 0; i<n; i++)
            for(int j = 0; j<n; j++)
                cout<<matrix[i][j];  
    }
