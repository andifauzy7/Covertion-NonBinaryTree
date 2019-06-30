/*
File        : nbtree_d.h
Edited      : Andi Fauzy - 181511007
              Fahmi Widianto - 181511012
              Hilmy Oktoharita - 181511015
Deskripsi   : Deklarasi Modul dan Kamus data.
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

/* Struct Non - Binary Tree */

typedef struct nbTreeNode{
	nbType nama;
	nbAddr fs, nb, parent;
}ElmtTree;

struct nbTree{
	nbAddr root;
};

/* Struct Binary Tree */

typedef struct TreeNode *bAddr;
typedef struct TreeNode{
	bAddr left,right;
	nbType info;
}BinaryTree;

typedef struct TreeNodeAVL *Addr;
typedef struct TreeNodeAVL{
	Addr left,right;
	nbType info;
	int height;
}BinaryTreeAVL;

/* Konstruktor Tree */

void nbCreate(nbTree *x);
nbAddr nbCNode(nbType X);
void create_nodebinary(Addr *root);
bAddr Convert_nbtree(nbAddr root, Addr *avl_root);

/* Modul Alokasi untuk sebuah Node. */
void Insertnode(nbTree *tRoot, nbAddr parent, nbType X);
bAddr insert_btree(bAddr First, nbAddr nonbinary);

/* Tampil Tree Preorder, Inorder, Postorder */

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

/* Untuk AVL Binary Tree */

void AVL_postorder(Addr root);
void AVL_preorder(Addr root);
void AVL_inorder(Addr root);
void view_traversal_AVL(Addr root);

/* Delete Node */


/* Search dengan mengembalikan address Node tertentu */
nbAddr nbSearch(nbAddr root, nbType src);
nbAddr nbSearchbefore(nbAddr root, nbAddr alamat);
bAddr bSearch(bAddr root, nbType src);

/* Cetak Tree */
void nbPrint(nbAddr node, char tab[]);
void list_parent(nbAddr root);

/*Input Data */
void nbInput (nbTree *tRoot);
void updatetree(nbTree *root);

/* Modul Pembantu Untuk AVL Tree */

int bDepth(bAddr root);

int AVLDepth(Addr root);

int max(int a, int b);

Addr build_node(nbType value);

int height_node(Addr root);

Addr rotasi_kanan(Addr y);

Addr rotasi_kiri(Addr x);

int get_different(Addr N);

Addr input_nodeAVL(Addr node, nbType value);


#endif
