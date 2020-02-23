#ifndef DYNSYS_MODEL_H
#define DYNSYS_MODEL_H


struct Point {
    long double x, y, z;
};


void set_constants(long double a, long double b, long double c);

std::vector<Point> generate_points(Point start_point, int points_count, int steps_per_point, long double tau);

#endif //DYNSYS_MODEL_H