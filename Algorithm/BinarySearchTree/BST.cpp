#include<iostream>
#include<string>
#include<queue>

using namespace std;

class BST;
class TreeNode{
    private:
    TreeNode *leftchild; 
    TreeNode *rightchild;
    TreeNode *parent;
    int key;
    public:
    TreeNode():leftchild(0),rightchild(0),parent(0),key(0){};
    TreeNode(int a):leftchild(0),rightchild(0),parent(0),key(a){};
    int getkey() {return key;}

    friend class BST;
};

class BST{
    private:
    TreeNode *root;

    public:
    BST():root(0){};
    void Insertion(int Key);
    void Deletion(int key);
    TreeNode* Search(int key);
    TreeNode* MINIMUN(TreeNode *current);
    TreeNode* MAXIMUM(TreeNode *current);
    TreeNode* Successor(TreeNode *current);
    TreeNode* Predecessor(TreeNode *current);
    void Levelorder(); 
    
};


int main(){   // test data ,  can change it
    BST T;
    T.Insertion(15);
    T.Insertion(18);
    T.Insertion(6);
    T.Insertion(20);
    T.Insertion(17);
    T.Insertion(3);
    T.Insertion(7);
    T.Insertion(13);
    T.Insertion(9);
    T.Insertion(2);
    T.Insertion(4);
    T.Insertion(14);
    T.Insertion(19);

    cout << "Level-order Traversal:\n";  // print in level order
    T.Levelorder();
    cout << endl;

    T.Deletion(14);
    T.Deletion(19);

    cout << "Level-order Traversal:\n";
    T.Levelorder();
    cout <<endl;

    TreeNode *node = T.MAXIMUM(T.Search(15));
    cout<<"Maxiumum for the key '15' : ";
    cout<<node->getkey()<<endl;

    node = T.MINIMUN(T.Search(15));
    cout<<"Miniumum for the key '15' : ";
    cout << node->getkey()<<endl;

    node = T.Successor(T.Search(15));
    cout<<"the successor for the key '15' : ";
    cout << node->getkey()<<endl;

    node = T.Predecessor(T.Search(15));
    cout<<"the predecessor for the key '15' : ";
    cout << node->getkey()<<endl;

    return 0;
}

void BST::Insertion(int Key){

    TreeNode *y = 0 ;        
    TreeNode *x = 0 ;        
    TreeNode *z = new TreeNode(Key);   // new one insert node

    y = NULL;
    x = root;
    while (x != NULL) {                     
        y = x;                          
        if (z->key < x->key){  //  determine whether x should go left or right
            x = x->leftchild;
        }
        else{
            x = x->rightchild;
        }
    }                                  
                                        // set the y to be the parent of insertnode
    z->parent = y;            

    if (y == NULL){                     // let insert node in BST
        this->root = z;
    }
    else if (z->key < y->key){
        y->leftchild = z;
    }
    else{
        y->rightchild = z;
    }
}

void BST::Deletion(int key){
    TreeNode *z = Search(key);    // make sure the BST whethe it has the key node at first
    if (z == NULL) {
        cout << "data not found.\n";
        return;
    }
    TreeNode *y = 0;        
    TreeNode *x = 0;        

    if(z->leftchild == NULL || z->rightchild == NULL){ // three cases in Deletion
        y = z;
    }
    else{
         y = Successor(z);
    }
    if(y->leftchild != NULL){
        x = y->leftchild;
    }
    else{
        x = y->rightchild;
    }
    if(x != NULL){
        x->parent = y->parent;
    }
    if(y->parent == NULL){
        this->root = x;
    }
    else if(y == y->parent->leftchild){
        y->parent->leftchild = x;
    }
   else{
       y->parent->rightchild = x;
   }
   if(y != z){
       z->key = y->key;
   }
}

TreeNode* BST::Successor(TreeNode *current){

    if (current->rightchild != NULL){
        return MINIMUN(current->rightchild);
    }
    
    TreeNode *successor = current->parent;
    
    while (successor != NULL && current == successor->rightchild) {
        current = successor;
        successor = successor->parent;
    }
    
    return successor;
}

TreeNode* BST::Predecessor(TreeNode *current){
    if (current->leftchild != NULL){
        return MAXIMUM(current->leftchild);
    }

    TreeNode *predecessor = current->parent;

    while (predecessor != NULL && current == predecessor->leftchild) {
        current = predecessor;
        predecessor = predecessor->parent;
    }

    return predecessor;
}

TreeNode* BST::MINIMUN(TreeNode *current){
    
    while (current->leftchild != NULL){
        current = current->leftchild; // point ot leftchild in while roop
    }
    return current;
}

TreeNode* BST::MAXIMUM(TreeNode *current){
    
    while (current->rightchild != NULL){
        current = current->rightchild; // point to rightchild in while loop
    }
    return current;
}

TreeNode* BST::Search(int Key){

    TreeNode *current = root;               // curent point to the root
         
    while (current != NULL && Key != current->key) {  // break the while loop when we can't fint it or find the key
    	                                              
        if (Key < current->key){                      
            current = current->leftchild;   // point to leftchild
        }
        else {
            current = current->rightchild;  // point to rightchild
        }
    }
    return current;
}

void BST::Levelorder(){ // print in level order fun.
    
    std::queue<TreeNode*> q;
    q.push(this->root);					   
    								        
    while (!q.empty()){                    

    	TreeNode *current = q.front();      
    	q.pop();                          
    	cout <<  "(" << current->key << ")" << " ";   

    	if (current->leftchild != NULL){    
            q.push(current->leftchild);
        }
        if (current->rightchild != NULL){   
            q.push(current->rightchild);
        }
    }
}