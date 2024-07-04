#include <string>
#include <vector>
#include <sstream>
using namespace std;

typedef struct {
    string stock_type;
    string holder_name;
    int stock_count;
    string currency;
    int value_per_stock;
} xchange;

typedef struct {
    string source;
    string destination;
    double ratio;
} xchange_rate;

typedef struct {
    string type;
    string name;
    string currency;
} question;

xchange string_to_exchange(string input_line);

xchange_rate string_to_exchange_rate(string input_line);

question string_to_question(string input_line);

double get_exchange_ratio(const vector<xchange_rate> &exchange_rates, const string &source, const string &destination);

double get_sum_exchanges_by_stock(const vector<xchange_rate> &exchanges_rate, const vector<xchange> &exchanges, const string &currency, const string &stock);

double get_sum_exchanges_by_name(const vector<xchange_rate> &exchanges_rate, const vector<xchange> &exchanges, const string &currency, const string &name);

vector<int> get_xchg_result(const vector<xchange_rate> &exchanges_rate, const vector<xchange> &exchanges, const vector<question> &questions);