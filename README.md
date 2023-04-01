# ESP32-CONNECTION
Using Arduino IDE and html with JavaScript, in a web page, connected to a server in the 80 port, we send trough a button a function to active on Arduino IDE.

A robotic mechanism has been developed to control the movement of a figure tracing instrument on a plane using two servo motors, and a third servo motor to control the mechanism and elevation in the z-axis. The working area of the mechanism is 50 cm2. The user controls the mechanism through a web application that presents a set of basic figures to select from. This mechanism allows for precise tracing of figures on the plane quickly and easily, making it suitable for educational and design applications.

More especific:
The Arduino IDE is an integrated development environment used for programming Arduino microcontrollers. It includes a code editor, compiler, and uploader for the Arduino board.

To control an Arduino board from a web page, we can use HTML and JavaScript to create a user interface, and send commands to the board via the Serial port. The Serial port is a hardware interface on the Arduino board that allows us to communicate with the board over a USB cable or other serial connection.

To send commands from a web page to an Arduino board, we need to establish a connection between the two devices. We can do this by running a web server on the Arduino board and connecting to it from the web page using an IP address and port number.

In this case, we're connecting to a server running on port 80, which is the default port for HTTP traffic. We can use XMLHttpRequests in JavaScript to send commands to the Arduino board by making GET or POST requests to the server.

When a button on the web page is clicked, a JavaScript function is called that sends a command to the Arduino board over the Serial port. The Arduino board receives the command and executes the appropriate action based on the code in its sketch.

This can be a powerful way to control physical devices and sensors connected to an Arduino board from a web interface. With the right combination of hardware and software, it's possible to create complex and interactive applications that can be accessed from anywhere with an internet connection.

INDEX FILE:

This is a HTML webpage that allows the user to control a drawing robot using two buttons. The webpage is designed with a green color scheme and includes a header and footer. The header displays the title of the webpage, which is "Control Online de Stand The Pencil". The body of the webpage contains two buttons, one for drawing a rectangle and the other for drawing a triangle. The buttons are centered on the webpage and have a large font size.

The script at the end of the HTML file uses jQuery to handle the button clicks. When the user clicks the "Rectángulo" button, a GET request is sent to the IP address and port of an ESP32 microcontroller. This triggers the execution of a predefined sequence of movements that will draw a rectangle with the robot. Similarly, when the user clicks the "Triángulo" button, another GET request is sent to the ESP32, which will execute a sequence of movements to draw a triangle. After each button click, an alert message pops up on the screen to confirm that the sequence has been initiated.

Codigobasepaginawe(INO) FILE:

 This code sets up an asynchronous web server using the ESPAsyncWebServer library. When a GET request is received at the root directory ("/"), the server sends a "Conectado" message in response. When a GET request is received at "/secuencia1" or "/secuencia2", the server calls a corresponding function to draw a figure (e.g. a circle or triangle) and sends a message indicating that the sequence has been activated. The wifihumilde() function is not used in this code, but appears to be intended for connecting to a WiFi network. The loop() function is empty in this example, but could be used for other tasks that need to be performed continuously.
 
 listadepuntos (python file):
 
 This code generates a set of points that lie on the circumference of a circle with a given center and radius. It first defines the center and radius of the circle, as well as the number of points to generate. It then generates a list of points on the circumference of the circle using a loop and some trigonometry to calculate the x and y coordinates of each point.

The loop generates num_puntos equally spaced points along the circumference of the circle by calculating the angle between the x-axis and a line connecting the center of the circle to each point. It then uses these angles to calculate the x and y coordinates of each point using the parametric equations of a circle.

Finally, the code saves the list of points to a CSV file named "puntos.csv". This file contains the x and y coordinates of each point, with each point represented as a row in the file.
