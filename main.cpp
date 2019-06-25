#include "nbtree_d.h"

int main(){
    nbType nama;
    nbTree MyList;

    nbCreate(&MyList);

    Insertnode(&MyList, nbSearch(MyList.root,0), "Alfonso 12");
    printf("%s",MyList.root->nama);

	return 0;
}
