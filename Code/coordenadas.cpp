#include <iostream>
#include <fstream>

using namespace std;

const char DIR_MAPA[] = "E:\\Programing\\C++\\BYME\\Oficial\\COORDENADAS\\Map\\mapa.txt";
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
  salida.open("E:\\Programing\\C++\\BYME\\Oficial\\COORDENADAS\\Map\\mapa1.txt");



}
