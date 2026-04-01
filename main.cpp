#include <bits/stdc++.h>
using namespace std;

class mystring {
private:
    char* ch = nullptr;
    int len = 0;

public:
    mystring() : ch(nullptr), len(0) {}

    mystring(int _len, int c) {
        if (_len < 0) _len = 0;
        len = _len;
        if (len > 0) {
            ch = new char[len];
            for (int i = 0; i < len; ++i) ch[i] = static_cast<char>(c);
        } else {
            ch = nullptr;
        }
    }

    mystring(string &c) {
        len = static_cast<int>(c.length());
        if (len > 0) {
            ch = new char[len];
            for (int i = 0; i < len; ++i) ch[i] = c[i];
        } else ch = nullptr;
    }

    mystring(const mystring &other) {
        len = other.len;
        if (len > 0) {
            ch = new char[len];
            memcpy(ch, other.ch, len);
        } else ch = nullptr;
    }

    mystring& operator=(const mystring &other) {
        if (this == &other) return *this;
        delete[] ch;
        len = other.len;
        if (len > 0) {
            ch = new char[len];
            memcpy(ch, other.ch, len);
        } else ch = nullptr;
        return *this;
    }

    ~mystring() { delete[] ch; ch = nullptr; len = 0; }

    // Indexing: if out of range, return '\0'
    char operator[](int x) const {
        if (x < 0 || x >= len) return '\0';
        return ch[x];
    }

    // Compare: lexicographical by characters, then by length
    bool operator<(const mystring &rhs) const {
        int n = min(len, rhs.len);
        for (int i = 0; i < n; ++i) {
            if (ch[i] != rhs.ch[i]) return ch[i] < rhs.ch[i];
        }
        return len < rhs.len;
    }

    // Append another mystring to this one
    void ADD(const mystring &rhs) {
        if (rhs.len == 0) return;
        char* nch = new char[len + rhs.len];
        if (len > 0) memcpy(nch, ch, len);
        memcpy(nch + len, rhs.ch, rhs.len);
        delete[] ch;
        ch = nch;
        len += rhs.len;
    }

    // Output without newline (use iostream to avoid mixing issues)
    void out() const {
        for (int i = 0; i < len; ++i) cout << ch[i];
    }

    int get_len() const { return len; }
};

string str_in1, str_in2;
int n, id;

int main() {
    // Keep default sync_with_stdio to avoid mixing issues with puts
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    if (!(cin >> id)) return 0;
    if (id == 1) {
        mystring str1(100, 'a');
        str1.out(); puts("");
        // cout << str1 << endl;
    } else if (id == 2) {
        cin >> str_in1;
        mystring str2 = str_in1; // implicit via mystring(string &)
        cin >> n;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            cout << str2[x] << '\n';
        }
    } else if (id == 3) {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        cout << (int)(str2 < str3) << '\n';
    } else if (id == 4) {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        str2.ADD(str3);
        str2.out(); puts("");
        // cout << str2 << endl;
    } else {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        cin >> n;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            cout << str3[x] << '\n';
        }
        cout << str2.get_len() << " " << str3.get_len() << '\n';
        cout << (int)(str2 < str3) << '\n';
        str2.ADD(str3);
        str2.out(); puts("");
        // cout << str2 << endl;
        cout << str2.get_len() << '\n';
    }
    return 0;
}
