/*
  Description : Write a function to determine the number of bits you would need to flip to convert integer A to integer B. 
*/

// code
  #include<bits/stdc++.h>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        int x = n^m;
        int count = 0;
        while(x){
            if(x&1)
                count++;
            x = x>>1;
            
        }
        // code
        cout<<count<<endl;
    }
	
	return 0;
}
