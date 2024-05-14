//
// Created by yuha on 2024/05/11.
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

struct node{
    node *prev = nullptr;
    node *next = nullptr;
    ll value = 0;
    void set_next(node *_next){
        this->next = _next;
    }
    void set_prev(node *_prev){
        this->prev = _prev;
    }
};

void insert_node(node &prev,node &target, node &next){
    target.set_next(&next);
    target.set_prev(&prev);
    prev.set_next(&target);
    next.set_prev(&target);
}

void delete_node(node &prev,node &target,node &next,node &nil){
    target.set_next(&nil);
    target.set_prev(&nil);
    prev.set_next(&next);
    next.set_prev(&prev);
}

int main() {
    node nil;
    nil.prev = nullptr;
    nil.next = nullptr;
    nil.value = 0;

    int n;
    cin>>n;

    map<ll,node> array;

    node *last = &nil;
    ll a;
    for (int i = 0; i < n; ++i) {

        cin>>a;
        array[a].prev = last;
        array[a].value = a;

        if(last != &nil){
            last->set_next(&array[a]);
        }
        last = &array[a];
    }
    last->set_next(&nil);

    int q;
    cin>>q;
    for (int i = 0; i < q; ++i) {
        int t;
        cin>>t;
        if(t == 1){
            ll x,y;
            cin>>x>>y;

            insert_node(array[x],array[y],*array[x].next);
            array[y].value = y;
        }else{
            ll x;
            cin>>x;
            delete_node(*array[x].prev,array[x],*array[x].next,nil);
            array.erase(x);
        }
    }

    node *now = &nil;
    for(auto item:array){
        if(item.second.prev != &nil || item.second.next != &nil){
            now = &array[item.first];
            break;
        }
    }
    while(now->prev != &nil){
        now = now->prev;
    }
    while(now->next != &nil){
        cout<<now->value<<" ";
        now = now->next;
    }
    cout<<now->value;

    cout<<endl;

    return 0;
}
