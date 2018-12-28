#include <string>
#include <stdexcept>
#include "Expression.h"
#include "BineryExpression.h"
#include "Num.h"
#ifndef PROJECT1_PLUS_H
#define PROJECT1_PLUS_H


/**
 * Plus class inheritors Expression, BinaryExpression
 */
class Plus : public Expression,public BinaryExpression {
public:
    Plus(Expression *leftArgument, Expression *rightArgument) : BinaryExpression(leftArgument, rightArgument
                                                                                 ) {
    }

    Plus(double leftArgument, double rightArgument) : BinaryExpression(new Num(leftArgument), new Num(rightArgument)
                                                                       ) {
    }

    Plus(double leftArgument, Expression *rightArgument) : BinaryExpression(new Num(leftArgument), rightArgument
                                                                            ) {
    }
    Plus(Expression *leftArgument, double rightArgument) : BinaryExpression(leftArgument, new Num(rightArgument)
                                                                            ) {
    }
    /**
     * calculate the expression
     * @param assignment map
     * @return the calculate of the experession
     */
    virtual double calculate(map<string, double> &assignment) ;

    /**
     * A convenience method ,evaluate(assignment)`same to the evaluate method above,
     * but this methods use in empty assignment.
     *
     * @return the result of the expression using
     */
    virtual double calculate() ;
};


#endif //PROJECT1_PLUS_H