#include<iostream>
#include<cstring>
using namespace std;

class car{
    private:
        int price;
    public:
        int model;
        char *name; // here we are dynamically allocating the array
        //initialising a constant data member whose value cannot be updated.
        const int tyres;

        car():name(NULL),tyres(4){ //this is constructor
            //tyres = 4; // cannot assign value only initialise to const data members
        }

        car(int p ,int m ,char *n , int t = 4):price(p), model(m), tyres(t){
            price = p;
            model = m;
            int l = strlen(n); //checking the length of n
            name = new char[l+1];
            strcpy(name, n); //we cannot copy strings like that we need strcpy command
        }
        
        //deep copy instructor
        car (car &X):tyres(X.tyres){
            price = X.price;
            model = X.model;
            name = new char[ strlen(X.name)+1]; //cause pointer was not set
            strcpy(name,X.name);
        }
        void operator = (car &X){
            price = X.price;
            model = X.model;
            name = new char[ strlen(X.name)+1]; //cause pointer was not set
            strcpy(name,X.name);
        }
        void setName( char *n){
            if (name == NULL){
                name = new char[strlen(n)+1];
                strcpy(name,n);
            }
            else{
                delete name; //deleting the dynamically allocated pointer from the heap memory
                name = new char[strlen(n)+1]; 
                strcpy(name,n);
            }
        }
        void start() const{
            cout<<"Start the bloody "<<name<<endl;
        }
        void setprice ( int k ){
            if ( k <= 0){
                price = -k;
            }
            else{
                price = k; //price is already defined as int
            }
        }

        int getprice(){
            return price;
        }
        void print(){
            cout<<name<<endl;
            cout<<model<<endl;
            cout<<price<<"\n";
        }
        ~car(){
            cout<<endl<<"destroying"<<name<<endl;
        }

}; 

int main(){
    // car A;
    // //A.price = 1000;
    // A.setprice(-100);
    // A.model = 123;
    // //A.name[3] = '\0';
    // //cout<<A.name<<", "<<endl;
    // A.setName("Nano");
    // //cout<<A.getprice()<<endl;
    // A.setName("Xolo");
    // A.print();


    car B(1,100,"Ferrari");
    // 
    // C.name[0] = 'S';   
    car C(2,200,"Audi");
    C = B;
    B.name[0] = 'D';
    B.print();
    cout<<endl;
    C.print();
    // C.print();
    // cout<<endl<<"This is B"<<endl;

    // car B(1200, 11 ,"Porche");
    // B.print();
    // cout<<endl;
    // cout<<endl;

    // car C(B); //copy constructor is there by default no need to create it
    // // car C(1000,99, "Toyota"); //cannot be declared twice
    // C.setprice(499);
    // C.print();

    // cout<<sizeof(car)<<endl;
    // cout<<sizeof(A)<<endl;
    return 0;

}