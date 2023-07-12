import matplotlib.pyplot as plt

def graficar(x, y, msg):
    plt.plot(x, y)  # Grafica los puntos (x, y)
    plt.xlabel('x')
    plt.ylabel('y')
    plt.title(msg)
    plt.grid(True)
    plt.show()

def graficar_funcion_lineal(m, b):
    x = range(0, 20)  # Rango de valores de x
    y = [m * i + b for i in x]  # Calcula los valores de y para cada x

    graficar(x, y, 'Gráfica de una función lineal')

# Parámetros de la función lineal: y = mx + b
pendiente = 1
intercepto = 0

# graficar_funcion_lineal(pendiente, intercepto)

def graficar_funcion_cuadratica(a, b ,c):
    x = range(-20, 21)
    y = [a * i**2 + b * i + c for i in x]
    
    graficar(x, y, 'Gráfica de una función cuadrática')
    
# Parámetros de la función cuadrática: y = ax^2 + bx + c
a = 1
b = 0
c = 0

# graficar_funcion_cuadratica(a, b, c)

def graficar_funcion_tercer_grado(a, b, c, d):
    x = range(-20, 21)
    y = [a * i**3 + b * i**2 + c * i + d for i in x]
    
    graficar(x, y, 'Gráfica de una función de tercer grado')
    
# Parámetros de la función de tercer grado: y = ax^3 + bx^2 + cx + d
a = 1
b = 0
c = 0
d = 0

graficar_funcion_tercer_grado(a, b, c, d)
    
    
