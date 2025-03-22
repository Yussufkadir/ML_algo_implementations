//
// Created by yusuf on 3/19/2025.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
//cmath's e looked very ugly, so I will be using this instead
double sigmoid(double z) {
  if (z >= 0) {
    return 1 / (1 + exp(-z));
  } else {
    double exp_z = exp(z);
    return exp_z / (1 + exp_z);
  }
}

class LogisticRegression {
private:
  double weight, bias, lr;

public:
  LogisticRegression(double learning_rate = 0.01) : lr(learning_rate), weight(0), bias(0) {}

  void fit(std::vector<double>& x, std::vector<double>& y, int epochs = 200) {
    int n = x.size();
    for (int i = 0; i < epochs; i++) {
      double weight_gradient = 0, bias_gradient = 0;
      for (int j = 0; j < n; j++) {
        double z = x[j] * weight + bias;
        double error = sigmoid(z);  // Stable sigmoid
        error = std::max(1e-15, std::min(error, 1 - 1e-15));  // Clip to avoid log(0) or log(1)

        double diff = error - y[j];  // Difference between prediction and true label

        weight_gradient += diff * x[j];
        bias_gradient += diff;
      }
      weight -= lr * (weight_gradient / n);  // Update weight
      bias -= lr * (bias_gradient / n);      // Update bias
    }
  }

  double predict(double x) {
    return round(sigmoid(x * weight + bias));  // Stable sigmoid
  }

  void print_model() {
    std::cout << "Weight: " << weight << ", Bias: " << bias << std::endl;
  }
};

int main() {
  std::vector<double> x = {1, 2, 3, 4, 5};
  std::vector<double> y = {0, 1, 0, 1, 0};

  LogisticRegression model(0.01);
  model.fit(x, y);
  model.print_model();

  double x_test = 8;
  std::cout << "Prediction for " << x_test << ": " << model.predict(x_test) << std::endl;

  return 0;
}
