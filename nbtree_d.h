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

typedef struct TreeNode *Addr;
typedef struct TreeNode{
	Addr left,right;
	nbType info;
	int height;
}BinaryTree;

/* Konstruktor Tree */

void nbCreate(nbTree *x);
nbAddr nbCNode(nbType X);
Addr Convert_nbtree(nbAddr root, Addr *avl_root);

/* Modul Alokasi untuk sebuah Node. */
void Insertnode(nbTree *tRoot, nbAddr parent, nbType X);
Addr insert_btree(Addr First, nbAddr nonbinary);

/* Kedalaman */
int bDepth(Addr root);

/* Tampil Tree Preorder, Inorder, Postorder */

/* Untuk Non - Binary Tree */
void Postorder(nbAddr root);
void Preorder(nbAddr root);
void Inorder(nbAddr root);
void view_traversal(nbAddr root);

/* Untuk AVL Binary Tree */

void Binary_post(Addr root);
void Binary_pre(Addr root);
void Binary_in(Addr root);
void view_traversal_binary(Addr root);

/* Delete Node */
void resetTree(nbTree *tRoot);
nbAddr delete_node(nbAddr root, nbType value);
bool isLeaf(nbAddr root);
nbAddr delete_leaf(nbAddr root, nbAddr value);
nbAddr delete_stem(nbAddr root, nbAddr value);

/* Search dengan mengembalikan address Node tertentu */
nbAddr nbSearch(nbAddr root, nbType src);
nbAddr nbSearchbefore(nbAddr root, nbAddr alamat);
Addr bSearch(Addr root, nbType src);

/* Cetak Tree */
void nbPrint(nbAddr node, char tab[]);
void list_parent(nbAddr root);

/*Input Data */
void nbInput (nbTree *tRoot);
void updatetree(nbTree *root);

/* Modul Pembantu Untuk AVL Tree */
int max(int a, int b);
Addr build_node(nbType value);
int height_node(Addr root);
Addr rotasi_kanan(Addr y);
Addr rotasi_kiri(Addr x);
int get_different(Addr N);
Addr input_nodeAVL(Addr node, nbType value);


#endif
