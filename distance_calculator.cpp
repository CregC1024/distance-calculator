#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

double calculateDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

bool getCoordinate(const string& prompt, double& value) {
    while (true) {
        cout << prompt;
        if (cin >> value) {
            return true;
        } else {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int main() {
    double x1, y1, x2, y2;
    
    cout << "Distance Formula Calculator" << endl;
    cout << "--------------------------" << endl;
    cout << "Calculates distance between two points (x1, y1) and (x2, y2)" << endl;
    cout << "Formula: √[(x₂-x₁)² + (y₂-y₁)²]" << endl << endl;
    
    cout << "Enter coordinates for first point:" << endl;
    while (!getCoordinate("x1: ", x1));
    while (!getCoordinate("y1: ", y1));
    
    cout << "\nEnter coordinates for second point:" << endl;
    while (!getCoordinate("x2: ", x2));
    while (!getCoordinate("y2: ", y2));
    
    double distance = calculateDistance(x1, y1, x2, y2);
    
    cout << fixed << setprecision(4);
    cout << "\nResults:" << endl;
    cout << "Point 1: (" << x1 << ", " << y1 << ")" << endl;
    cout << "Point 2: (" << x2 << ", " << y2 << ")" << endl;
    cout << "Distance: " << distance << endl;
    
    return 0;
}
