class Solution {
public:
    long long opt(long long num1,long long num2,char op){
        if (op == '+') return num2 + num1;
        if (op == '-') return num2 - num1; // Order matters: num2 comes first!
        if (op == '*') return num2 * num1;
        if (op == '/') return num2 / num1; // Order matters: num2 comes first!
        return 0;
        
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        long long ans=0;
        for(auto i:tokens){
            if (i == "+" || i == "-" || i == "*" || i == "/") {
            if (st.size() >= 2) { 
                long long num1 = st.top(); st.pop(); 
                long long num2 = st.top(); st.pop(); 
                
                 ans = opt(num1, num2, i[0]);
                st.push(ans);
            }
            }
            else{
                st.push(stoi(i));
            }
        }
        return st.top();

    }
};