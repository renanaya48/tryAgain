#include "CreateExpression.h"

/**
 * constructor
 */
CreateExpression::CreateExpression() {

}

/**
 * shunting yard
 * @param str the string to make expression
 * @return
 */
Expression *CreateExpression::convertToExpression(string str) {
    string oprtatorList = "";
    stack<Expression *> expressions;
    stack<string> operators;
    int stringLength = 0;
    int resultLength = 0;
    //go on all the string
    while (stringLength < str.length()) {
        //if there is a (, put in the stack
        if (str[stringLength] == '(') {
            operators.push("(");
            // if there is a )
        } else if (str[stringLength] == ')') {
            string temp;
            //until the ( is in the top og the stack
            while (operators.top() != "(") {
                temp = operators.top();
                oprtatorList += temp;
                operators.pop();
            }
            //out of the stack
            operators.pop();
            //if there is a condition: +-*/
        } else if (str[stringLength] != '+' && str[stringLength] != '-' &&
                   str[stringLength] != '*' && str[stringLength] != '/') {

            oprtatorList += str[stringLength];
        } else {
            string operatorPush = "";
            if ((stringLength == 0) && (str[stringLength] == '-')) {
                operatorPush = "^";
            } else {
                //check the current char and the previous char
                char previousChar = str[stringLength - 1];
                char currentChar = str[stringLength];
                if ((currentChar == '-') &&
                    ((previousChar == '*') || (previousChar == '+') ||
                     (previousChar == '/') || (previousChar == '-'))) {
                    operatorPush = "^";
                } else {
                    operatorPush = string(1, str[stringLength]);
                    oprtatorList +=",";

                }

            }
            //add the operator to the stack
            operators.push(operatorPush);


        }
        stringLength++;
    }
    //until the end
    while (!operators.empty()) {
        oprtatorList += operators.top();
        operators.pop();
    }
    //until there are operators in the list
    while (resultLength < oprtatorList.length()) {
        Expression *newExpression;
        Expression *rightExpression;
        Expression *leftExpression;
        if (oprtatorList[resultLength] != ' ') {
            if (oprtatorList[resultLength] == '+') {
                //set the first expression
                rightExpression = expressions.top();
                //out from stack
                expressions.pop();
                //set the second expression
                leftExpression = expressions.top();
                //out from stack
                expressions.pop();
                resultLength++;
                //new plus expression
                newExpression = new Plus(leftExpression, rightExpression);
            //if the operator is *
            } else if (oprtatorList[resultLength] == '*') {
                //set the first expression
                rightExpression = expressions.top();
                //out from stack
                expressions.pop();
                //set the second expression
                leftExpression = expressions.top();
                //out from stack
                expressions.pop();
                resultLength++;
                //new mul expression
                newExpression = new Mul(leftExpression, rightExpression);
                //if the operator is /
            } else if (oprtatorList[resultLength] == '/') {
                //set the first expression
                rightExpression = expressions.top();
                //out from stack
                expressions.pop();
                //set the second expression
                leftExpression = expressions.top();
                //out from stack
                expressions.pop();
                resultLength++;
                //new div expression
                newExpression = new Div(leftExpression, rightExpression);
                //if the operator is -
            } else if (oprtatorList[resultLength] == '-') {
                //set the first expression
                rightExpression = expressions.top();
                //out from stack
                expressions.pop();
                //set the second expression
                leftExpression = expressions.top();
                //out from stack
                expressions.pop();
                //new minus expression
                newExpression = new Minus(leftExpression, rightExpression);
                resultLength++;
                //if the operator is ^
            } else if (oprtatorList[resultLength] == '^') {
                //new neg expression
                newExpression = new Neg(expressions.top());
                resultLength++;
            } else if (isdigit(oprtatorList[resultLength])) {
                string num = "";
                while (((oprtatorList[resultLength]) != ',') && (isdigit(oprtatorList[resultLength]))) {
                    string s = string(1, oprtatorList[resultLength]);
                    num = num + s;
                    resultLength++;
                }
                double d = atof(num.c_str());
                newExpression = new Num(d);
            } else if (oprtatorList[resultLength] != ' ') {
                string tempVar = "";
                while ((oprtatorList[resultLength] != ',') || (isdigit(oprtatorList[resultLength])) ||
                       (isalpha(oprtatorList[resultLength]))) {
                    string s = string(1, oprtatorList[resultLength]);
                    tempVar = tempVar + s;
                    resultLength++;
                }

                newExpression = new Var(tempVar);
            }
            expressions.push(newExpression);
            Expression *e = expressions.top();
            if(oprtatorList[resultLength] == ',') {
                resultLength++;
            }
        } else {
            resultLength++;
        }
    }
    //return the expression
    return expressions.top();

}