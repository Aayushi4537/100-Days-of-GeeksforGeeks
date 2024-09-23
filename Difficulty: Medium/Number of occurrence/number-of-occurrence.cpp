//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int findFirst(int arr[], int n, int x) {
    int start = 0, end = n - 1, result = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == x) {
            result = mid;
            end = mid - 1; // Continue searching on the left side
        } else if (arr[mid] < x) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return result;
}

int findLast(int arr[], int n, int x) {
    int start = 0, end = n - 1, result = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == x) {
            result = mid;
            start = mid + 1; // Continue searching on the right side
        } else if (arr[mid] < x) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return result;
}

int count(int arr[], int n, int x) {
    // Find the first and last occurrences of x
    int first = findFirst(arr, n, x);
    if (first == -1) {
        return 0; // X is not present in the array
    }
    int last = findLast(arr, n, x);
    return last - first + 1; // Number of occurrences
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends