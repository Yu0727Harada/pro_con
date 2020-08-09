//
// Created on 2020/01/17.
//

//#include <bits/stdc++.h>
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

//#define all(x) (x).begin(),(x).end()
//typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;
//using gragh = vector<vector<int>>;

void selection_sort(vector<int> &A,int N,int &c){
    for (int i = 0; i < N; ++i) {
        int min;
        min = i;
        for (int j = i; j < N; ++j) {
            if(A[j]<A[min]) min = j;
        }
        if (i != min){
            swap(A[i],A[min]); c++;
        }
    }
}

int main() {
    int n;
    cin>>n;
    vector<int>A(n);
    for (int i = 0; i < n; ++i) {
        cin>>A[i];
    }
    int c = 0;
    selection_sort(A,n,c);
    for (int j = 0; j < n; ++j) {
        if (j == 0)cout<<A[j];
        else cout<<" "<<A[j];
    }
    cout<<endl;
    cout<<c<<endl;
}
