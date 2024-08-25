#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>


using namespace std;

long long readSeq(vector<long long>& l){
    sort(l.begin(), l.end());
    auto iter = l.begin();
    long long prev = -1;
    bool plugged = false;
    while(iter!=l.end()){
        if(!((*iter)==prev || *iter==prev+1)){
            if(!plugged && (*iter)==prev+2){
                plugged = true;
            }
            else{
                break;
            }
        }
        prev = *iter++;
    }
    if(!plugged){
        return prev+2;
    }
    else{
        return prev+1;
    }
}

long long solve(vector<vector<long long>>& ls, long long m) {
    set<long long> vals;
    for(vector<long long> l:ls){
        vals.insert(readSeq(l)); 
    }
    long long best = *(vals.rbegin());
    long long count=0;
    if(m>best){
        return best*(best+1) + ((best+1+m)*(m-best))/2;
    }
    else{
        return best *(m+1);
    }
}

void testSeq(){
    vector<long long> l = {7,3,6,0,3};
    cout << readSeq(l) << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i< t; i++) {
        int n;
        long long m;
        cin >> n >> m;
        vector<vector<long long>> ls(n);
        for(int j = 0; j<n; j++){
            int l_len;
            cin >> l_len;
            vector<long long> l(l_len);
            for(int k = 0; k<l_len; k++){
                cin >> l[k];
            }
            ls[j] = l;
        }
        cout << solve(ls, m) << endl;
    }
    //testSeq();
    return 0;
}