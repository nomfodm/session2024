#include <bits/stdc++.h>

using namespace std;

#define no cout << "NO"

int main () {
    string s;
    getline(cin, s);

    vector<int> alphabet(26, 0);
    for (char c : s) {
        if (toupper(c) >= 'A' && toupper(c) <= 'Z') {
            alphabet[toupper(c) - 'A']++;
        }
    }

    bool f = true;
    for (int i : alphabet) {
        if (i != 0) {
            f = false;
            break;
        }
    }

    if (f) {
        no;
        return 0;
    }

    string left = "";
    string mid = "";

    bool single = false;
    
    for (int i = 25; i >= 0; i--) {
        if (!alphabet[i]) continue;

        if (alphabet[i] % 2 != 0) {
            if (single) {
                no;
                return 0;
            }
            single = true;
            mid = toupper(char(i + 'A'));
            alphabet[i]--;
            i++;
        } else {
            for (int j = 0; j < alphabet[i] / 2; ++j) {
                left.push_back(toupper(char(i + 'A')));
            }
        }
    }

    cout << left << mid;
    for (int i = left.size() - 1; i >= 0; i--) {
        cout << left[i];
    }

    return 0;
}