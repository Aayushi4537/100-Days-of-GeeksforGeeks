//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void rotate(vector<int> &arr, int n) {
        int ele = arr[n-1]; // Store the last element of the array.
        for (int i = n-1; i > 0; i--) {
            arr[i] = arr[i-1]; // Shift every element one position to the right.
        }
        arr[0] = ele; // Place the last element at the beginning of the array.
    }

    
    void del(vector<int> &arr, int k, int n) {
        auto it = arr.begin() + n - k; // Find the position to delete.
        arr.erase(it); // Remove the element at that position.
    }

    int rotateDelete(vector<int> &arr) {
        int n = arr.size(); // Get the size of the array.
        for (int i = 0; i < n; i++) {
            rotate(arr, n); // Rotate the array.
            del(arr, i+1, n); // Delete the element at the calculated position.
            n = n - 1; // Decrease the size of the array after deletion.
            if (n == 0) // If the array becomes empty, stop the loop.
                break;
        }
        return arr[0]; // Return the remaining element in the array.
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.rotateDelete(arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends