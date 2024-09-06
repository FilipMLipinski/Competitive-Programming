#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll solve(int n, int m, int k, int w, vector<int> & a) {
    vector<int> scores(n*m, 0);
    int topmax = ((k-1)*2)<=m ? k : m-k+1;
    int sidemax = ((k-1)*2)<=n ? k : n-k+1;
    // cout << "topmax: " << topmax<<endl;
    // cout <<"sidemax: " << sidemax << endl;
    int maxtopcount = m - (topmax-1)*2;
    int maxsidecount = n - (sidemax-1)*2;
    // cout << "topcount: " << maxtopcount << endl;
    // cout << "sidecount: " << maxsidecount << endl;
    int topcount = maxtopcount;
    int sidecount = maxsidecount;
    bool topdec = false;
    int topcurr = 1;
    for(int i =0; i<m;i++){
        int sidecurr = 1;
        bool sidedec = false;
        sidecount = maxsidecount;
        for(int j=0;j<n;j++){
            // cout << "i: " << i << " j: "<<j<<" idx: " << n*i+j << endl;
            // cout<< "adding: "<< topcurr << " x " << sidecurr << endl;
            scores[n*i + j] = topcurr*sidecurr;
            // cout << scores[n*i + j] << endl;
            //scores.push_back(topcurr*sidecurr);
            if(sidecurr!=sidemax && !sidedec){
                sidecurr++;
            }
            else if(sidedec) sidecurr--;
            if(sidecurr==sidemax && sidecount>0){
                sidecount--;
            }
            else if(sidecurr==sidemax && sidecount==0){
                sidedec = true;
                sidecurr--;
            }
        }
        if(topcurr!=topmax && !topdec){
            topcurr++;
        }
        else if(topdec) topcurr--;
        if(topcurr==topmax && topcount>0){
            topcount--;
        }
        else if(topcurr==topmax && topcount==0){
            topdec = true;
            topcurr--;
        }
    }
    // for(int i =0;i<scores.size();i++){
    //     cout << scores[i] << " ";
    // }
    // cout << endl;
    sort(scores.begin(), scores.end(), greater<int>());
    sort(a.begin(), a.end(), greater<int>());
    ll ret = 0;
    for(int i=0;i<w;i++){
        // cout << "adding: " << scores[i] << " x " << a[i] << endl;
        ret += (ll)scores[i]*(ll)a[i];
    }
    return ret;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n,m,k,w;
        cin >>n>>m>>k>>w;
        vector<int> a(w);
        for(int i=0;i<w;i++){
            cin >> a[i];
        }
        cout << solve(n,m,k,w,a) << endl;
    }
    return 0;
}