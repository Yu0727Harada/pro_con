//
// Created on 2021/02/06.
//

#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <ios>
#include <iomanip>
#include <numeric>

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
const long long LINF =1e18;
const int INF = 1e9;



int main() {
    int h,w;
    cin>>h>>w;

    vvi map(h*3,vi(w*3,0));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            char c;
            cin>>c;
            if(c == '#'){
                map[i*3][j*3] = 1;

                map[i*3+1][j*3] = 1;
                map[i*3+2][j*3] = 1;


                map[i*3][j*3+1] = 1;
                map[i*3][j*3+2] = 1;

                map[i*3+1][j*3+1] = 1;
                map[i*3+2][j*3+2] = 1;

                map[i*3+1][j*3+2] = 1;
                map[i*3+2][j*3+1] = 1;
            }
        }
    }

//    for (int i = 0; i < h*3; ++i) {
//        for (int j = 0; j < w*3; ++j) {
//            cout<<map[i][j];
//        }
//        cout<<endl;
//    }
    queue<vi>q;

    vector<pair<int,int>>move_array = {
            {1,1},
            {-1,-1},
            {1,-1},
            {-1,1},
            {1,  0},
                {-1, 0},
                {0,  1},
                {0,-1}
                       };
    vector<pair<int,int>> move = {
            {0,  1},
            {1,  0},
            {-1, 0},
            {0,  -1},
    };
    for (int i = 0; i < h*3; ++i) {
        for (int j = 0; j < w*3; ++j) {
            int x = i;
            int y = j;

            for (int k = 0; k < 8; ++k) {
                int next_x = x + move_array[k].first;
                int next_y = y + move_array[k].second;
                if(next_x >= 0 && next_x < h*3 && next_y >= 0 && next_y < w*3){
                    if(map[next_x][next_y] == 1 && map[x][y] == 0){
                        map[x][y] = -1;
                        if(q.empty()){
                            q.push({x,y,0,-1});
                        }
                    }
                }
            }
        }
    }


    int ans = 0;
    while(!q.empty()){
        int x = q.front()[0];
        int y = q.front()[1];
        int cnt = q.front()[2];
        int angle = q.front()[3];
        q.pop();
        ans = max(cnt,ans);

        for (int k = 0; k < 4; ++k) {
            int next_x = x + move[k].first;
            int next_y = y + move[k].second;
            if(next_x >= 0 && next_x < h*3 && next_y >= 0 && next_y < w*3){
                if(map[next_x][next_y] == -1){
                    if(angle != k){
                        cnt ++;
                    }
                    q.push({next_x,next_y,cnt,k});
                    map[next_x][next_y] = -2;
                    break;
                }
            }
        }
    }

    cout<<ans<<endl;
    return 0;

}




