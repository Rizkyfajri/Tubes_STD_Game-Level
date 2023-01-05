#include "Tubes.h"

void createList(listLevel &L1, listType &L2){
    first(L1) = NIL;
    first(L2) = NIL;
}

addr1 createLevel(infotype X){
    addr1 P = new elmtLevel;
    info(P) = X;
    nextL(P) = NIL;
    firstR(P) = NIL;
    return P;
}

addr2 createType(infotype X){
    addr2 P = new elmtType;
    info(P) = X;
    nextT(P) = NIL;
    return P;
}

addr3 createNewRelasi(){
    addr3 P = new elmtRelasi;
    nextR(P) = NIL;
    nextT(P) = NIL;
    return P;
}

void insertLevel(listLevel &L1, addr1 P){
    if (first(L1) != NULL){
        nextL(P) = first(L1);
        first(L1) = P;
    } else {
        first(L1) = P;
    }
}

void insertType(listType &L2,addr2 P){
    if (first(L2) != NULL){
        nextT(P) = first(L2);
        first(L2) = P;
    } else {
        first(L2) = P;
    }
}

void insertRelasi(listLevel L1, listType L2, infotype X, infotype Y){
    addr1 P = searchLevel(L1,X);
    addr2 Q = searchType(L2,Y);
    if (P != NIL && Q!=NIL){
        addr3 R = createNewRelasi();
        if (firstR(P) == NIL){
            firstR(P) = R;
            nextT(R) = Q;
        }else{
            nextR(R) = firstR(P);
            firstR(P) = R;
            nextT(R) = Q;
        }
        cout << "\nLevel berhasil di hubungkan" << endl;
    }else{
        cout << "\nGagal" << endl;
    }
}

void insertLast_Level(listLevel &L1, addr1 P){

    addr1 Q = first(L1);

    if (first(L1) != NULL){
        while(nextL(Q) != NULL){
            Q = nextL(Q);
        }
        nextL(Q) = P;
    } else{
        insertLevel(L1,P);
    }
}

void insertType_Last(listType &L2, addr2 P){

    addr2 Q = first(L2);

    if (first(L2) != NULL){
        while(nextT(Q) != NULL){
            Q = nextT(Q);
        }
        nextT(Q) = P;
    }else{
        insertType(L2,P);
    }
}

void deleteLevel(listLevel &L1){
    if (first(L1) != NULL){
        addr1 P = first(L1);
        while(nextL(nextL(P)) != NULL){
            P = nextL(P);
        }
        nextL(P) = NULL;
    }else{
        cout<<"List kosong"<<endl;
    }
}

void deleteType(listLevel L1, listType &L2){
    addr2 P = first(L2);
    addr1 Q = first(L1);
    addr3 R;

    while (Q != NIL){
        R = firstR(Q);
            while (R != NIL){
                if (nextT(R) == P){
                    nextT(R) = NIL;
                }
                R = nextR(R);
            }
        Q = nextL(Q);
    }

    if (first(L2) != NULL){
        if(nextT(first(L2)) == NULL){
            first(L2) = NULL;
        }else{
            first(L2) = nextT(first(L2));
            nextT(P) = NULL;
        }
    }
    else{
        cout<<"List kosong"<<endl;
    }
}

void printLevel(listLevel L1){
    addr1 P = first(L1);
    int i = 1;
    if (first(L1) != NIL){
        while (P != NIL){
            cout << i << ". " << info(P) << endl;
            P = nextL(P);
            i++;
        }
    }else{
        cout << "List kosong" << endl;
    }
}

void printType(listType L2){
    addr2 P = first(L2);
    int i = 1;
    if (first(L2) != NIL){
        while (P != NIL){
            cout << i << ". " << info(P) << endl;
            P = nextT(P);
            i++;
        }
    }else{
        cout << "List kosong" << endl;
    }
}

void printRelasi(listLevel L1, listType L2){
    addr1 P;
    addr2 Q = first(L2);
    addr3 R;


    while (Q!= NIL){
        cout << "\nAttribut " << info(Q) << " dimiliki oleh level : " << endl;
        P = first(L1);
        while (P != NIL){
            R = firstR(P);
                while (R != NIL){
                    if (nextT(R) == Q){
                        cout << info(P) << endl;
                    }
                    R = nextR(R);
                }
            P = nextL(P);
        }
        Q = nextT(Q);
    }
}

