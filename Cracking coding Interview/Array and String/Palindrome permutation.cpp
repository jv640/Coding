/*
  Description : Given a string, write a function to check if it is a permutation of a palindrome. 
                A palindrome is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of letters. 
                The palindrome does not need to be limited to just dictionary words.
  EXAMPLE
    Input: Tact Coa
    Output: True (permutations: "taco cat". "atco cta". etc.) 
*/
// code
  #include<bits/stdc++.h>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.length();
        vector<int> count(26, 0);
        for(int i = 0; i<n; i++)
            count[s[i]-'a']++;
        int countOdd = 0;
        for(int i = 0; i<26; i++){
            if(count[i]%2)
                countOdd++;
            if(countOdd>1)
                break;
        }
        if(countOdd>1)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
        // code
    }
	
	return 0;
}
