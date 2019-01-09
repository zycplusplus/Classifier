class Classifier {
   public:
    virtual void train()      = 0;
    virtual void predict()    = 0;
    virtual void save_model() = 0;
    virtual void load_model() = 0;
};

class LinearRegression : public Classifier {};

class LogisticRegression : public Classifier {};

class NaiveBayes : public Classifier {};

class RandomForest : public Classifier {};

class KNN : public Classifier {};

class SVM : public Classifier {};

class SoftMax : public Classifier {};

class DecisionTree : public Classifier {};

class AdaBoost : public Classifier {};