class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
        long long sum = 0, mf = 1;
        
        for(int i = s.size() - 1; i >= 0; i--)
        {
            sum += (s[i] - '0') * (i + 1) * mf;
            mf = mf * 10 + 1;
        }
        
        return sum;
    }
};