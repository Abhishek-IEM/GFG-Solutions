//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        // Your code here
        vector<long long> a(2*n, -1);
        vector<long long> ans(2*n, -1);
        stack<int> st;
        for(int i=0;i<2*n;i++)
        {
            a[i] = arr[i%n];
        }
        for(int i=0;i<2*n;i++)
        {
            while(!st.empty() && a[st.top()] < a[i])
            {
                ans[st.top()] = a[i];
                st.pop();
            }
            st.push(i);
        }
        vector<long long> x(n,-1);
        for(int i=0;i<n;i++)
        {
            x[i] = ans[i];
        }
        return x;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends