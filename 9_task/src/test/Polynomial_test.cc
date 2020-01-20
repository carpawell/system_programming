#include <gtest/gtest.h>
#include <myproject/6_task/Polynomial.h>
#include <complex>

TEST(POLYNOMIAL, REAL_NUMBERS) {
    Polynomial<int> p = Polynomial<int>(1, 2);
    
    EXPECT_EQ(1, p.get_arg(0));
    EXPECT_EQ(2, p.get_arg(1));

    p.multiply(2);
    
    EXPECT_EQ(2, p.get_arg(0));
    EXPECT_EQ(4, p.get_arg(1));
}

TEST(POLYNOMIAL, SCHUR) {
    Polynomial<int> p = Polynomial<int>(1, 2, 3);
    
    Polynomial<int> schur_poly = schur_transform(p);

    EXPECT_EQ(schur_poly.get_arg(0), 0);
    EXPECT_EQ(schur_poly.get_arg(1), 4);
    EXPECT_EQ(schur_poly.get_arg(2), 8);
}

TEST(POLYNOMIAL, COMPLEX_NUMBERS) {
    std::complex<double> first = std::complex<double>(1, 1);
    std::complex<double> second = std::complex<double>(2, 2);

    std::complex<double> conj_first = std::conj(first);
    std::complex<double> conj_second = std::conj(second);

    EXPECT_EQ(std::real(conj_first), std::real(first));
    EXPECT_EQ(std::imag(conj_first), -1*std::imag(first));
    EXPECT_EQ(std::real(conj_second), std::real(second));
    EXPECT_EQ(std::imag(conj_second), -1*std::imag(second));

    std::complex<double> multi = first * second;
    EXPECT_EQ(std::real(multi), 0);
    EXPECT_EQ(std::imag(multi), 4);
}

TEST(POLYNOMIAL, SCHUR_2COMPLEX) {
    std::complex<double> first = std::complex<double>(1, 1);
    std::complex<double> second = std::complex<double>(2, 2);
    
    Polynomial<std::complex<double>> p = 
    Polynomial<std::complex<double>>(first, second);
    
    Polynomial<std::complex<double>> schur_poly = schur_transform(p);

    EXPECT_EQ(std::real(schur_poly.get_arg(0)), 0);
    EXPECT_EQ(std::imag(schur_poly.get_arg(0)), 0);
    EXPECT_EQ(std::real(schur_poly.get_arg(1)), 6);
    EXPECT_EQ(std::imag(schur_poly.get_arg(1)), 0);
}

TEST(POLYNOMIAL, SCHUR_3COMPLEX) {
    std::complex<double> first = std::complex<double>(1, 1);
    std::complex<double> second = std::complex<double>(2, 2);
    std::complex<double> third = std::complex<double>(3, 3);
    
    Polynomial<std::complex<double>> p = 
    Polynomial<std::complex<double>>(first, second, third);
    
    Polynomial<std::complex<double>> schur_poly = schur_transform(p);

    EXPECT_EQ(std::real(schur_poly.get_arg(0)), 0);
    EXPECT_EQ(std::imag(schur_poly.get_arg(0)), 0);
    EXPECT_EQ(std::real(schur_poly.get_arg(1)), 8);
    EXPECT_EQ(std::imag(schur_poly.get_arg(1)), 0);
    EXPECT_EQ(std::real(schur_poly.get_arg(2)), 16);
    EXPECT_EQ(std::imag(schur_poly.get_arg(2)), 0);
}