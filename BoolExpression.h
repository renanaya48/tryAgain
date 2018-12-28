#include "Expression.h"
#include "CreateExpression.h"
#include <map>
#ifndef PROJECT1_BOOLEXPRESSION_H
#define PROJECT1_BOOLEXPRESSION_H


/**
 * BoolExpression class
 */
class BoolExpression  {
    Expression* leftArgument;
    Expression* rightArgument;
    string action;
public:
/**
 * constructor
 * @param stringCondition the condition by string
 */
    BoolExpression(string stringCondition);

 /**
 * the function gets a condition in string and makes it to expression.
 * @param boolCondition the condition
 */
    void createBoolExpression(string boolCondition);

 /**
 * the function calculate the condition and returns the answer
 * @param symbolMap the symbol map
 * @return true / false according to the condition
 */
    bool calculateBool(map <string,double> symbolMap);

};
#endif //PROJECT1_BOOLEXPRESSION_H
