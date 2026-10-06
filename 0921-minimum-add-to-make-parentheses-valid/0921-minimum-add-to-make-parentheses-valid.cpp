class Solution {
public:
    int minAddToMakeValid(string s) {
        stack <char> st;
        int score=0;
    
        int i=0;
        while(s[i]!='\0')
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
               score++;
            }

            if(s[i]==')')
            {
                if(st.empty()){score++;}
                else{st.pop(); score--;}
               
            }
            i++;
        }

        int y=score;

        if(y<0){return -y;}
        return y;
    }
};