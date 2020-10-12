/*
  Description : Given a real number between 0 and 1 (e.g., 0.72) that is passed in as a double, print the binary representation. 
                If the number cannot be represented accurately in binary with at most 32 characters, print "ERROR:'
*/

// We have 2 approaches 1st is multiply n by 2 and see whether result is > 1 or not and other is compare number with .5 then .25 so on

// code
  string toBinary(double n) { 
    if (n >= 1 || n <= 0) 
        return "ERROR"; 
    string answer; 
    answer.append("0."); 
    while (n > 0){ 
        if (answer.length() >= 32) 
                return "ERROR"; 
            double b = n * 2; 
            if (b >= 1){ 
                answer.append("1"); 
                n = b - 1; 
            } 
            else{ 
                answer.append("0"); 
                n = b; 
            } 
        } 
        return answer; 
} 

// code
  string toBinary(double n){ 
    if (n >= 1 || n <= 0) 
        return "ERROR"; 
    string answer; 
    double frac = 0.5; 
    answer.append("0."); 
    while (n > 0){ 
        if (answer.length() >= 32) 
            return "ERROR"; 
        if (n >= frac){ 
            answer.append("1"); 
            n = n - frac; 
        } 
        else
            answer.append("0"); 
        frac /= 2; 
    } 
    return answer; 
}
