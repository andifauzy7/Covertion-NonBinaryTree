/*
File        : nbtree_d.cpp
Edited      : Andi Fauzy - 181511007
              Fahmi Widianto - 181511012
              Hilmy Oktoharita - 181511015
Deskripsi   : Implementasi dari NBTREE_D.H.
Kelas       : 1A / D3-T.Informatika (JTK'18)
*/
#include <malloc.h>
#include "nbtree_d.h"
#include "boolean.h"

/* Tampilan Menu */


/* Konstruktor Tree */
void nbCreate(nbTree *x){
	(*x).root=NULL;
}

nbAddr nbCNode(nbType X){
	nbAddr newNode;
	newNode=(nbAddr) malloc(sizeof(ElmtTree));
	if (newNode != NULL){
		strcpy(newNode->nama,X);
		newNode->fs=NULL;
		newNode->nb=NULL;
		newNode->parent=NULL;
	}
	return newNode;
}

bAddr Create_BTree(bAddr *First, nbType nama){
    (*First)=(bAddr)malloc(sizeof(BinaryTree));
    strcpy((*First)->info,nama);
    return (*First);
}

/* Modul Alokasi untuk sebuah Node. Terdapat Input-an spt (Nama, Usia, JK, Status) */
void Insertnode(nbTree *tRoot, nbAddr parent, nbType X){
    nbAddr newNode, temp;

    newNode=nbCNode(X);
    if (newNode !=NULL)
        {
        if (parent==NULL)
        {
            tRoot->root=newNode;
        }
        else{
            temp=parent;
            if(temp->fs !=NULL)
                {
                temp=temp->fs;
                while(temp->nb!=NULL)
                    {
                    temp=temp->nb;
                    }
                    temp->nb=newNode;
                    newNode->parent=parent;
                }
                else{
                    temp->fs=newNode;
                    newNode->parent=parent;
                    }
            }
        }
}

/* Tampil Tree Preorder, Inorder, Postorder */
void Postorder(nbAddr root){
	if (root!=NULL){
		Postorder(root->fs);
		printf(" %s.", root->nama);
		Postorder(root->nb);
	}
}

void Preorder(nbAddr root){
	if (root!=NULL){
		printf(" %s.", root->nama);
		Preorder(root->fs);
		Preorder(root->nb);
	}
}

void Inorder(nbAddr root){
	if (root!=NULL){
		Inorder(root->fs);
		if (root->fs==NULL) printf(" %s.", root->nama);
		if (root->parent !=NULL)
			if (root->parent->fs==root)
				printf(" %s.", root->parent->nama);
		Inorder(root->nb);
	}
}

void view_traversal(nbAddr root){
    printf("\n");
    printf("\tPOSTORDER : ");
    Postorder(root); printf("\n");
    printf("\tINORDER   : ");
    Inorder(root);   printf("\n");
    printf("\tPREORDER  : ");
    Preorder(root);  printf("\n");
}

/* Delete Node, diasumsikan pada silsilah keluarga statusnya menjadi meninggal */

/* Modul Pembantu */

/* Search dengan mengembalikan address Node tertentu */
nbAddr nbSearch(nbAddr root, nbType src){
	nbAddr nSrc;
	if (root!=NULL){
		if (strcmp(root->nama,src)==0)
			return root;
		else{
			nSrc=nbSearch(root->fs,src);
			if (nSrc==NULL)
				return nbSearch(root->nb,src);
			else
				return nSrc;
		}
	}
	else{
		return NULL;
	}
}

nbAddr nbSearchbefore(nbAddr root, nbAddr alamat){
	nbAddr nSrc;
	if (root!=NULL){
		if (root->nb==alamat)
			return root;
		else{
			nSrc=nbSearchbefore(root->fs,alamat);
			if (nSrc==NULL)
				return nbSearchbefore(root->nb,alamat);
			else
				return nSrc;
		}
	}
	else{
		return NULL;
	}
}


/* Cetak Tree */
void nbPrint(nbAddr node, char tab[]){
	char tempTab[255];
	strcpy(tempTab, tab);
	strcat(tempTab, "-");
	if (node!=NULL){
            printf("\t%s%s\n",tab,node->nama);
		nbPrint(node->fs,tempTab);
		nbPrint(node->nb,tab);
	}
}

/* Update Tree */

void updatetree(nbTree *root, nbTree *root2){
    nbTree memberlist;
    nbAddr change;
    nbType srcnama, newname;
    char pil;

    repeat:
    memberlist=(*root);
    nbPrint(memberlist.root, "");
    printf("\n\tNama Lengkap       : "); scanf(" %[^\n]", srcnama);
    change=nbSearch(memberlist.root, srcnama);
    if (change!=NULL)
    {
        printf("\n\tMasukan Nama Baru : ");
        scanf(" %[^\n]", newname);
        strcpy(change->nama, newname);
        printf("\n\tUpdate Sukses!!!");

        printf("\n\tApakah anda ingin Update lagi?(Y/T) :");
        scanf(" %c", &pil);
        if (pil=='Y' || pil=='y')
        {
            system("cls");
            goto repeat;
        }
        else
        {
            printf("\n\tUpdate selesai!!!");
        }
    }
    else
    {
        printf("\n\tNama Tidak Ada, Ulangi. \n\n\t");
        system("pause");
        system("cls");
        goto repeat;
    }
}

