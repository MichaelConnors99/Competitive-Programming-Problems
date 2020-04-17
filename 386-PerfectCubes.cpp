#include <bits/stdc++.h>

using namespace std;

int main(){
    for(int a = 1;a <= 200;a++){
        for(int b = 2;b < cbrt(a*a*a/3)+1;b++){
            for(int c = 3;c < cbrt(a*a*a*2/3)+1;c++){
                for(int d = 4;d < a;d++){
                    if(b*b*b + c*c*c + d*d*d == a*a*a && d > c && c > b){
                        cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")" << endl;
                    }
                }
            }
        }
    }
}
