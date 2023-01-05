#ifndef INST_COURSE_H_INCLUDED
#define INST_COURSE_H_INCLUDED

#include <iostream>
#include <stdlib.h>

#define info(P) P->info
#define first(L) L.first
#define nextT(P) P->nextT
#define nextL(P) P->nextL
#define nextR(P) P->nextR
#define firstR(P) P->firstR
#define NIL NULL

using namespace std;

typedef string infotype;
typedef struct elmtLevel *addr1;
typedef struct elmtType *addr2;
typedef struct elmtRelasi *addr3;

struct elmtLevel{
    infotype info;
    addr1 nextL;
    addr3 firstR;
};
struct elmtType{
    infotype info;
    addr2 nextT;
};
struct elmtRelasi{
    addr2 nextT;
    addr3 nextR;
};
struct listLevel{
    addr1 first;
};
struct listType{
    addr2 first;
};



void createList(listLevel &L1, listType &L2);
addr1 createLevel(infotype X);
addr2 createType(infotype X);
addr3 createNewRelasi();
void insertLevel(listLevel &L1,addr1 P);
void insertType(listType &L2,addr2 P);
void insertRelasi(listLevel L1, listType L2, infotype X, infotype Y);
void insertLevel_Last(listLevel &L1, addr1 P);
void insertType_Last(listType &L2, addr2 P);
void deleteLevel(listLevel &L1);
void deleteType(listLevel, listType &L2);
void printLevel(listLevel L1);
void printType(listType L2);
void printRelasi(listLevel L1, listType L2);
void findLevel(listLevel L1, listType L2, infotype X);
addr1 searchLevel(listLevel L1, infotype X);
addr2 searchType(listType L2, infotype X);

void menuUtama();
void menuPilihan(int pil, listLevel &L1, listType &L2);

#endif // INST_COURSE_H_INCLUDED
