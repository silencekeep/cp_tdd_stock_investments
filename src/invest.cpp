#include "invest.h"

xchange string_to_exchange(string input_line) {
    xchange result;
    stringstream ss(input_line);
    ss >> result.stock_type >> result.holder_name;
    ss >> result.currency >> result.stock_count;
    ss >> result.value_per_stock;
    return result;
}

xchange_rate string_to_exchange_rate(string input_line) {
    xchange_rate result;
    stringstream ss(input_line);
    ss >> result.source >> result.destination;
    ss >> result.ratio;
    return result;
}

question string_to_question(string input_line) {
    question result;
    stringstream ss(input_line);
    ss >> result.type >> result.name;
    ss >> result.currency;
    return result;
}

double get_exchange_ratio(
    const vector<xchange_rate>& exchange_rates, \
    const string& source, \
    const string& destination) {
    if (source == destination)
        return 1.0;
    for (auto it = exchange_rates.begin(); it != exchange_rates.end(); it++) {
        if (source == it->source && destination == it->destination)
            return it->ratio;
        if (destination == it->source && source == it->destination)
            return 1.0 / it->ratio;
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
        if (it->stock_type == stock) {
            double target_currency_value = it->stock_count * it->value_per_stock * \
                get_exchange_ratio(exchanges_rate, it->currency, currency);
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
        if (it->holder_name == name) {
            double target_currency_value = it->stock_count * it->value_per_stock * \
                get_exchange_ratio(exchanges_rate, it->currency, currency);
            result += target_currency_value;
        }
    }
    return result;
}

vector<int> get_xchg_result(
    const vector<xchange_rate>& exchanges_rate, \
    const vector<xchange>& exchanges, \
    const vector<question>& questions) {
    vector<int> result_list;
    for (auto it = questions.begin(); it != questions.end(); it++) {
        if (it->type == "PERSON") {
            double result = get_sum_exchanges_by_name(exchanges_rate, exchanges, it->currency, it->name);
            result_list.emplace_back(int(result));
        }
        else if (it->type == "STOCK") {
            double result = get_sum_exchanges_by_stock(exchanges_rate, exchanges, it->currency, it->name);
            result_list.emplace_back(int(result));
        }
        else {
            result_list.emplace_back(-1);
            break;
        }
    }
    return result_list;
}
