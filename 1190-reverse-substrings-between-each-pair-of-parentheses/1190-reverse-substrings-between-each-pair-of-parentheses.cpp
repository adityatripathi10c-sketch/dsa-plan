class Solution {
public:
    string reverseParentheses(string s) {
        string result="";
        stack<int> brackets;
        for(char c:s){
            if(c=='('){
                brackets.push(result.size());
            }
            else if(c==')'){
             int start=brackets.top();
             brackets.pop();
             reverse(result.begin()+start,result.end());

            }else{
                result.push_back(c);
            }
        }
        return result;
    }
};