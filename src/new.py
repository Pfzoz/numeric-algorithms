def func(n : float) -> float:
    return n**4+42*n

def difference(x_points : list) -> float:
    if len(x_points) == 1:
        return func(x_points[0])
    else:
        return (difference(x_points[1:])-difference(x_points[:-1]))/(x_points[-1]-x_points[0])

def newton_interpolate(x : float, x_points : list) -> float:
    sum = 0
    calculo = ''
    for i in range(len(x_points)):
        if i == 0:
            calculo += f"d0({difference(x_points[:1])})"
            sum += difference(x_points[:1])
        else:
            calculo += f" + d{i}({difference(x_points[:i+1])})"
            diff = difference(x_points[:i+1])
            for j in range(i):
                diff *= (x-x_points[j])
                calculo += f"*({x}-{x_points[j]})"
            sum += diff
    print(calculo)
    return sum

x_points = []

for i in range(int(input("Insira a quantidade de pontos:"))):
    x_points.append(float(input(f"Insira o x{i}: ")))

print("Interpolação: ", newton_interpolate(float(input("Número a ser interpolado: ")), x_points))
