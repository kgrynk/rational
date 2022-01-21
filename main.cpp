#include "wymierna.hpp"

using namespace obliczenia;

int main() {
    wymierna w = wymierna(1, 5);
    auto w2 = wymierna(2);

    std::cout << w << std::endl;
    std::cout << w + w2 << std::endl;
    std::cout << w - w2 << std::endl;
    std::cout << w * w2 << std::endl;
    std::cout << w / w2 << std::endl;
    std::cout << (double) w << std::endl;
    std::cout << (int) w << std::endl;
    try {
        std::cout << wymierna(3, 0);
    }
    catch (wyjatek_wymierny &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
