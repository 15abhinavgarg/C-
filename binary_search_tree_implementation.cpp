#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node * left;
        node * right;

        node( int d ){
            data = d;
            left = NULL; 
            right = NULL;
        }
};

node* insertBST(node * root , int k){

    if ( root == NULL){
        return new node(k);
    }

    if ( k <= root->data){
        root->left = insertBST(root->left, k);
    }
    else{
        root->right = insertBST(root->right, k);
    }
    return root;
}

node * build(){

    int data;
    cin>>data;
    
    node * root = NULL;
    
    while (data != -1){
        root = insertBST(root,data);
        cin>>data;
    }
    return root;
}
int height(node* root){
    if ( root == NULL){
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls,rs)+1;
}

void printKlevel( node * root, int k){
    if ( root == NULL){
        return;
    }
    if ( k == 1){
        cout<<root->data<<" ";
        return;
    }
    printKlevel(root->left, k-1);
    printKlevel(root->right, k-1);
    return;
}

void printAllLevel( node * root){
    int h = height(root);
    for ( int i = 1 ;  i <= h ; i++ ){
        printKlevel(root,i);
        cout<<endl;
    }
}

// void bfs( node * root){
//     cout<<"In bfs"<<endl;
//     queue<node *> q;
//     q.push(root);
//     q.push(NULL);

//     while( !q.empty()){
//         node * f = q.front();
//         if ( f == NULL){
//             cout<<endl;
//             q.pop();

//             if ( !q.empty()){
//                 q.push(NULL);
//             }
//         }
//         else{
//             cout<<f->data<<" ";
//             q.pop();
//             if (f->left){
//                 q.push(root->left);
//             }
//             if ( f->right){
//                 q.push(root->right);
//             }
//         }
        
//     }
//     return;
// }

void bfs ( node* root){
    queue<node *>  q;

    q.push(root);
    q.push(NULL);
    while (!q.empty()){
        node*f = q.front();
        if ( f == NULL){
            cout<<endl;
            q.pop();
            if (!q.empty()){
                q.push(NULL);
            }
            //cout<<endl;
        }
        else{
            cout<<f->data<<" ";
            q.pop();

            if(f->left){
                q.push(f->left);
            }
            if (f->right){
                q.push(f->right);
            }
            //cout<<endl;
        }
    }
    return ;
}

void inorder( node * root){
    if ( root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
    // cout<<root->data;
    return;
}

bool search( node * root, int target){
    if ( root == NULL){
        return false;
    }
    else if ( target == root->data){
        return true;
    }
    else if (target > root->data){
        return search(root->right,target);
    }
    else {
        return search(root->left,target);
    }
}

node * deleteinBST( node* root, int data){
    if ( root == NULL){
        return NULL;
    }

    else if ( data < root->data){
        root->left = deleteinBST(root->left,data);
        return root;  //cause I want the root of the tree
    }

    else if ( root->data == data) {
        //this is the first case with no child and leaf node
        if ( root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // second case when root has one child
        if ( root->left != NULL && root->right == NULL){
            node * temp = root->left;
            delete root;
            return temp;
        }
        if ( root->right != NULL && root->left == NULL){
            node * temp = root->right;
            delete root;
            return temp;
        }

        node * replace = root->right;
        
        while ( replace->left != NULL){
            replace = replace->left;
        }

        root->data = replace->data;
        root->right = deleteinBST(root->right,replace->data);
        return root;

    }

    else {
        root->right = deleteinBST(root->right,data);
        return root;
    }
}
int main(){
    node * root = build();
    printAllLevel(root);
    cout<<endl;

    inorder(root);

    // if (search(root,4)){
    //     cout<<"Found the element"<<endl;
    // }
    // else { cout<<"Not found";  }
    int s; cin>>s;
    
    root = deleteinBST(root,s);
    bfs(root);
    
    return 0;
}