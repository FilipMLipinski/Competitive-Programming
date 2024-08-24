#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canMedianBe(const vector<long long> & a, const vector<bool> & b, long long k, long long x){
    vector<long long> improvables;
    long long less_than_x = 0;
    for(long long i = 0; i < a.size(); ++i){
        if(a[i]<x && b[i] == 1){
            improvables.push_back(a[i]);
        }
        if(a[i]<x) ++less_than_x;
    }
    if(less_than_x + 1 < a.size()/2) return true;
    long long needed = (a.size()/2 + 1) - (a.size() - less_than_x);
    sort(improvables.begin(), improvables.end());
    long long i = improvables.size() - 1;
    while(needed > 0){
        if(i < 0) return false;
        k -= x-improvables[i];
        if(k < 0) return false;
        --needed;
        --i;
    }
    return true;
}

void solve(vector<long long> a, vector<bool> b, long long k){
    // find index of max(a) and the index of max(a) that has b=1;
    long long max_a_idx = -1;
    long long max_a = 0;
    long long max_l_a_idx = -1;
    long long max_l_a = 0;
    for(long long i = 0; i < a.size(); ++i){
        long long cand = a[i];
        if(cand > max_a){
            max_a = cand;
            max_a_idx = i;
        }
        if(b[i]){
            if(cand > max_l_a){
                max_l_a = cand;
                max_l_a_idx = i;
            }
        }
    }
    // if max has b=1, pump it.
    long long solution = 0;
    if(max_l_a_idx!=-1){
        vector<long long> a_cp = a;
        a_cp.erase(a_cp.begin()+max_l_a_idx);
        sort(a_cp.begin(), a_cp.end());
        long long med = a_cp[(a_cp.size()-1)/2];
        solution = med + max_l_a + k;
        if(max_a == max_l_a){
            cout << solution << endl;
            return;
        } 
    }
    if(max_l_a_idx==-1){
        a.erase(a.begin()+max_a_idx);
        sort(a.begin(), a.end());
        long long med = a[(a.size()-1)/2];
        cout << med+max_a << endl;
        return;
    }
    // now we consider the 'remove biggest, work on median' option
    a.erase(a.begin()+max_a_idx);
    b.erase(b.begin()+max_a_idx);
    // binary search.
    long long l = 0, r = k+1+max_a;
    while(l+1!=r){
        long long m = (l+r)/2;
        bool canBe = canMedianBe(a,b,k,m);
        //cout << "canMedianBe: " << m << ": " << canBe << endl;
        if(canBe){
            l = m;
        }
        else{
            r = m;
        }
    }
    solution = max(solution, l+max_a);
    cout << solution << endl;
    return;
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i<t; i++){
        vector<long long> a;
        vector<bool> b;
        long long n;
        long long k;
        cin >> n;
        cin >> k;
        for(int j = 0; j<n; ++j){
            long long num;
            cin >> num;
            a.push_back(num);
        }
        for(int j = 0; j<n; ++j){
            long long num;
            cin >> num;
            b.push_back(num);
        }
        solve(a,b,k);
    }
    return 0;
}