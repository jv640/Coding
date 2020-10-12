/*
  Description : You are given two 32-bit numbers, Nand M, and two bit positions, i and j. Write a method to insert Minto N such that M starts at bit j and ends at bit i. 
                You can assume that the bits j through i have enough space to fit all of M. That is, if M = 10011, 
                you can assume that there are at least 5 bits between j and i. You would not, for example, have j = 3 and i = 2, 
                because M could not fully fit between bit 3 and bit 2.
    EXAMPLE
        Input:  N 10011, i 2, j 6
        Output: N 10001001100 
*/

// Approach is to first we have to clear bits in N from i to j. means we have end N with num like 11..11(jth pos)00..00(ith pos)11..11. which means we have to tc of bits
// after j and before i in N for that first create a mask for bits after j we need 11..11(jth bit)000..00 and for bits before i we need 00..00(ith bit)11 then OR these both and
// AND resulted number with N

// Code
int updateBits(int n, int m, int i, int j) { 
    int allOnes = ~0; // will equal sequence of all ls 
    int left= allOnes << (j + 1); 
    int right = ((1 << i) - 1); 
    int mask = left | right; 
    int n_cleared = n & mask; // Clear bits j through i. 
    int m_shifted = m << i;   // Move m into correct position. 
    return (n_cleared | m_shifted); // OR them, and we're done! 
}
