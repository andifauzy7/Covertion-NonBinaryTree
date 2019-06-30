#include "nbtree_d.h"

int menu();

int main(){
    nbTree MyList;          // Pointer Head Non-Binary Tree
    bAddr MyList_Binary;    // Pointer Head Binary Tree
    bAddr MyList_BinAVL;    // Pointer Head Binary Tree AVL Mode
    MyList_Binary = MyList_BinAVL = (bAddr)malloc(sizeof(BinaryTree));
    nbCreate(&MyList);

    Insertnode(&MyList, nbSearch(MyList.root,0), "Andi");
    Insertnode(&MyList, nbSearch(MyList.root,"Andi"), "Bobby");
    Insertnode(&MyList, nbSearch(MyList.root,"Bobby"), "Endah");
    Insertnode(&MyList, nbSearch(MyList.root,"Bobby"), "Fahmi");
    Insertnode(&MyList, nbSearch(MyList.root,"Andi"), "Cindy");
    Insertnode(&MyList, nbSearch(MyList.root,"Cindy"), "Gabriel");
    Insertnode(&MyList, nbSearch(MyList.root,"Cindy"), "Hasna");
    Insertnode(&MyList, nbSearch(MyList.root,"Hasna"), "Lulu");
    Insertnode(&MyList, nbSearch(MyList.root,"Cindy"), "Jarot");
    Insertnode(&MyList, nbSearch(MyList.root,"Andi"), "Deni");
    Insertnode(&MyList, nbSearch(MyList.root,"Deni"), "Kevin");
    Insertnode(&MyList, nbSearch(MyList.root,"Kevin"), "Maman");
    Insertnode(&MyList, nbSearch(MyList.root,"Kevin"), "Nanad");

    for(;;){
        switch(menu()){
            case 1: {
                // Input Data.
                nbInput(&MyList);
                printf("\n\t"); system("pause"); system("cls");
                break;
            }
            case 2: {
                // Update Tree.
                updatetree(&MyList);
                printf("\n\t"); system("pause"); system("cls");
                break;
            }
            case 3: {
                // Delete Node.
                printf("\n\t"); system("pause"); system("cls");
                break;
            }
            case 4: {
                // Reset Tree.
                printf("\n\t"); system("pause"); system("cls");
                break;
            }
            case 5: {
                // Tampilkan Tree.
                view_traversal(MyList.root);
                MyList_Binary = Convert_nbtree(MyList.root);
                view_traversal_binary(MyList_Binary);
                printf("\n\t"); system("pause"); system("cls");
                break;
            }
            case 6:{
                system("cls"); exit(1);
            }
        }
    }

	return 0;
}

int menu(){
    int nilai;
    awal:
    printf("\n\tProgram Konversi Non Binary Tree - Binary Tree\n");
    printf("\t1A - D3 Teknik Informatika\n");
    printf("\t> Andi Fauzy Dewantara 181511007\n");
    printf("\t> Fahmi Widianto       181511012\n");
    printf("\t> Hilmy Oktoharitsa    181511015\n");
    printf("\n\t1.Input Tree");
    printf("\n\t2.Update Tree");
    printf("\n\t3.Delete Node");
    printf("\n\t4.Reset Tree");
    printf("\n\t5.Tampilkan Tree");
    printf("\n\t6.Keluar");
    printf("\n\tPilihan Anda : ");
    scanf(" %d",&nilai);
    if(nilai<=0 || nilai>6){
        system("cls");
        goto awal;
    } else {
        return nilai;
    }
}

