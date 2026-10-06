#include<stack>
#include<string>
class Solution {
public:
    bool isValid(string s) {
        stack <char> l;

        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
            {
                l.push(s[i]);
            }

            else 
            {
                if(l.empty()){return false;}
                
                else if(s[i]==')'&&l.top()!='('){return false;}

                else if(s[i]==']'&&l.top()!='['){return false;}

                else if(s[i]=='}'&&l.top()!='{'){return false;}

                l.pop();
            }
        }

        return l.empty();
    }
};