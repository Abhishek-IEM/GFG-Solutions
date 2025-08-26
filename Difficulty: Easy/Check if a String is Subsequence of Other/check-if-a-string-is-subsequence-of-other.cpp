class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        // code here
        int n = s1.length(), m = s2.length();
        int i = 0, j = 0, count = 0;
        
        while(i < n && j < m)
        {
            if(s1[i] == s2[j])
            {
                i++;
                j++;
                count++;
            }
            else j++;
        }
        return count == n;
    }
};