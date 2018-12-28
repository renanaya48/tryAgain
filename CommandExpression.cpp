#include "CommandExpression.h"

/**
 *
 * @param assignment map
 * @return the result of the expression in numbers
 */
double CommandExpression::calculate(map<string, double> &assignment) {
    int countSteps=0;
    string expression;
    int resultExpression;
    vector<string> newVector;
    Expression *newExpression;
    vector<string>::iterator tempItr;
    tempItr=this->vectorIt;
    CreateExpression *createExpression = new CreateExpression();
    //if the value is "openDateServer" or "sleep"
    if (((*this->vectorIt) == "openDateServer") || ((*this->vectorIt) == "sleep")) {
        //move the iterator 1 step
        this->vectorIt++;
        //count 1 step
        countSteps++;
        //move until the end
        while ((*this->vectorIt) != ";") {
            //put the string value of the expression in expression
            expression = (*vectorIt);
            //make the string to expression
            newExpression = createExpression->convertToExpression(expression);
            //calculate the result of the expression
            resultExpression = (int) newExpression->calculate(assignment);
            //add the result of the expression to the new vector
            newVector.push_back(to_string(resultExpression));
            //move the iterator 1 step
            vectorIt++;
            //count 1 step
            countSteps++;
        }
        //iterator to the new vector
        vector<string>::iterator itr;
        itr=newVector.begin();
        //do command on the vector
        this->command->doCommand(itr);
        //if the value in the vector is "connect"
    } else if((*vectorIt) == "connect"){
        //move the iterator 1 step
        vectorIt++;
        //count 1 step
        countSteps++;
        //put the string value of the ip in ip and add it to the new vector
        string ip = (*vectorIt);
        newVector.push_back(ip);
        //move the iterator 1 step
        vectorIt++;
        //count 1 step
        countSteps++;
        //put the string value of the iterator in expression
        expression = (*vectorIt);
        //create the expression from the string
        newExpression = createExpression->convertToExpression(expression);
        //calculate the result and add it to the new vector
        resultExpression = (int) newExpression->calculate(assignment);
        newVector.push_back(to_string(resultExpression));
        //iterator to the new vector
        vector<string>::iterator itr;
        itr=newVector.begin();
        //do the command
        this->command->doCommand(itr);
        //if the string value of the iterator is "print"
    } else if((*vectorIt) == "print"){
        //move the iterator 1 step
        vectorIt++;
        //count 1 step
        countSteps++;
        //check
        if((*vectorIt)[0]=='\"'){
            //do command
            this->command->doCommand(vectorIt);
        } else {
            //until the end
            while ((*this->vectorIt) != ";") {
                //put the string value of the iterator in expression
                expression = (*vectorIt);
                //create the expression from the string
                newExpression = createExpression->convertToExpression(expression);
                //calculate the result and add it to the new vector
                resultExpression = (int) newExpression->calculate(assignment);
                newVector.push_back(to_string(resultExpression));
                //move the iterator 1 step
                vectorIt++;
                //count 1 step
                countSteps++;
            }
            //iterator to the new vector

            vector<string>::iterator itr;
            itr=newVector.begin();
            //doCommand
            this->command->doCommand(itr);
        }
        //if the string value is "var"
    } else if ((*vectorIt)=="var"){
        //move the iterator 1 step
        vectorIt++;
        //count 1 step
        countSteps++;
        countSteps+=this->command->doCommand(vectorIt);
    } else {
        //add the string value to the new vector
        newVector.push_back(*this->vectorIt);
        string expressin = "";
        //add 2 to the vector and to the steps
        this->vectorIt += 2;
        countSteps += 2;
        //until the end
        while ((*this->vectorIt) != ";") {
            expressin += (*this->vectorIt);
            //add 1 to the vector and to the steps
            this->vectorIt++;
            countSteps++;
        }
        //create new expression
        newExpression = createExpression->convertToExpression(expressin);
        //calculate the result and add it to the new vector
        double result = newExpression->calculate(assignment);
        //newVector.push_back("=");
        newVector.push_back(to_string(result));
        vector<string>::iterator newVectorIt;
        newVectorIt = newVector.begin();
        this->command->doCommand(newVectorIt);
    }
    this->vectorIt=tempItr;
    //return the numbers of steps
    return countSteps;
}
/**
 * calculate the value of the expression
 * @return the value after calculate
 */
double CommandExpression::calculate() {
    map<string, double> temp;
    calculate(temp);
}
