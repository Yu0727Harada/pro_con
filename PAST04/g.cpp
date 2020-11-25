//
// Created on 2020/11/08.
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
const long long LINF =1e18;
const int INF = 1e9;



int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>mura(n,vector<int>(m,INF));//INF->通路　-1>壁　->訪問可能
    for (int i = 0; i < n; ++i) {
        string s;
        cin>>s;
        for (int j = 0; j < m; ++j) {
            if(s[j] =='#'){
                mura[i][j] = -1;
            }
        }
    }

    int ans = 0;

    vector<pair<int,int>> move = {
                {0,  1},
                {1,  0},
                {-1, 0},
                {0,  -1},
        };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(mura[i][j] == -1){
                auto mura_test = mura;
                mura_test[i][j] = INF;
                queue<vector<int>>q;
                q.push({i,j,0});//x,y,cnt
                mura_test[i][j] = 0;
                while(!q.empty()){
                    int now_x = q.front()[0];
                    int now_y = q.front()[1];
                    int cnt = q.front()[2];
                    q.pop();

                    for (int k = 0; k < 4; ++k) {
                        int next_x = now_x + move[k].first;
                        int next_y = now_y + move[k].second;
                        if(0<= next_x && next_x < n && 0<=next_y && next_y < m){
                            if(mura_test[next_x][next_y] > cnt + 1){
                                mura_test[next_x][next_y] = cnt + 1;
                                q.push({next_x,next_y,cnt+1});
                            }
                        }
                    }
                }
                bool ok = true;
                for (int l = 0; l < n; ++l) {
                    for (int k = 0; k < m; ++k) {
                        if(mura_test[l][k] == INF){
                            ok =false;
                        }
                    }
                }
                if(ok)ans ++;
            }else{
                continue;
            }


        }
    }

    cout<<ans<<endl;
    return 0;
}
