class Solution {
public:
    string removeOuterParentheses(string s) {
        
        int balance=0;
        string ans;

        for(char c:s)
        {
            if(c=='(')
            {
                if(balance>0){ans=ans+c;}
               balance++;
            }

            else if(c==')')
            {
                balance--;
                 if(balance>0){ans=ans+c;}
            }
        }

        return ans;
    }
};