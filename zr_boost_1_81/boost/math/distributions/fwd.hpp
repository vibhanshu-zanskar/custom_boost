// fwd.hpp Forward declarations of Boost.Math distributions.

// Copyright Paul A. Bristow 2007, 2010, 2012, 2014.
// Copyright John Maddock 2007.

// Use, modification and distribution are subject to the
// Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt
// or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MATH_DISTRIBUTIONS_FWD_HPP
#define BOOST_MATH_DISTRIBUTIONS_FWD_HPP

// 33 distributions at Boost 1.9.1 after adding hyperexpon and arcsine

namespace zr_boost_1_81{ namespace math{

template <class RealType, class Policy>
class arcsine_distribution;

template <class RealType, class Policy>
class bernoulli_distribution;

template <class RealType, class Policy>
class beta_distribution;

template <class RealType, class Policy>
class binomial_distribution;

template <class RealType, class Policy>
class cauchy_distribution;

template <class RealType, class Policy>
class chi_squared_distribution;

template <class RealType, class Policy>
class exponential_distribution;

template <class RealType, class Policy>
class extreme_value_distribution;

template <class RealType, class Policy>
class fisher_f_distribution;

template <class RealType, class Policy>
class gamma_distribution;

template <class RealType, class Policy>
class geometric_distribution;

template <class RealType, class Policy>
class hyperexponential_distribution;

template <class RealType, class Policy>
class hypergeometric_distribution;

template <class RealType, class Policy>
class inverse_chi_squared_distribution;

template <class RealType, class Policy>
class inverse_gamma_distribution;

template <class RealType, class Policy>
class inverse_gaussian_distribution;

template <class RealType, class Policy>
class kolmogorov_smirnov_distribution;

template <class RealType, class Policy>
class laplace_distribution;

template <class RealType, class Policy>
class logistic_distribution;

template <class RealType, class Policy>
class lognormal_distribution;

template <class RealType, class Policy>
class negative_binomial_distribution;

template <class RealType, class Policy>
class non_central_beta_distribution;

template <class RealType, class Policy>
class non_central_chi_squared_distribution;

template <class RealType, class Policy>
class non_central_f_distribution;

template <class RealType, class Policy>
class non_central_t_distribution;

template <class RealType, class Policy>
class normal_distribution;

template <class RealType, class Policy>
class pareto_distribution;

template <class RealType, class Policy>
class poisson_distribution;

template <class RealType, class Policy>
class rayleigh_distribution;

template <class RealType, class Policy>
class skew_normal_distribution;

template <class RealType, class Policy>
class students_t_distribution;

template <class RealType, class Policy>
class triangular_distribution;

template <class RealType, class Policy>
class uniform_distribution;

template <class RealType, class Policy>
class weibull_distribution;

}} // namespaces

#define BOOST_MATH_DECLARE_DISTRIBUTIONS(Type, Policy)\
   typedef zr_boost_1_81::math::arcsine_distribution<Type, Policy> arcsine;\
   typedef zr_boost_1_81::math::bernoulli_distribution<Type, Policy> bernoulli;\
   typedef zr_boost_1_81::math::beta_distribution<Type, Policy> beta;\
   typedef zr_boost_1_81::math::binomial_distribution<Type, Policy> binomial;\
   typedef zr_boost_1_81::math::cauchy_distribution<Type, Policy> cauchy;\
   typedef zr_boost_1_81::math::chi_squared_distribution<Type, Policy> chi_squared;\
   typedef zr_boost_1_81::math::exponential_distribution<Type, Policy> exponential;\
   typedef zr_boost_1_81::math::extreme_value_distribution<Type, Policy> extreme_value;\
   typedef zr_boost_1_81::math::fisher_f_distribution<Type, Policy> fisher_f;\
   typedef zr_boost_1_81::math::gamma_distribution<Type, Policy> gamma;\
   typedef zr_boost_1_81::math::geometric_distribution<Type, Policy> geometric;\
   typedef zr_boost_1_81::math::hypergeometric_distribution<Type, Policy> hypergeometric;\
   typedef zr_boost_1_81::math::kolmogorov_smirnov_distribution<Type, Policy> kolmogorov_smirnov;\
   typedef zr_boost_1_81::math::inverse_chi_squared_distribution<Type, Policy> inverse_chi_squared;\
   typedef zr_boost_1_81::math::inverse_gaussian_distribution<Type, Policy> inverse_gaussian;\
   typedef zr_boost_1_81::math::inverse_gamma_distribution<Type, Policy> inverse_gamma;\
   typedef zr_boost_1_81::math::laplace_distribution<Type, Policy> laplace;\
   typedef zr_boost_1_81::math::logistic_distribution<Type, Policy> logistic;\
   typedef zr_boost_1_81::math::lognormal_distribution<Type, Policy> lognormal;\
   typedef zr_boost_1_81::math::negative_binomial_distribution<Type, Policy> negative_binomial;\
   typedef zr_boost_1_81::math::non_central_beta_distribution<Type, Policy> non_central_beta;\
   typedef zr_boost_1_81::math::non_central_chi_squared_distribution<Type, Policy> non_central_chi_squared;\
   typedef zr_boost_1_81::math::non_central_f_distribution<Type, Policy> non_central_f;\
   typedef zr_boost_1_81::math::non_central_t_distribution<Type, Policy> non_central_t;\
   typedef zr_boost_1_81::math::normal_distribution<Type, Policy> normal;\
   typedef zr_boost_1_81::math::pareto_distribution<Type, Policy> pareto;\
   typedef zr_boost_1_81::math::poisson_distribution<Type, Policy> poisson;\
   typedef zr_boost_1_81::math::rayleigh_distribution<Type, Policy> rayleigh;\
   typedef zr_boost_1_81::math::skew_normal_distribution<Type, Policy> skew_normal;\
   typedef zr_boost_1_81::math::students_t_distribution<Type, Policy> students_t;\
   typedef zr_boost_1_81::math::triangular_distribution<Type, Policy> triangular;\
   typedef zr_boost_1_81::math::uniform_distribution<Type, Policy> uniform;\
   typedef zr_boost_1_81::math::weibull_distribution<Type, Policy> weibull;

#endif // BOOST_MATH_DISTRIBUTIONS_FWD_HPP
