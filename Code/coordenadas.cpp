#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <cstring>

using namespace std;

const char DIR_MAPA[] = "E:\\Programing\\C++\\BYME\\Oficial\\COORDENADAS\\Map\\mapa.txt";
const char DIR_MAPA_1[] = "E:\\Programing\\C++\\BYME\\Oficial\\COORDENADAS\\Map\\mapa1.txt";
const char DIR_MAPA_O[] = "E:\\Programing\\C++\\BYME\\Oficial\\COORDENADAS\\Map\\mapa-original.txt";
const int NUM_MAX = 4;
const int NUM_MIN = 1;


/*Structs*/

struct coordenada {
  char x;
  char y;
};


/*Funciones*/
void mostrarMapa();
void enumerarMapa();
void formatearMapa();
void addCord(coordenada c);
void removeCord(coordenada c);
void mostrarCord(coordenada c);
coordenada pedirCord();


/*Main*/

int main(){
  formatearMapa();
  mostrarMapa();

  return 0;
}


/*Pidiendo Coordenada*/

coordenada pedirCord(){
  coordenada c;
  int a;
  int b;
  do {
    std::cout << "Punto X: ";
    std::cin >> c.x;
    a = c.x - '0';
  } while( a > NUM_MAX  || a < NUM_MIN);

  do {
    std::cout << "Punto Y: ";
    std::cin >> c.y;
    b = c.y - '0';
  } while( b > NUM_MAX || b < NUM_MIN);

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

  else{
    std::cout << "Error 04: No se puede leer el ARCHIVO" << DIR_MAPA << '\n';
    entrada.close();
  }

}


/*Enumerar Mapa*/

void enumerarMapa(){
  ifstream entrada;
  ofstream salida;

  entrada.open(DIR_MAPA);
  salida.open(DIR_MAPA_1,ios::trunc);

  char linea[6];
  int i1 = 1;
  int e1 = 1;

  if(entrada.good()){

                while (entrada.read( (char*) &linea, sizeof(linea)-1 ) ) {

                          if (strcmp(linea,"[  ] " ) == 0 || strcmp(linea,"[  ]\n") == 0) {

                             if (strcmp(linea,"[  ] " ) == 0 ){
                                salida << "[" << i1 << e1 << "] ";
                              }


                             if (strcmp(linea,"[  ]\n") == 0) {
                                salida << "[" << i1 << e1 << "]\n";
                              }

                            }

                          else if (strcmp(linea,"[++] " ) == 0 || strcmp(linea,"[++]\n") == 0) {

                            if (strcmp(linea,"[++] ") == 0) {
                              salida << "[++] ";
                            }

                            if (strcmp(linea,"[++]\n") == 0) {
                              salida << "[++]\n";
                            }
                          }



                            e1++;
                            if (e1==5) {
                              i1++;
                              e1 = 1;
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

  entrada.open(DIR_MAPA_1);
  salida.open(DIR_MAPA,ios::trunc);

  char linea[6];
  int i1 = 0;
  int e1 = 0;
  char comb1[6] = {'[',c.x,c.y,']',' '};
  char comb2[6] = {'[',c.x,c.y,']','\n'};

  if(entrada.good()){

                while (entrada.read( (char*) &linea, sizeof(linea)-1 ) ) {


                          if (strcmp(linea,comb1 ) == 0 || strcmp(linea,comb2) == 0) {

                              if (strcmp(linea,comb1) == 0) {
                                salida << "[++] ";
                              }

                              if (strcmp(linea,comb2) == 0) {
                                salida << "[++]\n";
                              }

                            }

                          else if (strcmp(linea,"[++] " ) == 0 || strcmp(linea,"[++]\n") == 0) {

                            if (strcmp(linea,"[++] ") == 0) {
                              salida << "[++] ";
                            }

                            if (strcmp(linea,"[++]\n") == 0) {
                              salida << "[++]\n";
                            }

                          }

                          else {
                            salida << "[  ]";
                            if (e1==3) {
                              salida << endl;
                            }
                            else {
                              salida << " ";
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

/*Eliminar Coordenada*/
void removeCord(coordenada c){

    ifstream entrada;
    ofstream salida;

    entrada.open(DIR_MAPA_1);
    salida.open(DIR_MAPA,ios::trunc);

    char linea[6];
    int i1 = 1;
    int e1 = 1;
    char i2 = 1;
    char e2 = 1;

    int q2 = c.y - '1';

    char k2 = (char)(q2 + 48);

    char comb3[6] = {'[',c.x,k2,']',' '};
    char comb4[6] = {'[',c.x,k2,']','\n'};
    char comb5[6] = {"[00] "};
    char comb6[6] = {"[00]\n"};
    std::cout << comb3 << '\n';
    char comb1[6];
    char comb2[6];

    bool a = false;
    bool b = false;

    if(entrada.good()){

                  while (entrada.read( (char*) &linea, sizeof("[  ] ")- 1 ) ) {
                            i2 = (char)(i1 + 48);
                            e2 = (char)(e1 + 48);
                            char combA[6] = {'[',i2,e2,']',' '};
                            char combB[6] = {'[',i2,e2,']','\n'};;
                            if (a  || b ) {
                              std::cout << "ENTERED" << '\n';
                              if (a) {
                                salida << "[  ] ";
                              }

                              else {
                                salida << "[  ]\n";
                              }
                            }

                            else if (strcmp(linea,"[++] " ) == 0 || strcmp(linea,"[++]\n") == 0) {
                              std::cout << "Ha entrado" << '\n';
                              if (strcmp(linea,"[++] ") == 0) {
                                salida << "[++] ";
                              }

                              if (strcmp(linea,"[++]\n") == 0) {
                                salida << "[++]\n";
                              }

                            }

                            else {
                              salida << "[  ]";
                              std::cout << "MESSAGE" << '\n';
                              if (e1==4) {
                                salida << endl;
                              }
                              else {
                                salida << " ";
                              }
                            }

                            if (strcmp(linea,comb3 ) == 0 || strcmp(linea, comb4 ) == 0) {
                              std::cout << "P" << '\n';
                              if (strcmp(linea,comb3 ) == 0) {
                                a = true;
                              }

                              else{
                                b = true;
                              }

                            }

                            else{
                              a = false;
                              b = false;
                            }

                            e1++;
                            if (e1==5) {
                              i1++;
                              e1 = 1;
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

/*Formatear Mapa*/

void formatearMapa() {

  ifstream ent;
  ofstream sal;

  ent.open(DIR_MAPA_O);
  sal.open(DIR_MAPA,ios::trunc);

  char linea[100];
  if (ent.good()) {
    while (!ent.eof()) {
      ent.getline(linea,100);
      sal << linea << '\n';
    }
  }

  else{
    std::cout << "Error 03: NO se puede leer el ARCHIVO " << DIR_MAPA_O << '\n';
    ent.close();
    sal.close();
  }
}
