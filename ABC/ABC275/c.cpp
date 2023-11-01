//
// Created on 2023/07/12.
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

    vector<string>vs(9);
    for (int i = 0; i < 9; ++i) {
        cin>>vs[i];
    }

    pair<int,int>one;
    pair<int,int>two;
    pair<int,int>three;
    pair<int,int>four;

    set<vector<pair<int,int>>>ret;

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if(vs[i][j] == '#'){
                one = {i,j};

                for (int k = i; k < 9; ++k) {

                    int l = 0;
                    if(k == i)l = j + 1;
                    for ( l ;l < 9; ++l) {


                        if(vs[k][l] == '#'){
                            two = {k,l};
                            if(i <= k){
                                three = {(k + (l - j)), l + (i - k)};
                                four = {i + ( l - j), j + (i - k)};
                                if((0 <= three.first  && three.first < 9 && 0 <= three.second  && three.second < 9) && (0 <= four.first  && four.first < 9 && 0 <= four.second  && four.second < 9)){
                                    if(vs[three.first][three.second] == '#' && vs[four.first][four.second] == '#'){
                                        vector<pair<int,int>> r = {one,two,three,four};
                                        sort(all(r));
                                        ret.insert(r);
                                    }
                                }
                            }else{
                                three = {(i - (l - j)), j + (i - k)};
                                four = {k - ( l - j), l + (i - k)};
                                if((0 <= three.first  && three.first < 9 && 0 <= three.second  && three.second < 9) && (0 <= four.first  && four.first < 9 && 0 <= four.second  && four.second < 9)){
                                    if(vs[three.first][three.second] == '#' && vs[four.first][four.second] == '#'){
                                        vector<pair<int,int>> r = {one,two,three,four};
                                        sort(all(r));
                                        ret.insert(r);
                                    }
                                }

                            }
                        }
                    }
                }
            }
        }
    }

    cout<<ret.size()<<endl;
    return 0;
}
