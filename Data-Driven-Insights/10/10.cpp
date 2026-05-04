#include <iostream>
#include <utility>
#include <vector>

using namespace std;

const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool dfs(vector<vector<char>> &grid, const string &word,
         const pair<int, int> &size, pair<int, int> posi, int idx) {
  if (idx == word.length())
    return true;
  for (pair<int, int> v : DIRECTIONS) {
    int x = posi.first + v.first;
    int y = posi.second + v.second;
    if (x >= 0 && x < size.first && y >= 0 && y < size.second)
      if (grid[x][y] == word[idx]) {
        char temp = grid[x][y];
        grid[x][y] = '\0';
        int found = dfs(grid, word, size, {x, y}, idx + 1);
        grid[x][y] = temp;
        if (found)
          return true;
      }
  }
  return false;
}

bool wordSearch(vector<vector<char>> &grid, string word) {
  pair<int, int> size = {grid.size(), grid[0].size()};
  for (int i = 0; i < size.first; i++)
    for (int j = 0; j < size.second; j++) {
      if (grid[i][j] == word[0]) {
        char temp = grid[i][j];
        grid[i][j] = '\0';
        int found = dfs(grid, word, size, {i, j}, 1);
        grid[i][j] = temp;
        if (found)
          return true;
      }
    }
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
