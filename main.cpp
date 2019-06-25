#include "nbtree_d.h"

int main(){
    nbType nama;
    nbTree MyList;


    nbCreate(&MyList);
    nbInput(&MyList);


    nbPrint(MyList.root," ");
    view_traversal(MyList.root);

	return 0;
}
