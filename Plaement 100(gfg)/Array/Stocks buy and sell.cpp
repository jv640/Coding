/*
  The cost of stock on each day is given in an array A[] of size N. 
  Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.
  Note: There may be multiple possible solutions. Return any one of them. 
  Any correct solution will result in a output of 1, whereas wrong solutions will result in an output of 0.

  Example 1:
      Input: N = 7 A[] = {100,180,260,310,40,535,695}
      Output: 1
      Explanation: One possible solution is (0 3) (4 6) We can buy stock on day 0, and sell it on 3rd day, 
      which will give us maximum profit. Now, we buy stock on day 4 and sell it on day 6.
  Example 2:
      Input: N = 5 A[] = {4,2,2,2,4}
      Output: 1
      Explanation: There are multiple possible solutions. one of them is (3 4) We can buy stock on day 3, and sell it on 4th day, which will give us maximum profit.

  Your Task: The task is to complete the function stockBuySell() 
  which takes an array A[] and N as input parameters and finds the days of buying and selling stock. 
  The function must return a 2D list of integers containing all the buy-sell pairs. 
  If there is No Profit, return an empty list. The driver code will return 1 if your answer is correct, otherwise, it will return 0. 
  In case there's no profit the driver code will return the string "No Profit" for a correct solution.

  Expected Time Complexity: O(N)
  Expected Auxiliary Space: O(N)

  Constraints:
      2 ≤ N ≤ 106
      0 ≤ A[i] ≤ 106

  Company Tags
   *Accolite *Amazon *D-E-Shaw *Directi *Flipkart 
   *Goldman *Sachs *Intuit *MakeMyTrip *Microsoft 
   *Ola *Cabs *Oracle *Paytm *Pubmatic *Quikr 
   *Salesforce *Sapient *Swiggy *Walmart *Media.net *Google
*/

// Below code will store all possible buy ans sells
vector<vector<int>> res;
        int i = 0;
        while(i<n){
            while(i<n-1 && arr[i+1] <= arr[i])
                i++;
            if(i == n-1)
                break;
            int buy = i++;
            while(i<n && arr[i] >= arr[i-1])
                i++;
            int sell = i-1;
            vector<int> temp;
            temp.push_back(buy);
            temp.push_back(sell);
            res.push_back(temp);
        }
        return res;
