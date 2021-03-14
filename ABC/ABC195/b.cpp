//
// Created on 2021/03/13.
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
    int a,b;
    cin>>a>>b;
    double w;
    cin>>w;
    w = w * 1000;

    int min_n = INF;
    int max_n = 0;

    for (int i = 1; i <= 100000; ++i) {
        double j = w / i;
        if(j < a) break;
        if(a <= j && j <= b){
            min_n = min(min_n,i);
            max_n = max(max_n,i);
        }
    }

    if(min_n == INF || max_n == 0 ){
        cout<<"UNSATISFIABLE"<<endl;
    }else{
        cout<<min_n<<" "<<max_n<<endl;
    }

    return 0;
}
