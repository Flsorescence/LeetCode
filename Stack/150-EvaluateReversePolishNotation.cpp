/**150 Evaluate Reverse Polish Notation
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 * Note:
 * Division between two integers should truncate toward zero.
 * The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.
 * Example 1:
 * Input: ["2", "1", "+", "3", "*"]
 * Output: 9
 * Explanation: ((2 + 1) * 3) = 9
 */
 
// 借助栈来实现，每次遇到运算符，就弹出栈顶的两个元素进行运算并将结果保存到栈中 
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int len = tokens.size();
        if(len == 0) return 0;
        stack<int> st;
        for(int i = 0; i < len; i++){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                st.push(std::stoi(tokens[i]));
            }else{
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                if(tokens[i] == "+"){
                    st.push(num1 + num2);
                }else if(tokens[i] == "-"){
                    st.push(num2 - num1);
                }else if(tokens[i] == "*"){
                    st.push(num1 * num2);
                }else{
                    st.push(num2 / num1);
                }
            }
        }
        return st.top();
    }
};