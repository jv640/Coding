/*
  Description :  Given a positive integer, print the next smallest and the next largest number that have the same number of 1 bits in their binary representation. 
*/

// think how can we get next greater with same number of one we have flip one 0 bit to 1 and one 1 bit to 0. now think in this direcion.

// code
  int getNext(int n) 
{ 
    /* Compute c0 and c1 */
    int c = n; 
    int c0 = 0; 
    int c1 = 0; 
  
    while (((c & 1) == 0) && (c != 0)) 
    { 
        c0 ++; 
        c >>= 1; 
    } 
    while ((c & 1)==1) 
    { 
        c1++; 
        c >>= 1; 
    } 
  
    // If there is no bigger number with the 
    // same no. of 1's 
    if (c0 +c1 == 31 || c0 +c1== 0) 
        return -1; 
  
    // position of rightmost non-trailing zero 
    int p = c0 + c1; 
  
    // Flip rightmost non-trailing zero 
    n |= (1 << p); 
  
    // Clear all bits to the right of p 
    n &= ~((1 << p) - 1); 
  
    // Insert (c1-1) ones on the right. 
    n |= (1 << (c1 - 1)) - 1; 
  
    return n; 
}

int getPrev(int n) 
{ 
    /* Compute c0 and c1  and store N*/
    int temp = n; 
    int c0 = 0; 
    int c1= 0; 
  
    while ((temp & 1) == 1) 
    { 
        c1++; 
        temp = temp >> 1; 
    } 
  
    if (temp == 0) 
        return -1; 
  
    while (((temp & 1) == 0) && (temp!= 0)) 
    { 
        c0++; 
        temp  = temp >> 1; 
    } 
  
    // position of rightmost non-trailing one. 
    int p = c0 + c1; 
  
    // clears from bit p onwards 
    n = n & ((~0) << (p + 1)); 
  
    // Sequence of (c1+1) ones 
    int mask = (1 << (c1 + 1)) - 1; 
  
    n = n | mask << (c0 - 1); 
  
    return n; 
} 

int getNext(int n) 
{ 
    /* Compute c0 and c1 */
    int c = n; 
    int c0 = 0; 
    int c1 = 0; 
  
    while (((c & 1) == 0) && (c != 0)) 
    { 
        c0 ++; 
        c >>= 1; 
    } 
    while ((c & 1)==1) 
    { 
        c1++; 
        c >>= 1; 
    } 
  
    // If there is no bigger number with the 
    // same no. of 1's 
    if (c0 +c1 == 31 || c0 +c1== 0) 
        return -1; 
  
    return n + (1 << c0) + (1 << (c1 - 1)) - 1; 
} 

int getPrev(int n) 
{ 
    /* Compute c0 and c1  and store N*/
    int temp = n; 
    int c0 = 0; 
    int c1 = 0; 
  
    while ((temp & 1) == 1) 
    { 
        c1++; 
        temp = temp >> 1; 
    } 
  
    if (temp == 0) 
        return -1; 
  
    while (((temp & 1) == 0) && (temp!= 0)) 
    { 
        c0++; 
        temp  = temp >> 1; 
    } 
  
    return n - (1 << c1) - (1 << (c0 - 1)) + 1; 
} 
