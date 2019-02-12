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
  char x;
  char y;
};


/*Funciones*/
void mostrarMapa();
void enumerarMapa();
void addCord(coordenada c);
void mostrarCord(coordenada c);
coordenada pedirCord();


/*Main*/

int main(){
  mostrarMapa();
  enumerarMapa();
  addCord(pedirCord());
  mostrarMapa();
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

  if(entrada.good()){

                while (entrada.read( (char*) &linea, sizeof(linea)-1 ) ) {

                          if (strcmp(linea,"[  ] " ) == 0 || strcmp(linea,"[  ]\n") == 0) {
                              salida << "[" << i1 << e1 << "] ";

                              if (strcmp(linea,"[  ]\n") == 0) {
                                salida << endl;
                              }

                            }

                          else if (strcmp(linea,"[++] " ) == 0 || strcmp(linea,"[++]\n") == 0) {
                            salida << "[++] ";
                            if (strcmp(linea,"[++]\n") == 0) {
                              salida << endl;
                            }
                          }



                            e1++;
                            if (e1==4) {
                              i1++;
                              e1 = 0;
                            }
                  }
      entrada.close();
      salida.close();
    }

    else {
      std::cout << "Error 01: NO se puede leer el ARCHIVO " << DIR_MAPA << '\n';
      entrada.close();
      salida.close();
    }

}

/*Añadir Coordenada*/
void addCord(coordenada c){

  ifstream entrada;
  ofstream salida;

  char linea[6];
  char x = c.x;
  char y = c.y;
  char comb1[6] = {'[',x,y,']',' '};
  char comb2[6] = {'[',x,y,']','\n'};
  int i1 = 0;
  int e1 = 0;

  entrada.open(DIR_MAPA_1);
  salida.open(DIR_MAPA,ios::trunc);

  if (entrada.good()) {

      std::cout << comb1 << '\n';

      while (entrada.read( (char*) &linea, sizeof(linea)-1) ) {

        if (strcmp(linea,comb1) == 0 || strcmp(linea,comb2) == 0) {
            salida << "[++] ";

            if (strcmp(linea,comb2) == 0) {
              salida << endl;
              i1++;
            }

          }

        else {
          salida << "[  ] ";
        }


          e1++;
          if (e1==4) {
            i1++;
            e1 = 0;
            salida << endl;
          }
      }

      entrada.close();
      salida.close();
  }

  else{
      std::cout << "Error 02: NO se puede leer el ARCHIVO " << DIR_MAPA << '\n';
      entrada.close();
      salida.close();
  }
}
