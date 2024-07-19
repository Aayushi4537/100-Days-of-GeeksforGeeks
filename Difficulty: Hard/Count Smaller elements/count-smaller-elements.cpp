//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++

class Solution {
  public:
    int getSum(vector<int>& BIT, int index) {
    int sum = 0;
    index = index + 1; // BIT array is 1-indexed

    while (index > 0) {
        sum += BIT[index];
        index -= index & (-index);
    }

    return sum;
}

// A utility function to update BIT for an index by a value
void updateBIT(vector<int>& BIT, int n, int index, int value) {
    index = index + 1; // BIT array is 1-indexed

    while (index <= n) {
        BIT[index] += value;
        index += index & (-index);
    }
}
    vector<int> constructLowerArray(vector<int> &arr) {
        // code here
        int n = arr.size();
    vector<int> result(n);

    // Create a sorted copy of arr to get the ranks
    vector<int> sortedArr(arr);
    sort(sortedArr.begin(), sortedArr.end());

    // Coordinate compression: map elements to their ranks
    vector<int> ranks(n);
    for (int i = 0; i < n; i++) {
        ranks[i] = lower_bound(sortedArr.begin(), sortedArr.end(), arr[i]) - sortedArr.begin();
    }

    // Initialize BIT array
    vector<int> BIT(n + 1, 0);

    // Process elements from right to left
    for (int i = n - 1; i >= 0; i--) {
        result[i] = getSum(BIT, ranks[i] - 1);
        updateBIT(BIT, n, ranks[i], 1);
    }

    return result;

        
    }
};

//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends