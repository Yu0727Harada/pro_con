//
// Created by 原田 on 2021/10/30.
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
//#include <atcoder/all>


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

    vvi a(h,vi(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin>>a[i][j];
        }
    }

    int i = 0;
    int j = 0;
    int nx = 1;
    int ny = 0;

    vector<string> ans;

    while(true){
        if(a[i][j] % 2 == 1){
            ans.push_back(to_string(j + 1)+" "+to_string(i + 1)+" "+to_string(ny + 1)+" "+to_string(nx + 1));
            a[ny][nx] ++;
            a[i][j] --;
        }
        if(i % 2 == 0 && j < w - 1){
            j++;
        }else if(i % 2 == 1 && j > 0){
            j--;
        }else{
            if(i < h){
                i++;
            }
        }

        if(nx < w - 1 && ny % 2 == 0){
            nx++;
        }else if(ny % 2 == 1 && nx > 0){
            nx--;
        }else{
            if(ny < h){
                ny++;
            }
        }
        if(ny == h - 1){
            if(ny % 2 == 0 && nx == w - 1){
                break;
            }else if(ny % 2 == 1 && nx == 0){
                break;
            }
        }
    }
    cout<<ans.size()<<endl;
    for (int k = 0; k < ans.size(); ++k) {
        cout<<ans[i]<<endl;
    }

    return 0;

}
