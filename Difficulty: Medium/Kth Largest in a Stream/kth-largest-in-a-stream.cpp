//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        // code here
        vector<int> ans(n, -1);
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(long long i = 0; i < k; i++) pq.push(arr[i]);
        ans[k - 1] = pq.top();

        for(long long i = k; i < n; i++)
        {
            if(arr[i] > pq.top()){
                pq.push(arr[i]);
                pq.pop();
            }
            ans[i] = pq.top();
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends