/*
  Description :   Write a program to swap odd and even bits in an integer with as few instructions as possible 
                  (e.g., bit 13 and bit 1 are swapped, bit 2 and bit 3 are swapped, and so on).
*/

// trick is shift all even bit to right and all odd bits to left

// code
  #include<bits/stdc++.h>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        unsigned int even_bits = x & 0xAAAAAAAA;  
  
        // Get all odd bits of x  
        unsigned int odd_bits = x & 0x55555555;  
      
        even_bits >>= 1; // Right shift even bits  
        odd_bits <<= 1; // Left shift odd bits  
      
        cout<<(even_bits | odd_bits)<<endl;
        // code
    }
	
	return 0;
}
