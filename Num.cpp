
#include "Expression.h"

class Num : Expression {
private:
    double num;

public:
    Num(double num) : num(num) {}

    double Calculate() {
        return num;
    }
};