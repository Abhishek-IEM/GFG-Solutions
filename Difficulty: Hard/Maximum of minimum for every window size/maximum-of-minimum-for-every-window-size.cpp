//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
        vector<int>ans(n, 0);
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()] > arr[i])
            {
                int index = st.top();
                st.pop();
                if(st.empty())
                {
                    int range = i;
                    ans[range - 1] = max(ans[range - 1], arr[index]);
                }
                else
                {
                    int range = i - st.top() - 1;
                    ans[range - 1] = max(ans[range - 1], arr[index]);
                }
            }
            st.push(i);
        }
        while(!st.empty())
        {
            int index = st.top();
            st.pop();
            if(st.empty())
            {
                int range = n;
                ans[range - 1] = max(ans[range - 1], arr[index]);
            }
            else
            {
                int range = n - st.top() - 1;
                ans[range - 1] = max(ans[range - 1], arr[index]);
            }
        }
        
        for(int i=n-2;i>=0;i--)
        {
            ans[i] = max(ans[i], ans[i+1]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends