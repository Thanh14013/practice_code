#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
public:
    int n;
    vector<int> st;
    SegmentTree(int n)
    {
        this->n = n;
        st.assign(4 * n, 0);
    };
    void build(vector<int> &a, int v, int tl, int tr)
    {
        if (tl == tr)
        {
            st[v] = a[tl];
        }
        else
        {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            st[v] = st[v * 2] + st[v * 2 + 1];
        }
    }
    void update(int v, int pos, int newval, int tl, int tr)
    {
        if (tl == tr)
        {
            st[v] = newval;
        }
        else
        {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, pos, newval, tl, tm);
            else
                update(v * 2 + 1, pos, newval, tm + 1, tr);
            st[v] = st[v * 2] + st[v * 2 + 1];
        }
    }
    int doSth(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return 0;
        else
        {
            if (l == tl && r == tr)
                return st[v];
            int tm = (tl + tr) / 2;
            return doSth(v * 2, tl, tm, l, min(r, tm)) + doSth(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        }
    }
};