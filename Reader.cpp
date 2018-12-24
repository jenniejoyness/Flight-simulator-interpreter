#include "Reader.h"
#include "ExpressionCommand.h"
#include "ConditionCommand.h"
#include "GetCommandMap.h"
#include <regex>
#include <list>

Reader::Reader(Data* data, map<string,ExpressionCommand*> map) {
    this->data = data;
    this->commandMap = map;
}

vector<string> Reader::lexer(string line) {
    string addedSpaces = addSpaces(line);
    vector<string> chopped = split(addedSpaces, " ");
    return findParameters(chopped);
}

/*
 *
 */
void Reader::parser(vector<string> lineData) {
    ExpressionCommand *expression;
    //if in the first place found a symbol - is equal command
     if (data->isVar(lineData[0])) {
        //find the correct expression in map
        expression = commandMap.find(lineData[1])->second;
        //erase the second parameter which is the command
        lineData.erase(lineData.begin() + 1);
    } else {
    expression = commandMap.find(lineData[0])->second;
    //erase the command
    lineData.erase(lineData.begin());
     }
    //setting the parameters of the expressioncommand
    expression->getCommand()->setParameters(lineData, data);
    //will calculate parameters and execute the command
    expression->Calculate();
}


string Reader::addSpaces(string str) {
    bool inBrackets = false;
    int first = 0;
    int i = 0;
    string newString;
    while (i != str.size()) {
        //checking if the quote brackets
        if (str[i] == '"' && first == 0) {
            inBrackets = true;
            first++;
        } else if (str[i] == '"' && first == 1) {
            inBrackets = false;
        }
            //if is an operator and not in quotes add a space before operator
        else if (isOperator(str[i]) && !inBrackets) {
            if (i != 0) {
                if (newString[newString.size() - 1] != ' ') {
                    newString += " ";
                }

            }
            if (i != str.size()) {
                if ((str[i + 1]) != ' ') {
                    newString += str[i];
                    newString += " ";
                } else {
                    newString += str[i];
                }
            }

            i++;
            continue;

        }
        //if in quote brackets or not an operator add to newstring
        if (str[i] == ' ' && newString[newString.size() - 1] == ' ') {
            i++;
            continue;
        }
        newString += str[i];
        i++;
    }
    return newString;

}

bool Reader::isOperator(char s) {
    if ((s == '+') || (s == '-') || (s == '/') || (s == '*') || (s == '(') || (s == ')') || (s == ',') || (s == '=')
        || s == '>' || s == '<' || s == '{' || s == '}') {
        return true;

    }
    return false;
}

/*
 * add a parameter to the list of parameters from string line from index j to index i
 */
void Reader::addParameter(int j, int i, vector<string> &params, vector<string> line) {
    string s = "";
  /*  if (line[j] == "-") {
        s += "0";
    }
*/
    for (j; j <= i; j++) {
        s += line[j];
    }
    params.push_back(s);
}

vector<string> Reader::findParameters(vector<string> line) {
    int i = 0;
    int startIndexParameter = 0;
    int bracketsCounter = 0;
    bool previousIsNumber = false;
    bool previousIsCloseingBrackets = false;
    vector<string> params;

    while (i < line.size()) {
        if (line[i] == "(") {
            bracketsCounter++;
            previousIsNumber = false;
            previousIsCloseingBrackets = false;
        } else if (line[i] == ")") {
            bracketsCounter--;
            previousIsCloseingBrackets = true;
            previousIsNumber = false;
        } else if (line[i] == ",") {
            // i - 1: for ignore the comma
            addParameter(startIndexParameter, i - 1, params, line);
            startIndexParameter = i + 1;
            previousIsNumber = false;
            previousIsCloseingBrackets = false;
        } else if (line[i] == "=") {
            addParameter(startIndexParameter, i - 1, params, line);
            //enter = as parameter
            addParameter(i, i, params, line);
            startIndexParameter = i + 1;
            previousIsNumber = false;
            previousIsCloseingBrackets = false;
        } else {
            //this iteration the string is a number or an operator-
            // if is either num num or closing brackets num
            if ((previousIsNumber && !isOperator(line[i][0]))
                || (previousIsCloseingBrackets && !isOperator(line[i][0]) && bracketsCounter == 0)) {
                if (startIndexParameter == i) {
                    addParameter(startIndexParameter, i, params, line);
                } else {
                    addParameter(startIndexParameter, i - 1, params, line);
                }

                startIndexParameter = i;
            }
            previousIsCloseingBrackets = false;
            previousIsNumber = true;
            if (isOperator(line[i][0])) {
                previousIsNumber = false;
            }
        }
        i++;

    }
    addParameter(startIndexParameter, line.size() - 1, params, line);
    return params;
}

vector<string> Reader::split(string line, string delimiter) {
    vector<string> data;
    size_t pos = 0;
    while ((pos = line.find(delimiter)) != string::npos) {
        if (line.substr(0, pos) != "") {
            data.push_back(line.substr(0, pos));
        }
        line.erase(0, pos + delimiter.length());
    }
    data.push_back(line.substr(0, pos));
    return data;

}

/*
 * deals with splitting the params of a condition command,
 * and starts the do command of the condition map
 */
void Reader::conditionParser(string str) {
    bool inAnotherCondtion = false;
    bool bracketInNextLine = true;
    int counter = 0;
    string s;
    vector<vector<string>> params;
    //recieves all the commands of the while command
    vector<string> chopped = split(str, "#");
    //add spaces to the condition string and split
    vector<string> condition = split(addSpaces(chopped[0]), " ");
    if (condition.back() == "") {
        condition.erase(condition.end());
    }
    chopped.erase(chopped.begin());

    //sending each command line to lexer and adding to list of commands for the whilecommand
    for (int i = 0; i < chopped.size() - 1; ++i) {
        //if the line does not contains condition send to the lexer and add to params
        if ((strstr(chopped[i].c_str(), "while") == NULL && strstr(chopped[i].c_str(), "if") == NULL)
            && !inAnotherCondtion) {
            if (lexer(chopped[i])[0] != "}") {
                params.push_back(lexer(chopped[i]));
            }
        } else {
            //in another condition
            inAnotherCondtion = true;
            if (strstr(chopped[i].c_str(), "{") != NULL) {
                counter++;
                bracketInNextLine = false;
            }
        }
        //counting the brackets of the next condition in order to find the end of this condition
        if (inAnotherCondtion) {
            //add to brackets counter is see an opening bracket
            if (bracketInNextLine && strstr(chopped[i].c_str(), "{") != NULL) {
                counter++;
                //decrease the brackets, closing a condition
            } else if (strstr(chopped[i].c_str(), "}") != NULL) {
                counter--;
            }
            s += chopped[i] + "#";
            //got to the end of the condition
            if (counter == 0) {
                vector<string> anotherConditionParams;
                //add the whole condition in the condition as a string in the params
                anotherConditionParams.push_back(s);
                params.push_back(anotherConditionParams);
                inAnotherCondtion = false;
            }
        }
    }
    //find expression command, set params for the new expression command
    ExpressionCommand *expression = commandMap.find(condition[0])->second;
    //setting the parameters of the expressioncommand
    expression->getCommand()->setParameters(condition, data);
    dynamic_cast<ConditionCommand*>(expression->getCommand())->setCommandsParam(params, commandMap);
    //will calculate parameters and execute the command
    expression->Calculate();
}