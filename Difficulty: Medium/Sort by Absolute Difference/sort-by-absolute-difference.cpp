class Solution {
  public:
    typedef pair<int, pair<int, int>> P;
    void rearrange(vector<int> &arr, int x) {
        // code here
        int n = arr.size();
        priority_queue<P, vector<P>, greater<P>> pq;
        
        for(int i = 0; i < n; i++)
        {
            int diff = abs(arr[i] - x);
            pq.push({diff, {i, arr[i]}});
        }
        
        for(int i = 0; i < n; i++)
        {
            arr[i] = pq.top().second.second;
            pq.pop();
        }
    }
};