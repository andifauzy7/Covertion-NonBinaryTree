#include "nbtree_d.h"

int main(){
    nbType nama;
    nbTree MyList;
    address Awal=NULL;

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

    nbPrint(MyList.root," ");
    view_traversal(MyList.root);

    printf("\n");
    bAddr First=Convert_nbtree(MyList.root);

	return 0;
}
