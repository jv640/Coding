/*
  Description : Implement a method to perform basic string compression using the counts of repeated characters. 
    For example, the string aabcccccaaa would become a2b1c5a3. If the "compressed" string would not become smaller than the original string, 
    your method should return the original string.
*/
// Normal solution is easy but think about inplace
/*
  Given an array of characters, compress it in-place. The length after compression must always be smaller than or equal to the original array. 
  Every element of the array should be a character (not int) of length 1. After you are done modifying the input array in-place, return the new length of the array.
  Follow up:  Could you solve it using only O(1) extra space?
  Example 1:  Input:  ["a","a","b","b","c","c","c"]
              Output:  Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
              Explanation: "aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".
  Example 2:  Input:  ["a"]
              Output:  Return 1, and the first 1 characters of the input array should be: ["a"]
              Explanation:  Nothing is replaced.
  Example 3:
              Input:  ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
              Output:  Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
              Explanation:  Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12". Notice each digit has it's own entry in the array.
  Constraints:
              1 <= chars.length <= 2000
              chars[i].length == 1
              chars[i] is a lower-case English letter, upper-case English letter, digit or a symbol.
*/

// code
      int compress(vector<char>& chars) {
        int i = 0;              // current index
        int index = 0;          // solution index 
        while(i < chars.size()){
            char current = chars[i];
            int count = 1;
            while(++i < chars.size() && chars[i] == current){
                count++;
            }
            chars[index++] = current;
            if(count > 1){
                for(char& ch : to_string(count)){
                    chars[index++] = ch;
                }
            }
        }
        return index;
    }
