class Solution {
public:
    int myAtoi(string s) {
        stringstream ss(s);
        string token;
        
        // BUG FIX 1: Only take the FIRST token. 
        // If s = "4193 with words", the first token is "4193".
        if (!(ss >> token)) return 0; 

        // BUG FIX 2: Check sign on the cleaned 'token', not 's'
        int sign = 1;
        int start_idx = 0;
        if (token[0] == '-') {
            sign = -1;
            start_idx = 1; // Start reading numbers after the sign
        } else if (token[0] == '+') {
            sign = 1;
            start_idx = 1; // Start reading numbers after the sign
        }
        
        // If it starts with a letter after skipping leading whitespace, it's invalid
        if (start_idx < token.length() && isalpha(token[start_idx])) return 0;

        // BUG FIX 3: Find where digits end using !isdigit instead of isalpha
        long long idx = token.length();
        for (long long i = start_idx; i < token.length(); i++) {
            if (!isdigit(token[i])) { // Stops at letters, symbols, periods, etc.
                idx = i;
                break;
            }
        }
            
        long long num = 0;
        // BUG FIX 4: Start loop from 'start_idx' to avoid processing the sign character
        for (int i = start_idx; i < idx; i++) {
            num = num * 10 + (token[i] - '0');
            
            // BUG FIX 5: Correct the overflow bounds check
            if (sign == 1 && num > INT_MAX) return INT_MAX;
            if (sign == -1 && num > 2147483648LL) return INT_MIN; // 2147483648 is absolute value of INT_MIN
        }
        
        return num * sign;
    }
};
