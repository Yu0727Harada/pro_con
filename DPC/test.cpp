#include <bits/stdc++.h>

using namespace std;
int main() {
    int N;
    cin>>N;
    //Black=0,white =1, None=-1
    vector<vector <int> > board (9,vector<int>(9,-1));

    board[4][4] = 1;
    board[4][5] = 0;
    board[5][4] = 0;
    board[5][5] = 1;

    vector<vector<int>>move_array = {
            {1,  0},
            {-1, 0},
            {0,  1},
            {0,-1},
            {1,1},
            {-1,-1},
            {1,-1},
            {-1,1}
    };

    for (int i = 0; i < N; ++i) {
        string player;
        int x,y=0;
        cin>>player>>x>>y;

        if (player == "B") {
            board[x][y] = 0;
        }else{
            board[x][y] = 1;
        }
        for(vector<int>move:move_array){
            int counter =1;
            if (x+move[0]*counter > 0 && x+move[0]*counter <= 8 && y+move[1]*counter>0 && y+move[1]*counter <=8){
                while (board[x + move[0] * counter][y + move[1] * counter] != board[x][y] and board[x + move[0] * counter][y + move[1] * counter] != -1) {
                    if (x+move[0]*(counter+1) > 0 && x+move[0]*(counter+1) <= 8 && y+move[1]*(counter+1)>0 && y+move[1]*(counter+1) <=8) {
                        counter++;
                    }else break;
                }
                if (board[x + move[0] * counter][y + move[1] * counter] != -1 and board[x + move[0] * counter][y + move[1] * counter] == board[x][y]){
                    for (int j = 1; j < counter; ++j) {
                        board[x + move[0]*j][y + move[1]*j] = board[x][y];
                    }

                }
            }

        }

    }

    int black_num=0;
    int white_num=0;

    for (int j = 0; j < 9; ++j) {
        for (int i = 0; i < 9; ++i) {
            if(board[j][i]==0) black_num++;
            else if(board[j][i]==1) white_num++;
        }

    }
    if(black_num>white_num){
        cout<<std::setfill('0')<<std::right<<std::setw(2)<<black_num;
        cout<<"-";
        cout<<std::setfill('0')<<std::right<<std::setw(2)<<white_num;
        cout<<" The black won!"<<endl;
    }
    else if(black_num<white_num){
        cout<<std::setfill('0')<<std::right<<std::setw(2)<<black_num;
        cout<<"-";
        cout<<std::setfill('0')<<std::right<<std::setw(2)<<white_num;
        cout<<" The white won!"<<endl;
    }
    else {
        cout<<std::setfill('0')<<std::right<<std::setw(2)<<black_num;
        cout<<"-";
        cout<<std::setfill('0')<<std::right<<std::setw(2)<<white_num;
        cout<<" Draw!"<<endl;
    }


}