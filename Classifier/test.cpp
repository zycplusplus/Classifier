#include <iostream>
#include "classifier.h"
#include "utils.h"

int main() {
    M x(2, 3), y(3, 2);

    x.data_[0] = {1, 2, 3};
    x.data_[1] = {4, 5, 6};

    y.data_[0] = {1, 4};
    y.data_[1] = {2, 5};
    y.data_[2] = {3, 6};
    try {
        auto z = x * y;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                printf("%.2f, ", z.data_[i][j]);
            }
            printf("\n");
        }
    } catch (MatrixSizeError& e) {
        std::cerr << e.what() << "\n";
    }

    return 0;
}