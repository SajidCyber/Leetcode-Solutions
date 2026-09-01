class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size(), l_cnt = 0, sx = -1, sy = -1;
        vector<pair<int, int>> litters;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') sx = i, sy = j;
                else if (classroom[i][j] == 'L') litters.push_back({i, j});
            }
        }
        l_cnt = litters.size();
        auto get_litter_id = [&](int r, int c) {
            for (int k = 0; k < l_cnt; ++k)
                if (litters[k].first == r && litters[k].second == c) return k;
            return -1;
        };

        vector<vector<vector<int>>> best(m, vector<vector<int>>(n, vector<int>(1 << l_cnt, -1)));
        queue<tuple<int, int, int, int>> q;

        q.push({sx, sy, 0, energy});
        best[sx][sy][0] = energy;

        int steps = 0, dirs[5] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c, mask, e] = q.front();
                q.pop();

                if (mask == (1 << l_cnt) - 1) return steps;
                if (e == 0) continue;

                for (int d = 0; d < 4; ++d) {
                    int nr = r + dirs[d], nc = c + dirs[d + 1];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n || classroom[nr][nc] == 'X') continue;

                    int nmask = mask, ne = e - 1;
                    if (classroom[nr][nc] == 'L') {
                        int id = get_litter_id(nr, nc);
                        if (id != -1) nmask |= (1 << id);
                    } else if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    if (ne > best[nr][nc][nmask]) {
                        best[nr][nc][nmask] = ne;
                        q.push({nr, nc, nmask, ne});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};