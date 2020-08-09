//
// Created on 2019/12/15.
//

#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using namespace std;
using gragh = vector<vector<int>>;

int main() {
    int ans=0;
    int a,b,c,d,e,f;
    int fir_max;
    int sec_max;
    cin>>a>>b>>c>>d>>e>>f;

    fir_max = a;
    sec_max = min(b,c);

    if (d>=(fir_max+sec_max)){
        ans = fir_max*e+sec_max*f;
        cout<<ans<<endl;
        return 0;
    }
    else{
        for (int i = 0; i <= d; ++i) {
            if (d-i <= fir_max && i <= sec_max){
                ans = max(ans,(d-i)*e + i*f);
            }
        }
        cout<<ans<<endl;
    }

}
