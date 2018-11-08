#include "nonlinear_response.h"

class Kerr : public NonlinearResponse {
public:
  Kerr(double n2, double pressure) {
    chi3 = 4.0/3.0 * Constants::epsilon_0 * Constants::c * n2 * pressure;
  }

  void calculate_temporal_response(const Radial& electric_field, const Array2D<double>&, Radial& response) override {
    for (int i = 0; i < response.Nradius; ++i) {
      for (int j = 0; j < response.Ntime; ++j) {
        const double E = electric_field.rt(i, j).real();
        response.rt(i, j) = Constants::epsilon_0 * chi3 * std::pow(E, 3);
      }
    }
  }
  
  double chi3;
};
