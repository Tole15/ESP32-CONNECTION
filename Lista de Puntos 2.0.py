import csv
import math
import serial

# definir el centro de la circunferencia 
# Tome en cuenta que en este caso se utilizo centro 0,0 sin embargo para el uso  final debe ser modificado segun la calibración del 0 de los servos, y la longitud del los eslabones
#En el caso de la simulación anexada como "AREA DE TRABAJO 5 BARRAS" puede usar el archivo gbb para modificar el tamaño de los eslabones y el área del trabajo
#Asi mismo se puede observar la posición inicial.
#Por ende en nuestro trabajo final será 5,13 dentro del formato  (x,y)
centro_x = 0
centro_y = 0

# definir el radio de la circunferencia
radio = 4

# definir la cantidad de puntos a generar
num_puntos = 50

# generar lista de puntos
puntos = []
for i in range(num_puntos):
    angulo = 2 * math.pi * i / num_puntos
    x = centro_x + radio * math.cos(angulo)
    y = centro_y + radio * math.sin(angulo)
    puntos.append((x, y))

# abrir conexión serial con Arduino
ser = serial.Serial('COM3', 9600)  # cambiar 'COM3' por el puerto serie correspondiente

# enviar lista de puntos a través de la conexión serial
with open('puntos.csv', 'w', newline='') as csvfile:
    writer = csv.writer(csvfile, delimiter=',')
    writer.writerow(['x', 'y'])
    for punto in puntos:
        writer.writerow(punto)
        ser.write("{},{}\n".format(punto[0], punto[1]).encode())

# cerrar conexión serial
ser.close()
