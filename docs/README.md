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
* Realizar historia de usuario número 2 del taller de Estructura de Datos, la cual consiste en mostrar las ultimas cinco ídentidades que más tiempo han sido vistas.
* Realizar historia de usuario número 4 del taller de Estructura de Datos, la cual consiste en contar con un listado por sesión de todas las identidades detectadas, indicando el tiempo total de las veces que apareció.
* Realizar historia de usuario número 5 del taller de Estructura de Datos, la cual consiste en almacenar las imagenes obtenidas.
* Realizar historia de usuario número 6 del taller de Estructura de Datos, la cual consiste en obtener un listado con las identidades obtenidas y todos los intervalos de tiempo en el que aparece.

## 1. Introducción
En el presente informe se dará a conocer un breve paso a paso sobre la creación de este proyecto, el cual consiste en una aplicación capaz de detectar rostros, guardar imágenes, obtener una serie de resultados.
### 1.1 Descripción del problema
Se debe desarrollar un algoritmo capaz de detectar rostros, destacándolos con un rectángular, seguido de esto, la aplicación deberá permitir realizar cada historia de usuario nombrada anteriormente. 
### 1.2 Objetivos
* Construir un sistema capaz de detectar rostros, el sistema debe ser capaz de dibujar un rectángulo encima del un rostro bien detectado.
  1. Instalar y configurar CLion.
  2. Instalar OpenCV en CLion.
  3. Construir un programa capaz de detectar rostros de fotografías.
* Almacenar cada imagen observada en un Árbol binario de búsqueda, luego, en base a este, revolver los requerimientos de las historias de usuario.
### 1.3 Solución propuesta
La solución consiste en un software capaz de realizar lo siguiente:
* Dibujar un rectángulo en todos los rostros detectados de una fotografía.
* Observar los rostros mas comunes. 
* Mostrar y almacenar (txt) las identidades detectadas, indicando el total de las veces que apareció. 
* Almacenar en formato jpg las identidades obtenidas. 
* Mostrar y almacenar (txt) un listado con las identidades obtenidas y todas las veces que apareció. 
* Realizar un listado por sesión de las identidades detectadas.

Todo esto en una interfaz guardia/administrador, en el cual y según corresponda podrán acceder a una serie de opciones.
## 2. Materiales y métodos
### 2.1 Instalación
OpenCV: Open Source Computer Vision es una libreria de c y c++ que provee una infraestructura para aplicaciones de visión artificial, esta librería permite, en este caso, detectar objetos (rostros humanos).
### 2.2 Diseño

------------
    ├── src         	<- Source code for use in this project.
    │   ├── logic		<- Contains the classes used in the program.
    │   │   │   └── header
    │   │   │       ├── BinaryTree.h
    │   │   │       ├── BinaryTreeNode.h
    │   │   │       ├── FaceDetector.h
    │   │   │       └── ImageCoding.h
    │   │   ├── BinaryTree.cpp
	│   │   ├── FaceDetector.cpp
	│   │   └── ImageCoding.cpp
    │   ├── results     	<- Contains the information and images saved after a session.
    │   │   ├── images      <- images saved after a session.
	│   │   └── information <- information saved after a session.
    │   │       ├── appearances.txt
    │   │       └── information.txt
    │   ├── resources	<- Contains the images / videos used for testing.
    │   │   ├── haarscascade_frontalface_default.xml
	│   │   └── ...jpg
    │   └── main.cpp
--------
### 2.3 Implementación
#### Detector de caras
El detector de caras utilizado fue el Haar Cascade, el cual permite detectar objetos, en este caso, se utilizó el frontal face, para detectar los rostros en las imágenes que utilizamos de prueba.
Los rostros detectados se fueron guardando en el arbol binario que implementamos.
```c++
for (string im : imagesStr) {
        cout << im << endl;
        frame = imread(im, IMREAD_COLOR);


        auto faces = faceDetector.detectRectangles(frame);

        icoding.setImage(frame);
        auto faceCodingGray = icoding.codeGray(faces, true, Size(25, 25));
        Mat colorImage;
        Mat newSize;
        int posX = 10;
        for (const auto &cf : faceCodingGray){
            abb.insert(cf); //ACA SE UTILIZA EL ARBOL BINARIO
            cvtColor(cf, colorImage, COLOR_GRAY2BGR);
            resize(colorImage, newSize, Size(40, 40), INTER_LINEAR);
            newSize.copyTo(frame(Rect(posX, 10, newSize.cols, newSize.rows)));
            posX += 40 + 10;
        }

        for(const auto &fm : faces){
            rectangle(frame, fm, drawColor, 4);
        }
        imshow("Image: ", frame);
        waitKey(0);
    }
```
#### Árbol Binario de Busqueda
Para ir guardando los rostros de las identidades se utilizó un ABB, el cual permitirá realizar todos los requerimientos, a continuación de enseñara su .h
```c++
class BinaryTree {
private:
    int DIFFERENT = 1700;
    int SIMILAR = 1300;
    int counter;
    int sequence;
    struct BinaryTreeNode* root;
    BinaryTreeNode* insert(BinaryTreeNode* node, Mat);
    void preOrder(BinaryTreeNode* node);
    double euclideanDistance(Mat, Mat);
    void writeAppearances(BinaryTreeNode* node, std::ofstream* file);
    void writeTotalTime(BinaryTreeNode* node, std::ofstream* file);
    void writeImages(BinaryTreeNode* node);
    void observeFiveIdentities(BinaryTreeNode* node, int cant);

public:
    BinaryTree() {
        counter = 0;
        root = nullptr;
        sequence = 1;
    }
    void insert(Mat);
    void preOrder();
    void writeAppearances();
    void writeTotalTime();
    void writeImages();
    void observeFiveIdentities();


    BinaryTreeNode* getRoot();


    ~BinaryTree();
};
```
## 3. Resultados obtenidos
Se pudo obtener los resultados esperados en base a lo que entendimos de los requerimientos, obteniendo las imágenes y almacenando correctamente los datos pedidos.
* Información pedida por el administrador (historia número 4):
![information](https://github.com/Shpm21/ED21-02-Aravena-Galleguillos/blob/release_1.0/docs/images/information.png)
* Imágenes en results/images (historia número 5):
![images](https://github.com/Shpm21/ED21-02-Aravena-Galleguillos/blob/release_1.0/docs/images/imagenes.png)
* Información pedida por el administrador (historia número 6):
![appearances](https://github.com/Shpm21/ED21-02-Aravena-Galleguillos/blob/release_1.0/docs/images/appearances.png)
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
