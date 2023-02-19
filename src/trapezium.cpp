#include <iostream>
#include <cmath>

using namespace std;

float func(float n)
{
    return pow(n, 3)+42*n;
}

float integral(float x_one, float x_two)
{
    float h = x_two-x_one;
    cout << "h = " << x_two << "-" << x_one << endl;
    cout << "S f(x) dx = (" << h << "/2)*(" << func(x_one)
    << "+" << func(x_two) << ")\n"; 
    return (h/2)*(func(x_one)+func(x_two));
}

float repeated(float x_one, float x_two, float m)
{
    float step = (x_two-x_one)/m;
    float sum = 0;
    for (float i = x_one; i < x_two; i += step)
    {
        sum += integral(i, i+step);
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