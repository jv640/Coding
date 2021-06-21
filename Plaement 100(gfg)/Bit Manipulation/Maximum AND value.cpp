/*
    Given an array arr[] of N positive elements. The task is to find the Maximum AND Value generated by any pair(arri, arrj) from the array such that i != j.
    Note: AND is bitwise '&' operator.
    
    Example 1:
        Input: 
        N = 4
        arr[] = {4, 8, 12, 16}
        Output: 8
        Explanation:
        Pair (8,12) has the Maximum AND Value 8.
    
    Example 2:
        Input:
        N = 4
        arr[] = {4, 8, 16, 2}
        Output: 0
        Explanation: Any two pairs of the array has Maximum AND Value 0.

    Your Task: 
    You don't need to read input or print anything. 
    Your task is to complete the function maxAND() which takes the array elements and N (size of the array) as input parameters and returns the maximum AND value generated by any pair in the array. 

    Expected Time Complexity: O(N * log M), where M is the maximum element of the array.
    Expected Auxiliary Space: O(1).

    Constraints:
        1 <= N <= 105
        1 <= arr[i] <= 105
*/

// Approach
// Here we will check bits from leftmost if particular bit is set in all numbers then we add it in our result else not

// code
  int countBit(int pat, int arr[], int n){
        int count = 0;
        for(int i = 0; i<n; i++){
            if((pat&arr[i]) == pat)
                count++;
        }
        return count;
    }
    
    int maxAND (int arr[], int N)
    {
        int ans = 0;
        for(int bit = 31; bit>-1; bit--){
            int count = countBit(ans | (1<<bit), arr, N);
            if(count > 1)
            ans = ans|(1<<bit);
        }
        return ans;
    }
