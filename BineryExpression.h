
#include <string>
#include <map>
#include <iostream>
#include <cmath>
#include "Expression.h"

#ifndef PROJECT1_BINERYEXPRESSION_H
#define PROJECT1_BINERYEXPRESSION_H


class BineryExpression {
    //Members
public:
    Expression *leftArgument;
    Expression *rightArgument;
    /**
     * The BinaryExpression constructor by two expression and operator.
     *
     * @param leftArgument  the left side argument
     * @param rightArgument the right side argument
     * @param operator      string of the class.
     */
public:

    /**
     * distructor
     */
    virtual ~BinaryExpression() {
        delete leftArgument;
        delete rightArgument;
    }

    /**
     * constructor
     */
    BinaryExpression(Expression *leftArgument, Expression *rightArgument) {
        this->leftArgument = leftArgument;
        this->rightArgument = rightArgument;
    }
};
#endif //PROJECT1_BINERYEXPRESSION_H
