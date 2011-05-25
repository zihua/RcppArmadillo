// Copyright (C) 2008-2011 NICTA (www.nicta.com.au)
// Copyright (C) 2008-2011 Conrad Sanderson
// Copyright (C)      2009 Edmund Highcock
// Copyright (C)      2011 James Sanders
// 
// This file is part of the Armadillo C++ library.
// It is provided without any warranty of fitness
// for any purpose. You can redistribute this file
// and/or modify it under the terms of the GNU
// Lesser General Public License (LGPL) as published
// by the Free Software Foundation, either version 3
// of the License or (at your option) any later version.
// (see http://www.opensource.org/licenses for more info)


//! \addtogroup auxlib
//! @{


//! wrapper for accessing external functions defined in ATLAS, LAPACK or BLAS libraries
class auxlib
  {
  public:
  
  
  template<const u32 row, const u32 col>
  struct pos
    {
    static const u32 n2 = row + col*2;
    static const u32 n3 = row + col*3;
    static const u32 n4 = row + col*4;
    };
  
  
  //
  // inv
  
  template<typename eT, typename T1>
  inline static bool inv(Mat<eT>& out, const Base<eT,T1>& X);
  
  template<typename eT>
  inline static bool inv(Mat<eT>& out, const Mat<eT>& A);
  
  template<typename eT>
  inline static bool inv_noalias_tinymat(Mat<eT>& out, const Mat<eT>& X, const u32 N);
  
  template<typename eT>
  inline static bool inv_inplace_tinymat(Mat<eT>& out, const u32 N);
  
  template<typename eT>
  inline static bool inv_inplace_lapack(Mat<eT>& out);
  
  
  //
  // inv_tr
  
  template<typename eT, typename T1>
  inline static bool inv_tr(Mat<eT>& out, const Base<eT,T1>& X, const u32 layout);
  
  
  //
  // inv_sym
  
  template<typename eT, typename T1>
  inline static bool inv_sym(Mat<eT>& out, const Base<eT,T1>& X, const u32 layout);
  
  
  //
  // det
  
  template<typename eT, typename T1>
  inline static eT det(const Base<eT,T1>& X);
  
  template<typename eT>
  inline static eT det_tinymat(const Mat<eT>& X, const u32 N);
  
  template<typename eT>
  inline static eT det_lapack(const Mat<eT>& X, const bool make_copy);
  
  
  //
  // log_det
  
  template<typename eT, typename T1>
  inline static void log_det(eT& out_val, typename get_pod_type<eT>::result& out_sign, const Base<eT,T1>& X);
  
  
  //
  // lu
  
  template<typename eT, typename T1>
  inline static void lu(Mat<eT>& L, Mat<eT>& U, podarray<blas_int>& ipiv, const Base<eT,T1>& X);
  
  template<typename eT, typename T1>
  inline static void lu(Mat<eT>& L, Mat<eT>& U, Mat<eT>& P, const Base<eT,T1>& X);
  
  template<typename eT, typename T1>
  inline static void lu(Mat<eT>& L, Mat<eT>& U, const Base<eT,T1>& X);
  
  
  //
  // eig
  
  template<typename eT, typename T1> 
  inline static bool eig_sym(Col<eT>& eigval, const Base<eT,T1>& X);
  
  template<typename T, typename T1> 
  inline static bool eig_sym(Col<T>& eigval, const Base<std::complex<T>,T1>& X);
  
  template<typename eT, typename T1>
  inline static bool eig_sym(Col<eT>& eigval, Mat<eT>& eigvec, const Base<eT,T1>& X);
  
  template<typename T, typename T1>
  inline static bool eig_sym(Col<T>& eigval, Mat< std::complex<T> >& eigvec, const Base<std::complex<T>,T1>& X);
  
  template<typename T, typename T1>
  inline static bool eig_gen(Col< std::complex<T> >& eigval, Mat<T>& l_eigvec, Mat<T>& r_eigvec, const Base<T,T1>& X, const char side);
  
  template<typename T, typename T1>
  inline static bool eig_gen(Col< std::complex<T> >& eigval, Mat< std::complex<T> >& l_eigvec, Mat< std::complex<T> >& r_eigvec, const Base< std::complex<T>, T1 >& X, const char side);
  
  
  //
  // chol
  
  template<typename eT, typename T1>
  inline static bool chol(Mat<eT>& out, const Base<eT,T1>& X);
  
  
  //
  // qr
  
  template<typename eT, typename T1>
  inline static bool qr(Mat<eT>& Q, Mat<eT>& R, const Base<eT,T1>& X);
  
  
  //
  // svd
  
  template<typename eT, typename T1>
  inline static bool svd(Col<eT>& S, const Base<eT,T1>& X, u32& n_rows, u32& n_cols);
  
  template<typename T, typename T1>
  inline static bool svd(Col<T>& S, const Base<std::complex<T>, T1>& X, u32& n_rows, u32& n_cols);
  
  template<typename eT, typename T1>
  inline static bool svd(Col<eT>& S, const Base<eT,T1>& X);
  
  template<typename T, typename T1>
  inline static bool svd(Col<T>& S, const Base<std::complex<T>, T1>& X);
  
  template<typename eT, typename T1>
  inline static bool svd(Mat<eT>& U, Col<eT>& S, Mat<eT>& V, const Base<eT,T1>& X);
  
  template<typename T, typename T1>
  inline static bool svd(Mat< std::complex<T> >& U, Col<T>& S, Mat< std::complex<T> >& V, const Base< std::complex<T>, T1>& X);
  
  
  //
  // solve
  
  template<typename eT>
  inline static bool solve   (Mat<eT>& out, Mat<eT>& A, const Mat<eT>& B);
  
  template<typename eT>
  inline static bool solve_od(Mat<eT>& out, Mat<eT>& A, const Mat<eT>& B);
  
  template<typename eT>
  inline static bool solve_ud(Mat<eT>& out, Mat<eT>& A, const Mat<eT>& B);
  
  
  //
  // solve_tr
  
  template<typename eT>
  inline static bool solve_tr(Mat<eT>& out, const Mat<eT>& A, const Mat<eT>& B, const u32 layout);


  //
  // Schur decomposition
  
  template<typename eT>
  inline static bool schur_dec(Mat<eT>& Z, Mat<eT>& T, const Mat<eT>& A);
  
  template<typename cT>
  inline static bool schur_dec(Mat<std::complex<cT> >& Z, Mat<std::complex<cT> >& T, const Mat<std::complex<cT> >& A);
  
  
  //
  // syl (solution of the Sylvester equation AX + XB = C)
  
  template<typename eT>
  inline static bool syl(Mat<eT>& X, const Mat<eT>& A, const Mat<eT>& B, const Mat<eT>& C);
  
  
  //
  // lyap (solution of the continuous Lyapunov equation AX + XA^H + Q = 0)
  
  template<typename eT>
  inline static bool lyap(Mat<eT>& X, const Mat<eT>& A, const Mat<eT>& Q);
  
  
  //
  // dlyap (solution of the discrete Lyapunov equation AXA^H - X + Q = 0)
  
  template<typename eT>
  inline static bool dlyap(Mat<eT>& X, const Mat<eT>& A, const Mat<eT>& Q);
  };


//! @}