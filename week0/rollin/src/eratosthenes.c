//eratosthenes.c
//Rollin Tschirgi
//CSC311 Systemas software
//23/Nov/2015

#include <stdio.h>
#include <stdlib.h>

//define variable Size so we don't have to type 1million every time
//program will find all primes less than SIZE
#define SIZE 1000000

int bitmap[SIZE];

//the main sieve function
void filter(){

  int i = 0;
  int j = 2;
  
  //initialize first two to 1 aka: isDivisible=true
  bitmap[0] = bitmap[1] = 1;
  
  //initialize the rest to zero
  for(i=2; i<SIZE; i++) {
  bitmap[i]=0;
  }
  
  //begin search at 2 could be in the form of a four loop
  i=2;
  while(i < SIZE){
    if(bitmap[i]==0){
      
      for(j=i+i; j<SIZE; j+=i){
        bitmap[j]=1;
      }//for
      
    }//if
    i++;
  }//while

}//filter()

int main(int argc, char** argv){
  
  filter();
  
  int i;
  for(i=0; i<SIZE; i++){
    
    if (bitmap[i] == 0){
      printf("%d is prime \n", i);
    }//if
  }//for
}//main
