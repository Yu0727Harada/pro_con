//
// Created on 2020/03/10.
//shellsort p 74


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

#define all(x) (x).begin(),(x).end()

using namespace std;
const long long LINF =1e18;
const int INF = 1e9;
int cnt = 0;
int m;
vector<int>G;

void insertionSort(vector<int> &data,int n,int g){
    for (int i = g; i < n ; ++i) {
        int value = data[i];
        int j = i -g;
        while(j>= 0 && data[j] > value){
            data[j + g] = data[j];
            j -= g;
            cnt ++;
        }
        data[j+g] = value;
    }
}

void shellsort(vector<int> &data,int n){
    int h = 1;
    while(h<=n) {
        G.push_back(h);
        h = 3*h +1;
            }
    m = G.size();
    for (int i = m; i >= 0; --i) {
        insertionSort(data,n,G[i]);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }
    shellsort(data, n);

    cout << m << endl;
    reverse(all(G));
    cout << G[0];
    for (int j = 1; j < G.size(); ++j) {
        cout << " " << G[j];
    }
    cout<<endl;
    cout << cnt << endl;
    for (int k = 0; k < n; ++k) {
        cout << data[k]<<endl;
    }


}


