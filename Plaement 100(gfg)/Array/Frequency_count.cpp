/*
    Given an array A[] of N positive integers which can contain integers from 1 to P where elements can be repeated or can be absent from the array. 
    Your task is to count the frequency of all elements from 1 to N.
    Example 1:
        Input: N = 5 arr[] = {2, 3, 2, 3, 5} P = 5
        Output: 0 2 2 0 1
        Explanation: Counting frequencies of each array element
            We have:
            1 occurring 0 times.
            2 occurring 2 times.
            3 occurring 2 times.
            4 occurring 0 times.
            5 occurring 1 time.
    Example 2:
        Input: N = 4 arr[] = {3,3,3,3} P = 3
        Output: 0 0 4 0
        Explanation: Counting frequencies of each array element
            We have:
            1 occurring 0 times.
            2 occurring 0 times.
            3 occurring 4 times.
            4 occurring 0 times.
    Your Task:
    Complete the function frequencycount() that takes the array and n as input parameters and returns an array in place to denote the frequency count of each element from 1 to N. 
    i,e element at index 0 should represent frequency of 1 and so on.
    Expected Time Complexity: O(N logN)
    Expected Auxiliary Space: O(1)

    Constraints:
        1 ≤ N ≤ 105
        1 ≤ P ≤ 4*104 
        1 <= A[i] <= P
*/

/*
  There are many approach for this but all approach have different time and space requirement
  1st approach is to use index as hashmap to store count and as we know elements are positive so we can store count as negative elements
  1. Traverse the array from start to end.
  2. For each element check if the element is less than or equal to zero or not. If negative or zero skip the element as it is freqeuncy.
  3. If an element (e = array[i] - 1 ) is positive, then check if array[e] is positive or not. 
     If positive then that means it is the first occurrence of e in the array and replace array[i] with array[e], i.earray[i] = array[e] and assign array[e] = -1. 
     If array[e] is negative, then it is not the first occurrence, the update array[e] as array[e]-- and update array[i] as array[i] = 0.
  4. Again, traverse the array and print i+1 as value and array[i] as frequency.
*/

// Code
void findCounts(int *arr, int n){
    // Traverse all array elements
    int i = 0;
    while (i<n){
        // If this element is already processed, then nothing to do
        if (arr[i] <= 0){
            i++;
            continue;
        }

        // Find index corresponding to this element. For example, index for 5 is 4
        int elementIndex = arr[i]-1;

        // If the elementIndex has an element that is not processed yet, then first store that element to arr[i] so that we don't lose anything.
        if (arr[elementIndex] > 0){
            arr[i] = arr[elementIndex];

            // After storing arr[elementIndex], change it to store initial count of 'arr[i]'
            arr[elementIndex] = -1;
        }
        else{
            // If this is NOT first occurrence of arr[i], then decrement its count.
            arr[elementIndex]--;

            // And initialize arr[i] as 0 means the element 'i+1' is not seen so far
            arr[i] = 0;
            i++;
        }
    }

    printf("\nBelow are counts of all elements\n");
    for (int i=0; i<n; i++)
        printf("%d -> %d\n", i+1, abs(arr[i]));
}

/*
  This approach is very useful and used in many question related frequency
  Another approach is to store element as we can get 2 value from them and one way to do is to store element as arr[arr[i]%n] = arr[arr[i]%n] + n. 
  This way we can get 2 numbers 1 as arr[i]%n and other as arr[i]/n;
  1. Traverse the array from start to end and reduce all the elements by 1.
  2. Again traverse the array from start to end.
  3. For each element array[i]%n update array[array[i]%n], i.e array[array[i]%n]++
  4. Traverse the array from start to end and print i + 1 as value and array[i]/n as frequency.
*/
// Code
void printfrequency(int arr[],int n){
    // Subtract 1 from every element so that the elements become in range from 0 to n-1
    for (int j =0; j<n; j++)
        arr[j] = arr[j]-1;

    // Use every element arr[i] as index and add 'n' to element present at arr[i]%n to keep track of count of occurrences of arr[i]
    for (int i=0; i<n; i++)
        arr[arr[i]%n] = arr[arr[i]%n] + n;

    // To print counts, simply print the number of times n
    // was added at index corresponding to every element
    for (int i =0; i<n; i++)
        cout << i + 1 << " ->  " << arr[i]/n << endl;
}
  
  
  
  
  
  
