#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;
typedef long long ll;

list<int> addV(list<int>& a, list<int>& b);

void printV(list<int>& a){
    auto it = a.rbegin();
    for(auto rit = a.rbegin();rit!=a.rend();rit++){
        cout << *rit;
    }
    cout << endl;
}

list<int> multiplyVnum(list<int>& a, int b){
    list<int> ret;
    int carry = 0;
    for(auto it = a.begin();it!=a.end();it++){
        int c = ((*it)*b + carry);
        ret.push_back(c%10);
        carry = c/10;
    }
    if(carry){
        ret.push_back(carry);
    }
    return ret;
}

list<int> multiplyV(list<int> a, list<int> b){
    if(b.size()==1){
        return multiplyVnum(a, *(b.begin()));
    }
    list<int> res1 = multiplyVnum(a, b.front());
    a.push_front(0);
    b.pop_front();
    list<int> res2 = multiplyV(a,b);
    return addV(res1, res2);
    
}

list<int> addV(list<int>& a, list<int>& b){
    list<int> ret;
    int n = min(a.size(), b.size());
    int carry = 0;
    auto ait = a.begin();
    auto bit = b.begin();
    for(int i=0;i<n;i++){
        int c = *ait+*bit+carry;
        ret.push_back(c%10);
        carry = c/10;
        ait++;
        bit++;
    }
    int m = max(a.size(), b.size());
    for(int i=n;i<m;i++){
        if(a.size()>b.size()){
            ret.push_back((*ait+carry)%10);
            carry = (*ait+carry)/10;
            ait++;
        }
        else{
            ret.push_back((*bit+carry)%10);
            carry = (*bit+carry)/10;
            bit++;
        }
    }
    if(carry){
        ret.push_back(carry);
    }
    return ret;
}

list<int> toVec(ll a){
    list<int> ret;
    while(a>9){
        ret.push_back(a%10);
        a/=10;
    }
    ret.push_back(a);
    // reverse(ret.begin(), ret.end());
    return ret;
}

bool compV(list<int> &a, list<int>& b){
    if(a.size()>b.size()) return false;
    if(a.size()<b.size()) return true;
    auto ait = a.rbegin();
    auto bit = b.rbegin();
    while(ait!=a.rend()){
        if(*ait< *bit) return true;
        if(*ait > *bit) return false;
        ait++;
        bit++;
    }
    return false;
}

list<int> pows(list<int> & a, list<int> & b, ll & count) {
    while(compV(a, b)){
        a = multiplyV(a,a);
        count++;
    }
    return a;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        cout << solve(n, a) << endl;
    }
    return 0;
}