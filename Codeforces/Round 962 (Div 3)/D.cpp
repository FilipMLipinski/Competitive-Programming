#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll permutations(int a, int b, int c){
    if(a==b){
        if(b==c){
            return 1;
        }
        else return 3;
    }
    if(a==c){
        return 3;
    }
    if(b==c){
        return 3;
    }
    return 6;
}

bool cond(int a, int b, int n, int x){
    return min(x-a-b, (n-a*b)/(a+b)) >= b;
}

int getmaxb(int a, int x, int n){
    int e = x-a;
    int s = a;
    // max b is somewhere in [s, e)
    while(s+1!=e){
        int m = s + (e-s)/2;
        if(cond(a,m,n,x)){
            s = m;
        }
        else e = m;
    }
    return s;
}

ll solve(int n, int x) {
    ll count = 0;
    for(int a=1;a<=x/3;a++){
        int maxb = getmaxb(a,x,n);
        for(int b=a;b<=maxb;b++){
            int maxc = min((n-a*b)/(a+b), x-a-b);
            // count all permutations (a,b,c) where b<=c<=maxc;
            // first check if any such permutation exists;
            if(b<=maxc){
                // add (a,b,c) where b=c;
                if(a==b) count += 1;
                else count += 3;
                // then add (a,b,c) where b<c;
                if(a==b) count += (maxc-b) * 3;
                else count += (maxc-b) * 6;
            }
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n >> x;
        cout << solve(n, x)<<endl;        
    }
    return 0;
}