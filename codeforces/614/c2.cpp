//
// Created on 2020/01/20.
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

#define all(x) (x).begin(),(x).end()
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;
using gragh = vector<vector<int>>;

#define endl '\n'



void Solve() {
    int n, q;
    vector<vector<int>> lava;
    cin >> n >> q;
    lava.resize(2, vector<int>(n, 0));
    int blockedPair = 0;
    while (q--) {
        int x, y; cin >> x >> y; x--; y--;
        int delta = (lava[x][y] == 0) ? +1 : -1;

        lava[x][y] = 1 - lava[x][y];
        for (int dy=-1; dy<=1; dy++) {
            if (y+dy < 0 || y+dy >= n) continue;

            if (lava[1-x][y+dy] == 1) blockedPair += delta;
        }

        cout << ((blockedPair == 0) ? "Yes\n" : "No\n");
    }
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
     Solve(); return 0;
}
