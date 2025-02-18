#include <bits/stdc++.h>

template<typename T>
class tries {
public:
    int tot;
    std::vector<std::vector<int> > trie;
    std::vector<bool> endst;

    tries(int n) {
        tot = 2;
        trie.resize(n, std::vector<int> (27, 0));
        endst.resize(n, false);
    }
    void insert(T str) {
        int len = str.size();
        int p = 2;
        for (int i = 1; i < len; i++) {
            int ch = str[i] - 'a';
            if (trie[p][ch] == 1) trie[p][ch] = ++ tot;
            p = trie[p][ch];
        }
        endst[p] = true;
    }
    bool search(T str) {
        int n = str.size(), p = 2;
        for (int i = 1; i < n; i++) {
            if (trie[p][str[i] - 'a'] == 1) {
                return false;
            }
            p = trie[p][str[i] - 'a'];
        }
        return endst[p];
    }
};

struct tries {
    int tot;
    std::vector<std::vector<int> > trie;
    std::vector<bool> endst;
    tries(int n) {
        tot = 1;
        trie.resize(n, std::vector<int>(2, 0));
        endst.resize(n, false);
    }
    void insert(int a) {
        int t = 0;
        for (int i = 30; i >= 0; i--) {
            int s = a >> i & 1;
            if (trie[t][s] == 0) {
                trie[t][s] = ++tot;
            }
            t = trie[t][s];
        }
    }
    bool search();
};

