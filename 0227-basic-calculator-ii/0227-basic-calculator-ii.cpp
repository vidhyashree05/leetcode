class Solution {
public:
    int calculate(string s) {
        long long num = 0;
        char sign = '+';
        stack<long long> st;
        
        for(int i = 0; i < s.length(); i++) {
            
            if(isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }
            
            // If operator or last character
            if((!isdigit(s[i]) && s[i] != ' ') || i == s.length() - 1) {
                
                if(sign == '+') {
                    st.push(num);
                }
                else if(sign == '-') {
                    st.push(-num);
                }
                else if(sign == '*') {
                    long long top = st.top();
                    st.pop();
                    st.push(top * num);
                }
                else if(sign == '/') {
                    long long top = st.top();
                    st.pop();
                    st.push(top / num); // truncates toward zero
                }
                
                sign = s[i];
                num = 0;
            }
        }
        
        long long result = 0;
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
        
        return result;
    }
};