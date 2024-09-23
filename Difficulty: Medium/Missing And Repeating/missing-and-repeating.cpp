//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> ans(2);
        
        //decrease value by 1
        
        for(int i=0;i<n;i++) arr[i]--;
        
        //occurrence
        
        for(int i=0;i<n;i++) 
        {
            arr[arr[i]%n]+=n;
        }
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]/n==2) ans[0]=i+1;
            else if(arr[i]/n==0) ans[1]=i+1;
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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends