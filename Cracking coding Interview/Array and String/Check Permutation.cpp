// Description  :  Given two strings, write a method to decide if one is a permutation of the other.

// basic appraoch is O(n2)
// other is to use map it will have O(26) space which O(1) of course
// Other approach is to use only 2 integers below is the code
#include<bits/stdc++.h>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--){
        string s1, s2;
        cin>>s1>>s2;
        int flag1 = 0;
        for(int i = 0; i<s1.length(); i++){
            if(s1[i] != ' ')
                flag1 = flag1 + (1 << (s1[i]-'a'));    
        }
        int flag2 = 0;
        for(int i = 0; i<s2.length(); i++){
            if(s2[i] != ' ')
                flag2 = flag2 + (1 << (s2[i]-'a'));    
        }
        // cout<<flag1<<" "<<flag2;
        if(flag1 != flag2)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
        // code
    }
	
	return 0;
}
