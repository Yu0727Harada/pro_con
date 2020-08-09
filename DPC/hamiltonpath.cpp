#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin>>N;
    vector<string>roads(N);
    for (int i = 0; i < N; ++i) {
        cin>>roads[i];
    }

    int decline_count=0;
    int solid_count =0;
    for (int j = 0; j < N; ++j) {
        int temp =0;
        for (int k = 0; k < N; ++k) {
            if(roads[j][k]=='Y'){
                temp++;
                if(temp ==2){
                    solid_count++;
                }
                if(temp>2 || temp >= N-1){
                    cout<<0<<endl;
                    return 0;
                }
                if(k>j){
                    decline_count++;
                }
            }
        }
    }
    int ans=1;
    N = N-decline_count;
    for (int l = 0; l < N; ++l) {
        ans *= (N-l);
    }
    for (int m = 0; m < decline_count-solid_count; ++m) {
        ans *= 2;
    }
    cout<<ans<<endl;

    

}