#include <bits/stdc++.h>
using namespace std;
int main() {
    int numRed,numBlue,onlyRed,onlyBlue,bothColours;

    cin>>numRed>>numBlue>>onlyRed>>onlyBlue>>bothColours;

    int point=-1000000;

    for (int i = 0; i <= min(numRed, numBlue); ++i) {
        point = max(point,(numRed-i)*onlyRed+(numBlue-i)*onlyBlue+2*i*bothColours);
    }
    cout<<point<<endl;

}