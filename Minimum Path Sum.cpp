class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
		int visited[m][n];
		int dist[m][n];
		int dir_x[4] = {1, 0};
		int dir_y[4] = {0, 1};

		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				visited[i][j] = 0;
				dist[i][j] = INT_MAX;
			}
		}

		priority_queue<tuple<int, int, int>>minDist;
		dist[0][0] = grid[0][0];

		minDist.push(make_tuple(-dist[0][0], 0, 0));
		while(1) {
			tuple<int, int, int> temp = minDist.top();
			minDist.pop();
			visited[get<1>(temp)][get<2>(temp)] = 1;
			tuple<int, int, int> next;

			for(int i = 0; i < 2; i++) {
				get<1>(next) = get<1>(temp) + dir_x[i];
				get<2>(next) = get<2>(temp) + dir_y[i];

				if(get<1>(next) < 0 || get<2>(next) < 0 || get<1>(next) >= m || get<2>(next) >= n) {
					continue;
				}

				if(!visited[get<1>(next)][get<2>(next)]) {
					if(dist[get<1>(next)][get<2>(next)] > dist[get<1>(temp)][get<2>(temp)] + grid[get<1>(next)][get<2>(next)]) {
						dist[get<1>(next)][get<2>(next)] = dist[get<1>(temp)][get<2>(temp)] + grid[get<1>(next)][get<2>(next)];
						minDist.push(make_tuple(-dist[get<1>(next)][get<2>(next)], get<1>(next), get<2>(next)));
					}
				}
			}
            if (minDist.size() == 0) {
				break;
			}
		}
		// cout << m << " " << n << endl;
		// for(int i = 0; i < m; i++) {
		//     for(int j = 0; j < n; j++) {
		//         cout << dist[i][j] << " ";
		//     }
		//     cout << "\n";
		// }
		return dist[m - 1][n - 1];
	}
};	