/**
 * Algorithm to find Geometric Median point
 * Implementation sample from:
 * - (1) StackOverflow
 *      https://stackoverflow.com/questions/12934213/how-to-find-out-geometric-median/12934484#12934484
 * - (2) Geeksforgeeks
 *      https://www.geeksforgeeks.org/geometric-median/
 *
 * The only problem here is the point we found __doesn't need to be different__ from given points,
 * aka result may be one of points input.
 */

#include<stdio.h>
#include<math.h>

#define maxN 50001

struct point {
    double x, y;
} typedef Point;

const Point testPoint[5] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

const double eps = 0.001;

int n;
Point a[maxN];

double distance(Point point) {
    double res = 0;

    for (int i = 1; i <= n; ++i) {
        double distance_x = a[i].x - point.x;
        double distance_y = a[i].y - point.y;
        res += sqrt((distance_x * distance_x) + (distance_y * distance_y));
    }

    return res;
}

void geometricMedian() {
    Point current_point;

    for (int i = 1; i <= n; ++i) {
        current_point.x += a[i].x;
        current_point.y += a[i].y;
    }

    current_point.x /= n;
    current_point.y /= n;

    // This step calculate the distance from every point to the gravity point
    double minimum_distance = distance(current_point);

    int k = 0;
    while (k < n) {
        for (int i = 1; i <= n; ++i) {
            if (i != k) {
                Point new_point;
                new_point.x = a[i].x;
                new_point.y = a[i].y;

                double new_distance = distance(new_point);
                if (new_distance < minimum_distance) {
                    minimum_distance = new_distance;
                    current_point = new_point;
                }
            }
        }
        ++k;
    }

    double test_distance = 100.0;
    int flag = 0;

    while (test_distance > eps) {
        flag = 0;
        for (int i = 0; i < 4; ++i) {
            Point new_point;
            new_point.x = current_point.x + (double)test_distance * testPoint[i].x;
            new_point.y = current_point.y + (double)test_distance + testPoint[i].y;

            double new_distance = distance(new_point);

            if (new_distance < minimum_distance) {
                minimum_distance = new_distance;
                current_point = new_point;
                flag = 1;
                break;
            }
        }

        if (flag == 0) test_distance /= 2;
    }

    printf("Geometric Median (%.4lf, %.4lf) with minimum distance = %.4lf", current_point.x, current_point.y, minimum_distance);

}

int main() {
    freopen("GeometricMedian.inp", "r+", stdin);
    freopen("GeometricMedian.out", "w+", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lf%lf", &a[i].x, &a[i].y);

    geometricMedian();

    return 0;
}
