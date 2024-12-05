//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& a) {
        // code here
        int n = a.size();
        int noz=0;
        int noo=0;
        int notw=0;
        for(int i=0;i<n;i++){
            if(a[i]==0) noz++;
            else if(a[i]==1) noo++;
            else notw++;
        }
        for(int i=0;i<n;i++){
            if(i<noz) a[i]=0;
            else if(i<(noz+noo)) a[i]=1;
            else a[i]=2;
        }
        return;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends