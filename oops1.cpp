#include<iostream>
#include<cstring>
using namespace std;
class car{
    private:
    int acc;
    
    public:
    //constructor
    car (){
        cout<<"making of the car"<<endl;
    }

    car (int a, int b, char *n){
        cout<<"making parametrized car"<<endl;
        topspeed = a;
        model = b;
        strcpy(name,n);
    }

    int topspeed;
    int model;
    char name[20];
    void setacc(int a){
        acc = a;
    }
    int getacc(){
        return acc;
    }
    //print function
    void print(){
        cout<<name<<endl;
        cout<<topspeed<<endl;
        cout<<model<<endl;
    }

};
int main(){
    car c;
    //cout<<sizeof(c)<<endl;
    //cout<<sizeof(car)<<endl; //it will take 28 bytes when an object would be declared
    //cout<<"hello"<<endl;
    c.model = 1001;
    c.topspeed = 60;
    c.name[0] = 'B';
    c.setacc(10);
    cout<<"Acceleration is "<<c.getacc()<<endl;
    cout<<c.topspeed<<endl;
    cout<<c.model<<endl;
    cout<<c.name<<endl;

    //cout <<
    car p(100,10001,"Ferrari");
    p.print();

    return 0;
}
