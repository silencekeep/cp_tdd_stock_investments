#include <string>
#include <vector>
#include <sstream>
#include "object.h"
using namespace std;

class xchange :public stock_object{
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

class xchange_rate :public stock_object {
private:
    std::string source;
    std::string destination;
    double ratio;

public:
    xchange_rate(const std::string& src, const std::string& dest, double rat)
        : source(src), destination(dest), ratio(rat) {}

    xchange_rate() : source(""), destination(""), ratio(0.0) {}

    std::string getSource() const { return source; }
    std::string getDestination() const { return destination; }
    double getRatio() const { return ratio; }

    void setSource(const std::string& src) { source = src; }
    void setDestination(const std::string& dest) { destination = dest; }
    void setRatio(double rat) { ratio = rat; }
};

class question : public stock_object {
private:
    std::string type;
    std::string name;
    std::string currency;

public:
    question(const std::string& qType, const std::string& qName, const std::string& curr)
        : type(qType), name(qName), currency(curr) {}

    question() : type(""), name(""), currency("") {}

    std::string getType() const { return type; }
    std::string getName() const { return name; }
    std::string getCurrency() const { return currency; }

    void setType(const std::string& qType) { type = qType; }
    void setName(const std::string& qName) { name = qName; }
    void setCurrency(const std::string& curr) { currency = curr; }
};

xchange string_to_exchange(string input_line);

xchange_rate string_to_exchange_rate(string input_line);

question string_to_question(string input_line);

double get_exchange_ratio(const vector<xchange_rate> &exchange_rates, const string &source, const string &destination);

double get_sum_exchanges_by_stock(const vector<xchange_rate> &exchanges_rate, const vector<xchange> &exchanges, const string &currency, const string &stock);

double get_sum_exchanges_by_name(const vector<xchange_rate> &exchanges_rate, const vector<xchange> &exchanges, const string &currency, const string &name);

vector<int> get_xchg_result(const vector<xchange_rate> &exchanges_rate, const vector<xchange> &exchanges, const vector<question> &questions);