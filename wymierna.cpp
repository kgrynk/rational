#include "wymierna.hpp"


using namespace obliczenia;

wymierna::wymierna(int licz, int mian) {
    int gcd = std::gcd(licz,mian);
    licz /= gcd;
    mian /= gcd;
    this->licz = licz;
    if(mian==0)
    {
        throw obliczenia::wyjatek_wymierny::dzielenie_przez_0();
    }
    this->mian = mian;
}

wymierna::wymierna(int liczba) : wymierna(liczba, 1) {}

wymierna obliczenia::operator+(const wymierna &w1, const wymierna &w2) {
    int w1_licz = w1.get_licz();
    int w1_mian = w1.get_mian();
    int w2_licz = w2.get_licz();
    int w2_mian = w2.get_mian();
    if (w1_mian != w2_mian) {
        int lcm = std::lcm(w1_mian, w2_mian);
        w1_licz *= lcm / w1_mian;
        w2_licz *= lcm / w2_mian;
        w1_mian = lcm;
    }
    w1_licz += w2_licz;
    return {w1_licz, w1_mian};
}

wymierna obliczenia::operator-(const wymierna &w1, const wymierna &w2) {
    int w1_licz = w1.get_licz();
    int w1_mian = w1.get_mian();
    int w2_licz = w2.get_licz();
    int w2_mian = w2.get_mian();
    if (w1_mian != w2_mian) {
        int lcm = std::lcm(w1_mian, w2_mian);
        w1_licz *= lcm / w1_mian;
        w2_licz *= lcm / w2_mian;
        w1_mian = lcm;
    }
    return {w1_licz - w2_licz, w1_mian};
}

wymierna obliczenia::operator*(const wymierna &w1, const wymierna &w2) {
    int w1_licz = w1.get_licz();
    int w1_mian = w1.get_mian();
    int w2_licz = w2.get_licz();
    int w2_mian = w2.get_mian();
    if (w1_licz == 0 or w2_licz == 0){
        return {0,1};
    }
    int gcd1 = std::gcd(w1_licz,w2_mian);
    int gcd2 = std::gcd(w2_licz,w1_mian);
    w1_licz /= gcd1;
    w2_mian /= gcd1;
    w2_licz /= gcd2;
    w1_mian /= gcd2;
    w1_licz *= w2_licz;
    w1_mian *= w2_mian;
    return {w1_licz,w1_mian};
}

wymierna obliczenia::operator/(const wymierna &w1, const wymierna &w2) {
    int w1_licz = w1.get_licz();
    int w1_mian = w1.get_mian();
    int w2_mian = w2.get_licz();
    int w2_licz = w2.get_mian();
    if (w1_licz == 0 or w2_licz == 0){
        return {0,1};
    }
    int gcd1 = std::gcd(w1_licz,w2_mian);
    int gcd2 = std::gcd(w2_licz,w1_mian);
    w1_licz /= gcd1;
    w2_mian /= gcd1;
    w2_licz /= gcd2;
    w1_mian /= gcd2;
    w1_licz *= w2_licz;
    w1_mian *= w2_mian;
    return {w1_licz,w1_mian};
}

wymierna obliczenia::operator!(const wymierna &w) {
    return {w.get_mian(), w.get_licz()};
}

wymierna obliczenia::operator-(const wymierna &w) {
    return {-w.get_licz(), w.get_mian()};
}

wymierna::operator double() const {
    return (double)licz / mian;
}

wymierna::operator int() const {
    int v = licz / mian;
    return v;
}

int wymierna::get_licz() const {
    return licz;
}

int wymierna::get_mian() const {
    return mian;
}

std::ostream &obliczenia::operator<<(std::ostream &wy, const wymierna &w) {
    wy << w.get_licz();
    wy << '/';
    wy << w.get_mian();
    return wy;
}