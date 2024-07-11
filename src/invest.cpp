#include "invest.h"

xchange string_to_exchange(string input_line) {
    xchange result;
    string stock_type, holder_name, currency;
    int stock_count, value_per_stock;
    stringstream ss(input_line);
    ss >> stock_type >> holder_name;
    ss >> currency >> stock_count;
    ss >> value_per_stock;
    result.setValuePerStock(value_per_stock);
    result.setCurrency(currency);
    result.setStockCount(stock_count);
    result.setStockType(stock_type);
    result.setHolderName(holder_name);
    return result;
}

xchange_rate string_to_exchange_rate(string input_line) {
    xchange_rate result;
    string source, destination;
    double ratio;
    stringstream ss(input_line);
    ss >> source >> destination;
    ss >> ratio;
    result.setDestination(destination);
    result.setSource(source);
    result.setRatio(ratio);
    return result;
}

question string_to_question(string input_line) {
    question result;
    stringstream ss(input_line);
    string type, name, currency;
    ss >> type >> name >> currency;
    result.setCurrency(currency);
    result.setType(type);
    result.setName(name);
    return result;
}

double get_exchange_ratio(
    const vector<xchange_rate>& exchange_rates, \
    const string& source, \
    const string& destination) {
    if (source == destination)
        return 1.0;
    for (auto it = exchange_rates.begin(); it != exchange_rates.end(); it++) {
        if (source == it->getSource() && destination == it->getDestination())
            return it->getRatio();
        if (destination == it->getSource() && source == it->getDestination())
            return 1.0 / it->getRatio();
    }
    return -1.0;
}

double get_sum_exchanges_by_stock(
    const vector<xchange_rate>& exchanges_rate, \
    const vector<xchange>& exchanges, \
    const string& currency, \
    const string& stock) {
    double result = 0;
    for (auto it = exchanges.begin(); it != exchanges.end(); it++) {
        if (it->getStockType() == stock) {
            double target_currency_value = it->getStockCount() * it->getValuePerStock() * \
                get_exchange_ratio(exchanges_rate, it->getCurrency(), currency);
            result += target_currency_value;
        }
    }
    return result;
}

double get_sum_exchanges_by_name(
    const vector<xchange_rate>& exchanges_rate, \
    const vector<xchange>& exchanges, \
    const string& currency, \
    const string& name) {
    double result = 0;
    for (auto it = exchanges.begin(); it != exchanges.end(); it++) {
        if (it->getHolderName() == name) {
            double target_currency_value = it->getStockCount() * it->getValuePerStock() * \
                get_exchange_ratio(exchanges_rate, it->getCurrency(), currency);
            result += target_currency_value;
        }
    }
    return result;
}

vector<long long> get_xchg_result(
    const vector<xchange_rate>& exchanges_rate, \
    const vector<xchange>& exchanges, \
    const vector<question>& questions) {
    vector<long long> result_list;
    for (auto it = questions.begin(); it != questions.end(); it++) {
        if (it->getType() == "PERSON") {
            double result = get_sum_exchanges_by_name(exchanges_rate, exchanges, it->getCurrency(), it->getName());
            result_list.emplace_back(static_cast<long long>(result * 100));
        }
        else if (it->getType() == "STOCK") {
            double result = get_sum_exchanges_by_stock(exchanges_rate, exchanges, it->getCurrency(), it->getName());
            result_list.emplace_back(static_cast<long long>(result * 100));
        }
        else {
            result_list.emplace_back(-1);
            break;
        }
    }
    return result_list;
}
