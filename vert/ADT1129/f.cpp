//
// Created by yu on 2023/11/29.
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
    int n;
    cin>>n;
    vector<string> masu(n);
    for (int i = 0; i < n; ++i) {
        cin>>masu[i];
    }
    bool find = false;
    for (int i = 0; i <= n - 6; ++i) {
        for (int j = 0; j <= n - 6; ++j) {
            //縦の判定
            for (int k = i; k < i + 6; ++k) {
                int cnt = 0;
                for (int l = j; l < j + 6; ++l) {
                    if(masu[k][l] == '#')cnt++;
                }
                if(cnt >= 4)find = true;
            }

            //横の判定
            for (int l = j; l < j + 6; ++l) {
                int cnt = 0;
                for (int k = i; k < i + 6; ++k) {
                    if(masu[k][l] == '#')cnt++;
                }
                if(cnt >= 4)find = true;
            }
            //斜めの判定
            int cnt = 0;
            for (int m = 0; m < 6; ++m) {
                if(masu[i + m][j + m] == '#')cnt++;
            }
            if(cnt >= 4)find = true;
            cnt = 0;
            for (int m = 0; m < 6; ++m) {
                if(masu[i + (5 - m)][j + m] == '#')cnt++;
            }
            if(cnt >= 4)find = true;

        }
    }
    if(find){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}
