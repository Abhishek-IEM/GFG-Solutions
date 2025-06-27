class Solution {
  public:
    int maxLen(string& s) {
        // code here
        int n = s.length();
        int maxi = 0;
        stack<int> st;
        st.push(-1);
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(') st.push(i);
            else{
                st.pop();
                if(!st.empty()) maxi = max(maxi, i - st.top());
                else st.push(i);
            }
        }
        return maxi;
    }
};