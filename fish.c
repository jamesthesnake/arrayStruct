#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define STRINGLENGTH 128
typedef char  String[STRINGLENGTH];

//animal name 
typedef  enum  {
     mammal,
    fish,
     bird, 
     insect,
     error
  } species;
typedef struct {
  double weight;
  String  name;
  species animalSpecies;
} newAni;
//typedef newAni *animalArray;
void * Malloc(size_t Size) {

  void * Memory;

  if ((Memory = malloc(Size)) == NULL) {
    perror("Cannot malloc");
    exit(EXIT_FAILURE);
  } else {
    return(Memory);
  }
}
char* StringSpeciesType(species Pet) {

  switch (Pet) {
  case mammal:
    return("mammal");
    break;
  case fish:
    return("fish");
    break;
  case bird:
    return("bird");
    break;
  case insect:
    return("insect");
    break;
  default:
    return("error");
    break;
  }
}
species InputSpeciesType(void) {

  String Pet;

  scanf("%s",Pet);
  if (!strcmp(Pet,"mammal")) {
    return(mammal);
  }
  if (!strcmp(Pet,"fish")) {
    return(fish);
  }
  if (!strcmp(Pet,"bird")) {
    return(bird);
  }
  if (!strcmp(Pet,"insect")) {
    return(insect);
  }
  return(error);
}
int  main(void){
    int i=1;   
    newAni*  animalArray= malloc(i);
    int j=0;
    while(strcmp(animalArray[i-1].name,"Exit")){
printf("Enter  animal information:  \n");
printf(" what is the name :  ");
 scanf("%s",animalArray[i-1].name);
 if(!strcmp(animalArray[i-1].name,"Exit")){
   printf("exiting");
   break;
 }
 printf("what is the type : ");
 //scanf("%s",animalArray[i-1].animalSpecies);
 animalArray[i-1].animalSpecies=InputSpeciesType();
 
printf("what is the weight :");
scanf("%lf", &animalArray[i-1].weight);
 
 animalArray=realloc(animalArray,sizeof(animalArray)*2);
 
 i=i+1;
 j=j+1;
    }
    for(i=0;i<j;i++){
printf("the following new speices were found : \n");
 printf("%s  has a size %.2f and is a %s \n",animalArray[i].name,animalArray[i].weight,StringSpeciesType(animalArray[i].animalSpecies));    }
    return(EXIT_SUCCESS);
  }
