class Solution {
public:
    vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};

    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>> q;
        int count = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '@') {
                    q.push({i,j,0,0});
                }
                else if(grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    count++;
                }
            }
        }

        int final_key_status_decimal = (1 << count) - 1;
        int total_masks = (1 << count);

        vector<vector<vector<bool>>> visited(
            m, vector<vector<bool>>(n, vector<bool>(total_masks, false))
        );

        auto start = q.front();
        visited[start[0]][start[1]][0] = true;

        while(!q.empty()) {
            auto temp = q.front();
            q.pop();

            int i = temp[0];
            int j = temp[1];
            int steps = temp[2];
            int current_key_status_decimal = temp[3];

            if(current_key_status_decimal == final_key_status_decimal)
                return steps;

            for(auto &dir : directions) {
                int new_i = i + dir[0];
                int new_j = j + dir[1];

                if(new_i < 0 || new_i >= m || new_j < 0 || new_j >= n)
                    continue;

                char cell = grid[new_i][new_j];

                if(cell == '#')
                    continue;

                int new_key_status = current_key_status_decimal;

                if(cell >= 'A' && cell <= 'F') {
                    int key = cell - 'A';
                    if((new_key_status & (1 << key)) == 0)
                        continue;
                }

                if(cell >= 'a' && cell <= 'f') {
                    int key = cell - 'a';
                    new_key_status |= (1 << key);
                }

                if(!visited[new_i][new_j][new_key_status]) {
                    visited[new_i][new_j][new_key_status] = true;
                    q.push({new_i,new_j,steps + 1,new_key_status});
                }
            }
        }

        return -1;
    }
};