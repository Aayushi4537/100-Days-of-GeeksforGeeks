//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        map<int, int> mp;
    for (int i = 0; i < arr.size(); i++) {
        mp[arr[i]]++;
    }

    int maxFreq = 0;
    for (auto& it : mp) {
        maxFreq = max(maxFreq, it.second);
    }
    vector<vector<int>> adj(maxFreq + 1);
    for (auto& it : mp) {
        adj[it.second].push_back(it.first);
    }

    // Step 3: Prepare the result in sorted order
    vector<int> ans;
    for (int i = maxFreq; i >= 1; i--) {
        if (!adj[i].empty()) {
            sort(adj[i].begin(), adj[i].end());
            for (int j = 0; j < adj[i].size(); j++) {
                for (int k = 0; k < i; k++) {
                    ans.push_back(adj[i][j]);
                }
            }
        }
    }
    
    return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends