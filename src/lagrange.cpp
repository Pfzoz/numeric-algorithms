#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

float lagrange(float x, int j, vector<vector<float>> coords)
{
    float nominator = 1, denominator = 1;
    for (int i = 0; i < coords.size(); i++)
    {
        vector<float> coord = coords[i];
        if (j != i)
        {
            nominator *= (x - coord[0]);
            denominator *= (coords[j][0] - coord[0]);
        }
    }
    return nominator/denominator;
}

float func(float x)
{
    // return pow(x, 3)*pow(x, 2)-x+10;
    return pow(x, 3)+42*x;
}

float lagrange_interpolation(float x, vector<vector<float>> coords)
{
    float interpolation = 0;
    int i = 0;
    string calculo;
    for (vector<float> coord : coords)
    {
        calculo.append(to_string(coord[1]));
        calculo.append("*L(");
        calculo.append(to_string(i));
        calculo.append(")");
        calculo.append(to_string(lagrange(x, i, coords)));
        calculo.append(" + ");
        interpolation += (coord[1]*lagrange(x, i++, coords));
    }
    cout << calculo << endl;
    return interpolation;
}

int main()
{
    int points_amount;
    cout << "Insira a quantidade de coordenadas:";
    cin >> points_amount;
    vector<vector<float>> coordinates;

    for (int i = 0; i < points_amount; i++)
    {
        float x;
        cout << "Insira coordenada x para o ponto " << i << ":";
        cin >> x;
        coordinates.push_back(vector<float>{x, func(x)});
    }
    int x;
    while (1)
    {
        cout << "Insira o ponto x: ";
        cin >> x;
        cout << "Interpolação: " << lagrange_interpolation(x, coordinates) << '\n';
        string answer;
        cout << "Continuar? [s(default)/n]";
        cin >> answer;
        if (answer == "n") break;
    }
    
    return 0;
}