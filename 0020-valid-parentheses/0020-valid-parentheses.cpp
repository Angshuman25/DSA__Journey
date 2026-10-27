class Solution {
public:
    bool isValid(string str) {
        stack<char>st;

        for(int i = 0; i < str.size(); i++) {
            if(str[i] == '(' || str[i] == '{' || str[i] == '[') {   // Opening
               st.push(str[i]);
            } else {    // Closing
                if(st.size() == 0) {   // Closing > Opening
                   return false;
                }

                if((st.top() == '(' && str[i] == ')') || (st.top() == '{' && str[i] == '}') || (st.top() == '[' && str[i] == ']')) {
                   st.pop();
                } else {    // No Matches Found
                   return false;
                }
            }
        }

        if(st.size() == 0) {   // String is Valid
           return true;
        } else {   // Opening > Closing
           return false;
        }  
    }
};