#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

float func(float n)
{
    return pow(n, 2)-42*n;
}

float derivative(float x, float h)
{
    cout << 1 << "/" << 2 << "*" << h << "*" << "(" <<
    -3 << "*f(" << x << ")" << "+" << 4 << "*" << "f(" << x << "+" << h << ")" << "-"
    << "f(" << "x" << "+" << 2 << "*" << h << ")";
    return (1/(2*h))*(-3*func(x)+4*func(x+h)-func(x+2*h));
}

float cent_derivative(float x, float h)
{
    cout << 1 << "/" << 2 << "*" << h << "*" << "(-f(" << x << "-" << h << ")" << "+" << "f("
    << x << "+" << h << ")";
    return (1/(2*h))*(-func(x-h)+func(x+h));
}



int main()
{

    vector<vector<float>> center, higher, lower;
    int points_amount;
    cout << "Insira a quantidade de coordenandas: ";
    cin >> points_amount;
    float x, y;
    cout << "Insira x: ";
    cin >> x;
    cout << "Insira y: ";
    cin >> y;

    float h;
    cout << "Insira h: ";
    cin >> h;

    center.push_back(vector<float>{x, func(x)});
    higher.push_back(vector<float>{x+h, func(x+h)});
    higher.push_back(vector<float>{x+2*h, func(x+2*h)});
    lower.push_back(vector<float>{x-h, func(x-h)});
    lower.push_back(vector<float>{x-2*h, func(x-2*h)});
    cout << lower[0][0] << endl;
    cout << derivative(higher[0][0], h) << endl;
    cout << derivative(lower[0][0], h) << endl;
    cout << cent_derivative(center[0][0], h) << endl;

    
    
    return 0;
}