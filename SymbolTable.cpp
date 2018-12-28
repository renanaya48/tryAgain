#include "SymbolTable.h"


void SymbolTable::addPairSymbol(string key, string value) {
    this->bindMap->addToPathMap(key, value);
    if (this->flightValues->getFlightVauleMap().count(key)) {
        this->symbols.insert(pair<string, double>(key, this->flightValues->getFlightVauleMap()
                .find(value)->second));
    } else {
        double tempValue = this->getValue(value);
        this->symbols.insert(pair<string, double>(key,tempValue));
        this->bindedSymbols.insert(pair<string, string>(key, value));
        this->bindedSymbols.insert(pair<string, string>(value, key));
    }
}

string SymbolTable::getPath(string key){
    if (bindMap->getBindMap().count(key)){
        return bindMap->getBindMap().find(key)->second;
    } else if (this->bindedSymbols.count(key)){
        return bindMap->getBindMap().find(this->bindedSymbols.find(key)->second)->second;
    } else {
        throw ("Path not found\n");
    }
}

void SymbolTable::setSymbol(string key, double num){
    if(this->bindedSymbols.count(key)){
        string tempBind = this->bindedSymbols.find(key)->second;
        symbols.find(key)->second = num;
        symbols.find(tempBind)->second = num;
    } else if (this->bindMap->getBindMap().count(key)){
        symbols.find(key)->second = num;
    }
}

void SymbolTable::addSymbol(string s, double num){
    symbols.insert(std::pair<string, double>(s, num));
}

map<string, double> SymbolTable::getSymbols(){
    return this->symbols;
}

double SymbolTable::getValue(string s){
    return this->symbols.find(s)->second;
}

/*void SymbolTable::setBindedSymbols(string s1, string s2){
    this->bindedSymbols.insert(std::pair<string, string>(s1, s2));
    addSymbol(s1, getValue(s2));
}
map<string, string> SymbolTable::getBindedSymbols(){
    return this->bindedSymbols;
}*/