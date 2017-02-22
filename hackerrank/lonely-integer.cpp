#include <iostream>
#include <string>
using namespace std;

string xr(string a, string b){
    string ret = (a.size() < b.size()) ? b : a;
    string c = (a.size() < b.size()) ? a : b;
    
    for (int i = 0; i < c.size(); ++i){
        ret[i] ^= c[i];
    }
    return ret;
}

string bin(int x){
    string s = "";
    do{
        s += x % 2;
        x /= 2;
    } while(x);
    return s;
}

int dek(string s){
    int n = 0, d = 1;
    for (string::iterator it = s.begin(); it != s.end(); ++it){
        n += d * (*it);
        d *= 2;
    }
    return n;
}

int main(){
    int n; cin >> n;
    string a = "";
    while(n--){ 
        int x; cin >> x;
        if (a == "") a = bin(x);
        else a = xr(a, bin(x));
    }
    cout << dek(a) << endl;
    return 0;
}