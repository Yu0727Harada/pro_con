//
// Created on 2021/03/20.
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

class hanjo{
public:
    vvi g;
    int cnt;
}


int main() {

    int h,w,a,b;
    cin>>h>>w>>a>>b;

    vvi g(h + 1,vi(w + 1,0));
    //0 -no 1-part 2-dame

    for (int i = 0; i <= w; ++i) {
        g[0][i] = 2;
        g[h][i] = 2;
    }
    for (int i = 0; i <= h; ++i) {
        g[i][0] = 2;
        g[i][w] = 2;
    }


    hanjo init;
    init.g = g;
    init.cnt = 0;

    queue<hanjo> que;
    que.push(init);
    int ans = 0;
    while(!que.empty()){
        hanjo gr = que.front();
        que.pop();
        if(gr.cnt == a){
            ans ++;
        }
        for (int i = 0; i <= h; ++i) {

            if(gr[i]
        }


    }



    return 0;
}
