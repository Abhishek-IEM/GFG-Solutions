class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        int n = arr.size();
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) mp[arr[i]]++;
        for(auto x : mp)
        {
            int a = x.first;
            int b = x.second;
            if(b > n/3) ans.push_back(a);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
