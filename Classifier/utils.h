#include <fstream>
#include <sstream>
#include <string>
#include "matrix.h"

template <typename T>
int LoadTrainData(const char* file_path, Matrix<T>* x, Matrix<T>* y) {
    std::ifstream ifs(file_path);
    if (!ifs.good()) {
        return;
    }

    std::string head;

    std::getline(ifs, head);
    std::stringstream head_ss(head);
    int data_num = 0, x_dim = 0;
    head_ss >> data_num >> x_dim;

    x->resize(data_num, x_dim);
    y->resize(data_num, 1);

    std::string line;
    int line_cnt = 0;
    while (getline(ifs, line)) {
        if (line_cnt >= data_num) {
            break;
        }
        if (line.empty()) {
            continue;
        }
        std::stringstream ss(line);

        ss >> y->data_[line_cnt][0];
        for (int i = 0; i < x_dim; i++) {
            ss >> x->data_[line_cnt][i];
        }
    }
}