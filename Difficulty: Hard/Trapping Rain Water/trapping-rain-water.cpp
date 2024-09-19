//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

    // Function to find the trapped water between the blocks.
  public:
    long long trappingWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        long long water=0,index=0,maxheight=arr[0],leftmax=0,rightmax=0;
        
        for(int i=1;i<n;i++)
        {
            if(maxheight<arr[i])
            {
                maxheight=arr[i];
                index=i;
            }
        }
        
        for(int i=0;i<index;i++)
        {
            if(leftmax>arr[i])
            water+=leftmax-arr[i];
            else leftmax=arr[i];
        }
        
        for(int i=n-1;i>index;i--)
        {
            if(rightmax>arr[i])
            water+=rightmax-arr[i];
            else rightmax=arr[i];
        }
        return water;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    // testcases
    cin >> t;

    while (t--) {
        int n;

        // size of array
        cin >> n;

        vector<int> a(n);

        // adding elements to the array
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution obj;
        // calling trappingWater() function
        cout << obj.trappingWater(a) << endl;
    }

    return 0;
}
// } Driver Code Ends