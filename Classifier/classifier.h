#include "matrix.h"

typedef Matrix<double> M;

class Classifier {
   public:
    virtual void train(const M& train_data, const M& labels) = 0;

    virtual M predict(const M& input) const = 0;

    virtual void save_model(const char* file_path) const = 0;

    virtual void load_model(const char* file_path) const = 0;
};

class LinearRegression : public Classifier {
private:
    int dim_;
    int interations_;
    double train_rate_;
    M theta_;

   public:
    explicit LinearRegression(int dim) noexcept;

    void train(const M& train_data, const M& labels) override;

    M predict(const M& input) const override;

    void save_model(const char* file_path) const override;

    void load_model(const char* file_path) const override;
};

class LogisticRegression : public Classifier {};

class NaiveBayes : public Classifier {};

class RandomForest : public Classifier {};

class KNN : public Classifier {};

class SVM : public Classifier {};

class SoftMax : public Classifier {};

class DecisionTree : public Classifier {};

class AdaBoost : public Classifier {};