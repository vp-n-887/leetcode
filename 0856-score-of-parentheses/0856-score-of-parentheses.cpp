class Solution {
public:
    int scoreOfParentheses(string s) {
        stack <int> st;
        st.push(0);

        int i=0;
        while(s[i]!='\0')
        {
            if(s[i]=='(')
            {
                st.push(0);
            }
            else{
                int x=st.top();
                st.pop();

                int score;
                if(x==0)
                {
                    score=1;
                }

                else{
                    score=2*x;
                }

                st.top()=st.top()+score;
            }
            i++;
        }

        return st.top();



        
    }
};