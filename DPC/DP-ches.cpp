#include <bits/stdc++.h>
using namespace std;
int main() {
    int numMoves;
    int size;
    int start_row;
    int start_col;
    int end_row,end_col;

    cin>>size;

    cin>>start_row>>start_col>>end_row>>end_col>>numMoves;
    //vector<vector <> >  (,vector<>(,));
    vector<vector<vector<long long>>>DP_table(numMoves+1,vector<vector<long long>>(size,vector<long long>(size,0)));
//    int DP_table[numMoves][size][size];

    long long move_count =0;
    DP_table[0][start_row][start_col] = 1;
    vector<vector<int>>move_array ={
            {-1,-1},
            {-1,0},
            {-1,+1},
            {0,-1},
            {0,+1},
            {+1,-1},
            {+1,0},
            {+1,+1},
            {-2,-1},
            {-2,+1},
            {+2,-1},
            {+2,+1},
            {+1,-2},
            {-1,-2},
            {+1,+2},
            {-1,+2}
    };

    for (int i = 1; i < numMoves + 1; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                move_count = 0;
                for(vector<int>move:move_array){
                    if (0 <= j+move[0] && j+move[0] < size && 0 <= k+move[1] && k+move[1]<size){
                        move_count += DP_table[i-1][j+move[0]][k+move[1]];
                    }
                }
                DP_table[i][j][k] = move_count;
            }
        }
    }
    cout<<DP_table[numMoves][end_row][end_col]<<endl;
}