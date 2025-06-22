class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : arr) {
            if (minHeap.size() < k)
                minHeap.push(num);
            else if (num > minHeap.top()) {
                minHeap.pop();
                minHeap.push(num);
            }
        }
    
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }
    
        
        sort(result.rbegin(), result.rend());
        return result;
    }
};