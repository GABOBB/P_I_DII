#include <iostream>

class prueva {
    int a = 5;
public:
    void seta(int x) {
        a = x;
    }

    bool operator & (prueva p) {
        if(p.a == a) {
            return true;
        }
        return false;
    };
};


int main(){
    prueva x,y;

    y.seta(66);

    std::cout << (x & y) <<std::endl;

}
