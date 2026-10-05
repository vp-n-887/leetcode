class Solution {
public:
    int longestValidParentheses(string s) {
        int count=0;

        stack<int> st;

        st.push(-1);

        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='('){st.push(i);}

            else{
                st.pop();

                if(st.empty()){
                    st.push(i);
                }

                else{
                    count=max(count,i-st.top());
                }
            }
        }

return count;
        
    }
};