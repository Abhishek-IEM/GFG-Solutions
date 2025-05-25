class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        unordered_set<int> st;
        
        int n = arr.size();
        
        for(int i = 0; i < n; i++) st.insert(arr[i] * arr[i]);
        
        for(int i = 0; i < n; i++)
        {
            int a = arr[i];
            for(int j = i + 1; j < n; j++)
            {
                int b = arr[j];
                if(st.count(a * a + b * b)) return true;
            }
        }
        
        return false;
    }
};