//
// Created on 2020/07/10.
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
    int w,h;
    cin>>w>>h;
    vector<vector<int>>map(w + 2,vector<int>(h + 2,false));

    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            int t;
            cin>>t;
            map[j][i] = -1 * t;
        }
    }
    //-1 => building
    //0 => 未到達
    //1 =>　到達
    queue<pair<int,int>>q;
    //w,h

    for (int k = 0; k <= h + 1; ++k) {
        q.push({0,k});
    }
    for (int l = 1; l <= w; ++l) {
        q.push({l,0});
        q.push({l,h + 1});
    }
    for (int m = 0; m <= h + 1; ++m) {
        q.push({w + 1,m});
    }
    vector<pair<int,int>>move_1 = {{0, -1},{1,-1},{-1,0},{1,0},{0,1},{1,1}};
    vector<pair<int,int>>move_2 = {{-1,-1},{0,-1},{-1,0},{1,0},{-1,1},{0,1}};
    //w,h
    while(!q.empty()){
        int now_w = q.front().first;
        int now_h = q.front().second;
        q.pop();
        if(map[now_w][now_h] == 0){
            map[now_w][now_h] = 1;
            if(now_h % 2 == 0){
                for (int i = 0; i < move_2.size(); ++i) {
                    int n_w = now_w + move_2[i].first;
                    int n_h = now_h + move_2[i].second;

                    if(0 <= n_h && n_h <= h + 1 && 0 <= n_w && n_w <= w+1 && map[n_w][n_h] == 0){
                        q.push({n_w,n_h});
                    }

                }
            }else{
                for (int i = 0; i < move_1.size(); ++i) {
                    int n_w = now_w + move_1[i].first;
                    int n_h = now_h + move_1[i].second;

                    if(0 <= n_h && n_h <= h + 1 && 0 <= n_w && n_w <= w + 1 && map[n_w][n_h] == 0){
                        q.push({n_w,n_h});
                    }

                }
            }
        }

    }
    int ans = 0;
    bool last = false;
    for (int n = 0; n <= h + 1; ++n) {
        for (int m = 0; m <= w + 1 ; ++m) {
            if(map[m][n] == 0 || map[m][n] == -1){
                if(!last){
                    last = true;
                    ans ++;
                }
                if(n % 2 == 0){
                    if(map[m-1][n-1] == 1 && 0 <= m-1 && m-1 <= w+1 && 0 <= n-1 && n-1 <= h+1){
                        ans ++;
                    }
                    if(map[m][n-1] == 1 && 0 <= m && m <= w+1 && 0 <= n-1 && n-1 <= h+1){
                        ans ++;
                    }
                    if(map[m-1][n+1] == 1 && 0 <= m-1 && m-1 <= w+1 && 0 <= n+1 && n+1 <= h+1){
                        ans++;
                    }
                    if(map[m][n+1] == 1 && 0 <= m && m <= w+1 && 0 <= n+1 && n+1 <= h+1){
                        ans++;
                    }
                }else{
                    if(map[m][n-1] == 1 && 0 <= m && m <= w+1 && 0 <= n-1 && n-1 <= h+1){
                        ans++;
                    }
                    if(map[m+1][n-1] == 1 && 0 <= m+1 && m+1 <= w+1 && 0 <= n-1 && n-1 <= h+1){
                        ans++;
                    }
                    if(map[m+1][n+1] == 1 && 0 <= m+1 && m+1 <= w+1 && 0 <= n+1 && n+1 <= h+1){
                        ans++;
                    }
                    if(map[m][n+1] == 1 && 0 <= m && m <= w+1 && 0 <= n+1 && n+1 <= h+1){
                        ans++;
                    }
                }
            }else{
                if(last){
                    ans ++;

                }
                last = false;
            }

        }
    }
    cout<<ans<<endl;

    return 0;
}
