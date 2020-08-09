#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin>>N;
    vector<long long>duration(N);
    vector<string>user(N);

    for (int i = 0; i < N; ++i) {
        cin>>duration[i];
    }
    for (int j = 0; j < N; ++j) {
        cin>>user[j];
    }
    map<string,long long>jobtime;
    for (int k = 0; k < N; ++k) {
        jobtime[user[k]]+=duration[k];
    }

    vector<bool>done(N);
    vector<int>ans;
    while(ans.size()<N){
        string next;
        for(int n=0;n<N;n++){
            if(!done[n]&&(next.empty()||jobtime[user[n]]<jobtime[next])){
                next = user[n];
            }

        }
        for (int n = 0; n < N; ++n) {
            if(user[n]==next){
                done[n] = true;
                ans.push_back(n);
            }
        }

    }

    //cout<<ans<<endl;
}