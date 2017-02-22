#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define fs first
#define sc second

string action[9];
void init(){
    action[0] = "ABDE";
    action[1] = "ABC";
    action[2] = "BCEF";
    action[3] = "ADG";
    action[4] = "BDEFH";
    action[5] = "CFI";
    action[6] = "DEGH";
    action[7] = "GHI";
    action[8] = "EFHI";
}

class State{
public:
    int clocks[9];
    vector<int> sol;
    State() {};
    State(State *s){
        for (int i = 0; i < 9; ++i){
            clocks[i] = s->clocks[i];
        }
        sol = s->sol;
    }
    
    State *apply(int i){
        string act = action[i];
        State *news = new State(this);
        
        for (int j = 0; j < act.size(); ++j){
            int x = act[j] - 'A';
            news->clocks[x] += 3;
            news->clocks[x] %= 13;
        }
        news->sol.push_back(i+1);
        return news;
    }
    bool final(){
        for (int i = 0; i < 9; ++i){
            if (clocks[i] != 12) return false;
        }
        return true;
    }
};

int main(){
    ifstream in("clocks.in");
    ofstream out("clocks.out");
    init();
    
    State *start = new State();
    for (int i = 0; i < 9; ++i){
        int x; in >> x;
        start->clocks[i] = x;
    }
    queue<State*> states;
    states.push(start);
    State* sol;
    while (!states.empty()){
        // << states.size() << endl;
        State *state = states.front();
        states.pop();
        if (state->final()) {
            sol = state;
            break;
        }
        for (int i = 0; i < 9; ++i){
            states.push(state->apply(i));
        }
    }
    for (int i = 0; i < sol->sol.size(); ++i){
        out << sol->sol[i] << " ";
    }
    
    in.close();
    out.close();
    
    return 0;
}