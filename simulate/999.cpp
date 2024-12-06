
// just simualte logic
class Solution {
public:
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int numRookCaptures(vector<vector<char>>& board) {
        int n = 8;
        int x, y;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'R') {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        int result = 0;
        for (int i = 1; i < n; i++) {
            if (x - i < 0) {
                break;
            }
            if (board[x - i][y] == 'B') {
                break;
            }
            if (board[x - i][y] == 'p') {
                result++;
                break;
            }
        }
        for (int i = 1; i < n; i++) {
            if (x + i >= n) {
                break;
            }
            if (board[x + i][y] == 'B') {
                break;
            }
            if (board[x + i][y] == 'p') {
                result++;
                break;
            }
        }
        for (int i = 1; i < n; i++) {
            if (y - i < 0) {
                break;
            }
            if (board[x][y - i] == 'B') {
                break;
            }
            if (board[x][y - i] == 'p') {
                result++;
                break;
            }
        }
        for (int i = 1; i < n; i++) {
            if (y + i >= n) {
                break;
            }
            if (board[x][y + i] == 'B') {
                break;
            }
            if (board[x][y + i] == 'p') {
                result++;
                break;
            }
        }
        return result;
    }
};