//
// Created by yu on 2023/11/30.
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

struct ball{
    int number;
    int next;
    int prev;
};


int main() {
    int n,q;
    cin>>n>>q;
    vector<ball> line(n+2);
    for (int i = 0; i <= n + 1; ++i) {
        line[i].number = i;
        line[i].prev = i - 1;
        line[i].next = i + 1;
    }
    for (int i = 0; i < q; ++i) {
        int x;
        cin>>x;
        if(line[x].next == n + 1)x = line[x].prev;

       ball& a = line[line[x].prev];
       ball& b = line[x];
       ball& c = line[b.next];
       ball& d = line[c.next];

       a.next = c.number;
       c.prev = a.number;
       c.next = b.number;
       b.prev = c.number;
       b.next = d.number;
       d.prev = b.number;

    }
    int f;
    for (int i = 1; i <= n; ++i) {
        if(line[i].prev == 0)f = i;
    }
    int next = f;
    while(true){
        if(next == n + 1)break;
        cout<<line[next].number<<endl;

        f = next;
        next = line[f].next;

    }
    return 0;
}
