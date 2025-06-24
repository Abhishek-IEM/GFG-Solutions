class Solution {
  public:
    string maxSubseq(string& s, int k) {
        // code here
        int n = s.size();
        string ans = "";
        
        for(int i = 0; i < n; i++)
        {
            while(!ans.empty() && ans.back() < s[i] && k > 0)
            {
                ans.pop_back();
                k--;
            }
            ans.push_back(s[i]);
        }
        while(k > 0)
        {
            ans.pop_back();
            k--;
        }
        
        return ans;
    }
};
