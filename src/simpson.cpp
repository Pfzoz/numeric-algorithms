#include <iostream>
#include <cmath>

using namespace std;

float func(float n)
{
    return pow(n, 3)+42*n;
}

float simpson(float x_one, float x_two)
{
    float h = (x_two-x_one)/2;
    cout << "h = (" << x_two << "-" << x_one << ")/2" << endl;
    float x_middle = x_one+h;
    cout << "x1 = " << x_one << "+" << h << endl;
    cout << "(" << h << "/3)*(" << func(x_one) << "+4*" <<
    func(x_middle) << "+" << func(x_two) << ")" << endl;
    return (h/3)*(func(x_one)+4*func(x_middle)+func(x_two));
}

float repeated(float x_one, float x_two, float m)
{
    float step = (x_two-x_one)/m;
    float sum = 0;
    for (float i = x_one; i < x_two; i += step)
    {
        sum += simpson(i, i+step);
    }
    return sum;
}

int main()
{
    float m, a, b;
    cout << "Insira o a do intervalo [a, b]: ";
    cin >> a;
    cout << "Insira o b do intervalo [a, b]: ";
    cin >> b;
    cout << "Insira m: ";
    cin >> m;
    cout << "Resultado: " << repeated(a, b, m) << endl;
    return 0;
}