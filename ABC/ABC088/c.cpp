//
// Created on 2020/09/12.
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
    vector<vector<int>>c(3,vector<int>(3,0));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin>>c[i][j];
        }
    }

    for (int one = -60; one < 60; ++one) {
        for (int two = -60; two < 60; ++two) {
            for (int three = -60; three < 60; ++three) {
                for (int four = -60; four < 60; ++four) {

                    if(one + four != c[0][0])continue;
                    if(two + four != c[1][0])continue;
                    if(three + four != c[2][0])continue;
                    for (int five = -60; five < 60; ++five) {

                        if(one + five != c[0][1])continue;
                        if(two + five != c[1][1])continue;
                        if(three + five != c[2][1])continue;
                        for (int six = -60; six < 60; ++six) {

                            if(one + six != c[0][2])continue;
                            if(two + six != c[1][2])continue;
                            if(three + six != c[2][2])continue;

                            cout<<"Yes"<<endl;
                            return 0;
                        }
                    }
                }

            }
        }
    }
    cout<<"No"<<endl;

    return 0;
}
