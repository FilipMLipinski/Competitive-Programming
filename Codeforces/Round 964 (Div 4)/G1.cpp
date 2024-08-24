#include <string>
#include <vector>
#include <iostream>

#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REPR(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
using namespace std;

const string YES = "YES";
const string NO = "NO";

int T = 1000;

// int whichIsWrong(int a, int b, int area){
//     if(a*b==area) return 0;

// }

int main() {
    int t;
    cin >> t;
    REP(i, t){
        int l = 1, r = T;
        // x is the LAST CORRECTLY WRITTEN LETTER
        while(l+1!=r){
            int area;
            int m1 = (2*l+r)/3;
            int m2 = (l+2*r)/3;
            //cout<<"l: "<<l<<" r: " << r << endl;
            cout << "? " << m1 << " " << m2 << endl;
            //cout.flush();
            cin >> area;
            if(m1*m2==area){
                // x in [m2, r)
                l = m2;
            }
            if(m1*(m2+1)==area){
                l = m1;
                r = m2;
            }
            if((m1+1)*(m2+1)==area){
                r = m1;
            }
        }
        cout << "! " << l+1 << endl;
    }
    return 0;
}