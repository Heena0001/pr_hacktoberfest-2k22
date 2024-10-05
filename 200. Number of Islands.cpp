#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();

        queue<pair<int, int>> q; // use pair for coordinates
        vector<vector<int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };
        int ans = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ans++; // Found a new island
                    q.push({i, j});
                    grid[i][j] = '0'; // Mark as visited

                    while (!q.empty()) {
                        auto cur = q.front(); q.pop();
                        for (const auto& dir : directions) {
                            int newI = cur.first + dir[0];
                            int newJ = cur.second + dir[1];
                            if (newI >= 0 && newI < m && newJ >= 0 && newJ < n && grid[newI][newJ] == '1') {
                                q.push({newI, newJ});
                                grid[newI][newJ] = '0'; // Mark as visited
                            }
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};