void findLevel(listLevel L1, listType L2, infotype X){
    addr1 P;
    addr2 Q = searchType(L2,X);
    addr3 R;

    if (Q != NIL){
        cout << "\nType " << info(Q) << " dimiliki oleh level : " << endl;
        P = first(L1);
        while (P != NIL){
            R = firstR(P);
                while (R != NIL){
                    if (nextT(R) == Q){
                        cout << info(P) << endl;
                    }
                    R = nextR(R);
                }
            P = nextL(P);
        }
    }else{
        cout << "\ntidak ada" << endl;
    }
}

addr1 searchLevel(listLevel L1, infotype X){
    addr1 P = first(L1);
    while (P != NIL){
        if (info(P) == X){
            return P;
            break;
        }else{
            P = nextL(P);
        }
    }
    if (P == NIL){
        return P;
    }
}

addr2 searchType(listType L2, infotype X){
    addr2 P = first(L2);
    while (P != NIL){
        if (info(P) == X){
            return P;
            break;
        }else{
            P = nextT(P);
        }
    }
    if (P == NIL){
        return P;
    }
}

void menuUtama(){
    cout << "Silakan pilih menu yang ingin Anda lakukan : " << endl;
    cout << "1. Print Level" << endl;
    cout << "2. Print Attribut level" << endl;
    cout << "3. Print level dengan typenya" << endl;
    cout << "4. Cari Type" << endl;
    cout << "5. Insert First Level" << endl;
    cout << "6. Insert First Type" << endl;
    cout << "7. Insert Last Level" << endl;
    cout << "8. Insert Last Type" << endl;
    cout << "9. Insert relasi antanra type dan level" << endl;
    cout << "10. Delete Last level" << endl;
    cout << "11. Delete First Type" << endl;
    cout << "12. Search Level" << endl;
    cout << "13. Search Attribute type" << endl;
    cout << "0 . Keluar" << endl;
    cout << "\nPilihan Anda : ";
}

void menuPilihan(int pil, listLevel &L1, listType &L2){
    infotype namaLevel, namaType;
    addr1 P;
    addr2 Q;
    switch(pil){
        case 1 : printLevel(L1);
                 break;
        case 2 : printType(L2);
                 break;
        case 3 : printRelasi(L1,L2);
                 break;
        case 4 : cout << "\nCari Type  : ";
                 cin >> namaLevel;
                 findLevel(L1,L2,namaLevel);
                 break;
        case 5 : cout << "\ninput level first : ";
                 cin >> namaLevel;
                 P = createLevel(namaLevel);
                 insertLevel(L1,P);
                 break;
        case 6 : cout << "\ninput type first : ";
                 cin >> namaType;
                 Q = createType(namaType);
                 insertType(L2,Q);
                 break;
        case 7 : cout << "\ninput level last : ";
                 cin >> namaLevel;
                 P = createLevel(namaLevel);
                 insertLast_Level(L1,P);
                 break;
        case 8 : cout << "\ninput type last : ";
                 cin >> namaType;
                 Q = createType(namaType);
                 insertType_Last(L2,Q);
                 break;
        case 9 : cout << "Input Nama Level dan Type yang mau dipasangkan : " << endl;
                 cout << "Nama Level : ";
                 cin >> namaLevel;
                 cout << "Jenis Type : ";
                 cin >> namaType;
                 insertRelasi(L1,L2,namaLevel,namaType);
                 break;
        case 10 : deleteLevel(L1);
                  break;
        case 11 : deleteType(L1,L2);
                  break;
        case 12 : cout << "Input Nama Level : ";
                  cin >> namaLevel;
                  P = searchLevel(L1,namaLevel);
                  if (P != NIL){
                    cout << "Level " << namaLevel << " ditemukan" << endl;
                  }else{
                    cout << "Not found" << endl;
                  }
                  break;
        case 13 : cout << "Input Type : ";
                  cin >> namaType;
                  Q = searchType(L2,namaType);
                  if (Q != NIL){
                    cout << "Type " << namaType << " ditemukan" << endl;
                  }else{
                    cout << "Not found" << endl;
                  }
                  break;
        case 0 : break;
        default : cout << "Tolong masukkan angka yang valid! " << endl;
                  break;
    }
}


