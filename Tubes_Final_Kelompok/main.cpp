#include "Tubes.h"

int main()
{
    listLevel L1;
    listType L2;
    addr1 P;
    addr2 Q;
    int pil;

    createList(L1,L2);

    do{
        menuUtama();
        cin >> pil;
        menuPilihan(pil,L1,L2);
        system("PAUSE");
        system("CLS");
    }while(pil != 0);
}
