#include <iostream>
#include <utility>
#include <vector>

using namespace std;

const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool dfs(vector<vector<char>> &grid, const string &word, const int m,
         const int n, int x, int y, int idx) {
  if (idx == word.length())
    return true;
  if (x < 0 || x >= m || y < 0 || y >= n)
    return false;
  if (grid[x][y] != word[idx])
    return false;
  char temp = grid[x][y];
  grid[x][y] = '\0';
  for (const auto &v : DIRECTIONS)
    if (dfs(grid, word, m, n, x + v.first, y + v.second, idx + 1)) {
      grid[x][y] = temp;
      return true;
    }
  grid[x][y] = temp;
  return false;
}

bool wordSearch(vector<vector<char>> &grid, string word) {
  int m = grid.size();
  int n = grid[0].size();
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (dfs(grid, word, m, n, i, j, 0))
        return true;
  return false;
}

int main() {
  cout << "It's Showtime Folks!" << endl;
  vector<vector<char>> grid = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  string msg = wordSearch(grid, "ABCCED") ? "Word found" : "Word not found";
  cout << msg << endl;
  msg = wordSearch(grid, "ABCESCFSADEE") ? "Word found" : "Word not found";
  cout << msg << endl;
  grid = {{'a', 'a'}};
  msg = wordSearch(grid, "aaa") ? "Word found" : "Word not found";
  cout << msg << endl;
  return 0;
}
