//
// Created on 2021/05/17.
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



int main() {

    string n;
    int k;
    cin>>n>>k;

    while(k){

        vi l;
        for (int i = 0; i < n.size(); ++i) {
            l.push_back(n[i] - '0');
        }

        int g1 = 0;
        int g2 = 0;

        sort(rall(l));
        for (int i = 0; i < l.size(); ++i) {
            g1 += l[i] *pow(10, l.size() - (i + 1));
        }

        sort(all(l));
        for (int i = 0; i < l.size() ;++i) {
            g2 += l[i] * pow(10,l.size() - (i+1));
        }
        int f = g1 - g2;
        n = to_string(f);
        k--;
    }
    cout<<n<<endl;
    return 0;
}
