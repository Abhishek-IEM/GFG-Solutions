//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int n = arr.size(), area = 0;
        
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
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends