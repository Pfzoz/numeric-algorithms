#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<float>> coordinates;
    float x_one, y_one, x_two, y_two;
    cout << "Insira a coordenada x1:";
    cin >> x_one;
    cout << "Insira a coordenada y1:";
    cin >> y_one;
    cout << "Insira a coordenada x2:";
    cin >> x_two;
    cout << "Insira a coordenada y2:";
    cin >> y_two;
    float a = (y_two - y_one)/(x_two-x_one);
    float b = (y_one)-(a*x_one);
    float x;
    cout << "Insira o ponto a ser interpolado: ";
    cin >> x;
    float interpolation = a*x+b;
    cout << "Interpolação: " << interpolation << endl;
    return 0;
}