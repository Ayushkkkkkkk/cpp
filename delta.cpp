#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        if (n == 1) {
            int q;
            scanf("%d", &q);
            while (q--) {
                int pos, val;
                scanf("%d %d", &pos, &val);
                cout << val << " ";
            }
            cout << "\n";
            continue;
        }
        multiset<int> aset;
        for (int i = 0; i < n; ++i) {
            aset.insert(a[i]);
        }
        multiset<int> deltas;
        for (auto it = ++aset.begin(); it != aset.end(); ++it) {
            auto prev = it;
            --prev;
            deltas.insert(*it - *prev);
        }
        int q;
        scanf("%d", &q);
        while (q--) {
            int pos, val;
            scanf("%d %d", &pos, &val);
            auto it = aset.find(a[pos - 1]);
            auto nxt = it, prev = it;
            ++nxt; --prev;
            if (it == aset.begin()) {
                deltas.erase(deltas.find(*nxt - *it));
            } else if (it == --aset.end()) {
                deltas.erase(deltas.find(*it - *prev));
            } else {
                deltas.erase(deltas.find(*nxt - *it));
                deltas.erase(deltas.find(*it - *prev));
                deltas.insert(*nxt - *prev);
            }
            aset.erase(it);
            aset.insert(val);
            it = aset.find(val);
            nxt = it, prev = it;
            ++nxt; --prev;
            if (it == aset.begin()) {
                deltas.insert(*nxt - *it);
            } else if (it == --aset.end()) {
                deltas.insert(*it - *prev);
            } else {
                deltas.insert(*nxt - *it);
                deltas.insert(*it - *prev);
                deltas.erase(deltas.find(*nxt - *prev));
            }
            a[pos - 1] = val;
            cout << *--aset.end() + *--deltas.end() << " ";
        }
        cout << "\n";
    }
    return 0;
}