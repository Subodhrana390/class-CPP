#include <iostream>
#include <cmath>

using namespace std;

class Polar {
public:
    double radius;
    double angle;

    Polar(double r = 0, double a = 0.0) {
        radius = r;
        angle = a;
    }

    void toRectangular(double& x, double& y) const {  // Marked as const
        double radians = angle * M_PI / 180.0;
        x = radius * cos(radians);
        y = radius * sin(radians);
    }

    static Polar fromRectangular(double x, double y) {
        double r = sqrt(x * x + y * y);
        double a = atan2(y, x) * 180.0 / M_PI;
        return Polar(r, a);
    }

    Polar operator+(const Polar& other) const {  // Marked as const
        double x1, y1, x2, y2;
        this->toRectangular(x1, y1);
        other.toRectangular(x2, y2);
        double x_sum = x1 + x2;
        double y_sum = y1 + y2;
        return fromRectangular(x_sum, y_sum);
    }
};

int main() {
    Polar p1(3, 45);
    Polar p2(4, 60);
    Polar p3 = p1 + p2;

    cout << "Polar Point 1: (" << p1.radius << ", " << p1.angle << " degrees)\n";
    cout << "Polar Point 2: (" << p2.radius << ", " << p2.angle << " degrees)\n";
    cout << "Sum of Polar Points: (" << p3.radius << ", " << p3.angle << " degrees)\n";

    return 0;
}
