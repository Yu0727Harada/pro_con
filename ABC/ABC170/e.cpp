//
// Created on 2020/06/14.
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
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;


int main() {
    int n,q;
    cin>>n>>q;

    vector<multiset<int>>school(2*100003);
    for (int i = 0; i < 2*100003; ++i) {
        school[i].insert(-1);
    }
    vector<pair<int,int>>student(n+1);
    multiset<int>max_value;
    for (int j = 1; j <= n; ++j) {
        int a,b;
        cin>>a>>b;
        student[j] = {a,b};
        int max_prev = *rbegin(school[b]);
        school[b].insert(a);
        int max_now = *rbegin(school[b]);
        if(max_prev != max_now){
            if(max_prev != -1){
                max_value.erase(max_value.find(max_prev));
            }
            max_value.insert(max_now);
        }
    }
    for (int k = 1; k <= q; ++k) {
        int c,d;
        cin>>c>>d;

        int prev_school = student[c].second;
        int rating = student[c].first;
        int max_prev_p = *rbegin(school[prev_school]);
        int max_prev_n = *rbegin(school[d]);
        school[prev_school].erase(rating);
        school[d].insert(rating);
        student[c].second = d;
        int max_now_p = *rbegin(school[prev_school]);
        int max_now_n = *rbegin(school[d]);
        if(max_prev_p != max_now_p){
            if(max_prev_p != -1){
                max_value.erase(max_value.find(max_prev_p));
                //multisetは普通にerasesすると同じ値はすべて削除してしまうのでイテレータを渡すようにする
            }
            if(max_now_p != -1){
                max_value.insert(max_now_p);
            }
        }
        if(max_prev_n != max_now_n){
            if(max_prev_n != -1){
                max_value.erase(max_value.find(max_prev_n));
            }
            if(max_now_n != -1){
                max_value.insert(max_now_n);
            }
        }
        cout<<*begin(max_value)<<endl;
    }

    return 0;
}
