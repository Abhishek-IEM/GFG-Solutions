class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> mp;
        int count = 0, sum = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            if(sum == k) count++;
            if(mp.find(sum - k) != mp.end()) count += mp[sum - k];
            mp[sum]++;
        }
        return count;
    }
};