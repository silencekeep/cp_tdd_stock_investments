#include <string>
#include <vector>
#include <sstream>
using namespace std;

class xchange {
private:
    std::string stock_type;
    std::string holder_name;
    int stock_count;
    std::string currency;
    int value_per_stock;
public:
    xchange(std::string type, std::string name, int count, std::string curr, int value)
        : stock_type(type), holder_name(name), stock_count(count), currency(curr), value_per_stock(value) {}

    xchange() : stock_type(""), holder_name(""), stock_count(0), currency(""), value_per_stock(0) {}

    std::string getStockType() const { return stock_type; }
    std::string getHolderName() const { return holder_name; }
    int getStockCount() const { return stock_count; }
    std::string getCurrency() const { return currency; }
    int getValuePerStock() const { return value_per_stock; }

    void setStockType(const std::string& type) { stock_type = type; }
    void setHolderName(const std::string& name) { holder_name = name; }
    void setStockCount(int count) { stock_count = count; }
    void setCurrency(const std::string& curr) { currency = curr; }
    void setValuePerStock(int value) { value_per_stock = value; }
};


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