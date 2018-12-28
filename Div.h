#include <string>
#include <stdexcept>
#include "Expression.h"
#include "BineryExpression.h"
#include "Num.h"
#ifndef PROJECT1_DIV_H
#define PROJECT1_DIV_H

/**
 * Div class inheritors Expression, BinaryExpression
 */
class Div : public Expression,public BinaryExpression {
public:
    /**
     * constructor-2 Expressions
     * @param leftArgument Expression
     * @param rightArgument Expression
     */
    Div(Expression *leftArgument, Expression *rightArgument) : BinaryExpression(leftArgument, rightArgument) {
    }

    /**
     * constructor-2 doubles
     * @param leftArgument double
     * @param rightArgument double
     */
    Div(double leftArgument, double rightArgument) : BinaryExpression(new Num(leftArgument), new Num(rightArgument)) {
    }

/**
* constructor- double and Expression
* @param leftArgument double
* @param rightArgument Expression
*/
    Div(double leftArgument, Expression *rightArgument) : BinaryExpression(new Num(leftArgument), rightArgument) {
    }
    /**
* constructor-Expression and double
* @param leftArgument Expression
* @param rightArgument double
*/
    Div(Expression *leftArgument, double rightArgument) : BinaryExpression(leftArgument, new Num(rightArgument)) {
    }

/**
 * calculate the div expression
 * @param assignment map
 * @return the value after calculate
 */
    virtual double calculate(map<string, double> &assignment) ;

    /**
     * A convenience method ,evaluate(assignment)`same to the evaluate method above,
     * but this methods use in empty assignment.
     *
     * @return the result of the expression using
     * @throws Exception if the expression contains a variable which is not in the assignment, an exception is thrown.
     */
    virtual double calculate() ;

};


#endif //PROJECT1_DIV_H