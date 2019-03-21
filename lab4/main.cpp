#include <iostream>
#include <string>
#include <utility>
#include <initializer_list>


using std::string;

class K{

public:

    int x,y;
    K(int a, int b) : x(a) , y(b) {}
    K() : K(0,0) {}
    K(K& origin) : x(origin.x) , y(origin.y) {}

    friend std::ostream& operator<<(std::ostream& os, const K& k);
};

std::ostream& operator<<(std::ostream& os, const K& k){
    os << "x = " <<  k.x << ", y = " << k.y << '\n';
    return os;
}


int main(){

    K k1(1,2);
    std::cout << k1;

    K k2 = k1;

    std::cout << k2;



    return 0;
}
