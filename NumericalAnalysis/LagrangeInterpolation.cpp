#include <iostream>
#include <vector>

using namespace std;

struct Point {
    double x, y;
};

double interpolate(const vector<Point>& points, double xi) {
    double result = 0;
    size_t n = points.size();

    for (size_t i = 0; i < n; i++) {
        double term = points[i].y;
        for (size_t j = 0; j < n; j++) {
            if (i != j) {
                term *= (xi - points[j].x) / (points[i].x - points[j].x);
            }
        }
        result += term;
    }
    return result;
}

int main() {
    vector<Point> data = {{0, 2}, {1, 3}, {2, 12}, {5, 147}};
    
    double xi = 3;
    cout << "f(" << xi << ") = " << interpolate(data, xi) << endl;

    return 0;
}