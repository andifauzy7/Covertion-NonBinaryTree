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
bAddr Convert_nbtree(nbAddr root);

/* Modul Alokasi untuk sebuah Node. Terdapat Input-an spt (Nama, Usia, JK, Status)
By : Fahmi Widianto */
void Insertnode(nbTree *tRoot, nbAddr parent, nbType X);
void inputmember(nbTree *root);
bAddr insert_btree(bAddr First, nbAddr nonbinary);

/* Tampil Tree Preorder, Inorder, Postorder
By : Both */

/* Untuk Non - Binary Tree */
void Postorder(nbAddr root);
void Preorder(nbAddr root);
void Inorder(nbAddr root);
void view_traversal(nbAddr root);

/* Untuk Binary Tree */
void Post_binary(bAddr root);
void Pre_binary(bAddr root);
void In_binary(bAddr root);
void view_traversal_binary(bAddr root);

/* Delete Node, diasumsikan pada silsilah keluarga statusnya menjadi meninggal
By : Andi Fauzy D */


/* Modul Pembantu */

/* Search dengan mengembalikan address Node tertentu
By : Andi Fauzy D */
nbAddr nbSearch(nbAddr root, nbType src);
nbAddr nbSearchbefore(nbAddr root, nbAddr alamat);
bAddr bSearch(bAddr root, nbType src);

/* Cetak Tree
By : Both */
void nbPrint(nbAddr node, char tab[]);


#endif
