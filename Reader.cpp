
#include "Reader.h"
#include "ExpressionCommand.h"
#include <regex>
#include <list>

Reader::Reader() {
    this->data = new Data();
    commandMap.insert(pair<string, ExpressionCommand *>("openDataServer",
                                                 new ExpressionCommand(new OpenDataServerCommand())));

}

vector<string> Reader::lexer(string line) {
    string addedSpaces = addSpaces(line);
    vector<string> chopped = split(addedSpaces);
    return findParameters(chopped);
}

/*
 *
 */
void Reader::parser(vector<string> lineData) {
    ExpressionCommand *expression;
    //if in the first place found a symbol
    if (data->getsymbleTablehMap().find(lineData[0]) != data->getsymbleTablehMap().end()){
        //find the correct expression in map
        expression = commandMap.find(lineData[1])->second;
        //erase the second parameter which is the command
        lineData.erase(lineData.begin()+1);
    }
    else {
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
                if ((str[i + 1]) !=  ' ') {
                    newString += str[i];
                    newString += " ";
                }
                else {
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
    if ((s == '+') || (s == '-') || (s == '/') || (s == '*') || (s == '(') || (s == ')') || (s == ',') || (s == '=')) {
        return true;
    }
    return false;
}

/*
 * add a parameter to the list of parameters from string line from index j to index i
 */
void Reader::addParameter(int j, int i, vector<string> &params, vector<string> line) {
    string s = "";
    if (line[j] == "-"){
        s += "0";
    }

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
        } else if(line[i] == "=") {
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
                if (startIndexParameter == i){
                    addParameter(startIndexParameter,i,params,line);
                }
                else {
                    addParameter(startIndexParameter, i-1, params, line);
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
    addParameter(startIndexParameter, line.size()-1, params, line);
    return params;
}

vector<string> Reader::split(string line) {
    vector<string> data;
    size_t pos = 0;
    string delimiter = " ";
    while ((pos = line.find(delimiter)) != string::npos) {
        data.push_back(line.substr(0, pos));
        line.erase(0, pos + delimiter.length());
    }
    data.push_back(line.substr(0, pos));
    return data;

}

