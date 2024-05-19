#include <bits/stdc++.h>

using namespace std;

struct student {
    string surname;
    string name;
    string form;
    string birthdate;
};

int getFormNumber(string form) {
    int a = form[0] - '0';
    if (form.size() == 3) {
        a = (form[1] - '0') + 10;
    }

    return a;
}

bool comp(student a, student b) {
    int form_a = getFormNumber(a.form);
    int form_b = getFormNumber(b.form);

    if (form_a < form_b) return true;
    if (a.form.back() < b.form.back() && form_a == form_b) return true;
    if (a.surname < b.surname && a.form.back() == b.form.back() && form_a == form_b) return true;

    return false;
}

int main () {
    int n;
    cin >> n;

    vector<student> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].surname >> v[i].name >> v[i].form >> v[i].birthdate;
    }

    sort(v.begin(), v.end(), comp);

    for (student i : v) {
        cout << i.form << " " << i.surname << " " << i.name << " " << i.birthdate << endl;
    }

    return 0;
}
