#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
using namespace std;

const int OO = 1000000;

const int MAX = 100;
char grid[MAX][MAX];
int rows, cols;
int total_paths = 0;
int best_path_so_far = OO;
int total_steps = 0;

int dr[] { 0, 0, 1, -1 };
int dc[] { 1, -1, 0, 0 };

bool valid(int r, int c) {
	if (r < 0 || r >= rows || c < 0 || c >= cols)
		return false;	// invalid location

	if (grid[r][c] != '.')
		return false;	// blocked or used (don't cycle)

	return true;
}

void cntWays(int r, int c) {
	if (r == rows - 1 && c == cols - 1) {
		// Only keep the total paths of minimum steps
		if (best_path_so_far > total_steps) {
			best_path_so_far = total_steps;
			total_paths = 1;	// new benchmark
		}
		else if (best_path_so_far == total_steps)
			total_paths += 1;	// found one way of equal min len
		//else bigger ignore
		return;
	}

	for (int dir = 0; dir < 4; ++dir) {
		int nr = r + dr[dir];
		int nc = c + dc[dir];

		if (!valid(nr, nc))
			continue;

		total_steps += 1;
		grid[nr][nc] = 'z';		// update state

		cntWays(nr, nc);		// call

		total_steps -= 1;
		grid[nr][nc] = '.';		// reset/undo state
	}
}

int main() {
	// freopen("data.txt", "rt", stdin);

	cin >> rows >> cols;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cin >> grid[i][j];
		}
	}

	// mark first cell to not revisit
	grid[0][0] = 'z';

	cntWays(0, 0);
	cout <<"Shortest Path Length: " << best_path_so_far<< "\n";
	cout <<"Shortest Paths Count: " << total_paths << "\n";

	return 0;
}

/*


5 7
.......
.xxxxx.
...x...
.x....x
..x.x..


3 3
...
...
...


2 2
..
..


*/
