/*
  Description : Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures? 
*/
// first approach is to use O(n2)
// second approach is to use sorting making it a O(nlogn) 
// another is to use a hash table which maintain count of 26 letter although it O(1) in space but if you still want to reduce some space
// you can use an integer value of 32 bit and use its bits as a sign of character also if lenght is greater than 26 then it ll have duplicates(valid only for a-z).
// code for last approach
  bool isUnique(string s){
      int flag = 0;
      for(int i = 0; i<s.length(); i++){
          int bitIndex = s[i] - 'a';
          if( flag & (1 << bitIndex))
              return false;
          flag = flag | (1 << bitIndex);
      }
      return true;
  }
