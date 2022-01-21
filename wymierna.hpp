#include <iostream>
#include <numeric>

namespace obliczenia {

    class wymierna {
    private:
        int licz, mian;
    public:
        wymierna(int licz, int mian) noexcept(false);

        wymierna(int liczba);

        int get_licz() const;

        int get_mian() const;

        friend wymierna operator+(const wymierna &w1, const wymierna &w2);

        friend wymierna operator-(const wymierna &w1, const wymierna &w2);

        friend wymierna operator*(const wymierna &w1, const wymierna &w2);

        friend wymierna operator/(const wymierna &w1, const wymierna &w2);

        friend wymierna operator!(const wymierna &w);

        friend wymierna operator-(const wymierna &w);

        explicit operator double() const;

        explicit operator int() const;

        friend std::ostream &operator<<(std::ostream &wy, const wymierna &w);

    };

    class wyjatek_wymierny : public std::logic_error {
    public:
        class przekroczenie_zakresu {
        public:
            const char *get_info() const noexcept { return "Przekroczenie zakresu!\n"; }
        };

        class dzielenie_przez_0 {
        public:
            const char *get_info() const noexcept { return "Dzielenie przez 0!\n"; }
        };
    };

//    class wyjatek_wymierny : public std::logic_error {
//        const char *info;
//
//    public:
//        wyjatek_wymierny(const std::string &arg) : logic_error(arg) {
//        }
//        const char *get_info() const { return info; }
//        class przekroczenie_zakresu {
//        public:
//            przekroczenie_zakresu(const std::string &arg) : obliczenia::wyjatek_wymierny(arg){
//            }
//        };
//
//        class dzielenie_przez_0 {
//        public:
//            const char *get_info() const noexcept { return "Dzielenie przez 0!\n"; }
//        };
//
//    };

}