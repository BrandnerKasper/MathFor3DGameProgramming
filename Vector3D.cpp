#include <cmath>

#include "Vector3D.h"


Vector3D operator+(const Vector3D &v1, const Vector3D &v2) {
    return {v1.x+v2.x, v1.y+v2.y, v1.z+v2.z};
}

Vector3D operator-(const Vector3D &v1, const Vector3D &v2) {
    return {v1.x-v2.x, v1.y-v2.y, v1.z-v2.z};
}

double operator*(const Vector3D &v1, const Vector3D &v2) {
    return {v1.x*v2.x + v1.y*v2.y + v1.z*v2.z};
}

Vector3D operator*(const Vector3D &v, const double s) {
    return {s*v.x, s*v.y, s*v.z};
}

Vector3D operator/(const Vector3D &v, const double s) {
    return {v.x/s, v.y/s, v.z/s};
}

Vector3D operator^(const Vector3D &v1, const Vector3D &v2) {
    return {v1.y*v2.z - v1.z*v2.y, v1.z*v2.x - v1.y*v2.y, v1.y*v2.y - v1.y*v2.x};
}

double mag(const Vector3D &v) {
    return std::sqrt(v*v);
}
