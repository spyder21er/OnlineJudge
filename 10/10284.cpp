#include <bits/stdc++.h>
using namespace std;

void fill_rook(bitset<64> &board, const bitset<64> &pieces, const int &row, const int &col) {
    int ofx[4] = {-1, 0, 1, 0};
    int ofy[4] = {0, -1, 0, 1,};
    for (int i = 0; i < 4; i++) {
        int offrow = row + ofy[i];
        int offcol = col + ofx[i];
        while (offcol < 8 && offcol >= 0  && offrow < 8 && offrow >= 0) {
            if (pieces.test(8 * offrow + offcol)) break;
            board.reset(8 * offrow + offcol);
            offrow += ofy[i];
            offcol += ofx[i];
        }
    }
}

void fill_bishop(bitset<64> &board, const bitset<64> &pieces, const int &row, const int &col) {
    int ofx[4] = {1, 1, -1, -1};
    int ofy[4] = {-1, 1, 1, -1};
    for (int i = 0; i < 4; i++) {
        int offrow = row + ofy[i];
        int offcol = col + ofx[i];
        while (offcol < 8 && offcol >= 0  && offrow < 8 && offrow >= 0) {
            if (pieces.test(8 * offrow + offcol)) break;
            board.reset(8 * offrow + offcol);
            offrow += ofy[i];
            offcol += ofx[i];
        }
    }
}

void fill_knight(bitset<64> &board, const int &row, const int &col) {
    int ofx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int ofy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    for (int i = 0; i < 8; i++) {
        if ((row + ofy[i]) >= 0 && (row + ofy[i]) < 8) {
            if ((col + ofx[i]) >= 0 && (col + ofx[i]) < 8) {
                board.reset(8 * (row+ofy[i]) + col + ofx[i]);
            }
        }
    }
}

void fill_pawn(bitset<64> &board, int color, const int &row, const int &col) {
    // for color 0 = white, 1 = black
    int ofy[2] = {-1, 1};
    int offrow = row + ofy[color];
    if (offrow < 8 && offrow >= 0) {
        if ((col + 1) < 8)
            board.reset(8 * (row+ofy[color]) + col + 1);
        if ((col - 1) >= 0)
            board.reset(8 * (row+ofy[color]) + col - 1);
    }
}

void fill_king(bitset<64> &board, const int &row, const int &col) {
    int ofx[8] = {-1,  0,  1, 1 ,1, 0, -1, -1};
    int ofy[8] = {-1, -1, -1, 0, 1, 1,  1,  0};
    for (int i = 0; i < 8; i++) {
        int offcol = col + ofx[i];
        int offrow = row + ofy[i];
        if (offcol < 8 && offcol >= 0 && offrow < 8 && offrow >= 0) {
            board.reset(8 * (offrow) + offcol);
        }
    }
}

int main() {
    bitset<64> board;
    bitset<64> pieces;
    string s, token;
    int pos, row, col;
    char piece;
    vector<pair<int, int> > rooks;
    vector<pair<int, int> > bishops;

    while (getline(cin, s)) {
        board.set();
        pieces.reset();
        rooks.clear();
        bishops.clear();
        row = 0;
        while (s.length()) {
            pos = s.find("/");
            if (pos == string::npos) {
                token = s;
                s.erase();
            } else {
                token = s.substr(0, pos);
                s.erase(0, pos + 1);
            }
            
            col = 0;
            for (int i = 0; i < token.length(); i++) {
                if (!isalpha(token[i])) {
                    col += (int) (token[i] - '0');
                } else {
                    board.reset(row * 8 + col);
                    pieces.set(row * 8 + col);
                    piece = tolower(token[i]);

                    if (piece == 'p') {
                        // for color 0 = white, 1 = black
                        fill_pawn(board, token[i] == 'p', row, col);
                    } else if (piece == 'r') {
                        rooks.push_back(make_pair(row, col));
                    } else if (piece == 'n') {
                        fill_knight(board, row, col);
                    } else if (piece == 'b') {
                        bishops.push_back(make_pair(row, col));
                    } else if (piece == 'q') {
                        rooks.push_back(make_pair(row, col));
                        bishops.push_back(make_pair(row, col));
                    } else {
                        fill_king(board, row, col);
                    }
                    col++;
                }
            }
            row++;
        }

        for (auto x : rooks) {
            fill_rook(board, pieces, x.first, x.second);
        }

        for (auto x : bishops) {
            fill_bishop(board, pieces, x.first, x.second);
        }
        
        printf("%d\n", (int) board.count());
    }
    return 0;
}