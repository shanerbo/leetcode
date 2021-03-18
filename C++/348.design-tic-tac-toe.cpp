/*
 * @lc app=leetcode id=348 lang=cpp
 *
 * [348] Design Tic-Tac-Toe
 *
 */
#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;
// @lc code=start
class TicTacToe {
public:
  /** Initialize your data structure here. */
  TicTacToe(int n) {
    v = vector(n, vector(n, '0'));
    h = vector(n, vector(n, '0'));
    d = vector(n, '0');
    ad = vector(n, '0');
    size = n;
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
    v[col][row] = player - '0';
    h[row][col] = player - '0';
    if (row == col) {
      d[row] = player - '0';
    }
    if (row + col + 1 == size) {
      ad[row] = player - '0';
    }
    if (check(player, row, col)) {
      return player;
    }
    return 0;
  }
  bool check(int player, int row, int col) {
    bool r_h = true, r_v = true, r_d = true, r_ad = true;
    for (auto const &c : h[row]) {
      if (c != player - '0') {
        r_h = false;
        break;
      }
    }
    for (auto const &c : v[col]) {
      if (c != player - '0') {
        r_v = false;
        break;
      }
    }
    for (auto const &c : d) {
      if (c != player - '0') {
        r_d = false;
        break;
      }
    }
    for (auto const &c : ad) {
      if (c != player - '0') {
        r_ad = false;
        break;
      }
    }
    return r_h or r_v or r_d or r_ad;
  }

private:
  vector<vector<char>> h; // horizontal
  vector<vector<char>> v; // vertical
  vector<char> d;         // diagnal
  vector<char> ad;        // anti-diagnal
  size_t size;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
// @lc code=end
