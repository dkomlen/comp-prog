#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long int

//101-november-13

vector<int> data;

class Node{
public:
    int minimum, l, r;
    Node *left, *right;

    Node (int l, int r){
        int mid = (l+r)/2;
        this->l = l;
        this->r = r;
        if (l != r) {
            left = new Node(l, mid);
            right = new Node(mid+1, r);
        } else {
            minimum = data[l];
            left = NULL; right = NULL;
        }
        this->calc();
    }
    int getmin(int l, int r){
        int m = (l+r)/2;
        int mid = (this->l + this->r) / 2;

        if (l == this->l && r == this->r) return this->minimum;
        else if (l > mid) return right->getmin(l, r);
        else if (r <= mid) return left->getmin(l, r);
        return min(left->getmin(l, mid), right->getmin(mid+1, r));
    }
    void calc(){
        if (left && right)
            minimum = min(left->minimum, right->minimum);
        else if (left) minimum = left->minimum;
        else if (right) minimum = right->minimum;
    }
};

int main(){
    int n, x; cin >> n >> x;

    for (int i = 0; i < n; ++i){
        int k; cin >> k; data.push_back(k);
    }
    Node *root = new Node(0, n-1);
    while(x--){
        int x,y; cin >> x >> y;
        cout << root->getmin(x,y) << endl;
    }
    return 0;
}