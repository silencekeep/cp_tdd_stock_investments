#include "invest.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
    int i = 0, p = 0;
    string out;
    vector<xchange> xchg_list;
    vector<xchange_rate> xchg_rate_list;
    vector<question> questions;
    int a, b, c;
    bool aa = true, bb = true, cc = true;
    cin >> a;
    while (a--) {
        string s;
        if (aa) { cin.ignore(); aa = false; }
        getline(cin, s);
        xchg_list.emplace_back(string_to_exchange(s));
    }
    cin >> b;
    while (b--) {
        string s;
        if (bb) { cin.ignore(); bb = false; }
        getline(cin, s);
        xchg_rate_list.emplace_back(string_to_exchange_rate(s));
    }
    cin >> c;
    while (c--) {
        string s;
        if (cc) { cin.ignore(); cc = false; }
        getline(cin, s);
        questions.emplace_back(string_to_question(s));
    }
    vector<long long> list = get_xchg_result(xchg_rate_list, xchg_list, questions);
    for (int i = 0; i < list.size(); i++) {
        string xiaoshu = (list.at(i) % 100 == 0 ? "" : "." + to_string(list.at(i) % 100));
        cout << list.at(i) / 100 << xiaoshu << endl;
    }
    return 0;
}