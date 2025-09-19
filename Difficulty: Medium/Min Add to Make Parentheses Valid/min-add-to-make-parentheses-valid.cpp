class Solution {
  public:
    int minParentheses(string& s) {
        // code here
        int n = s.length();
        int left = 0, right = 0;
        for(int i = 0;i < n; i++)
        {
            if(s[i] == '(') left++;
            else
            {
                if(left > 0) left--;
                else right++;
            }
        }
        return left + right;
    }
};