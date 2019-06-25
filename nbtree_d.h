/*
File        : nbtree_d.h
Edited      : Andi Fauzy - 181511007
              Fahmi Widianto - 181511012
Deskripsi   : Program silsilah keluarga kerajaan (Asumsi serupa dengan kerajaan Spanyol).
Kelas       : 1A / D3-T.Informatika (JTK'18)
*/

#ifndef nbtree_d_H
#define nbtree_d_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"

typedef struct nbTreeNode *nbAddr;
typedef char nbType[30];

typedef struct nbTreeNode{
	nbType nama;
	nbAddr fs, nb, parent;
}ElmtTree;

struct nbTree{
	nbAddr root;
};

/* Ini Struct Binary Tree */

typedef struct TreeNode *bAddr;
typedef struct TreeNode{
	bAddr left,right;
	nbType info;
}BinaryTree;


/* Konstruktor Tree
By : Fahmi Widianto */

void nbCreate(nbTree *x);
nbAddr nbCNode(nbType X);
bAddr Create_BTree(bAddr *First, nbType nama);

/* Modul Alokasi untuk sebuah Node. Terdapat Input-an spt (Nama, Usia, JK, Status)
By : Fahmi Widianto */
void Insertnode(nbTree *tRoot, nbAddr parent, nbType X);
void inputmember(nbTree *root);

/* Tampil Tree Preorder, Inorder, Postorder
By : Both */
void Postorder(nbAddr root);
void Preorder(nbAddr root);
void Inorder(nbAddr root);
void view_traversal(nbAddr root);

/* Delete Node, diasumsikan pada silsilah keluarga statusnya menjadi meninggal
By : Andi Fauzy D */


/* Modul Pembantu */

/* Search dengan mengembalikan address Node tertentu
By : Andi Fauzy D */
nbAddr nbSearch(nbAddr root, nbType src);
nbAddr nbSearchbefore(nbAddr root, nbAddr alamat);

/* Cetak Tree
By : Both */
void nbPrint(nbAddr node, char tab[]);


#endif
