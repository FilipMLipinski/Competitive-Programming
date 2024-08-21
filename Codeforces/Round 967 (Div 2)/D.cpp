#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <set>

#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
using namespace std;

const string YES = "YES";
const string NO = "NO";

// this submission gets a verdict 'time limit exceeded on test 31'.
void solve(int n, const vector<int> & a) {
    if(n==1){
        cout << n << endl;
        cout << a[0] << endl;
        return;
    }
    vector<int> counter(n+1, 0);
    int distinct = 0;
    REP(i, n){
        if(counter[a[i]]==0) distinct++;
        counter[a[i]] += 1;
    }
    cout << distinct << endl;
    // used items have counter set to -1;
    int printed = 0;
    int j = 0;
    set<int> curr_set;
    unordered_map<int, int> positions;
    set<int> used;
    while(printed < distinct){
        // find j - last occurrence of SOME int k.
        while(j < n){
            if(used.count(a[j])==0){
                counter[a[j]] -= 1;
                if(curr_set.count(a[j]) == 0){
                    positions[a[j]] = j;
                    curr_set.insert(a[j]);
                }
                if(counter[a[j]] == 0){
                    break;
                }
            }
            ++j;
        }
        // i - begginning of interval, j - last occurrence of k.
        // print the best number so far, and go back to its position.
        int best = printed%2 ? (*curr_set.begin()) : (*curr_set.rbegin());
        curr_set.erase(best);
        used.insert(best);
        cout<< best << " ";
        printed += 1;
        int back_position = positions[best];
        while(j>back_position){
            counter[a[j]] += 1;
            --j;
        }
        positions.clear();
        curr_set.clear();
        j++;
    }
    cout<<endl;
    return;
}

int main() {
    cout.clear();
    int t;
    cin >> t;
    REP (i, t) {
        int n;
        cin >> n;
        vector<int> a(n);
        REP(j, n){
            cin >> a[j];
        }
        //cout << "answer: ";
        solve(n, a);
    }
    return 0;
}