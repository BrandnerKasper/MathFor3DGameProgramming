#pragma once
#include <format>


struct Vector3D {
    Vector3D() = default;
    Vector3D(const double x, const double y, const double z)
        : x{x}, y{y}, z{z}
    {}

    friend Vector3D operator+(const Vector3D& v1, const Vector3D& v2);
    friend Vector3D operator-(const Vector3D& v1, const Vector3D& v2);
    friend double operator*(const Vector3D& v1, const Vector3D& v2);
    friend Vector3D operator*(const Vector3D& v, double s);
    friend Vector3D operator*(const double s, const Vector3D& v) {return v*s;}
    friend Vector3D operator/(const Vector3D& v, double s);
    friend Vector3D operator/(const double s, const Vector3D& v) {return v/s;}
    friend Vector3D operator^(const Vector3D& v1, const Vector3D& v2);

    friend double mag(const Vector3D& v);

    double x {0};
    double y {0};
    double z {0};
};

template<>
    struct std::formatter<Vector3D> {
    constexpr auto parse(std::format_parse_context& ctx) {
        return ctx.begin();
    }

    auto format(const Vector3D& v, format_context& ctx) const {
        // format_to writes into ctx.out() using the fmt-style syntax
        return std::format_to( ctx.out(),"({}, {}, {})", v.x, v.y, v.z);
    }
};