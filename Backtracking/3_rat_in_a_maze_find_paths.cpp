// Rat in a maze problem : https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function template for C++

// L R U D
int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};
string dir = "LRUD";

class Solution
{
public:
    vector<string> findPath(vector<vector<int>> &grid, int n)
    {
        vector<string> paths;
        if (grid[0][0] && grid[n - 1][n - 1])
        {
            grid[0][0] = 0;
            solve(0, 0, grid, paths, "");
        }

        return paths;
    }

    void solve(int r, int c, vector<vector<int>> &grid, vector<string> &paths, string activePath)
    {
        if (r == (int)grid.size() - 1 && c == (int)grid.size() - 1)
        {
            paths.push_back(activePath);
            return;
        }

        for (int d = 0; d < 4; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (!valid(nr, nc, grid))
                continue;

            grid[nr][nc] = 0;
            solve(nr, nc, grid, paths, activePath + dir[d]);
            grid[nr][nc] = 1;
        }
    }

    bool valid(int r, int c, vector<vector<int>> &grid)
    {
        if (r < 0 || r >= (int)grid.size() || c < 0 || c >= (int)grid.size())
            return false;

        if (!grid[r][c])
            return false;

        return true;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends