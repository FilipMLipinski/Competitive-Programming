#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

bool isSub(string& s, string& t){
    int i = 0;
    int j = 0;
    while(j<t.size()){
        if(t[j]==s[i]){
            i++;
            if(i==s.size()){
                return true;
            }
        }
        else{
            i = 0;
        }
        j++;
    }
    return false;
}

bool anySubstring(vector<string>& wrongs, string& guess){
    for(int i = 0;i<wrongs.size();i++){
        if(isSub(wrongs[i], guess)) return true;
    }
    return false;
}

class Guesser{
    vector<string> wrongs;
    int n;
    string lastguess = "";
    string attguess = "";
    int attempt;
    bool lastanswer;
public:
    string getGuess(){
        if(lastguess.size()==n && lastanswer==true){
            return "! " + lastguess; 
        }
        bool goodGuess = false;
        while(!goodGuess){
            if(attempt == 0) attguess = lastguess+"0";
            else if(attempt == 1) attguess = lastguess+"1";
            else if(attempt == 2) attguess = "0"+lastguess;
            else if(attempt == 3) attguess = "1"+lastguess;
            attempt++;
            if(!anySubstring(wrongs, attguess)) goodGuess = true;
        }
        return "? " + attguess;
    }
    void recordAnswer(bool ans){
        lastanswer = ans;
        if(!ans){
            wrongs.push_back(attguess);
        }
        else{
            lastguess = attguess;
            attempt = 0;
        }
    }
    Guesser(int _n){n=_n; attempt = 0;}
};

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Guesser guesser(n);
        string g = guesser.getGuess();
        while(g[0]!='!'){
            cout << g << endl;
            bool ans;
            cin >> ans;
            guesser.recordAnswer(ans);
            g = guesser.getGuess();
        }
        cout << g << endl;
    }
    return 0;
}