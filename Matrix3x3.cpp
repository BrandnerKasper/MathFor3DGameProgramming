#include <cassert>

#include "Matrix3x3.h"


double &Matrix3x3::operator()(const int row, const int col) {
    assert(row >= 0 && row < 3);
    assert(col >= 0 && col < 3);

    return m_data[row][col];
}

double Matrix3x3::operator()(const int row, const int col) const {
    assert(row >= 0 && row < 3);
    assert(col >= 0 && col < 3);

    return m_data[row][col];
}


Matrix3x3 operator+(const Matrix3x3& m1, const Matrix3x3& m2) {
    std::array<double, 9> vals {};
    size_t idx {0};
    for (int i {0}; i < 3; ++i) {
        for (int j {0}; j < 3; ++j) {
            vals[idx++] = m1(i, j) + m2(i, j);
        }
    }
    return Matrix3x3{vals};
}

Matrix3x3 operator-(const Matrix3x3& m1, const Matrix3x3& m2) {
    std::array<double, 9> vals {};
    size_t idx {0};
    for (int i {0}; i < 3; ++i) {
        for (int j {0}; j < 3; ++j) {
            vals[idx++] = m1(i, j) - m2(i, j);
        }
    }
    return Matrix3x3{vals};
}

Matrix3x3 operator*(const Matrix3x3& m, const double s) {
    std::array<double, 9> vals {};
    size_t idx {0};
    for (int i {0}; i < 3; ++i) {
        for (int j {0}; j < 3; ++j) {
            vals[idx++] = m(i, j) * s;
        }
    }
    return Matrix3x3{vals};
}

Matrix3x3 operator*(const double s, const Matrix3x3& m) {
    return m*s;
}

Matrix3x3 operator*(const Matrix3x3& m1, const Matrix3x3& m2) {
    std::array<double, 9> vals {};
    size_t idx {0};
    for (int i {0}; i < 3; ++i) {
        for (int j {0}; j < 3; ++j) {
            vals[idx++] = m1(i, j) * m2(i, j);
        }
    }
    return Matrix3x3{vals};
}

Matrix3x3 operator/(const Matrix3x3& m, const double s) {
    std::array<double, 9> vals {};
    size_t idx {0};
    for (int i {0}; i < 3; ++i) {
        for (int j {0}; j < 3; ++j) {
            vals[idx++] = m(i, j) / s;
        }
    }
    return Matrix3x3{vals};
}

Matrix3x3 operator/(const double s, const Matrix3x3& m) {
    return m/s;
}

Vector3D operator*(const Matrix3x3& m, const Vector3D& v) {
    return {
        m(0,0)*v.x + m(0, 1)*v.y + m(0, 2)*v.z,
        m(1, 0)*v.x + m(1, 1)*v.y + m(1, 2)*v.z,
        m(2, 0)*v.x + m(2, 1)*v.y + m(2, 2)*v.z
    };
}

Vector3D operator*(const Vector3D& v, const Matrix3x3& m) {
    return m*v;
}

void Matrix3x3::identity() {
    for (int i {0}; i < 3; ++i) {
        for (int j {0}; j < 3; ++j) {
            operator()(i, j) = (i==j);
        }
    }
}

double Matrix3x3::det() {
    return
    operator()(0,0) * (operator()(1, 1)*operator()(2, 2) - operator()(1, 2)*operator()(2, 1))
    - operator()(0, 1) * (operator()(1, 0)*operator()(2, 2) - operator()(1, 2)*operator()(2, 0))
    + operator()(0, 2) * (operator()(1, 0)*operator()(2,1) - operator()(1, 1)*operator()(2, 0));
}


Matrix3x3 Matrix3x3::inverse() {
    if (det() == 0)
        return Matrix3x3{{0, 0, 0, 0, 0, 0, 0, 0, 0}};
    const Matrix3x3 mat {
        {
            (operator()(1, 1)*operator()(2, 2) - operator()(1, 2)*operator()(2, 1)),
            (operator()(0, 2)*operator()(2, 1) - operator()(0, 1)*operator()(2, 2)),
            (operator()(0, 1)*operator()(1, 2) - operator()(0, 2)*operator()(1, 1)),
            (operator()(1, 2)*operator()(2, 0) - operator()(1, 0)*operator()(2, 2)),
            (operator()(0, 0)*operator()(2, 2) - operator()(0, 2)*operator()(2, 0)),
            (operator()(0, 2)*operator()(1, 0) - operator()(0, 0)*operator()(1, 2)),
            (operator()(1, 0)*operator()(2, 1) - operator()(1, 1)*operator()(2, 0)),
            (operator()(0, 1)*operator()(2, 0) - operator()(0, 0)*operator()(2, 1)),
            (operator()(0, 0)*operator()(1, 1) - operator()(0, 1)*operator()(1, 0))
        }
    };

    return 1 / det() * mat;
}
