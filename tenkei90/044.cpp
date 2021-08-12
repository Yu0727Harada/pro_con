//
// Created on 2021/08/01.
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
    int n,q;
    cin>>n>>q;
    vi a(n+1);
    for (int i =1 ; i <= n; ++i) {
        cin>>a[i];
    }
    vi b;
    int b_size = 0;
    while(q){
        q--;
        int t;
        cin>>t;
        if(t == 1){
            //swap
            int x,y;
            cin>>x>>y;
            if(x <= b_size && y <= b_size){
                int temp = b[abs(b_size - x)];
                b[abs(b_size - x)] = b[abs(b_size - y)];
                b[abs(b_size - y)] = temp;
            }else if(x <= b_size && y > b_size ){
                int temp = b[abs(b_size - x)];
                b[abs(b_size-x)] = a[y - b_size];
                a[y - b_size] = temp;
            }else if(x > b_size && y <= b_size){
                int temp = a[x - b_size];
                a[x - b_size] = b[abs(b_size - y)];
                b[abs(b_size - y)] = temp;
            }else{
                int temp = a[x - b_size];
                a[x - b_size] = a[y - b_size];
                a[y - b_size] = temp;
            }
        }else if(t == 2){
            int x,y;
            cin>>x>>y;
            b.push_back(a[a.size()-1]);
            a.pop_back();
            b_size++;
        }else{
            int x,y;
            cin>>x>>y;
            if(x <= b_size ){
                int temp = b[abs(b_size - x)];
                cout<<temp<<endl;
            }else if(x > b_size ){
                int temp = a[x - b_size];
                cout<<temp<<endl;
            }
        }

    }

    return 0;
}
