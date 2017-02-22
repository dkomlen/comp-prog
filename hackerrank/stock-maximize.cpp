#include <set>
#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long int
multiset<ll> s;
multiset<ll>::iterator median;

void print(){
    multiset<ll>::iterator next = median;
    if (s.size() % 2 == 0) next++;

    printf("%.20g\n", (double)(*median + *next) / 2);
}

bool is_odd(){
    return s.size() % 2 == 1;
}
bool is_right(ll x){
    return x > *median;
}

void recalc(){
    int size = s.size();
    int d = (size % 2 == 0 ? size : size + 1)/2 -1;
    median = s.begin();
    advance(median, d);
}

void add(ll x){
    bool odd = is_odd();
    s.insert(x);

    if (s.size() == 1) median = s.begin();
    else if (*median == x) recalc();
    else {
        bool right = is_right(x);
        if (odd && !right) median--;
        if (!odd && right) median++;
    }
    print();
}

void remove(ll x){
    multiset<ll>::iterator it = s.find(x);

    if (it == s.end()){
        cout << "Wrong!" << endl;
        return;
    }
    bool odd = is_odd();
    int med = *median;
    s.erase(it);
    if (s.size() == 0) {
        cout << "Wrong!" << endl;
        return;
    }

    if (med == x) recalc();
    else {
        bool right = is_right(x);
        if (odd && right) median--;
        if (!odd && !right) median++;
    }

    print();
}

int main(){
    int n; cin >> n;

    while(n--){
        char c; ll x; cin >> c >> x;
        switch(c){
            case 'a': add(x); break;
            case 'r': remove(x); break;
        }
    }
    return 0;
}