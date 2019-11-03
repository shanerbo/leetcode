class TicTacToe {
  private:
    int n = 0;
    vector<vector<int>> r;
    vector<vector<int>> c;
    vector<int> dia;
    vector<int> antiDia;

  public:
    /** Initialize your data structure here. */
    TicTacToe(int n) : r(2, vector<int>(n, 0)), c(2, vector<int>(n, 0)), dia(2, 0), antiDia(2, 0), n(n) {
    }
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        player--;
        r[player][row]++;
        c[player][col]++;
        if (col == row) {
            dia[player]++;
        }
        if (col + row == n - 1) {
            antiDia[player]++;
        }
        if (r[player][row] == n || c[player][col] == n || dia[player] == n || antiDia[player] == n) {
            return ++player;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */