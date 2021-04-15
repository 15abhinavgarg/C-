#include<iostream>
#include<string>
using namespace std;

template<typename T> // this allows us to initiate any kind of datatype in value
class Node{
    public:
        string key ; 
        T value ;
        Node<T> *next;
        
        Node( string key , T val){  //this particular node will store the value but its location would be determined by hash fn
            this->key = key;
            value = val;
            next = NULL;
        }
        ~Node(){  //this is a destrutor
            if ( next != NULL){
                delete next;
            }
        }
};

template<typename T>
class HashTable{
    Node<T> ** table; // pointer to the array of pointers 
    int current_size;
    int table_size;

    int hashFn ( string key){ // private because we dont want to access through
        int idx = 0; //this is what we will return
        int p = 1;
        for ( int j = 0 ; j < key.length() ; j++ ){
            idx = idx + (key[j]*p)%table_size;
            idx = idx%table_size;
            p = (p*27)%table_size;
        }
        return idx;
    }
    public:
        HashTable( int ts = 7){        
            table_size = ts;
            table = new Node<T>*[table_size]; //each container can contain datatype of Node
            current_size = 0;

            for ( int i = 0 ; i < table_size ; i++){
                table[i] = NULL; // assigning the every box to NULL overwriting a garbage value
            }
        } 

        void rehash(){
            Node<T>**oldTable = table;
            int oldtable_Size = table_size;

            table_size = table_size*2;
            table = new Node<T>*[table_size];
            //Assigning all the values to null
            for ( int i= 0 ; i < table_size ; i++){
                table[i] = NULL;
            }
            current_size = 0;
            //shifting elements from old table to new one
            for ( int i = 0 ; i < oldtable_Size ;i++){
                Node<T> *temp = oldTable[i];
                while( temp != NULL){
                    insert(temp->key, temp->value);
                    temp = temp->next;
                }
                if (oldTable[i] != NULL){
                    delete oldTable[i];
                }
            }
            delete [] oldTable;
            //deleting the previous assigned table
        }

        void insert ( string key, T value){
            //calling hash function
            int idx = hashFn( key );
            Node<T>*n = new Node<T>(key, value);  //creating a new node 
            
            n->next = table[idx];   
            table[idx] = n; //inserting at head

            current_size++;

            float load_factor = current_size/(1.0*table_size);
            if ( load_factor > 0.75){
                //rehashing required
                rehash();
            }

        }

        void print(){
            for ( int i = 0 ; i < table_size ; i++){
                cout<<""<<i<<"= ";
                Node<T>*temp = table[i]; //declaring a pointer which will point to Node<T>

                while ( temp != NULL){
                    cout<<"["<<temp->key<<" : "<<temp->value<<"] , ";
                    temp = temp->next;
                }
                cout<<endl;
            }
        }

        // T search ( string key){
        //     //returning the value
            
        // }

        // void erase ( string key){
        //     //to remove particular argument
        // }
};

int main(){

    HashTable<int> menu;
    
    
    menu.insert("Coke",112);
    menu.insert("Broke",100);
    menu.insert("Burger",50);
    menu.insert("Pizza",60);
    menu.insert("Jira",2);
    menu.insert("Fiddle",80);
    menu.insert("Brownie",90);
    menu.print();
    

    return 0;
}