//
// Created on 2020/09/15.
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
    int m,n,k;
    cin>>m>>n>>k;

    vector<vector<int>>j(m+1,vector<int>(n+1,0));
    vector<vector<int>>o(m+1,vector<int>(n+1,0));
    vector<vector<int>>i(m+1,vector<int>(n+1,0));
    for (int l = 1; l <= m ; ++l) {
        string t;
        cin>>t;
        t =  t;
        for (int i1 = 1; i1 <= n; ++i1) {
            if(t[i1-1] =='J'){
                j[l][i1] ++;
            }else if(t[i1-1]=='I'){
                i[l][i1] ++;
            }else{
                o[l][i1] ++;
            }
            j[l][i1] = j[l][i1-1] + j[l][i1];
            o[l][i1] = o[l][i1-1] + o[l][i1];
            i[l][i1] = i[l][i1-1] + i[l][i1];

        }
    }
    for (int l = 1; l <= m ; ++l) {
        for (int i1 = 1; i1 <= n; ++i1) {

            j[l][i1] += j[l - 1][i1];
            o[l][i1] += o[l - 1][i1];
            i[l][i1] += i[l - 1][i1];
        }
    }

    for (int k1 = 0; k1 < k; ++k1) {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int out_j = 0;
        int out_i = 0;
        int out_O = 0;
        out_j += j[c][d] - j[a - 1][d] - j[c][b-1] + j[a-1][b-1];
        out_i += i[c][d] - i[a - 1][d] - i[c][b-1] + i[a-1][b-1];
        out_O += o[c][d] - o[a - 1][d] - o[c][b-1] + o[a-1][b-1];

        cout<<out_j<<" "<<out_O<<" "<<out_i<<endl;
    }

    return 0;
}
