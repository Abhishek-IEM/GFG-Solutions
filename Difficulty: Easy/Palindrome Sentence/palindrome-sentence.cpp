class Solution {
  public:
    bool isPalinSent(string &s) {
        // code here
        int i = 0, j = s.size() - 1;
        
        while(i < j)
        {
            if(!isalnum(s[i])) i++;
            else if(!isalnum(s[j])) j--;
            else if(tolower(s[i]) == tolower(s[j])) i++, j--;
            else return false;
        }
        
        return true;
    }
};