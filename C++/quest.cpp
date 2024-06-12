#include <iostream>

using namespace std;

const int TABLE_SIZE = 101;

struct HashEntry {
    string key;
    bool isDeleted;

    HashEntry() : key(""), isDeleted(false) {}
};

struct Dictionary {
    HashEntry table[TABLE_SIZE];
    int cnt;
    int m;

    Dictionary() : cnt(0), m(TABLE_SIZE) {}

    int hashFunction(const string& K) {
        int h = 0;
        int n = K.length();
        for (int i = 0; i < n; ++i) {
            h += (K[i] * (i + 1));
        }
        return (19 * h) % m;
    }
};

int perm(int i) {
    return i * i + 23 * i;
}

int find(Dictionary& d, const string& k) {
    int pos = d.hashFunction(k);
    for (int i = 0; i < 20; ++i) {
        int newPos = (pos + perm(i)) % d.m;
        if (d.table[newPos].key == k && !d.table[newPos].isDeleted) {
            return newPos;
        }
        if (d.table[newPos].key == "" && !d.table[newPos].isDeleted) {
            break;
        }
    }
    return -1;
}

void insert(Dictionary& d, const string& k) {
    if (d.cnt < d.m && find(d, k) == -1) {
        int pos = d.hashFunction(k);
        if (d.table[pos].key != "" && !d.table[pos].isDeleted) {
            int i = 0;
            int newPos;
            do {
                i++;
                int offset = perm(i - 1);
                newPos = (pos + offset) % d.m;
            } while (d.table[newPos].key != "" && !d.table[newPos].isDeleted);
            pos = newPos;
        }
        d.table[pos].key = k;
        d.table[pos].isDeleted = false;
        d.cnt++;
    }
}

void remove(Dictionary& d, const string& k) {
    int pos = find(d, k);
    if (pos != -1) {
        d.table[pos].isDeleted = true;
        d.table[pos].key = "";
        d.cnt--;
    }
}

void processTestCase() {
    Dictionary d;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string operation;
        cin >> operation;
        if (operation.substr(0, 3) == "ADD") {
            string key = operation.substr(4);
            insert(d, key);
        } else if (operation.substr(0, 3) == "DEL") {
            string key = operation.substr(4);
            remove(d, key);
        }
    }
    cout << d.cnt << endl;
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (d.table[i].key != "" && !d.table[i].isDeleted) {
            cout << i << ":" << d.table[i].key << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        processTestCase();
    }
    return 0;
}