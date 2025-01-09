//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int n=arr.size();
        vector<int>pre(n,0);
        pre[0]=arr[0];
        for(int i=1;i<n;++i)
            pre[i]=pre[i-1]+arr[i];
        int l=0,r=0,sum=0;
        while(l<n && r<n)
        {
            sum=pre[r]-(l>0?pre[l-1]:0);
            
            if(pre[r]==target || sum==target)
                return {l+1,r+1};
            
            if(sum<target)
                r++;
            else if(sum>target)
                l++;
            
            
            
            //sum+=arr[r];
                
            
            //cout<<sum<<" {"<<l<<" "<<r<<"}"<<"\n";
        }
        return {-1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends