#include <iostream>
#include <vector>
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

float lagrange_interpolation(float x, vector<vector<float>> coords)
{
    float interpolation = 0;
    int i = 0;
    for (vector<float> coord : coords)
    {
        interpolation += (coord[1]*lagrange(x, i++, coords));
    }
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
        float x, y;
        cout << "Insira coordenada x para o ponto " << i << ":";
        cin >> x;
        cout << "Insira coordenada y para o ponto " << i << ":";
        cin >> y;
        coordinates.push_back(vector<float>{x, y});
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