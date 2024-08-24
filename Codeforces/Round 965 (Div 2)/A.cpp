#include <iostream>
#include <vector>
using namespace std;
void solve(int x, int y, int k){
    if(k%2 == 1){
        cout << x << " " << y << endl;
        --k;
    }
    int dx = 1;
    int dy = 1;
    int max = 10000;
    while(k>0){
        cout << x+dx << " " << y+dy << endl;
        cout << x-dx << " " << y-dy << endl;
        k-=2;
        if(dy==max){
            dy = 1;
            dx++;
        }
        else dy++;
    }
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i<t; i++){
        int x,y,k;
        cin >> x >> y >> k;
        solve(x,y,k);
    }
}