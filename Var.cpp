#include "Var.h"

Var::Var(string v) {
    this->var = v;
}

double Var::calculate(map<string, double> &assignment) {
    if(assignment.count(this->var)){
        return assignment.find(this->var)->second;
    } else {
        throw "error: no such variable";
    }
}

double Var::calculate() {
    map<string, double> temp;
    calculate(temp);
}