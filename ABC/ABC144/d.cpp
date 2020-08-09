#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
    double a,b,x;
    static const double pi = acos(-1);
    cin>>a>>b>>x;

    double s,e;

    double deg;
    double h;
    double w;

    if (x/a>=(a*b)/2){
        s=0;
        e=90;

        h = 2*b-((2*x)/(a*a));

        deg = abs(s - e) / 2 + min(e, s);

        for (int i = 0; i < 100000; ++i)  {

            if (tan(deg * pi / 180) == h / a){
                printf("%.10f\n", deg);
                return 0;
            }else if (tan(deg * pi / 180) < h / a){
                s = deg;
                deg = abs(e - deg) / 2 + min(deg, e);

            }else if(tan(deg * pi / 180) > h / a){
                e = deg;
                deg = abs(deg - s) / 2 + min(deg, s);

            }
        }
        printf("%.10f\n", deg);
        return 0;

    }else {

        s = 0;
        e = 90;

        w = (2*x)/(a*b);
        deg = abs(s - e) / 2 + min(e, s);


        for (int j = 0; j < 100000; ++j) {


            if (tan(deg * pi / 180) == b / w) {
                printf("%.10f\n", deg);
                return 0;
            } else if (tan(deg * pi / 180) < b / w) {
                s = deg;
                deg = abs(e - deg) / 2 + min(deg, e);
            } else if (tan(deg * pi / 180) > b / w) {
                e = deg;
                deg = abs(deg - s) / 2 + min(deg, s);

            }
        }
        printf("%.10f\n", deg);
    }
}
