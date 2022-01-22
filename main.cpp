#include "rational.hpp"

using namespace calculations;

int main() {
    rational w = rational(1, 5);
    auto w2 = rational(2);

    std::cout << w << std::endl;
    std::cout << w + w2 << std::endl;
    std::cout << w - w2 << std::endl;
    std::cout << w * w2 << std::endl;
    std::cout << w / w2 << std::endl;
    std::cout << (double) w << std::endl;
    std::cout << (int) w << std::endl;
    try {
        std::cout << rational(3, 0);
    }
    catch (rational_exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
