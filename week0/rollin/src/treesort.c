
// treesort.c
// Rollin Tschirgi
// CSC311 Systems Software
// 23 November 2015

#include <stdio.h>
#include <stdlib.h>

// define a node in a binary search tree
struct node{
    int value;
    struct node* lp;
    struct node* rp;
};//node

// define aliases
deftype struct node Node;
deftype struct node* NodePtr;
// define a function that will create
// a new tree that contains only a single
// node
NodePtr createRoot(int n){
    NodePtr np = (NodePtr)malloc(sizeof(Node));
    np->value = n;
    np->lp = NULL;
    np->rp = NULL;
    return np;
}//createroot

// define a function that will add a new
// node to an existing binary search tree
NodePtr addNode(NodePtr np, int n){
    NodePtr rp = np;
    
    if(np==NULL){rp = createRoot(n);}
    else if(n < np->value){
       
        if(np->lp == NULL){np->lp = createRoot(n);}
        else{np->lp = addNode(np->lp, n);}
    }
    else if(n > np->value){
       
        if(np->rp==NULL){np->rp = createRoot(n);}
        else{np->rp = addNode(np->rp, n);}
    }
    // if value to be added is already in tree, do nothing
    // (do not add duplicate values to tree)
    else{}
}//addnode


// traverse a binary search tree
// in order, printing the values
// found at each node
void printNodes(NodePtr np){
    if(np != NULL){
        printNodes(np->lp);
        printf("value at node = %4d \n", np->value);
        printNodes(np->rp);
    }
}


int main( int argc, char** argv ) {

  // build a binary search tree that
  // contains integers found on the command line,
  // then print the integers in ascending order

  printf( "Hello from treesort!\n" );

  exit(0);
} // main( int, char** )
