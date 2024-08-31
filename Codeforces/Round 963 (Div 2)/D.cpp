#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll median(vector<ll> & v){
    sort(v.begin(), v.end());
    return v[((v.size()+1)/2)-1];
}

void nextPerm(vector<int> & v, int size){
    // find the incrementable
    int prev = size;
    int inc = -1;
    for(int i = v.size()-1; i>=0; i--){
        if(prev-1!=v[i]){
            inc = i;
            break;
        }
        prev = v[i];
    }
    if(inc == -1){ 
        v[0] = -1;
        return;
    }
    v[inc]++;
    int curr = v[inc]+1;
    for(int i = inc+1;i<v.size();i++){
        v[i] = curr;
        curr++;
    }
}

vector<ll> choose(vector<ll> & a, vector<int> & ks, int k){
    vector<ll> ret;
    int omcount = 0;
    int prev = -1;
    for(int i=0;i<ks.size();i++){
        if(prev+1!=ks[i]){
            omcount += ks[i]-prev - 1;
        }
        ret.push_back(a[i+omcount*k]);
        prev = ks[i];
    }
    return ret;
}

template<class T>
void printV(vector<T> & ks){
    for(int i : ks){
        cout << i << " ";
    }
    cout << endl;
}

// this solution gives time limit exceeded on test 18.
ll solve(vector<ll> & a, int k) {
    int omcount;
    if(a.size()%k==0){
        omcount = a.size()/k - 1;
    }
    else{
        omcount = a.size()/k;
    }
    int kcount = a.size() - omcount*k;
    vector<int> ks;
    for(int i = 0; i<kcount; i++){
        ks.push_back(i);
    }
    ll maxmed = 0;
    while(ks[0]!=-1){
        // cout << "permutation: ";
        // printV(ks);
        vector<ll> chosen = choose(a, ks, k);
        maxmed = max(maxmed, median(chosen));
        // cout << "chosen:";
        // printV(chosen);
        //cout << "median: " << median(chosen) << endl;
        nextPerm(ks, kcount+omcount);
    }
    return maxmed;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i<t; i++) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for(int j = 0;j<n;j++){
            cin >> a[j];
        }
        cout << solve(a, k) << endl;

    }
    // vector<int> k = {0,1};
    // nextPerm(k, 4);
    // printV(k);
    // nextPerm(k, 4);
    // printV(k);
    // nextPerm(k, 4);
    // printV(k);
    // nextPerm(k, 4);
    // printV(k);   
    return 0;
}