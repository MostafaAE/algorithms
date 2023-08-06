#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
using namespace std;

const int MAX = 100;
char grid[MAX][MAX];
int rows, cols;
int total_paths = 0;

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
		total_paths += 1;	// found one way
		return;
	}

	for (int dir = 0; dir < 4; ++dir) {
		int nr = r + dr[dir];
		int nc = c + dc[dir];

		if (!valid(nr, nc))
			continue;

		grid[nr][nc] = 'z';		// update state
		cntWays(nr, nc);		// call
		grid[nr][nc] = '.';		// reset/undo state
	}
}

int main() {
	//freopen("data.txt", "rt", stdin);

	cin >> rows >> cols;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cin >> grid[i][j];
		}
	}

	// mark first cell to not revisit
	grid[0][0] = 'z';

	cntWays(0, 0);
	cout << total_paths << "\n";

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
