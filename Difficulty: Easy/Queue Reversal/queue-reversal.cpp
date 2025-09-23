class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        stack<int> st;
        while(q.size() > 0)
        {
            st.push(q.front());
            q.pop();
        }
        while(st.size()  > 0)
        {
            q.push(st.top());
            st.pop();
        }
    }
};