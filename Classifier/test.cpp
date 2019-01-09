#include "classifier.h"

int main() {
    int data_dim = 10;
    M x(10, data_dim), y(10, 1);
    LinearRegression lr(data_dim);
    lr.train(x, y);
    M input(1, data_dim);
    lr.predict(input);
    return 0;
}