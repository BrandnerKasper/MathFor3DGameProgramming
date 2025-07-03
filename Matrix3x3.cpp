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


Matrix3x3 operator+(const Matrix3x3 &m1, const Matrix3x3 &m2) {
    std::array<double, 9> vals {};
    size_t idx {0};
    for (int j {0}; j < 3; ++j) {
        for (int i {0}; i < 3; ++i) {
            vals[idx++] = m1(j, i) + m2(j, i);
        }
    }
    return Matrix3x3{vals};
}