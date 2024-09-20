//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(vector<long long> &arr) {
        // Your code here
        long long area = 0;
        long long n = arr.size();
        
        stack<int> st;
        
        vector<int> right(n,0);
        vector<int> left(n,0);
        
        //next smallest right
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()] > arr[i])
            {
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
        {
            right[st.top()] = n;
            st.pop();
        }
        
        //next smallest left
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()] > arr[i])
            {
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
        {
            left[st.top()] = -1;
            st.pop();
        }
        for(int i=0;i<n;i++)
        {
            area = max(area, arr[i] * (right[i] - left[i] - 1));
        }
        return area;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends