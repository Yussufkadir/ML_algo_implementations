//
// Created by yusuf on 3/19/2025.
//
#include <iostream>
#include <vector>

class LinearRegression {
private:
   double weight, bias, lr;
public:
  LinearRegression(double learning_rate = 0.01) : lr(learning_rate), weight(0), bias(0) {}

  void fit(std::vector<double>& x, std::vector<double>& y, int epochs = 200){
    int n = x.size();
    for (int i = 0; i < epochs; i++){
      double error_sum = 0, weight_grad = 0, bias_grad = 0;
      for (int j = 0; j < n; j ++){
        double error = y[j] - (weight * x[j] + bias);
        weight_grad += error * x[j];
        bias_grad += error;
      }
      weight += lr * (weight_grad / n);
      bias += lr * (bias_grad / n);
    }
  }

  double predict(double x){
    return weight * x + bias;
  }

  void print_model(){
    std::cout << "Weight " << weight << " Bias " << bias << std::endl;
  }
 };

 int main() {
   std::vector<double> x = {1,2,3,4,5};
   std::vector<double> y = {2,4,6,8,10};

   LinearRegression model(0.01);
   model.fit(x, y);
   model.print_model();

   double x_test = 6;
   std::cout << "Prediction for " << x_test << ": " << model.predict(x_test) << std::endl;

   return 0;
 }
