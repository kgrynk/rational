#include <iostream>
#include <numeric>

namespace calculations {

    class rational {
    private:
        int numerator, denominator;
    public:
        rational(int numerator, int denominator) noexcept(false);

        rational(int integer);

        int get_numerator() const;

        int get_denominator() const;

        friend rational operator+(const rational &r1, const rational &r2);

        friend rational operator-(const rational &r1, const rational &r2);

        friend rational operator*(const rational &r1, const rational &r2);

        friend rational operator/(const rational &r1, const rational &r2);

        friend rational operator!(const rational &r);

        friend rational operator-(const rational &r);

        explicit operator double() const;

        explicit operator int() const;

        friend std::ostream &operator<<(std::ostream &in, const rational &r);

    };

    class rational_exception : public std::logic_error {
    public:
        class overflow {
        public:
            const char *get_info() const noexcept { return "Overflow!\n"; }
        };

        class division_by_zero {
        public:
            const char *get_info() const noexcept { return "Division by zero!\n"; }
        };
    };
}