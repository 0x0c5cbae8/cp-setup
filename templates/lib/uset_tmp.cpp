#include <templates/init>

#define P Node<T>*
template <typename T> struct Node {
    Node *l=0, *r=0, *p=0;
    T val;
    int y;
    size_t sz=1;
    Node(T val) : val(val), y(rand()) {}
    static size_t getsz(P n) { return n ? n->sz : 0; }
    void pull() {
        sz = getsz(l) + getsz(r) + 1;
        l->p = r->p = this;
    }
    static P find_by_order(P n, int k) {
        if(!n || k < 0 || k >= getsz(n)) return 0;
        if(getsz(n->l) > k) return find_by_order(n->l, k);
        if(getsz(n->l) < k) return find_by_order(n->r, k - getsz(n->l) - 1);
        return n; // n->val == k
    }
    static int order_of_key(P n, T k) {
        if(!n) return 0;
        if(n->val < k) return getsz(n->l) + 1 + order_of_key(n->r, k);
        else return order_of_key(n->l, k);
    }
    static P lower_bound(P n, T k) {
        if(!n) return 0;
        if(n->val < k) return lower_bound(n->r, k);
        else {
            auto l = lower_bound(n->l, k);
            return l ? l : n; // n->val >= k
        }
    }
    static pair<P, P> split(P n, int k) {
        if(!n)return {};
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
    static P merge(P l, P r) {
        if (!l) return r;
        if (!r) return l;
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
};


template <typename T> struct uset {
    Node<T>* t = 0;
    template<class F> void foreach(Node<T>* n, F f) {
        if(n){
            foreach(n->l, f);
            f(n->val);
            foreach(n->r, f);
        }
    }
    void ins(Node<T>* t, Node<T>* n, int pos) {
        auto pa = split(t, pos);
        return merge(merge(pa.first, n), pa.second);
    }
};


