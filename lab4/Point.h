#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>


class Point {
public:
  //Konstruktor bezparametrowy
  Point();
  //Konstruktor parametrowy
  Point(double x, double y);
  //Destruktor wykonywany przed zwolnieniem pamięci ~Point();
  //Metoda nie modyfikująca stanu obiektu (const na końcu metody) //nie mogą zmodyfikować tego obiektu.
  double Distance(const Point &other) const;
  //metody akcesorów są publiczne i tylko przy ich pomocy
  //można się dostać z zewnątrz do pól klasy
  double GetX() const;
  double GetY() const;
  //metody seterów pozwalające zmienić stan obiektu //po jego zainicjalizowaniu
  void SetX(double x);
  void SetY(double y);
private:
//C++ wymaga jawnej deklaracji składowych pól klasy double x, y;
    double x_,y_;
};
