#include <templates/init>

struct Node {
    Node *l = 0, *r = 0;
    int val, y, sz = 1;
    bool inv = 0;
    Node(int val) : val(val), y(rand()) {}
    void pull();
    void push();
};

int getsz(Node* n) { return n ? n->sz : 0; }

void Node::push() {
    if(inv){
        swap(l, r);
        if(l) l->inv ^= 1;
        if(r) r->inv ^= 1;
        inv = 0;
    }
}

void Node::pull() {
    sz = getsz(l) + getsz(r) + 1;
}

template<class F> void foreach(Node* n, F f) {
    if(n){
        n->push();
        foreach(n->l, f);
        f(n->val);
        foreach(n->r, f);
    }
}

pair<Node*, Node*> split(Node* n, int k) {
    if(!n)return {};
    n->push();
    if(getsz(n->l)>=k) { // ”n−>val >= k” for lower bound(k)
        auto pa = split(n->l, k);
        n->l = pa.second;
        n->pull();
        return {pa.first, n};
    }else{
        auto pa = split(n->r, k - getsz(n->l) - 1); // and just ”k”
        n->r = pa.first;
        n->pull();
        return {n, pa.second};
    }
}

Node* merge(Node* l, Node* r) {
    if (!l) return r;
    if (!r) return l;
    l->push();
    r->push();
    if (l->y > r->y) {
        l->r = merge(l->r, r);
        l->pull();
        return l;
    } else {
        r->l = merge(l, r->l);
        r->pull();
        return r;
    }
}

Node* ins(Node* t, Node* n, int pos) {
    auto pa = split(t, pos);
    return merge(merge(pa.first, n), pa.second);
}
