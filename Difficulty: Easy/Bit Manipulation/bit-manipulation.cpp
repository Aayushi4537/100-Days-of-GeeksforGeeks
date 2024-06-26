//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int num, int i) {
        
        int z=(1&(num>>i-1));
        cout<<z<<" ";
        
        
        int x=num|(1<<i-1);
        cout<<x<< " ";
        int y =num&(~(1<<i-1));
        cout<<y;
            
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends