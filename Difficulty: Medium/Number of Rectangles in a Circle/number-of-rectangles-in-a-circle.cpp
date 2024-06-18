//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int rectanglesInCircle(int r) {
        // code here
        int count = 0;
    
    for (int length = 1; length <= 2 * r; ++length) {
        for (int width = 1; width <= 2 * r; ++width) {
            // Check if the rectangle can fit inside the circle
            if ((length / 2.0) * (length / 2.0) + (width / 2.0) * (width / 2.0) <= r * r) {
                count++;
            }
        }
    }
    return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.rectanglesInCircle(n);
        cout << ans << "\n";
    }
}
// } Driver Code Ends