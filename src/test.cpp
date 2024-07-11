#include "gtest/gtest.h"
#include "invest.h"

string getOut1(){
    
}

TEST(testCase, given_sample_in_ppt) 
{
    int i = 0, p = 0;
    vector<string> input;
    string output = "25000\n35000\n";
    
    input.emplace_back("2");
    input.emplace_back("A ZhangSan CNY 1000 25");
    input.emplace_back("A LiSi JPY 2200 100");
    input.emplace_back("1");
    input.emplace_back("CNY JPY 22");
    input.emplace_back("2");
    input.emplace_back("PERSON ZhangSan CNY");
    input.emplace_back("STOCK A CNY");

    string out;
    vector<xchangeImpl> xchg_list;
    vector<xchange_rateImpl> xchg_rate_list;
    vector<questionImpl> questions;
    int a = stol(input[p++]);
    while(a--) xchg_list.emplace_back(string_to_exchange(input[p++]));
    int b = stol(input[p++]);
    while(b--) xchg_rate_list.emplace_back(string_to_exchange_rate(input[p++]));
    int c = stol(input[p++]);
    while(c--) questions.emplace_back(string_to_question(input[p++]));
    vector<int> list = get_xchg_result(xchg_rate_list, xchg_list, questions);
    for(int i = 0; i < list.size(); i++){
        out += to_string(list[i]) + "\n";
    }
    EXPECT_EQ(out,output);
}

TEST(testCase, generated_by_chatgpt) 
{
    int i = 0, p = 0;
    vector<string> input;
    string output = "437747\n582589\n97518\n18075800\n";
    
    input.emplace_back("35");
    input.emplace_back("A ZhangSan CNY 1000 25");
    input.emplace_back("A ZhangSan CNY 2000 30");
    input.emplace_back("A ZhangSan USD 1500 20");
    input.emplace_back("A ZhangSan EUR 1200 15");
    input.emplace_back("A LiSi JPY 2200 100");
    input.emplace_back("A LiSi JPY 1800 80");
    input.emplace_back("A LiSi USD 300 15");
    input.emplace_back("A LiSi EUR 500 25");
    input.emplace_back("B WangWu USD 500 30");
    input.emplace_back("B WangWu EUR 600 40");
    input.emplace_back("B WangWu JPY 1000 50");
    input.emplace_back("B ZhaoLiu EUR 800 20");
    input.emplace_back("B ZhaoLiu USD 700 25");
    input.emplace_back("B ZhaoLiu CNY 4000 35");
    input.emplace_back("C QianQi CNY 3000 10");
    input.emplace_back("C QianQi USD 2000 15");
    input.emplace_back("C QianQi EUR 1500 12");
    input.emplace_back("D SunBa USD 700 25");
    input.emplace_back("D SunBa EUR 900 30");
    input.emplace_back("D SunBa JPY 1200 40");
    input.emplace_back("D ZhouJiu JPY 1800 110");
    input.emplace_back("D ZhouJiu JPY 2000 90");
    input.emplace_back("D ZhouJiu USD 1500 80");
    input.emplace_back("E WuShi CNY 500 28");
    input.emplace_back("E WuShi JPY 1000 40");
    input.emplace_back("E WuShi EUR 800 22");
    input.emplace_back("E ZhengShiYi EUR 600 18");
    input.emplace_back("E ZhengShiYi USD 400 30");
    input.emplace_back("E ZhengShiYi CNY 1500 12");
    input.emplace_back("F WangShiEr USD 1000 35");
    input.emplace_back("F WangShiEr JPY 2000 75");
    input.emplace_back("F WangShiEr EUR 1200 30");
    input.emplace_back("F ZhaoShiSan JPY 2500 95");
    input.emplace_back("F ZhaoShiSan JPY 3000 110");
    input.emplace_back("F ZhaoShiSan USD 2000 85");
    input.emplace_back("6");
    input.emplace_back("CNY JPY 22");
    input.emplace_back("CNY USD 0.14");
    input.emplace_back("CNY EUR 0.13");
    input.emplace_back("USD JPY 105.26");
    input.emplace_back("USD EUR 0.89");
    input.emplace_back("EUR JPY 117.65");
    input.emplace_back("4");
    input.emplace_back("PERSON ZhangSan CNY");
    input.emplace_back("STOCK A CNY");
    input.emplace_back("STOCK B USD");
    input.emplace_back("STOCK D JPY");

    string out;
    vector<xchangeImpl> xchg_list;
    vector<xchange_rateImpl> xchg_rate_list;
    vector<questionImpl> questions;
    int a = stol(input[p++]);
    while(a--) xchg_list.emplace_back(string_to_exchange(input[p++]));
    int b = stol(input[p++]);
    while(b--) xchg_rate_list.emplace_back(string_to_exchange_rate(input[p++]));
    int c = stol(input[p++]);
    while(c--) questions.emplace_back(string_to_question(input[p++]));
    vector<int> list = get_xchg_result(xchg_rate_list, xchg_list, questions);
    for(int i = 0; i < list.size(); i++){
        out += to_string(list[i]) + "\n";
    }
    EXPECT_EQ(out,output);
}

