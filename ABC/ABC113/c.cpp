//
// Created on 2020/11/24.
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
    vector<vector<int>>prefecture(n+10,vector<int>(1,0));
    for (int i = 0; i < n+10; ++i) {
        prefecture[i].push_back(INF);
    }
    vector<pair<int,int>>q;
    for (int i = 0; i < m; ++i) {
        int p ,y;
        cin>>p>>y;
        prefecture[p].push_back(y);
        q.push_back({p,y});
    }
    for (int i = 0; i < n+10; ++i) {
        sort(all(prefecture[i]));
    }

    for (auto t_q : q){
        int pre = t_q.first;
        int year = t_q.second;

        int ok = 0;
        int ng = prefecture[pre].size()-1;
        int mid = (ok + ng)/2;
        while(abs(ok - ng) > 1){
            if(prefecture[pre][mid] <= year){
                ok = mid;
            }else{
                ng = mid;
            }
            mid =(ok+ng)/2;
        }

            printf("%06d", pre);
            printf("%06d\n",ok);

    }



    return 0;
}
