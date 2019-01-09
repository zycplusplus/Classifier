#include "classifier.h"

LinearRegression::LinearRegression(int dim)noexcept:dim_(dim),train_rate_(0.001),interations_(10), theta_(M(dim_, 1)){}


void LinearRegression::train(const M& train_data, const M& labels) {
    for (int i = 0; i < interations_; ++i) {
        M predictions = predict(train_data);

        M this_diff = predictions - labels;

        M delta_theta = train_data*this_diff;

        theta_-=delta_theta;
    }
}

M LinearRegression::predict(const M& input) const {
    return input*theta_;
}

void LinearRegression::save_model(const char* file_path) const {}

void LinearRegression::load_model(const char* file_path) const {}
