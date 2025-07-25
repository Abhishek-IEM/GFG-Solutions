class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        // code here
        stack<pair<int, int>> st; 
    
        for (int i = 0; i < color.size(); ++i) {
            if (!st.empty()) {
                auto top = st.top();
                if (top.first == color[i] && top.second == radius[i]) {
                    st.pop();
                } else {
                    st.push({color[i], radius[i]});
                }
            } else {
                st.push({color[i], radius[i]});
            }
        }
        
        return st.size();
    }
};