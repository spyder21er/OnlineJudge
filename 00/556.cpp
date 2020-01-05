#include <bits/stdc++.h>
using namespace std;

// face 0 => N, 1 => E, 2 => S, 3 => W
int frontr[4] = {-1, 0, 1, 0};
int frontc[4] = {0, 1, 0, -1};

// visit the cell at loc
void visit(vector< int > &v, vector< int > &mz, const pair< int, int > &loc, const int &c) {
    int i = mz[loc.first * c + loc.second];
    v[i]--;
    v[i + 1]++;
    mz[loc.first * c + loc.second]++;
}

bool canMoveForward(const vector< int > mz, const pair< int, int > &loc, const int &face, const int &b, const int &w) {
    int row = loc.first + frontr[face];
    int col = loc.second + frontc[face];
    bool inbound = row >= 0 && row < b && col >= 0 && col < w;
    return (inbound) ? (mz[row * w + col] != -1) : false;
}

int main()
{
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
        // while we can't move forward, turnleft
        while (!canMoveForward(maze, loc, face, b, w)) {
            face = (face + 3) % 4;
        }
        // move forward
        loc.first  += frontr[face];
        loc.second += frontc[face];
        // visit this cell
        visit(visits, maze, loc, w);
        
        // now let's travel around the maze while we are not at the starting point
        while (loc.first != start || loc.second != 0) {
            // turnright
            face = (face + 1) % 4;
            // while we can't move forward, turnleft
            while (!canMoveForward(maze, loc, face, b, w)) {
                face = (face + 3) % 4;
            }
            // move forward
            loc.first += frontr[face];
            loc.second += frontc[face];
            // visit this cell
            visit(visits, maze, loc, w);
        }

        for (int i = 0; i < 5; i++)
            printf("%3d", visits[i]);

        cout << endl;
    }

    return 0;
}