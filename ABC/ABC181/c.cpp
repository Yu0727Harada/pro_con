//
// Created on 2020/11/01.
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
    int n;
    cin>>n;
    vector<pair<long double,long double>>point(n);
    for (int i = 0; i < n; ++i) {
        long double x,y;
        cin>>x>>y;
        point[i] = {x,y};
    }
    bool ok = false;
    for (int i = 0; i < n; ++i) {
        if(ok)break;
        for (int j = i+1; j < n; ++j) {
            for (int k = j+1; k < n; ++k) {
                if(point[i] == point[j] || point[j] == point[k]){
                    continue;
                }

                long double x1 = point[i].first;
                long double y1 = point[i].second;
                long double x2 = point[j].first;
                long double y2 = point[j].second;

                long double x3 = point[k].first;
                long double y3 = point[k].second;

                long double a;
                long double b;
                if(x2 - x1 == 0){
                    if(x3 == x1){
                        ok = true;
                    }
                }else{
                    a = (y2 - y1) / (x2 - x1);
                    b = - a * x1 + y1;
                    if(y3 == a * x3 + b){
                        ok = true;
                    }
                }
            }
        }
    }
    if(ok){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

    return 0;
}
