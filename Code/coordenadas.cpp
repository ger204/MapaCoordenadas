#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>

using namespace std;

const char DIR_MAPA[] = "E:\\Programing\\C++\\BYME\\Oficial\\COORDENADAS\\Map\\mapa.txt";
const char DIR_MAPA_1[] = "E:\\Programing\\C++\\BYME\\Oficial\\COORDENADAS\\Map\\mapa1.txt";
const int VISUAL_CORD = 5;

/*Structs*/

struct coordenada {
  int x;
  int y;
};


/*Funciones*/
void mostrarMapa();
void enumerarMapa();
void mostrarCord(coordenada c);
coordenada pedirCord();


/*Main*/

int main(){
  mostrarMapa();
  enumerarMapa();
  return 0;
}


/*Pidiendo Coordenada*/

coordenada pedirCord(){
  coordenada c;
  std::cout << "Punto X: ";
  std::cin >> c.x;
  std::cout << "Punto Y: ";
  std::cin >> c.y;
  return c;
}


/*Mostrar Coordenada*/

void mostrarCord(coordenada c){
  std::cout << "X: " << c.x << '\n';
  std::cout << "Y: " << c.y << '\n';
}


/*Mostrar Mapa*/

void mostrarMapa(){
  ifstream entrada;
  char linea[100];

  entrada.open(DIR_MAPA);
  if (entrada.good()) {
    while (!entrada.eof()) {
      entrada.getline(linea,100);
      std::cout << linea << '\n';
    }
    entrada.close();
  }
  entrada.close();
}


/*Enumerar Mapa*/

void enumerarMapa(){
  ifstream entrada;
  ofstream salida;

  entrada.open(DIR_MAPA);
  salida.open(DIR_MAPA_1);

  char linea[6];

  if(entrada.good()){
    std::cout << "ENTRADA EN BUEN ESTADO" << '\n';

      for (int i = 0; i < 6; i++) {
        entrada.getline(linea,6);
        std::cout << linea << '\n';

        if (strcmp(linea, "[  ] ") == 0) {
          std::cout << "HA ENTRADO AL IF" << '\n';
          salida << "[" << i << " ] ";
        }

      }


     entrada.close();
     salida.close();
    }

}
