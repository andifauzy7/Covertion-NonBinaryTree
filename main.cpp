#include "nbtree_d.h"

int main(){
    nbType nama;
    nbTree MyList;

    nbCreate(&MyList);

    Insertnode(&MyList, nbSearch(MyList.root,0), "Alfonso 12", 'L', 162, 0, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Alfonso 12"),"Maria de las Mercedes", 'W', 139, 0, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Maria de las Mercedes"),"Infante Alfonso", 'L', 118, 0, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infante Alfonso"),"Infante Carlos Calabria", 'L', 71, 0, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Alfonso 12"),"Alfonso 13", 'L', 133, 0, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Alfonso 13"),"Infante Juan", 'L', 106, 0, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infante Juan"),"Infanta Pilar", 'W', 82, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infanta Pilar"),"Dona Simoneta", 'W', 50, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infanta Pilar"),"La Torre", 'L', 49, 1,0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infanta Pilar"),"Don Bruno", 'L', 48, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infanta Pilar"),"Don Luis", 'L', 46, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infanta Pilar"),"Don Fernando", 'L', 45, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infante Juan"),"Juan Carlos 1", 'L', 81, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Juan Carlos 1"),"Infanta Elena", 'W', 55, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infanta Elena"),"Felipe de Marichalar", 'L', 20, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infanta Elena"),"Victoria de Marichalar", 'W', 18, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Juan Carlos 1"),"Infanta Cristina", 'W', 53, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infanta Cristina"),"Juan Urdangarin", 'L', 19, 1,0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infanta Cristina"),"Don Pablo", 'L', 18, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infanta Cristina"),"Don Miguel", 'L', 17, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infanta Cristina"),"Dona Irene", 'W', 14, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Juan Carlos 1"),"Felipe 6", 'L', 51, 1, 1);
    Insertnode(&MyList, nbSearch(MyList.root,"Felipe 6"),"Leonor Princess Asturias", 'W', 14, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Felipe 6"),"Infanta Sofia", 'W', 12, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infante Juan"),"Infanta Margarita", 'W', 80, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infanta Margarita"),"Alfonso Zurita", 'L', 46, 1, 0);
    Insertnode(&MyList, nbSearch(MyList.root,"Infanta Margarita"),"Maria Zurita", 'W', 43, 1, 0);

	return 0;
}
