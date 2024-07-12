//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
   void subsetSumsHelper(vector<int> &arr, int n, int index, int currentSum, vector<int> &allSums) {
        if (index == n) {
            allSums.push_back(currentSum);
            return;
        }
        
        // Include the current element in the subset
        subsetSumsHelper(arr, n, index + 1, currentSum + arr[index], allSums);
        
        // Exclude the current element from the subset
        subsetSumsHelper(arr, n, index + 1, currentSum, allSums);
    }
    
    
    
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> allSums;
        subsetSumsHelper(arr, n, 0, 0, allSums);
        sort(allSums.begin(), allSums.end());
        return allSums;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends