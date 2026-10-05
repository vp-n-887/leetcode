class Solution {
public:
    bool alphanum(char a)
    {
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9')){return true;}
        return false;
    }
    bool isPalindrome(string s) {
        int left=0;
        int right=s.length()-1;

        while(left<right)
        {
            while(left<right&&!alphanum(s[left])){left++;}

            while(left<right&&!alphanum(s[right])){right--;}

            if(tolower(s[left])!=tolower(s[right])){return false;}

            left++;
            right--;
        }

        return true;
    }
};
