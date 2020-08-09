//
// Created on 2019/12/15.
//

#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;
using gragh = vector<vector<int>>;

int main() {
    int n;
    ll sx,sy;
    cin>>n>>sx>>sy;
    vector<vector <int> > location (1e3,vector<int>(1e3,0));;
    for (int i = 0; i < n; ++i) {
        ll ix,iy;
        cin>>ix>>iy;
        for (int j = min(ix,sx); j <= max(ix,sx); ++j) {
            for (int k = min(iy,sy); k <= max(iy,sy); ++k) {
                location[j][k] ++;
            }
        }
    }
    int ans = 0;
    int ansx,ansy;
    for (int l = 0; l < location.size(); ++l) {
        if (ans < *max_element(all(location[l]))){
            std::vector<int>::iterator iter = std::max_element(all(location[l]));
            size_t index = std::distance(location[l].begin(),iter);
            ans = *iter;
            if (l != sx || index != sy){
                ansx = l;
                ansy = index;
            }

        }
    }
    cout<<ans<<endl;
    cout<<ansx<<" "<<ansy<<endl;
}

