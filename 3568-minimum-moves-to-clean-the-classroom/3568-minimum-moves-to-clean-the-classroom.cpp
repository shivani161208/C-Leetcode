class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        // Store positions of all litter
        vector<pair<int, int>> litter;

        int sx = 0, sy = 0;

        // Find S and L
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }

                if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();

        // All litter collected
        int fullMask = (1 << k) - 1;

        // bestEnergy[x][y][mask]
        vector<vector<vector<int>>> bestEnergy(
            m,
            vector<vector<int>>(n, vector<int>(1 << k, -1))
        );

        // Queue:
        // {x, y, mask, energy, steps}
        queue<array<int, 5>> q;

        // Initial state
        q.push({sx, sy, 0, energy, 0});

        bestEnergy[sx][sy][0] = energy;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while (!q.empty()) {

            auto [x, y, mask, e, steps] = q.front();
            q.pop();

            // All litter collected
            if (mask == fullMask) {
                return steps;
            }

            // Try 4 directions
            for (int d = 0; d < 4; d++) {

                int nx = x + dx[d];
                int ny = y + dy[d];

                // Outside grid
                if (nx < 0 || nx >= m ||
                    ny < 0 || ny >= n) {
                    continue;
                }

                // Obstacle
                if (classroom[nx][ny] == 'X') {
                    continue;
                }

                // One move costs one energy
                int ne = e - 1;

                // Can't move with zero energy
                if (ne < 0) {
                    continue;
                }

                int nmask = mask;

                // If we reach a litter
                if (classroom[nx][ny] == 'L') {

                    for (int i = 0; i < k; i++) {

                        if (litter[i].first == nx &&
                            litter[i].second == ny) {

                            nmask |= (1 << i);
                            break;
                        }
                    }
                }

                // Reset energy
                if (classroom[nx][ny] == 'R') {
                    ne = energy;
                }

                // If we have already reached this
                // state with equal or greater energy,
                // don't explore it again.
                if (ne <= bestEnergy[nx][ny][nmask]) {
                    continue;
                }

                bestEnergy[nx][ny][nmask] = ne;

                q.push({
                    nx,
                    ny,
                    nmask,
                    ne,
                    steps + 1
                });
            }
        }

        return -1;
    }
};