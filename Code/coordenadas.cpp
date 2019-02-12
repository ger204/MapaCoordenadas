#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <cstring>

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
  salida.open(DIR_MAPA_1,ios::trunc);

  char linea[6];
  int i1 = 0;
  int e1 = 0;
  int count = 0;

  if(entrada.good()){
    std::cout << "ENTRADA EN BUEN ESTADO" << '\n';

                while (entrada.read( linea, 5 )) {
                  std::cout << "Ha entrado al WHILE" << '\n';
                  std::cout << linea << '\n';

                        if ( i1<5 ) {
                          std::cout << "001" << '\n';
                            if (e1<5) {
                              std::cout << "002" << '\n';
                                if (strcmp(linea,"[  ] " ) == 0) {
                                    std::cout << "HA ENTRADO AL IF" << '\n';
                                    salida << "[" << i1 << e1 << "] ";
                                  }
                                e1++;
                            }
                          salida << endl;
                          i1++;
                        }
                  }
      entrada.close();
      salida.close();
    }

    else {
      std::cout << "ENTRADA EN MAL ESTADO" << '\n';
      entrada.close();
      salida.close();
    }


}
