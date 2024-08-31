#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> BG;
vector<int> BR;
vector<int> BY;
vector<int> GR;
vector<int> GY;
vector<int> RY;

void clearColors(){
    BG.clear(); BR.clear(); BY.clear();
    GR.clear(); GY.clear(); RY.clear();
}

void printV(vector<int> v){
    for(int i: v){
        cout << i << " ";
    }
}

void printColors(){
    cout << "BG: ";
    printV(BG);
    cout << endl;
     cout << "BR: ";
    printV(BR);
    cout << endl;   
    cout << "BY: ";
    printV(BY);
    cout << endl;
    cout << "GR: ";
    printV(GR);
    cout << endl;
    cout << "GY: ";
    printV(GY);
    cout << endl;
    cout << "RY: ";
    printV(RY);
    cout << endl;
}

// find a value in the interval [l, r], if no such value, then
// -1
int bsearch(vector<int> & a, int v){
    // find value v
    // the value would be in [s, e)
    if(a.size()==0) return -1;
    int s = 0;
    int e = a.size();
    while(s+1!=e){
        int m = (s+e)/2;
        //cout << m << endl;
        if(v < a[m]){
            e = m;
        }
        else if(a[m] <= v){
            s = m;
        }
    }
    if(a[s] == v) return s;
    else return -1;
}

int closest(vector<int> & a, double x){
    // find the value in a closest to x
    // find the index of the value that would be immediately before x
    // first checking if ANYTHING would be immediately before x
    if(a[0] > x){
        return a[0];
    }
    int s = 0;
    int e = a.size();
    while(s+1!=e){
        int m = (s+e)/2;
        if(a[m] > x){
            e = m;
        }
        else if(a[m] <= x){
            s = m;
        }
    }
    // a[s] would be right before x. Check if the thing AFTER x would be closer;
    if(s+1<a.size() && a[s+1]-x < x - a[s]) return a[s+1];
    return a[s];
}

int solve(int s, int e) {
    // find the colours of s and e;
    //printColors();
    double x = ((double) s + (double) e)/2;
    vector<vector<int>*> portals = {&BG, &BR, &BY, &GR, &GY, &RY};
    static const vector<int> far = {5, 4, 3, 2, 1, 0};
    int p_s, p_e;
    for(int i = 0; i<portals.size(); i++){
        if(bsearch(*(portals[i]), s) != -1) p_s = i;
        if(bsearch(*(portals[i]), e) != -1) p_e = i;
    }
    if(far[p_s]!=p_e){
        return abs(s-e);
    }
    else{
        //find the number closest to x in one of the appropriate portals
        double best_dist = 2e6;
        int best_num = 0;
        for(int i = 0; i<portals.size(); i++){
            if(i!=p_s && i!=p_e){
                vector<int>* p = portals[i];
                if((*p).size() == 0){
                    continue;
                }
                int cand = closest(*p, x);
                double cand_dist = abs((double) cand - x);
                if(cand_dist < best_dist){
                    best_num = cand;
                    best_dist = cand_dist;
                }
            }
        }
        if(best_num == 0) return -1;
        else{
            return abs(s - best_num) + abs(e - best_num);
        }
    }
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i<t; i++) {
        int n, q;
        cin >> n >> q;
        clearColors();
        for (int c = 1; c<n+1; c++){
            string p;
            cin >> p;
            if(p == "BG")
                BG.push_back(c);
            if(p=="BR")
                BR.push_back(c);
            if(p=="BY")
                BY.push_back(c);
            if(p=="GR")
                GR.push_back(c);
            if(p=="GY")
                GY.push_back(c);
            if(p=="RY")
                RY.push_back(c);
        }
        for(int j = 0; j<q; j++){
            int s, e;
            cin >> s >> e;
            cout << solve(s, e) <<endl;
        }
    }
    return 0;
}