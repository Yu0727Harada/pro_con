//
// Created on 2021/09/18.
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

map<char,int>mp;


bool compare(string a, string b){//a>b true
    for (int i = 0; i < min(a.size(),b.size()); ++i) {
        if(a[i] != b[i]){
            if(mp[a[i]] > mp[b[i]]){
                return true;
            }else{
                return false;
            }
        }
    }
    if(a.size() > b.size())return true;
    else return false;

}

void swap(string* a, string* b)
{
    string t = *a;
    *a = *b;
    *b = t;
}

int partition (vector<string> &array, int l, int r) {
    string pivot = array[r];
    int i = (l - 1);

    for (int j = l; j <= r - 1; j++) {
        if (compare(pivot,array[j])) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[r]);
    return (i + 1);
}

void quickSort(vector<string>&array, int l, int r) {
    if (l < r) {
        int pivot = partition(array, l, r);
        quickSort(array, l, pivot - 1);
        quickSort(array, pivot + 1, r);
    }
}



int main () {

    string x;
    cin>>x;
    for (int i = 0; i < x.size(); ++i) {
        mp[x[i]] = i;
    }
    int n;
    cin>>n;
    vector<string> array(n);
    for (int i = 0; i < n; ++i) {
        cin>>array[i];
    }

    quickSort(array, 0, array.size() - 1);

    
    for (int i = 0; i < array.size(); i++) {
        cout<<array[i]<<endl;
    }
    

    return 0;
}