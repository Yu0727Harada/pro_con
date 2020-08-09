//
// Created on 2020/06/08.
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
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;


int main() {
    int n;
    cin>>n;
    vector<pair<int,int>>poll(n);
    vector<vector<bool>>g(10002,vector<bool>(10002,false));
    for (int i = 0; i < n; ++i) {
        int x,y;
        cin>>x>>y;
        poll[i] = {x,y};
        g[x][y] = 1;

    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            double e_1 = (pow((poll[i].first - poll[j].first),2) + pow((poll[i].second - poll[j].second),2));
            if(e_1 <= ans)continue;
            int x_m = (poll[j].first - poll[i].first);
            int y_m = (poll[j].second - poll[i].second);
            if(poll[i].second - x_m >= 0 && poll[i].first + y_m >= 0) {
                if (g[poll[i].first + y_m][poll[i].second - x_m] == true) {
                    int x_3 = poll[i].first + y_m;
                    int y_3 = poll[i].second - x_m;
                    if(x_3 + x_m >= 0 && y_3 + y_m >= 0){
                        if (g[x_3 + x_m][y_3 + y_m] == true) {
                            //update
                            ans = max((int) e_1, ans);
                            break;
                        }
                    }
                }
            }
            if(poll[j].second - x_m >= 0 && poll[j].first + y_m >= 0){
                if(g[poll[j].first + y_m][poll[j].second - x_m] == true){
                    int x_3 = poll[j].first + y_m;
                    int y_3 = poll[j].second - x_m;
                    if(x_3 + x_m >= 0 && y_3 + y_m >= 0) {
                        if (g[x_3 + x_m][y_3 + y_m] == true) {
                            //update

                            ans = max((int) e_1, ans);
                            break;
                        }
                    }
                }
            }
            if(poll[i].first - y_m >= 0 && poll[i].second + x_m >= 0){
                if(g[poll[i].first - y_m][poll[i].second + x_m] == true){
                    int x_3 = poll[i].first - y_m;
                    int y_3 = poll[i].second + x_m;
                    if(x_3 + x_m >= 0 && y_3 + y_m >= 0){
                        if(g[x_3 + x_m][y_3 + y_m] == true){
                            //update

                            ans = max((int)e_1, ans);
                            break;
                        }
                    }
                }
            }
            if(poll[j].first - y_m >= 0 && poll[j].second + x_m >= 0){
                if(g[poll[j].first - y_m][poll[j].second + x_m] == true){
                    int x_3 = poll[j].first - y_m;
                    int y_3 = poll[j].second + x_m;
                    if(x_3 + x_m >= 0 && y_3 + y_m >= 0) {
                        if (g[x_3 + x_m][y_3 + y_m] == true) {
                            //update

                            ans = max((int) e_1, ans);
                            break;
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}

/*
ビットで持っておくとメモリが超えないようになる。
 広い範囲のグリッドの状態を持って置きたい時はvector<bool>でとるとメモリが軽くなる
 */
