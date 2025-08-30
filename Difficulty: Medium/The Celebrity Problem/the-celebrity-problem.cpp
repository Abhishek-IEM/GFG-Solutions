// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        stack<int> st;
        
        // Push all people
        for(int i = 0; i < n; i++) st.push(i);
        
        // Eliminate until one remains
        while(st.size() > 1) {
            int first = st.top(); st.pop();
            int second = st.top(); st.pop();
            
            if(mat[first][second] == 1) st.push(second);  // first knows second → first not celeb
            else st.push(first);  // first doesn't know second → second not celeb
        }
        
        if(st.empty()) return -1;
        
        int candidate = st.top();
        
        // Verify candidate
        for(int i = 0; i < n; i++) {
            if(i != candidate) {
                if(mat[candidate][i] == 1 || mat[i][candidate] == 0) return -1;
            }
        }
        
        return candidate;
    }
};
