#include <bits/stdc++.h>
using namespace std;

// face 0 => N, 1 => E, 2 => S, 3 => W
int frontr[4] = {-1, 0, 1, 0};
int frontc[4] = {0, 1, 0, -1};

// visit the cell at loc
void moveForward(vector< int > &v, vector< int > &mz, pair< int, int > &loc, const int &c, const int &face) {
    // move loc to cell forward
    loc.first  += frontr[face];
    loc.second += frontc[face];
    // get the number of times we visited this cell
    int i = mz[loc.first * c + loc.second];
    v[i]--; // the cell we visited i times will now 
    v[i + 1]++; // be visited i + 1 times
    mz[loc.first * c + loc.second]++;
}

bool canMoveForward(const vector< int > &mz, const pair< int, int > &loc, const int &face, const int &b, const int &w) {
    // let (row, col) be a cell in our front where we are facing
    int row = loc.first + frontr[face];
    int col = loc.second + frontc[face];
    // check if we are not hitting a wall
    bool inbound = row >= 0 && row < b && col >= 0 && col < w;
    // return true if we are inbound and not in a close square, false otherwise
    return (inbound) ? (mz[row * w + col] != -1) : false;
}

int main() {
    int b, w, start, r, c, face;
    char cell;
    vector< int > visits, maze;
    // current location (r, c)
    pair< int, int > loc; 

    while (true) {
        visits.clear();
        visits.resize(5);
        maze.clear();

        scanf("%d %d", &b, &w);
        if ((b + w) == 0) break;

        // build maze
        maze.resize(b * w);
        for (r = 0; r < b; r++) {
            for (c = 0; c < w; c++) {
                scanf(" %c", &cell);
                if (cell == '0') {
                    // include this cell to number of unvisited
                    visits[0]++;
                } else {
                    maze[r * w + c] = -1;
                }
            }
        }

        // start with the southwest corner facing east
        start = b - 1; 
        face = 1; loc = make_pair(start, 0);

        // we need to leave start cell before travelling the maze
        // while we can't move forward, turn left
        while (!canMoveForward(maze, loc, face, b, w)) {
            face = (face + 3) % 4;
        }
        moveForward(visits, maze, loc, w, face);
        
        // now let's travel around the maze while we are not at the starting point
        while (loc.first != start || loc.second != 0) {
            face = (face + 1) % 4; // turn right
            // while we can't move forward, turnleft
            while (!canMoveForward(maze, loc, face, b, w)) {
                face = (face + 3) % 4;
            }
            moveForward(visits, maze, loc, w, face);
        }

        for (int i = 0; i < 5; i++)
            printf("%3d", visits[i]);

        printf("\n");
    }

    return 0;
}