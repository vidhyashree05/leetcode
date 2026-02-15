class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string token : tokens) {

            // If operator
            if (token == "+" || token == "-" ||
                token == "*" || token == "/") {

                int b = st.top(); st.pop();  // second operand
                int a = st.top(); st.pop();  // first operand

                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(a / b);
            }
            else {
                // Convert string to integer
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
