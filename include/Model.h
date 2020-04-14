#pragma once

#include <functional>

namespace Model {

enum class ModelName {
    ROSSLER, LORENZ
};

struct Point {
    long double x, y, z;
};

void generate_points(
        const std::function<void(const Point &)> &new_point_action, //calls when generate new point
        Point start_point,
        int points_count,
        int steps_per_point,
        long double tau,
        ModelName modelName,
        const std::vector<long double> &constants);

} // namespace Model