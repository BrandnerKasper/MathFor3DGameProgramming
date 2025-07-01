#include <format>
#include <print>
#include <cmath>


struct  Vec3D {
    Vec3D() = default;
    Vec3D(const double x, const double y, const double z)
        : x{x}, y{y}, z{z}
    {}

    friend Vec3D operator+(const Vec3D& v1, const Vec3D& v2);
    friend Vec3D operator-(const Vec3D& v1, const Vec3D& v2);
    friend double operator*(const Vec3D& v1, const Vec3D& v2);
    friend Vec3D operator*(const Vec3D& v, double s);
    friend Vec3D operator*(const double s, const Vec3D& v) {return v*s;}
    friend Vec3D operator/(const Vec3D& v, double s);
    friend Vec3D operator/(const double s, const Vec3D& v) {return v/s;}
    friend Vec3D operator^(const Vec3D& v1, const Vec3D& v2);

    friend double mag(const Vec3D& v);

    double x {0};
    double y {0};
    double z {0};
};


Vec3D operator+(const Vec3D &v1, const Vec3D &v2) {
    return {v1.x+v2.x, v1.y+v2.y, v1.z+v2.z};
}

Vec3D operator-(const Vec3D &v1, const Vec3D &v2) {
    return {v1.x-v2.x, v1.y-v2.y, v1.z-v2.z};
}

double operator*(const Vec3D &v1, const Vec3D &v2) {
    return {v1.x*v2.x + v1.y*v2.y + v1.z*v2.z};
}

Vec3D operator*(const Vec3D &v, const double s) {
    return {s*v.x, s*v.y, s*v.z};
}

Vec3D operator/(const Vec3D &v, const double s) {
    return {v.x/s, v.y/s, v.z/s};
}

Vec3D operator^(const Vec3D &v1, const Vec3D &v2) {
    return {v1.y*v2.z - v1.z*v2.y, v1.z*v2.x - v1.y*v2.y, v1.y*v2.y - v1.y*v2.x};
}

double mag(const Vec3D &v) {
    return std::sqrt(v*v);
}

template<>
struct std::formatter<Vec3D> {
    constexpr auto parse(std::format_parse_context& ctx) {
        return ctx.begin();
    }

    auto format(const Vec3D& v, format_context& ctx) const {
        // format_to writes into ctx.out() using the fmt-style syntax
        return std::format_to( ctx.out(),"({}, {}, {})", v.x, v.y, v.z);
    }
};


int main() {
    std::println("Hello 3D Vec World");
    auto x {Vec3D{-1, 0, 2}};
    auto y {Vec3D{3, 4, 6.5}};
    auto z {Vec3D{1, 1, 1}};
    auto s {3};

    std::println("{} + {} = {}.", x, y, x+y);
    std::println("{} - {} = {}", x, y, x-y);
    std::println("{} * {} = {}", x, y, x*y);
    std::println("{} * {} = {}", s, y, s*y);
    std::println("{} / {} = {}", x, s, x/s);
    std::println("{} x {} = {}", x, y, x^y);
    std::println("|{} * {}| = {}", z, z, mag(z));

    return 0;
}