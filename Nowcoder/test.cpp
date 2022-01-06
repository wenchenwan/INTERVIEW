#include"iostream"
using namespace std;

class A{
    public:
    A(int a){
        this->data = a;
    }
    int data;

    A operator+=(const A& b){
        this->data+=b.data;
        return *this;
    }

    
};

const A operator+(const A& a,const A& b){
        return A(a)+=b;
}

int main(){
    A a = 3;
    A b = 5;
    a+b;
    cout << a.data;
    cout << (a+b).data;
    while(1);
    return 0;
}