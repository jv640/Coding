/*
  Problem Description:  A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time. 
                        Implement a method to count how many possible ways the child can run up the stairs.
                        
*/

// code
  int countWays(int n){ 
    int res[n + 1]; 
    res[0] = 1; 
    res[1] = 1; 
    res[2] = 2; 
    for (int i = 3; i <= n; i++) 
        res[i] = res[i - 1] + res[i - 2] 
                + res[i - 3]; 
  
    return res[n]; 
} 
