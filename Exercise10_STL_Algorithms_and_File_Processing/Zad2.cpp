#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

namespace math_utils {

    struct Point {
        double x{};
        double y{};
    };


    istream& operator>>(istream& is, Point& p) {
        return is >> p.x >> p.y;
    }

    ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

    double distance(const Point& a, const Point& b) {
        double dx = a.x - b.x;
        double dy = a.y - b.y;
        return sqrt(dx * dx + dy * dy);
    }

    Point centroid(const vector<Point>& pts) {
        if (pts.empty()) return { 0.0, 0.0 };

        Point sum = accumulate(pts.begin(), pts.end(), Point{ 0.0, 0.0 },
            [](Point acc, const Point& p) {
                acc.x += p.x;
                acc.y += p.y;
                return acc;
            }
        );

        double n = static_cast<double>(pts.size());
        return { sum.x / n, sum.y / n };
    }
}

int main() {
    using math_utils::Point;

   
    ifstream fin("points.txt");
    if (!fin) {
        cout << "Ne mogu otvoriti datoteku points.txt\n";
        return 1;
    }

    vector<Point> pts((istream_iterator<Point>(fin)), istream_iterator<Point>());

 
    Point O{ 0.0, 0.0 };
    sort(pts.begin(), pts.end(), [&](const Point& a, const Point& b) {
        return math_utils::distance(a, O) < math_utils::distance(b, O);
        });

  
    int brojPrviKvadrant = count_if(pts.begin(), pts.end(), [](const Point& p) {
        return p.x > 0 && p.y > 0;
        });

   
    Point c = math_utils::centroid(pts);

    transform(pts.begin(), pts.end(), pts.begin(), [](Point p) {
        p.x += 5;
        p.y += 3;
        return p;
        });


    pts.erase(remove_if(pts.begin(), pts.end(), [](const Point& p) {
        return p.x < 0 && p.y < 0;
        }), pts.end());


    cout << "Broj tocaka u prvom kvadrantu: " << brojPrviKvadrant << "\n";
    cout << "Centroid: " << c << "\n";
    cout << "Tocke nakon pomaka (+5, +3) i uklanjanja (x<0 && y<0):\n";

    copy(pts.begin(), pts.end(), ostream_iterator<Point>(cout, "\n"));

    return 0;
}
