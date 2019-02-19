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
const int NUM_MIN = 0;


/*Structs*/

struct coordenada {
  char x;
  char y;
};


/*Funciones Programa*/
void mostrarMapa();
void enumerarMapa();
void formatearMapa();
void addCord(coordenada c);
void delCord(coordenada c);
void mostrarCord(coordenada c);
coordenada pedirCord();

/*Menús*/
void menuAdd();

/*Main*/

int main(){
    //system("color f0");
    int op;
    int yn;
    do {
      std::cout << "\t\t\tMAPA COORDENADAS X Y" << "\n\n";
      std::cout << "\t\t\t   0    1    2    3" << '\n';
      mostrarMapa();

      std::cin >> op;

      switch (op) {
        case 1: std::cout << "1" << '\n';
        break;
      }
    } while(op != 4 );
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
  } while( a > NUM_MAX -1 || a < NUM_MIN);

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
  int i = 0;
  entrada.open(DIR_MAPA);
  if (entrada.good()) {
    while (!entrada.eof()) {
      entrada.getline(linea,100);
      if (i<4) {
        std::cout << "\t\t\t" << i << " ";
      }
      std::cout << linea << '\n';
      i++;
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
  int i1 = 0;
  int e1 = 0;

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
void delCord(coordenada c){
  ifstream entrada;
  ofstream salida;

  entrada.open(DIR_MAPA_1);
  salida.open(DIR_MAPA,ios::trunc);

  char linea[6];
  int i1 = 0;
  int e1 = 0;

  if(entrada.good()){

                while (entrada.read( (char*) &linea, sizeof(linea)-1 ) ) {

                          if ((int)c.x - 48  == i1 && (int)c.y - 48 == e1) {
                            salida << "[  ]";
                            if (e1==3) {
                              salida << "\n";
                            }
                            else{
                              salida << " ";
                            }
                          }
                          else{

                              if ( strcmp(linea,"[++] ") == 0){
                                    salida << "[++] ";
                                  }

                              else if (strcmp(linea,"[++]\n") == 0){
                                    salida << "[++]\n";
                                  }

                              else {
                                    salida << "[  ]";
                                    if (e1==3) {
                                      salida << "\n";
                                    }
                                    else{
                                      salida << " ";
                                    }
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
