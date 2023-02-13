#include <iostream>
#include <vector>
using namespace std;

float difference(int n, vector<vector<float>> coordinates)
{
    if (n == 0)
    {
        cout << coordinates[0][1];
        return coordinates[0][1];        
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            vector<vector<float>> erased_one = coordinates;
            vector<vector<float>> erased_two = coordinates;
            erased_one.erase(erased_one.begin());
            cout << erased_one.size() << "|" << erased_two.size() << endl;
            float nominator = (difference(n-1, erased_one)-difference(n-1, coordinates));
            float denominator = (coordinates[coordinates.size()-1][0]-coordinates[0][0]);
            cout << nominator/denominator << endl;
            return nominator/denominator;
        }
    }
    return 0;
}

float newton_interpolation(float x, vector<vector<float>> coordinates)
{
    float sum = 0;
    for (int i = 0; i < coordinates.size(); i++)
    {
        if (i == 0)
        {
            sum = difference(i, coordinates);
        }
        else
        {
            float summer = difference(i, coordinates);
            for (int j = 0; j < i; j++)
            {
                summer *= x-coordinates[j][0];
            }
            sum += summer;
        }
    }
    return sum;
}

int main()
{
    vector<vector<float>> coordinates;
    int point_amount;
    cout << "Insira a quantidade de coordenadas: ";
    cin >> point_amount;
    for (int i = 0; i < point_amount; i++)
    {
        float x, y;
        cout << "Cordenada - " << i << endl;
        cout << "Insira o ponto x: ";
        cin >> x;
        cout << "Insira o ponto y: ";
        cin >> y;
        coordinates.push_back(vector<float>{x, y});
    }
    float x_point;
    cout << "Insira o ponto a ser interpolado: ";
    cin >> x_point;
    cout << newton_interpolation(x_point, coordinates) << endl;
    


    return 0;
}