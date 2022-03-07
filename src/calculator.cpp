#include <iostream>
#include "calculator.h"


int Calculator::add(int first, int second) {
    return first + second;
}

int Calculator::sub(int first, int second) {
    return first - second;
}

int Calculator::divide(int first, int second) {
    return first/second;
}

int Calculator::multiply(int first, int second) {
    return first * second;
}

int Calculator::notCoverFuntion(int first, int second) {
    return first % second;
}
