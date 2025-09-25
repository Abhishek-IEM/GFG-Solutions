class Solution {
  public:
    vector<string> generateBinary(int n) {
        // code here
        vector<string> ans;
        queue<string> q;
        
        q.push("1");
        
        while(n--)
        {
            string temp = q.front();
            q.pop();
            
            ans.push_back(temp);
            
            q.push(temp + "0");
            q.push(temp + "1");
        }
        
        return ans;
    }
};