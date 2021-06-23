/*
  Given an array A[] of N positive integers. The task is to find the maximum of j - i subjected to the constraint of A[i] <= A[j].
  Example 1:
      Input:N = 2 A[] = {1, 10}
      Output: 1
      Explanation: A[0]<=A[1] so (j-i) is 1-0 = 1.
  Example 2:
      Input: N = 9 A[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}
      Output: 6
      Explanation: In the given array A[1] < A[7] satisfying the required condition(A[i] <= A[j]) thus giving the maximum difference of j - i which is 6(7-1).
  Your Task:
  The task is to complete the function maxIndexDiff() which finds and returns maximum index difference. Printing the output will be handled by driver code.
  Constraints:
      1 ≤ N ≤ 107
      0 ≤ A[i] ≤ 1018
  Expected Time Complexity: O(N).
  Expected Auxiliary Space: O(N).
  Company Tags
   * MakeMyTrip
   * Amazon
   * VMWare
   * Microsoft

*/

// Approach here is to use 2 aux vectors LeftMin which is going to store element minimum from current to left and similarily RightMax after that we will have 2 pointers
// both on starting of arrays and whenever Lmin[i]<Rmax[j] we will store the difference j-i

// code
int maxIndexDiff(int arr[], int n){
    vector<int> Lmin(n, 0), Rmax(n, 0);
    Lmin[0] = arr[0];
    for(int i = 1; i<n; i++)
        Lmin[i] = min(Lmin[i-1], arr[i]);
    Rmax[n-1] = arr[n-1];
    for(int i = n-2; i>-1; i--)
        Rmax[i] = max(Rmax[i+1], arr[i]);
    int i = 0, j = 0, max_diff = -1;
    while(i<n && j<n){
        if(Lmin[i] <= Rmax[j]){
            max_diff = max(max_diff, j-i);
            j++;
        }
        else 
            i++;
    }
    return max_diff;
}
