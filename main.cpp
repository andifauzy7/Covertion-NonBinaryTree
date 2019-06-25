#include "nbtree_d.h"

int main(){
    nbType nama;
    nbTree MyList;

    nbCreate(&MyList);

    Insertnode(&MyList, nbSearch(MyList.root,0), "Hilmy Okto");
    Insertnode(&MyList, nbSearch(MyList.root,"Hilmy Okto"), "Adhitya Febhiabar");
    Insertnode(&MyList, nbSearch(MyList.root,"Hilmy Okto"), "Ameliana Harahap");
    Insertnode(&MyList, nbSearch(MyList.root,"Hilmy Okto"), "Salma Meldiana");

    nbPrint(MyList.root," ");
    view_traversal(MyList.root);

	return 0;
}
