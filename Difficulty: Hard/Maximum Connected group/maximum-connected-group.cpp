//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        vector<vector<int>> group(n, vector<int>(n, -1));
        vector<int> groupSize;
        int groupId = 0;

        // Direction vectors for exploring neighbors
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        // Check if a cell is within bounds
        auto isValid = [&](int x, int y) {
            return x >= 0 && x < n && y >= 0 && y < n;
        };

        // Depth-First Search to find the size of connected components
        function<int(int, int)> dfs = [&](int x, int y) {
            visited[x][y] = 1;
            group[x][y] = groupId;
            int size = 1;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (isValid(nx, ny) && grid[nx][ny] == 1 && !visited[nx][ny]) {
                    size += dfs(nx, ny);
                }
            }
            return size;
        };

        // Identify all groups and their sizes
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int size = dfs(i, j);
                    groupSize.push_back(size);
                    groupId++;
                }
            }
        }

        // If there's no 0 in the grid, return the size of the largest group
        if (groupSize.empty()) return 1;

        int maxSize = *max_element(groupSize.begin(), groupSize.end());

        // Check each cell to see the effect of changing a 0 to 1
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    int newSize = 1;
                    set<int> connectedGroups;
                    for (int k = 0; k < 4; ++k) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (isValid(nx, ny) && grid[nx][ny] == 1) {
                            connectedGroups.insert(group[nx][ny]);
                        }
                    }
                    for (int g : connectedGroups) {
                        newSize += groupSize[g];
                    }
                    maxSize = max(maxSize, newSize);
                }
            }
        }

        return maxSize;
    }
};



//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends