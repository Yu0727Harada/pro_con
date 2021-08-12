//
// Created by 原田 on 2021/08/06.
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
#include <atcoder/all>

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


int op(int s_l, int s_r){
    if(s_l > s_r){
        return s_l;
    }else{
        return s_r;
    }
}

int e(){
    return 0;
}

int mapping(int f,int s){
    if(f > 0){
        return f;
    }else{
        return s;
    }

}

int composition(int f,int g){
    if(f > 0){
        return f;
    }else{
        return g;
    }
}

int id(){
    return 0;
}

int main() {
    int n,q;
    cin>>n>>q;
    vi v(n,0);

    atcoder::lazy_segtree<int,op,e,int,mapping,composition,id>seg(v);

    while(q){
        q--;
        int l,r;
        cin>>l>>r;
        l--;
        int x = seg.prod(l,r) + 1;
        cout<<x<<endl;
        seg.apply(l,r,x);

    }
    return 0;

}
