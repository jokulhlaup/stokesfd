#define EIGEN_DONT_PARALLELIZE
#define EPS 1e-15
#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Core>
#include <time.h>
#include <math.h>

using namespace std;
using namespace Eigen;

template <typename Derived, typename size_f, int n>
struct rk {
   EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
   Array<double, n, n+1> tableau;
   std::vector<EigenBase<Derived>, n+1>  Ks;
   EigenBase<Derived> tmp;

   rk(Array<double, n, n+1> c, EigenBase<Derived>& x0) {
      dims = x0.size();
      tableau = c;
      x = x0;
      EigenBase<Derived> 

   void update_Ks( EigenBase<Derived> x, size_f h ) {
      Ks[0]= h*f(t,x);
      for (i=0; i<n; i++) {
      tmp.setzeros()
         for (j=0; j<i+1; j++) {
            if (tableau[k,j] != 0)
               tmp += tableau[k,j]*Ks[k];
            }
         Ks[i] = h*f(t + c[k], x + tmp);
      }
   }
   
   void integrate( EigenBase<Derived>& x, std::array<size_f, rows+1>& b) {
      update_Ks(x,h);
      tmp.setZeros();
      for i=0:rows
         x += b[i]*Ks[i];
      }
   
   
      



template <typename derived, double hmin, double hmax, double epsmin, double epsmax>
void rk45(EigenBase<Derived>& x, 
         function<double, const(EigenBase<Derived>&)> f,
         EigenBase<Derived>& K1,
         EigenBase<Derived>& K2,
         EigenBase<Derived>& K3,
         EigenBase<Derived>& K4,
         EigenBase<Derived>& K5,
         EigenBase<Derived>& K6)

   K1 = h*f(t,x);
   K2 = h*f(t + 0.25*h, x + 0.25*K1);
   K3 = h*f(t + 3/8*h, x + 3/32*K1 + 9/32*K2);
   K4 = h*f(t + 12/13*h, x + 1932/2197*K1 - 7200/2197*K2 + 7296/2197*K3);
   K5 = h*f(t + h, x + 439/216*K1 - 8*K2 + 3680/513*K3 - 745/4104 * K4);
   K6 = h*f(t + 0.5*h, x - 8/27*K1 + 2*k2 - 3544/2565*K4 + 1859/4104*K4 - 11/40*K5);




