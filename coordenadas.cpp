#include <iostream>
#include <fstream>

using namespace std;


/*Structs*/

struct coordenada {
  int x;
  int y;
};


/*Funciones*/

void mostrarCord(coordenada c);
coordenada pedirCord();


/*Main*/

int main(){

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
