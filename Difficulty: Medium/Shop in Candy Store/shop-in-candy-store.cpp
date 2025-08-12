class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& candies, int k) {
        // Code here
        int N = candies.size();
        sort(candies.begin(), candies.end());
        int min = 0, max = 0;
        int i = 0, j = N - 1;
        
        while(i <= j)
        {
            min += candies[i];
            i++;
            j -= k;
        }
        
        i = N - 1, j = 0;
        
        while(i >= j)
        {
            max += candies[i];
            i--;
            j += k;
        }
        vector<int> ans(2);
        ans[0] = min;
        ans[1] = max;
        return ans;
    }
};