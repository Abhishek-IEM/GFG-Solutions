//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to return sum of upper and lower triangles of a matrix.
    vector<int> sumTriangles(const vector<vector<int> >& matrix, int n)
    {
        // code here
        int upperSum = 0, lowerSum = 0;
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i < j) lowerSum += matrix[i][j];
                if(i > j) upperSum += matrix[i][j];
                if(i == j)
                {
                    lowerSum += matrix[i][j];
                    upperSum += matrix[i][j];
                }
            }
        }
        
        ans.push_back(lowerSum);
        ans.push_back(upperSum);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }
        Solution ob;
        vector<int> result = ob.sumTriangles(matrix,n);
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends