#pragma once
#include <array>
#include <map>
#include <format>


class Matrix3x3 {
public:
    Matrix3x3() = default;
    explicit Matrix3x3(const std::array<double, 9>& vals) {
        for (size_t i {0}; i < std::size(vals); ++i) {
            auto const [x, y] = m_idxMap[i];
            m_data[x][y] = vals[i];
        }
    }

    double& operator()(int row, int col);
    double operator()(int row, int col) const;

    friend Matrix3x3 operator+(const Matrix3x3& m1, const Matrix3x3& m2);

private:
    double m_data[3][3]{};
    std::map<size_t, std::pair<size_t, size_t>> m_idxMap {
                {0, {0, 0}},
                {1, {0, 1}},
                {2, {0, 2}},
                {3, {1, 0}},
                {4, {1, 1}},
                {5, {1, 2}},
                {6, {2, 0}},
                {7, {2, 1}},
                {8, {2, 2}}
    };
};

template<>
    struct std::formatter<Matrix3x3> {
    constexpr auto parse(std::format_parse_context& ctx) {
        return ctx.begin();
    }

    auto format(const Matrix3x3& m, format_context& ctx) const {
        // format_to writes into ctx.out() using the fmt-style syntax
        return std::format_to(
            ctx.out(),"[{}, {}, {} | {}, {}, {} | {}, {}, {}]",
            m(0,0), m(0, 1), m(0, 2),
            m(1, 0), m(1, 1), m(1, 2),
            m(2, 0), m(2, 1), m(2, 2)
            );
    }
};