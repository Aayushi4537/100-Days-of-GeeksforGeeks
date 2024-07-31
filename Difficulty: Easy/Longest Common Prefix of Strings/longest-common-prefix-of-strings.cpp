//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
         if (arr.empty()) return "-1";
        
        // Sort the array to find the minimum and maximum strings
        sort(arr.begin(), arr.end());
        
        // The minimum and maximum strings in the sorted array
        string first = arr[0];
        string last = arr[arr.size() - 1];
        
        int i = 0;
        while (i < first.size() && first[i] == last[i]) {
            i++;
        }
        
        string prefix = first.substr(0, i);
        return prefix.empty() ? "-1" : prefix;
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends