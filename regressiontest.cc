//
// regressiontest.cc - regression test suite for vecmat3.h (not exhaustive)
//
// Copyright (c) 2013  Ramses van Zon
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#include <iostream>
#include <sstream>
#include <cassert>
#include "vecmat3.h"

#define BOOST_TEST_MODULE vecmat3_test

#ifndef DEBUG
  #include <boost/test/included/unit_test.hpp>
  #include <boost/test/floating_point_comparison.hpp>
  BOOST_AUTO_TEST_SUITE (vecmat3_test)
#else
  #define declare_assign_vector main2
  #define BOOST_AUTO_TEST_CASE(x) void x()
  #define BOOST_CHECK(x) assert(x)
  #define BOOST_CHECK_CLOSE_FRACTION(x,y,z) 
  void main2();int main(){main2();return 0;}
#endif

BOOST_AUTO_TEST_CASE( declare_uninitialized_vector )
{
  Vector v;
  BOOST_CHECK( sizeof(v) >= sizeof(DOUBLE)*3 );
}

BOOST_AUTO_TEST_CASE( declare_uninitialized_matrix )
{
  Matrix m;
  BOOST_CHECK( sizeof(m) >= sizeof(DOUBLE)*3 );
}

BOOST_AUTO_TEST_CASE( declare_initialized_vector )
{
  Vector v(1,2,3);
  BOOST_CHECK( v.x == 1 );
  BOOST_CHECK( v.y == 2 );
  BOOST_CHECK( v.z == 3 );
}

BOOST_AUTO_TEST_CASE( declare_initialized_matrix )
{
  Matrix m(1,2,3,
           4,5,6,
           7,8,9);
  BOOST_CHECK( m.xx == 1 ); BOOST_CHECK( m.xy == 2 ); BOOST_CHECK( m.xz == 3 );
  BOOST_CHECK( m.yx == 4 ); BOOST_CHECK( m.yy == 5 ); BOOST_CHECK( m.yz == 6 );
  BOOST_CHECK( m.zx == 7 ); BOOST_CHECK( m.zy == 8 ); BOOST_CHECK( m.zz == 9 );
}

BOOST_AUTO_TEST_CASE( declare_zero_vector )
{
  Vector v(0);
  BOOST_CHECK( v.x == 0 );
  BOOST_CHECK( v.y == 0 );
  BOOST_CHECK( v.z == 0 );
}

BOOST_AUTO_TEST_CASE( declare_zero_matrix )
{
  Matrix m(0);
  BOOST_CHECK( m.xx == 0 ); BOOST_CHECK( m.xy == 0 ); BOOST_CHECK( m.xz == 0 );
  BOOST_CHECK( m.yx == 0 ); BOOST_CHECK( m.yy == 0 ); BOOST_CHECK( m.yz == 0 );
  BOOST_CHECK( m.zx == 0 ); BOOST_CHECK( m.zy == 0 ); BOOST_CHECK( m.zz == 0 );
}

BOOST_AUTO_TEST_CASE( declare_assign_vector )
{
  Vector v(1,2,3);
  Vector w = v;
  BOOST_CHECK( w.x == 1 );
  BOOST_CHECK( w.y == 2 );
  BOOST_CHECK( w.z == 3 );
}

BOOST_AUTO_TEST_CASE( declare_assign_matrix )
{
  Matrix m(1,2,3,
           4,5,6,
           7,8,9);
  Matrix n = m;
  BOOST_CHECK( n.xx == 1 ); BOOST_CHECK( n.xy == 2 ); BOOST_CHECK( n.xz == 3 );
  BOOST_CHECK( n.yx == 4 ); BOOST_CHECK( n.yy == 5 ); BOOST_CHECK( n.yz == 6 );
  BOOST_CHECK( n.zx == 7 ); BOOST_CHECK( n.zy == 8 ); BOOST_CHECK( n.zz == 9 );
}

BOOST_AUTO_TEST_CASE( comma_assign_vector )
{
  Vector w;
  w = 1, 2, 3;
  BOOST_CHECK( w.x == 1 );
  BOOST_CHECK( w.y == 2 );
  BOOST_CHECK( w.z == 3 );
}

BOOST_AUTO_TEST_CASE( comma_assign_matrix )
{
  Matrix n;
  n = 1,2,3,
      4,5,6,
      7,8,9;
  BOOST_CHECK( n.xx == 1 ); BOOST_CHECK( n.xy == 2 ); BOOST_CHECK( n.xz == 3 );
  BOOST_CHECK( n.yx == 4 ); BOOST_CHECK( n.yy == 5 ); BOOST_CHECK( n.yz == 6 );
  BOOST_CHECK( n.zx == 7 ); BOOST_CHECK( n.zy == 8 ); BOOST_CHECK( n.zz == 9 );
}

BOOST_AUTO_TEST_CASE( zero_vector )
{
  Vector v(1,2,3);
  v.zero();
  BOOST_CHECK( v.x == 0 );
  BOOST_CHECK( v.y == 0 );
  BOOST_CHECK( v.z == 0 );
}

BOOST_AUTO_TEST_CASE( zero_matrix )
{
  Matrix m(1,2,3,
           4,5,6,
           7,8,9);
  m.zero();
  BOOST_CHECK( m.xx == 0 ); BOOST_CHECK( m.xy == 0 ); BOOST_CHECK( m.xz == 0 );
  BOOST_CHECK( m.yx == 0 ); BOOST_CHECK( m.yy == 0 ); BOOST_CHECK( m.yz == 0 );
  BOOST_CHECK( m.zx == 0 ); BOOST_CHECK( m.zy == 0 ); BOOST_CHECK( m.zz == 0 );
}

BOOST_AUTO_TEST_CASE( stream_vector )
{
  Vector v(1,2,3);
  std::stringstream s;
  s << v;
  BOOST_CHECK( s.str() == "1 2 3" );
}

BOOST_AUTO_TEST_CASE( stream_matrix )
{
  Matrix m(1,2,3,
           4,5,6,
           7,8,9);
  std::stringstream s;
  s << m;
  BOOST_CHECK( s.str() == "\n1 2 3\n4 5 6\n7 8 9\n" );
}

BOOST_AUTO_TEST_CASE( multiply_matrix )
{
  Matrix X(1,2,3,
           4,5,6,
           7,8,9);
  Matrix Y(0,1,2,
           3,4,5,
           6,7,8);
  Matrix Z = X*Y;
  Matrix Zexpected( 24,  30,  36,
                    51,  66,  81,
                    78, 102, 126);
  BOOST_CHECK( Z.xx == Zexpected.xx );
  BOOST_CHECK( Z.xy == Zexpected.xy );
  BOOST_CHECK( Z.xz == Zexpected.xz );
  BOOST_CHECK( Z.yx == Zexpected.yx );
  BOOST_CHECK( Z.yy == Zexpected.yy );
  BOOST_CHECK( Z.yz == Zexpected.yz );
  BOOST_CHECK( Z.zx == Zexpected.zx );
  BOOST_CHECK( Z.zy == Zexpected.zy );
  BOOST_CHECK( Z.zz == Zexpected.zz );
}

BOOST_AUTO_TEST_CASE( in_situ_multiply_matrix )
{
  Matrix X(1,2,3,
           4,5,6,
           7,8,9);
  Matrix Y(0,1,2,
           3,4,5,
           6,7,8);
  X = X*Y;
  Matrix Xexpected( 24,  30,  36,
                    51,  66,  81,
                    78, 102, 126);
  BOOST_CHECK( X.xx == Xexpected.xx );
  BOOST_CHECK( X.xy == Xexpected.xy );
  BOOST_CHECK( X.xz == Xexpected.xz );
  BOOST_CHECK( X.yx == Xexpected.yx );
  BOOST_CHECK( X.yy == Xexpected.yy );
  BOOST_CHECK( X.yz == Xexpected.yz );
  BOOST_CHECK( X.zx == Xexpected.zx );
  BOOST_CHECK( X.zy == Xexpected.zy );
  BOOST_CHECK( X.zz == Xexpected.zz );
}

BOOST_AUTO_TEST_CASE( vector_nrm2 )
{
  Vector d(-1, 2.2, 3.1);
  DOUBLE expected = 15.45;
  DOUBLE tol = 1e-10;
  BOOST_CHECK_CLOSE_FRACTION( d.nrm2(), expected, tol);
}

BOOST_AUTO_TEST_CASE( vector_nrm )
{
  Vector d(-1, 2.2, 3.1);
  DOUBLE expected = sqrt(15.45);
  DOUBLE tol = 1e-10;
  BOOST_CHECK_CLOSE_FRACTION( d.nrm(), expected, tol);
}

BOOST_AUTO_TEST_CASE( matrix_nrm2 )
{
  Matrix d(  -1, 0, 0,
            2.2, 0, 1,
              0, 0, 3.1);
  DOUBLE expected = 16.45;
  DOUBLE tol = 1e-10;
  BOOST_CHECK_CLOSE_FRACTION( d.nrm2(), expected, tol);
}

BOOST_AUTO_TEST_CASE( matrix_nrm )
{
  Matrix d(  -1, 0, 0,
            2.2, 0, 1,
              0, 0, 3.1);
  DOUBLE expected = sqrt(16.45);
  DOUBLE tol = 1e-10;
  BOOST_CHECK_CLOSE_FRACTION( d.nrm(), expected, tol);
}

BOOST_AUTO_TEST_CASE( vector_square_brackets )
{
  Vector d(-1, 2.2, 3.1);
  BOOST_CHECK( d[0] == -1 );
  BOOST_CHECK( d[1] == 2.2 );
  BOOST_CHECK( d[2] == 3.1 );
}

BOOST_AUTO_TEST_CASE( vector_round_brackets )
{
  Vector d(-1, 2.2, 3.1);
  BOOST_CHECK( d(0) == -1 );
  BOOST_CHECK( d(1) == 2.2 );
  BOOST_CHECK( d(2) == 3.1 );
}

BOOST_AUTO_TEST_CASE( matrix_square_brackets )
{
  Matrix M(-1, 2.2, 3.1,
            4,   5,   6,
            7,   8,   9);
  BOOST_CHECK( M[0][0] == -1 );
  BOOST_CHECK( M[0][1] == 2.2 );
  BOOST_CHECK( M[0][2] == 3.1 );
  BOOST_CHECK( M[1][0] == 4 );
  BOOST_CHECK( M[1][1] == 5 );
  BOOST_CHECK( M[1][2] == 6 );
  BOOST_CHECK( M[2][0] == 7 );
  BOOST_CHECK( M[2][1] == 8 );
  BOOST_CHECK( M[2][2] == 9 );
}

BOOST_AUTO_TEST_CASE( matrix_round_brackets )
{
  Matrix M(-1, 2.2, 3.1,
            4,   5,   6,
            7,   8,   9);
  BOOST_CHECK( M(0,0) == -1 );
  BOOST_CHECK( M(0,1) == 2.2 );
  BOOST_CHECK( M(0,2) == 3.1 );
  BOOST_CHECK( M(1,0) == 4 );
  BOOST_CHECK( M(1,1) == 5 );
  BOOST_CHECK( M(1,2) == 6 );
  BOOST_CHECK( M(2,0) == 7 );
  BOOST_CHECK( M(2,1) == 8 );
  BOOST_CHECK( M(2,2) == 9 );
}

BOOST_AUTO_TEST_CASE( multiply_vector )
{
  DOUBLE tol = 1e-10;
  Vector c(-1, 2.2, 3.1);
  Vector d;
  d = 2.4*c;
  BOOST_CHECK_CLOSE_FRACTION( d.x, -2.4, tol );
  BOOST_CHECK_CLOSE_FRACTION( d.y, 5.28, tol );
  BOOST_CHECK_CLOSE_FRACTION( d.z, 7.44, tol );
}

BOOST_AUTO_TEST_CASE( in_situ_multiply_vector )
{
  DOUBLE tol = 1e-10;
  Vector d(-1, 2.2, 3.1);
  d *= 2;
  BOOST_CHECK_CLOSE_FRACTION( d.x,  -2, tol );
  BOOST_CHECK_CLOSE_FRACTION( d.y, 4.4, tol );
  BOOST_CHECK_CLOSE_FRACTION( d.z, 6.2, tol );
}

BOOST_AUTO_TEST_CASE( in_situ_divide_vector )
{ 
  DOUBLE tol = 1e-10;
  Vector d(-1, 2.2, 3.1);
  d /= 5;
  BOOST_CHECK_CLOSE_FRACTION( d.x, -0.2, tol );
  BOOST_CHECK_CLOSE_FRACTION( d.y, 0.44, tol );
  BOOST_CHECK_CLOSE_FRACTION( d.z, 0.62, tol );
}

BOOST_AUTO_TEST_CASE( in_situ_add_vectors )
{
  DOUBLE tol = 1e-10;
  Vector d(-1, 2.2, 3.1);
  Vector c( 1, 1.7, -13.9);
  d += c;
  BOOST_CHECK_CLOSE_FRACTION( d.x,   0.0, tol );
  BOOST_CHECK_CLOSE_FRACTION( d.y,   3.9, tol );
  BOOST_CHECK_CLOSE_FRACTION( d.z, -10.8, tol );
}

BOOST_AUTO_TEST_CASE( in_situ_subtract_vectors )
{
  DOUBLE tol = 1e-10;
  Vector d(-1, 2.2, 3.1);
  Vector c( 1, 1.7, -13.9);
  d -= c;
  BOOST_CHECK_CLOSE_FRACTION( d.x, -2.0, tol );
  BOOST_CHECK_CLOSE_FRACTION( d.y,  0.5, tol );
  BOOST_CHECK_CLOSE_FRACTION( d.z, 17.0, tol );
}

BOOST_AUTO_TEST_CASE( add_vectors )
{
  DOUBLE tol = 1e-10;
  Vector b(-1, 2.2, 3.1);
  Vector c( 1, 1.7, -13.9);
  Vector d;
  d = b + c;
  BOOST_CHECK_CLOSE_FRACTION( d.x,   0.0, tol );
  BOOST_CHECK_CLOSE_FRACTION( d.y,   3.9, tol );
  BOOST_CHECK_CLOSE_FRACTION( d.z, -10.8, tol );
}

BOOST_AUTO_TEST_CASE( subtract_vectors )
{
  DOUBLE tol = 1e-10;
  Vector b(-1, 2.2, 3.1);
  Vector c( 1, 1.7, -13.9);
  Vector d;
  d = b - c;
  BOOST_CHECK_CLOSE_FRACTION( d.x, -2.0, tol );
  BOOST_CHECK_CLOSE_FRACTION( d.y,  0.5, tol );
  BOOST_CHECK_CLOSE_FRACTION( d.z, 17.0, tol );
}

BOOST_AUTO_TEST_CASE( cross_product )
{
  DOUBLE tol = 1e-10;
  Vector b( 3,  4,  5);
  Vector c(-7, -6, -5);
  Vector d = b^c;
  BOOST_CHECK_CLOSE_FRACTION( d.x, 10, tol );
  BOOST_CHECK_CLOSE_FRACTION( d.y,-20, tol );
  BOOST_CHECK_CLOSE_FRACTION( d.z, 10, tol );
}

BOOST_AUTO_TEST_CASE( negative )
{
  DOUBLE tol = 1e-10;
  Vector b( 3,  4,  5);
  Vector d;
  d = -b;
  BOOST_CHECK_CLOSE_FRACTION( d.x, -3, tol );
  BOOST_CHECK_CLOSE_FRACTION( d.y, -4, tol );
  BOOST_CHECK_CLOSE_FRACTION( d.z, -5, tol );
}

BOOST_AUTO_TEST_CASE( inner_product )
{
  DOUBLE tol = 1e-10;
  Vector b( 3,  4, 5);
  Vector c(-7, -6, 5);
  DOUBLE d = (b|c);
  DOUBLE dexpected = -20;
  BOOST_CHECK_CLOSE_FRACTION( d, dexpected, tol );
}

BOOST_AUTO_TEST_CASE( inner_product_variant )
{
  DOUBLE tol = 1e-10;
  Vector b( 3,  4, 5);
  Vector c(-7, -6, 5);
  DOUBLE d = b*c;
  DOUBLE dexpected = -20;
  BOOST_CHECK_CLOSE_FRACTION( d, dexpected, tol );
}

BOOST_AUTO_TEST_CASE( get_row )
{
  Matrix D( -1.0,  2.2, 3.1,
            -5.0, -3.0, 2.0,
             1.0, -2.0, 4.4);
  Vector w = D.row(1);
  BOOST_CHECK( w.x == -5.0 );
  BOOST_CHECK( w.y == -3.0 );
  BOOST_CHECK( w.z ==  2.0 );
}

BOOST_AUTO_TEST_CASE( set_row )
{
  Matrix D( -1.0,  2.2, 3.1,
            -5.0, -3.0, 2.0,
             1.0, -2.0, 4.4);
  Vector h(  1.0, 3.0 ,6.0);
  D.setRow(1,h);
  Vector w = D.row(1);
  BOOST_CHECK( w.x ==  1.0 );
  BOOST_CHECK( w.y ==  3.0 );
  BOOST_CHECK( w.z ==  6.0 );
}

BOOST_AUTO_TEST_CASE( get_column )
{
  Matrix D( -1.0,  2.2, 3.1,
            -5.0, -3.0, 2.0,
             1.0, -2.0, 4.4);
  Vector w = D.column(2);
  BOOST_CHECK( w.x == 3.1 );
  BOOST_CHECK( w.y == 2.0 );
  BOOST_CHECK( w.z == 4.4 );
}

BOOST_AUTO_TEST_CASE( set_column )
{
  Matrix D( -1.0,  2.2, 3.1,
            -5.0, -3.0, 2.0,
             1.0, -2.0, 4.4);
  Vector h(  1.0, 3.0 ,6.0);
  D.setColumn(1,h);
  Vector w = D.column(1);
  BOOST_CHECK( w.x ==  1.0 );
  BOOST_CHECK( w.y ==  3.0 );
  BOOST_CHECK( w.z ==  6.0 );
}

BOOST_AUTO_TEST_CASE( dyadic )
{
  Vector g( -1, 2, 3);
  Vector h(  1, 3, 6);
  Matrix F;
  F = Dyadic(g,h);
  Matrix Fexpected(-1,-3,-6,
                   2, 6, 12,
                   3, 9, 18);
  BOOST_CHECK( F.xx ==  Fexpected.xx );
  BOOST_CHECK( F.xy ==  Fexpected.xy );
  BOOST_CHECK( F.xz ==  Fexpected.xz );
  BOOST_CHECK( F.yx ==  Fexpected.yx );
  BOOST_CHECK( F.yy ==  Fexpected.yy );
  BOOST_CHECK( F.yz ==  Fexpected.yz );
  BOOST_CHECK( F.zx ==  Fexpected.zx );
  BOOST_CHECK( F.zy ==  Fexpected.zy );
  BOOST_CHECK( F.zz ==  Fexpected.zz );
}


BOOST_AUTO_TEST_CASE( scalar_multiply_matrix )
{
  DOUBLE tol = 1e-10;
  Matrix C(-1, 2, 3,
            7, 6, 5,
            4, 3, 1);
  Matrix D;
  D = 2.4*C;
  BOOST_CHECK_CLOSE_FRACTION( D.xx, -2.4, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.xy,  4.8, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.xz,  7.2, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.yx, 16.8, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.yy, 14.4, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.yz, 12.0, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.zx,  9.6, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.zy,  7.2, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.zz,  2.4, tol );
}

BOOST_AUTO_TEST_CASE( in_situ_scalar_multiply_matrix )
{
  DOUBLE tol = 1e-10;
  Matrix D(-1, 2, 3,
            7, 6, 5,
            4, 3, 1);
  D *= 2.4;
  BOOST_CHECK_CLOSE_FRACTION( D.xx, -2.4, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.xy,  4.8, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.xz,  7.2, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.yx, 16.8, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.yy, 14.4, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.yz, 12.0, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.zx,  9.6, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.zy,  7.2, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.zz,  2.4, tol );
}

BOOST_AUTO_TEST_CASE( scalar_in_situ_divide_matrix )
{ 
  DOUBLE tol = 1e-10;
  Matrix D(-1, 2, 3,
            7, 6, 5,
            4, 3, 1);
  D /= 4;
  BOOST_CHECK_CLOSE_FRACTION( D.xx, -0.25, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.xy,  0.5, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.xz,  0.75, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.yx,  1.75, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.yy,  1.5, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.yz,  1.25, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.zx,  1.0, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.zy,  0.75, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.zz,  0.25, tol );
}

BOOST_AUTO_TEST_CASE( in_situ_add_matrices )
{
  DOUBLE tol = 1e-10;
  Matrix D(-1, 2, 3,
            7, 6, 5,
            4, 3, 1);
  Matrix C(-2, 5, 4,
            4, 6, 2,
           -4, 3, 4);
  D += C;
  BOOST_CHECK_CLOSE_FRACTION( D.xx, -3, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.xy,  7, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.xz,  7, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.yx, 11, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.yy, 12, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.yz,  7, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.zx,  0, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.zy,  6, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.zz,  5, tol );
}

BOOST_AUTO_TEST_CASE( in_situ_subtract_matrices )
{
  DOUBLE tol = 1e-10;
  Matrix D(-1, 2, 3,
            7, 6, 5,
            4, 3, 1);
  Matrix C( 2, -5, -4,
           -4, -6, -2,
            4, -3, -4);
  D -= C;
  BOOST_CHECK_CLOSE_FRACTION( D.xx, -3, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.xy,  7, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.xz,  7, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.yx, 11, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.yy, 12, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.yz,  7, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.zx,  0, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.zy,  6, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.zz,  5, tol );
}

BOOST_AUTO_TEST_CASE( add_matrices )
{
  DOUBLE tol = 1e-10;
  Matrix A(-1, 2, 3,
            7, 6, 5,
            4, 3, 1);
  Matrix B(-2, 5, 4,
            4, 6, 2,
           -4, 3, 4);
  Matrix D;
  D = A + B;
  BOOST_CHECK_CLOSE_FRACTION( D.xx, -3, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.xy,  7, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.xz,  7, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.yx, 11, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.yy, 12, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.yz,  7, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.zx,  0, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.zy,  6, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.zz,  5, tol );
}

BOOST_AUTO_TEST_CASE( subtract_matrices )
{
  DOUBLE tol = 1e-10;
  Matrix A(-1, 2, 3,
            7, 6, 5,
            4, 3, 1);
  Matrix B(2, -5, -4,
           -4, -6, -2,
           4, -3, -4);
  Matrix D;
  D = A - B;
  BOOST_CHECK_CLOSE_FRACTION( D.xx, -3, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.xy,  7, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.xz,  7, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.yx, 11, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.yy, 12, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.yz,  7, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.zx,  0, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.zy,  6, tol );
  BOOST_CHECK_CLOSE_FRACTION( D.zz,  5, tol );
}

BOOST_AUTO_TEST_CASE( intermediate_row )
{
  DOUBLE tol = 1e-10;
  Matrix A(-1,  2,  3,
            7,  6,  5,
            4,  3,  1);
  Matrix B( 2, -5, -4,
           -4, -6, -2,
            4, -3, -4);
  Vector a = (A*B).row(1);
  BOOST_CHECK_CLOSE_FRACTION( a.x, 10, tol );
  BOOST_CHECK_CLOSE_FRACTION( a.y, -86, tol );
  BOOST_CHECK_CLOSE_FRACTION( a.z, -60, tol );
}

BOOST_AUTO_TEST_CASE( rodrigues )
{
  DOUBLE tol = 1e-10;
  Vector d(1,1,1);
  Vector n = d/d.nrm();
  Matrix R = Rodrigues((M_PI/2.0)*n);
  BOOST_CHECK_CLOSE_FRACTION( R.xx, 1./3., tol );
  BOOST_CHECK_CLOSE_FRACTION( R.xy, (1.-sqrt(3.))/3., tol );
  BOOST_CHECK_CLOSE_FRACTION( R.xz, (1.+sqrt(3.))/3., tol );
  BOOST_CHECK_CLOSE_FRACTION( R.yx, (1.+sqrt(3.))/3., tol );
  BOOST_CHECK_CLOSE_FRACTION( R.yy, 1./3., tol );
  BOOST_CHECK_CLOSE_FRACTION( R.yz, (1.-sqrt(3.))/3., tol );
  BOOST_CHECK_CLOSE_FRACTION( R.zx, (1.-sqrt(3.))/3., tol );
  BOOST_CHECK_CLOSE_FRACTION( R.zy, (1.+sqrt(3.))/3., tol );
  BOOST_CHECK_CLOSE_FRACTION( R.zz, 1./3., tol );
}

BOOST_AUTO_TEST_CASE( inverse )
{
  DOUBLE tol = 1e-10;
  Matrix A(-1,  2,  3,
            3,  2,  3,
            1,  3,  1);
  Matrix B = Inverse(A);
  BOOST_CHECK_CLOSE_FRACTION( B.xx, -1./4., tol );
  BOOST_CHECK_CLOSE_FRACTION( B.xy,  1./4., tol );
  BOOST_CHECK_CLOSE_FRACTION( B.xz,     0., tol );
  BOOST_CHECK_CLOSE_FRACTION( B.yx,     0., tol );
  BOOST_CHECK_CLOSE_FRACTION( B.yy, -1./7., tol );
  BOOST_CHECK_CLOSE_FRACTION( B.yz,  3./7., tol );
  BOOST_CHECK_CLOSE_FRACTION( B.zx,  1./4., tol );
  BOOST_CHECK_CLOSE_FRACTION( B.zy, 5./28., tol );
  BOOST_CHECK_CLOSE_FRACTION( B.zz, -2./7., tol );
}

#ifndef DEBUG
BOOST_AUTO_TEST_SUITE_END()
#endif
