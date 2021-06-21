/*
    You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).

    Example 1:
        Input: N = 4
        Output: 5
        Explanation:
        For numbers from 1 to 4.
        For 1: 0 0 1 = 1 set bits
        For 2: 0 1 0 = 1 set bits
        For 3: 0 1 1 = 2 set bits
        For 4: 1 0 0 = 1 set bits
        Therefore, the total set bits is 5.
    
    Example 2:
        Input: N = 17
        Output: 35
        Explanation: From numbers 1 to 17(both inclusive), 
        the total number of set bits is 35.
    Your Task: The task is to complete the function countSetBits() that takes n as a parameter and returns the count of all bits.
    Expected Time Complexity: O(log N).
    Expected Auxiliary Space: O(1).

    Constraints:
    1 ≤ N ≤ 10^8
*/

// There are many approach but to solve it in logn we have to see the bit pattern in numbers we know 0th bit happen in 0 then 1 then 0 format and 1st bit occuth in pair of 2

// code
    int countSetBits(int n){
        n++; // to compensate for 0th bith
        int ans = n/2;
        int powerOf2 = 2;
        while(powerOf2 <= n){
            int numOfGroups = n/powerOf2;
            ans += (numOfGroups/2)*powerOf2;
            ans += (numOfGroups%2)? n%powerOf2 : 0;
            powerOf2 *= 2;
        }
        return ans;
    }
