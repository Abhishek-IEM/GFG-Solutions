//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
public:
    int digits(int n)
    {
        int sum = 0; 
        while(n > 0)
        {
            int d = n % 10;
            sum += d;
            n /= 10;
        }
        return sum;
    }
    
    int sumOfDigits(int N){
        //code here
        int sum = 0;
        for(int i = 1; i <= N; i++)
        {
            if(i <= 9) sum += i;
            else
            {
                int d = digits(i);
                sum += d;
            }
        }
        return sum;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.sumOfDigits(N) << endl;
    
cout << "~" << "\n";
}
    return 0; 
}
// } Driver Code Ends