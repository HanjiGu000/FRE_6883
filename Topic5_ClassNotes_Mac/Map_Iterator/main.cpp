//
//  main.cpp
//  Map_Iterator
//
//  Created by Hanji Gu on 11/22/21.
//

#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

struct Option
{
    string type;
    double price;
    string symbol;
    
    Option() :type(""), price(0), symbol("") {}
    Option(string type_, double price_, string symbol_)
        :type(type_), price(price_), symbol(symbol_) {}
};

int main() {
    map<string, Option> myMap;
    myMap["MSFT211001P"] = Option("Put", 297.50, "MSFT");
    myMap["TSLA211001C"] = Option("Call", 975.00, "TSLA");
    myMap["AAPL211001C"] = Option("Call", 75.00, "AAPL");
    
    map<string, Option>::iterator itr;
    for (itr = myMap.begin(); itr != myMap.end(); itr++)
    {
        cout << fixed << setprecision(2)
             << itr->first << " " << itr->second.type << " " << itr->second.price << " " << itr->second.symbol <<endl;
    }
    return 0;
}

/*
 AAPL211001C Call 75.00 AAPL
 MSFT211001P Put 297.50 MSFT
 TSLA211001C Call 975.00 TSLA
 */
