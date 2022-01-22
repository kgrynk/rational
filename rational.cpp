#include "rational.hpp"


using namespace calculations;

rational::rational(int numerator, int denominator) {
    int gcd = std::gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
    this->numerator = numerator;
    if(denominator == 0)
    {
        throw calculations::rational_exception::division_by_zero();
    }
    this->denominator = denominator;
}

rational::rational(int integer) : rational(integer, 1) {}

rational calculations::operator+(const rational &r1, const rational &r2) {

    int r1_numerator = r1.get_numerator();
    int r2_numerator = r2.get_numerator();
    int r1_denominator = r1.get_denominator();
    int r2_denominator = r2.get_denominator();

    if (r1_denominator != r2_denominator) {
        int lcm = std::lcm(r1_denominator, r2_denominator);
        r1_numerator *= lcm / r1_denominator;
        r2_numerator *= lcm / r2_denominator;
        r1_denominator = lcm;
    }
    r1_numerator += r2_numerator;
    return {r1_numerator, r1_denominator};
}

rational calculations::operator-(const rational &r1, const rational &r2) {

    int r1_numerator = r1.get_numerator();
    int r2_numerator = r2.get_numerator();
    int r1_denominator = r1.get_denominator();
    int r2_denominator = r2.get_denominator();

    if (r1_denominator != r2_denominator) {
        int lcm = std::lcm(r1_denominator, r2_denominator);
        r1_numerator *= lcm / r1_denominator;
        r2_numerator *= lcm / r2_denominator;
        r1_denominator = lcm;
    }
    return {r1_numerator - r2_numerator, r1_denominator};
}

rational calculations::operator*(const rational &r1, const rational &r2) {

    int r1_numerator = r1.get_numerator();
    int r2_numerator = r2.get_numerator();
    int r1_denominator = r1.get_denominator();
    int r2_denominator = r2.get_denominator();

    if (r1_numerator == 0 or r2_numerator == 0){
        return {0,1};
    }

    int gcd1 = std::gcd(r1_numerator,r2_denominator);
    int gcd2 = std::gcd(r2_numerator,r1_denominator);

    r1_numerator /= gcd1;
    r2_numerator /= gcd2;
    r2_denominator /= gcd1;
    r1_denominator /= gcd2;
    r1_numerator *= r2_numerator;
    r1_denominator *= r2_denominator;
    return {r1_numerator,r1_denominator};
}

rational calculations::operator/(const rational &r1, const rational &r2) {
    int r1_numerator = r1.get_numerator();
    int r1_denominator = r1.get_denominator();
    int r2_denominator = r2.get_numerator();
    int r2_numerator = r2.get_denominator();
    if (r1_numerator == 0 or r2_numerator == 0){
        return {0,1};
    }
    int gcd1 = std::gcd(r1_numerator,r2_denominator);
    int gcd2 = std::gcd(r2_numerator,r1_denominator);
    r1_numerator /= gcd1;
    r2_denominator /= gcd1;
    r2_numerator /= gcd2;
    r1_denominator /= gcd2;
    r1_numerator *= r2_numerator;
    r1_denominator *= r2_denominator;
    return {r1_numerator,r1_denominator};
}

/* inverse */
rational calculations::operator!(const rational &r) {
    return {r.get_denominator(), r.get_numerator()};
}

/* additive inverse */
rational calculations::operator-(const rational &r) {
    return {-r.get_numerator(), r.get_denominator()};
}

rational::operator double() const {
    return (double)numerator / denominator;
}

rational::operator int() const {
    int v = numerator / denominator;
    return v;
}

int rational::get_numerator() const {
    return numerator;
}

int rational::get_denominator() const {
    return denominator;
}

std::ostream &calculations::operator<<(std::ostream &output, const rational &r) {
    output << r.get_numerator();
    output << '/';
    output << r.get_denominator();
    return output;
}