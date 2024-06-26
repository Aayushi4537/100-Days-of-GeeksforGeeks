//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        int n = matrix.size();
    int m = matrix[0].size();
    int totalCoverage = 0;

    // Define directions for left, right, up, and bottom
    int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 0) {
                for (int d = 0; d < 4; ++d) {
                    int ni = i + directions[d][0];
                    int nj = j + directions[d][1];
                    // Check if the neighboring cell is within bounds and is a 1
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && matrix[ni][nj] == 1) {
                        ++totalCoverage;
                    }
                }
            }
        }
    }

    return totalCoverage;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends