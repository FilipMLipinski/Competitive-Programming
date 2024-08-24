#include <string>
#include <vector>
#include <iostream>

#define REP(i, n) for (long long i = 0; (i) < (long long)(n); ++ (i))
#define REPR(i, n) for (long long i = (long long)(n) - 1; (i) >= 0; -- (i))
using namespace std;

const string YES = "YES";
const string NO = "NO";

vector<long long> facts(1e5*2+1);
const long long mod = 1e9 + 7;

long long logPower(long long n, long long p){
    long long res = 1;
    while(p){
        if(p&1) res = (res * n) %mod;
        p=p/2;
        n = (n*n) % mod;
    }
    return res;
}

long long nchoosek(int n, int k){
    return (facts[n] * logPower((facts[k] * facts[n-k])%mod, mod-2)) % mod;
}

void compute_factorials(){
    facts[0] = 1;
    for(int i = 1; i<=1e5*2; i++){
        facts[i] = (facts[i-1]*i)%mod;
    }
}

long long solve(const vector<bool> & a, int k) {
    int ones = 0, zeros=0;
    for(int i = 0; i<a.size(); i++){
        if(a[i]) ones++;
        else zeros++;
    }
    //if(ones<(k+1)/2) return 0;
    long long total = 0;
    for(int i = (k+1)/2; i <= min(k, ones); i++){
        if(zeros >= k-i){
            total += (nchoosek(ones, i) * nchoosek(zeros, k-i))%mod;
            total = total%mod;
        }
    }
    return total;
}

int main() {
    compute_factorials();
    int t;
    cin >> t;
    REP (i, t) {
        int n, k;
        cin >> n >> k;
        vector<bool> a(n);
        REP(j, n){
            bool b;
            cin >> b;
            a[j] = b;
        }
        cout << solve(a, k) << endl;
    }
    // vector<long long> f = factorials(10);
    // cout<<nchoosek(f, 0, 0)<< endl;
    return 0;
    
}