#include <iostream>
#include <set>
#include <cmath>
using namespace std;

class Node{
public:
    Node *left,*right, *parent;
    static Node *root;
    int ctr, val, tot;
    Node (int val) { this->val = val; ctr = 0; tot = 0; left = NULL; right = NULL; parent=NULL;}
    unsigned long long int add(Node *n){
        unsigned long long int ret = 0;
        tot++;
        if (n->val < this->val){
            if (left) ret = left->add(n);
            else {
                left = n;
                n->parent = this;
            }
            ret += ctr+1;
        } else {
            if (right) ret = right->add(n);
            else {
                right = n;
                n->parent = this;
            }
            ctr++;
        }        
        return ret;
    }
    
    void refresh(){
        tot = 0;
        if (left) tot += 1 + left->tot;
        if (right) tot += 1 + right->tot;
        ctr = 0;
        if (right) ctr = 1 + right->tot;
    }
    void rot(bool lft = false){
        Node *n = lft ? right : left;
        if (n == NULL) return;
        if (parent == NULL) Node::root = n;
        else ((parent->left == this)? parent->left : parent->right) = n;    
        
        if (lft){
            right = n->left;
            if (n->left) {
                n->left->parent = this;
            }
            n->left = this;
        } else {
            left = n->right;
            if (n->right) n->right->parent = this;
            n->right = this;
        }
        refresh();
        n->refresh();
        n->parent = parent;
        parent = n;
    }
    
    void print(int depth=0){
        string s = "";
        for (int i = 0; i < depth; ++i) s+= "\t";
        if (right == NULL) cout << s << "\tNULL"<< endl;
        else right->print(depth+1);
        cout << s << val << endl;;
        if (left == NULL) cout << s << "\tNULL"<< endl;
        else left->print(depth+1);
    }
};
Node* Node::root;

void rot(int k){
    Node *node = Node::root;
    for (int i = 0; i < k; ++i){
        node->rot(true);
        node = node->parent->right;
    }
}

void dsw(Node *node, int n){
    while (node){
        while(node->left) {
            Node *nd = node->left;
            node->rot(false);
            node = nd;
        }
        node = node->right;
    }
    int h = floor(log2(n+1));
    int m = pow(2, h) -1;
    rot(n-m);
    while(m > 1){
        m /= 2; rot(m);
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        unsigned long long int sol = 0;
        for (int i = 0; i < n; ++i){
            int x; cin >> x;
            if (i == 0) Node::root = new Node(x);
            else{
                sol += Node::root->add(new Node(x));
            }
            if (i % 1000 == 0) 
                dsw(Node::root, i+1);
        }
        cout << sol << endl;
    }
    return 0;
}
