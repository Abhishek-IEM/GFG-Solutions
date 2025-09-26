class Solution {
  public:
 
    void rotateDeque(deque<int>& dq, int type, int k) {
        int n = dq.size();
        if (n == 0) return; // Edge case: empty deque
        
        k = k % n; // Rotating n times brings it back to original
    
        if (type == 1) {  
            // Right Rotation (Clockwise)
            // Move last k elements to the front
            for (int i = 0; i < k; i++) {
                int val = dq.back();
                dq.pop_back();
                dq.push_front(val);
            }
        } 
        else if (type == 2) {  
            // Left Rotation (Anti-Clockwise)
            // Move first k elements to the back
            for (int i = 0; i < k; i++) {
                int val = dq.front();
                dq.pop_front();
                dq.push_back(val);
            }
        }
    }
};
