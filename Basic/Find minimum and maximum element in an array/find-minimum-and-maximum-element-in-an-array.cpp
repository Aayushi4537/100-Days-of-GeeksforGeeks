//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    pair<long long, long long> getMinMax(long long a[], int n) {
        // code here
       long long  int minElement = INT_MAX;
    long long int maxElement = INT_MIN;
    
    // Traverse the array and update minElement and maxElement
    for (int i = 0; i < n; ++i) {
        if (a[i] < minElement) {
            minElement = a[i];
        }
        if (a[i] > maxElement) {
            maxElement = a[i];
        }
    }
    
    return {minElement, maxElement};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        
        Solution ob;
        pair<long long, long long> pp = ob.getMinMax(a, n);
        
        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}
// } Driver Code Ends