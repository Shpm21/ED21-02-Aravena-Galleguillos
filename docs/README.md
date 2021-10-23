# Informe Técnico
## Curso: estructura de datos
#### Detección y reidentificación de caras en secuencias de imágenes o video
Alumnos:
* Joaquín Aravena (Bitácora)
* Cristian Galleguillos (Coordinador)

## Resumen
> En esta actividad, se realizaron las siguientes actividades:
* Instalación de la librería OpenCV en CLion.
* Realizar historia de usuario número 1 del taller de Estructura de Datos, la cual consiste en crear un algoritmo en conjunto con la librería OpenCV que dibuje un rectángulo en los rostros que fueron correctamente detectados.
* Realizar historia de usuario número 2 del taller de Estructura de Datos, la cual consiste en crear un algoritmo capaz de detectar rostros en un video para luego ser almacenados en una LinkedList.
## 1. Introducción
En el presente informe se explicará cómo realizar la instalación y configuración de CLion con la librería OpenCV, también se demostrará como llevar a cabo la actividad de la historia de usuario número 1 y número 2.
### 1.1 Descripción del problema
Se debe desarrollar un algoritmo capaz de detectar rostros en videos e imágenes, destacándolos con un rectángulo, pero para lograr desarrollar el programa primero que todo se debe realizar la instalación de OpenCV, una librería que nos ayudará a detectar de mejor forma los rostros. Luego de esto, los rostros detectados se guardarán en una clase llamada Identidad, la cual es capaz de almacenar un rostro detectado, luego, esta clase sera guardada en una LinkedList.
### 1.2 Objetivos
Construir un sistema capaz de detectar rostros, el sistema debe ser capaz de dibujar un rectángulo encima de un rostro bien detectado.
1. Instalar y configurar CLion.
2. Instalar OpenCV en CLion.
3. Construir un programa capaz de detectar rostros de fotografías.
4. Construir un programa capaz de detectar rostros en videos.
5. Construir una clase llamada Identidad, la cual se encargará de guardar tanto el rostro, como las veces que ese rostro aparece.
6. Constuir una clase llamada LinkedList, la cual se encargará de almacenar las instancias de Identidad.
### 1.3 Solución propuesta
Software capaz de dibujar un rectángulo en todos los rostros detectados de una fotografía/video.
## 2. Materiales y métodos
### 2.1 Instalación
OpenCV: Open Source Computer Vision es una libreria de c y c++ que provee una infraestructura para aplicaciones de visión artificial, esta librería permite, en este caso, detectar objetos (rostros humanos).
### 2.2 Diseño
------------
    ├── src         		   <- Source code for use in this project.
    │   ├── logic			<- Contains the classes used in the program.
    │   │   ├── Identidad.cpp
	│   │   ├── Identidad.h
	│   │   ├── LinkedList.cpp
	│   │   ├── LinkedList.h
    │   │   ├── Node.cpp
	│   │   └──  Node.h
    │   ├── resources	<- Contains the images / videos used for testing.
    │   │   ├── haarscascade_frontalface_default.xml
	│   │   ├── photo.jpg
	│   │   └── video.mp4
    │   └── main.cpp
--------
### 2.3 Implementación
#### Detector de caras
El detector de caras utilizado fue el Haar Cascade, el cual permite detectar objetos, en este caso, se utilizó el frontal face, para detectar los rostrosen los videos utilizados de prueba.
Primero se carga el path del video:

``` c++
	const string pathToVideo = "C:/C++Projects/Taller1/ED21-02-Aravena-Galleguillos/src/resources/video.mp4";
    VideoCapture video(pathToVideo);
```
Luego, utilizamos un ciclo while para que se ejecute el video y el programa comience a detectar rostros:
```c++
    Mat frame;
    vector<Rect> faces;
    LinkedList array = LinkedList();
    while(true) {
        video.read(frame);
        faceCascade.detectMultiScale(frame, faces, 1.1, 25);

        for (auto & area : faces){
            rectangle(frame, area.tl(), area.br(), drawColor, 3);
            Identidad i = Identidad(area);
            array.add(i);
        }

        //Muestra los frames
        imshow("Video", frame);
    }
```
## 3. Resultados obtenidos
El resultado del código que implementamos es el siguiente:
[![Resultado](https://github.com/Shpm21/ED21-02-Aravena-Galleguillos/blob/release_0.1/docs/images/resultado_release0.2.png "Resultado")](https://github.com/Shpm21/ED21-02-Aravena-Galleguillos/blob/release_0.2/docs/images/resultado_release0.1.png "Resultado")
## 4. Conclusiones
## Anexo A: Instalación librerías OpenCV
**Para ambos casos hay que descargar la versión 4.5.2**
(1) Link de descarga de OpenCV: [https://opencv.org/releases/](https://opencv.org/releases/)
(2) Link de descarga del compilador de OpenCV para Windows: https://github.com/huihut/OpenCV-MinGW-Build
1. Hacer doble click en el archivo descargado en el link (1) y extraer el contenido en la raíz del disco duro.
2. Descomprimir el archivo descargado en el link (2) y dirigirse a la carpeta **.../OpenCV-MinGW-Build-OpenCV-4.5.2-x64/x64** y cortar la carpeta mingw.
3. Pegar la carpeta anterior en extrajimos en el paso 1 en la siguiente ruta **.../opencv/build/x64**
4. Ahora debemos agregar al "path" las siguientes rutas:
- **.../opencv/build/x64/mingw/bin**
- **.../opencv/build/x64/mingw/lib**
## Anexo B: Instalación de IDE y configuración librerías OpenCV
El IDE utilizado para este taller es CLion descargado desde: [https://www.jetbrains.com/es-es/clion/download/#section=windows](https://www.jetbrains.com/es-es/clion/download/#section=windows)
## Configuración librerías OpenCV en CLion
Al momento de crear un proyecto en CLion se crea un archivo llamado **CMakeList.txt** en el archivo mencionado anteriormente debemos agregar las siguientes líneas:
set(OpenCV_DIR "...\\opencv\\build\\x64\\mingw\\lib")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Test ${OpenCV_LIBS})
Basta con reiniciar el archivo **CMakeList.txt** y CLion para que funcione OpenCV