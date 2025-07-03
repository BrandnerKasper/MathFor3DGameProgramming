#include <print>

#include "Vector3D.h"
#include "Matrix3x3.h"


namespace Chapter1 {
    void main() {
        std::println("Hello 3D Vec World");
        auto x {Vector3D{-1, 0, 2}};
        auto y {Vector3D{3, 4, 6.5}};
        auto z {Vector3D{1, 1, 1}};
        auto s {3};

        std::println("{} + {} = {}.", x, y, x+y);
        std::println("{} - {} = {}", x, y, x-y);
        std::println("{} * {} = {}", x, y, x*y);
        std::println("{} * {} = {}", s, y, s*y);
        std::println("{} / {} = {}", x, s, x/s);
        std::println("{} x {} = {}", x, y, x^y);
        std::println("|{} * {}| = {}", z, z, mag(z));
    }
}

namespace Chapter2 {
    void main() {
        std::println("Hello from Matrix 3x3 World!");
        Matrix3x3 m1 {{1, 2, 3, 4, 5, 6, 7, 8, 9}};
        Matrix3x3 m2 {{1, 2, 3, 4, 5, 6, 7, 8, 9}};

        std::println("{} + {} = {}.", m1, m2, m1+m2);
    }
}

int main() {
    // Chapter1::main();
    Chapter2::main();
    return 0;
}