TEST(testCase, manual_adapted) 
{
    int i = 0, p = 0;
    vector<string> input;
    string output = "158571428\n25070000\n";
    
    input.emplace_back("2");
    input.emplace_back("F LaoShi CNY 100000 205");
    input.emplace_back("F XueSheng USD 22200 1000");
    input.emplace_back("1");
    input.emplace_back("CNY USD 0.14");
    input.emplace_back("2");
    input.emplace_back("PERSON XueSheng CNY");
    input.emplace_back("STOCK F USD");

    string out;
    vector<xchangeImpl> xchg_list;
    vector<xchange_rateImpl> xchg_rate_list;
    vector<questionImpl> questions;
    int a = stol(input[p++]);
    while(a--) xchg_list.emplace_back(string_to_exchange(input[p++]));
    int b = stol(input[p++]);
    while(b--) xchg_rate_list.emplace_back(string_to_exchange_rate(input[p++]));
    int c = stol(input[p++]);
    while(c--) questions.emplace_back(string_to_question(input[p++]));
    vector<int> list = get_xchg_result(xchg_rate_list, xchg_list, questions);
    for(int i = 0; i < list.size(); i++){
        out += to_string(list[i]) + "\n";
    }
    EXPECT_EQ(out,output);
}

TEST(testCase, empty_sample) 
{
    int i = 0, p = 0;
    vector<string> input;
    string output = "";
    
    input.emplace_back("0");
    input.emplace_back("0");
    input.emplace_back("0");

    string out;
    vector<xchangeImpl> xchg_list;
    vector<xchange_rateImpl> xchg_rate_list;
    vector<questionImpl> questions;
    int a = stol(input[p++]);
    while(a--) xchg_list.emplace_back(string_to_exchange(input[p++]));
    int b = stol(input[p++]);
    while(b--) xchg_rate_list.emplace_back(string_to_exchange_rate(input[p++]));
    int c = stol(input[p++]);
    while(c--) questions.emplace_back(string_to_question(input[p++]));
    vector<int> list = get_xchg_result(xchg_rate_list, xchg_list, questions);
    for(int i = 0; i < list.size(); i++){
        out += to_string(list[i]) + "\n";
    }
    EXPECT_EQ(out,output);
}

TEST(testCase, shrinked_chatgpt_sample) 
{
    int i = 0, p = 0;
    vector<string> input;
    string output = "144842\n21704945\n20224\n";
    
    input.emplace_back("16");
    input.emplace_back("A ZhangSan CNY 1000 25");
    input.emplace_back("A ZhangSan CNY 2000 30");
    input.emplace_back("A ZhangSan USD 1500 20");
    input.emplace_back("A ZhangSan EUR 1200 15");
    input.emplace_back("A LiSi JPY 2200 100");
    input.emplace_back("A LiSi JPY 1800 80");
    input.emplace_back("A LiSi USD 300 15");
    input.emplace_back("A LiSi EUR 500 25");
    input.emplace_back("A WangWu USD 500 30");
    input.emplace_back("A WangWu JPY 1000 50");
    input.emplace_back("A ZhaoLiu EUR 800 20");
    input.emplace_back("A ZhaoLiu USD 700 25");
    input.emplace_back("A ZhaoLiu CNY 4000 35");
    input.emplace_back("A QianQi CNY 3000 10");
    input.emplace_back("A QianQi USD 2000 15");
    input.emplace_back("B QianQi EUR 1500 12");
    input.emplace_back("6");
    input.emplace_back("CNY JPY 22");
    input.emplace_back("CNY USD 0.14");
    input.emplace_back("CNY EUR 0.13");
    input.emplace_back("USD JPY 105.26");
    input.emplace_back("USD EUR 0.89");
    input.emplace_back("EUR JPY 117.65");
    input.emplace_back("3");
    input.emplace_back("PERSON LiSi CNY");
    input.emplace_back("STOCK A JPY");
    input.emplace_back("STOCK B USD");

    string out;
    vector<xchangeImpl> xchg_list;
    vector<xchange_rateImpl> xchg_rate_list;
    vector<questionImpl> questions;
    int a = stol(input[p++]);
    while(a--) xchg_list.emplace_back(string_to_exchange(input[p++]));
    int b = stol(input[p++]);
    while(b--) xchg_rate_list.emplace_back(string_to_exchange_rate(input[p++]));
    int c = stol(input[p++]);
    while(c--) questions.emplace_back(string_to_question(input[p++]));
    vector<int> list = get_xchg_result(xchg_rate_list, xchg_list, questions);
    for(int i = 0; i < list.size(); i++){
        out += to_string(list[i]) + "\n";
    }
    EXPECT_EQ(out,output);
}
    
int main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}