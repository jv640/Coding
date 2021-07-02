/*
  Given two arrays X and Y of positive integers, find the number of pairs such that xy > yx (raised to power of) where x is an element from X and y is an element from Y.

  Example 1:

  Input: 
  M = 3, X[] = [2 1 6] 
  N = 2, Y[] = [1 5]
  Output: 3
  Explanation: 
  The pairs which follow xy > yx are 
  as such: 21 > 12,  25 > 52 and 61 > 16 .
  Example 2:

  Input: 
  M = 4, X[] = [2 3 4 5]
  N = 3, Y[] = [1 2 3]
  Output: 5
  Explanation: 
  The pairs for the given input are 
  21 > 12 , 31 > 13 , 32 > 23 , 41 > 14 , 
  51 > 15 .

  Your Task:
  This is a function problem. You only need to complete the function countPairs() that takes X, Y, M, N as parameters and returns the total number of pairs.

  Expected Time Complexity: O((N + M)log(N)).
  Expected Auxiliary Space: O(1).

  Constraints:
  1 ≤ M, N ≤ 105
  1 ≤ X[i], Y[i] ≤ 103
*/

/*
 The trick here is if y > x then x^y > y^x with some exceptions. 

  Following are simple steps based on this trick. 

  Sort array Y[].
  For every x in X[], find the index idx of the smallest number greater than x (also called ceil of x) in Y[] using binary search, 
  or we can use the inbuilt function upper_bound() in algorithm library.
  All the numbers after idx satisfy the relation so just add (n-idx) to the count.
  Base Cases and Exceptions: 

  Following are exceptions for x from X[] and y from Y[]   



  If x = 0, then the count of pairs for this x is 0.
  If x = 1, then the count of pairs for this x is equal to count of 0s in Y[].
  x smaller than y means x^y is greater than y^x.
  x = 2, y = 3 or 4
  x = 3, y = 2
*/

//code
int count(int x, int Y[], int n, int NoOfY[])
{
    // If x is 0, then there cannot be any value in Y such
    // that x^Y[i] > Y[i]^x
    if (x == 0)
        return 0;
 
    // If x is 1, then the number of pais is equal to number
    // of zeroes in Y[]
    if (x == 1)
        return NoOfY[0];
 
    // Find number of elements in Y[] with values greater
    // than x upper_bound() gets address of first greater
    // element in Y[0..n-1]
    int* idx = upper_bound(Y, Y + n, x);
    int ans = (Y + n) - idx;
 
    // If we have reached here, then x must be greater than
    // 1, increase number of pairs for y=0 and y=1
    ans += (NoOfY[0] + NoOfY[1]);
 
    // Decrease number of pairs for x=2 and (y=4 or y=3)
    if (x == 2)
        ans -= (NoOfY[3] + NoOfY[4]);
 
    // Increase number of pairs for x=3 and y=2
    if (x == 3)
        ans += NoOfY[2];
 
    return ans;
}
 
// Function to return count of pairs (x, y) such that
// x belongs to X[], y belongs to Y[] and x^y > y^x
int countPairs(int X[], int Y[], int m, int n)
{
    // To store counts of 0, 1, 2, 3 and 4 in array Y
    int NoOfY[5] = { 0 };
    for (int i = 0; i < n; i++)
        if (Y[i] < 5)
            NoOfY[Y[i]]++;
 
    // Sort Y[] so that we can do binary search in it
    sort(Y, Y + n);
 
    int total_pairs = 0; // Initialize result
 
    // Take every element of X and count pairs with it
    for (int i = 0; i < m; i++)
        total_pairs += count(X[i], Y, n, NoOfY);
 
    return total_pairs;
}
