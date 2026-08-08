class Solution {
public:

    vector<vector<int>> directions = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1}
    };

    int shortestPath(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        // {row, col, remaining obstacles}
        queue<vector<int>> q;

        q.push({0, 0, k});

        // visited[row][col][remaining_k]
        vector<vector<vector<bool>>> visited(
            m,
            vector<vector<bool>>(
                n,
                vector<bool>(k + 1, false)
            )
        );

        visited[0][0][k] = true;

        int steps = 0;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                vector<int> temp = q.front();
                q.pop();

                int cur_i = temp[0];
                int cur_j = temp[1];
                int obstacle = temp[2];

                // Reached destination
                if (cur_i == m - 1 && cur_j == n - 1) {
                    return steps;
                }

                for (vector<int>& dir : directions) {

                    int new_i = cur_i + dir[0];
                    int new_j = cur_j + dir[1];

                    // Out of bounds
                    if (new_i < 0 || new_i >= m ||
                        new_j < 0 || new_j >= n) {
                        continue;
                    }

                    int newObstacle = obstacle;

                    // Moving into an obstacle
                    if (grid[new_i][new_j] == 1) {

                        if (newObstacle == 0) {
                            continue;
                        }

                        newObstacle--;
                    }

                    // Already visited this exact state
                    if (visited[new_i][new_j][newObstacle]) {
                        continue;
                    }
                    visited[new_i][new_j][newObstacle] = true;
                    q.push({
                        new_i,
                        new_j,
                        newObstacle
                    });
                }
            }
            steps++;
        }
        return -1;
    }
};