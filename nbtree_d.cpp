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

bAddr Convert_nbtree(nbAddr root){
    bAddr First = (bAddr)malloc(sizeof(BinaryTree));
    First->left = First->right = NULL;
    nbAddr pCur;
	boolean arah;
	arah=0;
    if(root == NULL){
        return NULL;
    }
	pCur=root;
	First = insert_btree(First, pCur);
	do{
		if(pCur->fs!=NULL && arah==0){
			pCur=pCur->fs;
			First = insert_btree(First, pCur);
		}else{
			arah=0;
			if (pCur->nb!= NULL){
				pCur=pCur->nb;
				First = insert_btree(First, pCur);
			}else{
				pCur=pCur->parent;
				arah=1;
			}
		}
	}while(pCur!=NULL);
    return First;
}


/* Modul Alokasi untuk sebuah Node. */

bAddr insert_btree(bAddr First, nbAddr nonbinary){
    bAddr temp = (bAddr)malloc(sizeof(BinaryTree));
    temp->left = temp->right = NULL;
    if(nonbinary->parent==NULL){
        // Jika tidak memiliki Parent == Menjadi Root.
        strcpy(First->info, nonbinary->nama);
        First->left = First->right = NULL;
    } else {
        // Jika memiliki Parent.
        bAddr parent = (bAddr)malloc(sizeof(BinaryTree));
        parent = bSearch(First, nonbinary->parent->nama);
        if(parent->left==NULL){
            // Jika Bagian FS dari parent belum terisi oleh anak pertama.
            strcpy(temp->info, nonbinary->nama);
            parent->left = temp;
        } else {
            // Jika Bagian FS dari parent sudah terisi oleh anak pertama = Disimpan pada bagian terkanan SON.
            parent = parent->left;
            if(parent->right == NULL){
                strcpy(temp->info, nonbinary->nama);
                parent->right = temp;
            } else {
                while(parent->right!=NULL){
                    parent = parent->right;
                }
                strcpy(temp->info, nonbinary->nama);
                parent->right = temp;
            }
        }

    }
    return First;
}

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

/* Untuk Non - Binary Tree */

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
    if(root==NULL){
        printf("\n\tTree belum dibuat!");
    }
    printf("\n\tNon - Binary Tree");
    printf("\n\tPOSTORDER : ");
    Postorder(root); printf("\n");
    printf("\tINORDER   : ");
    Inorder(root);   printf("\n");
    printf("\tPREORDER  : ");
    Preorder(root);  printf("\n");
}

/* Untuk Binary Tree */

void Post_binary(bAddr root){
	if (root!=NULL){
		Post_binary(root->left);
		Post_binary(root->right);
		printf(" %s.", root->info);
	}
}

void Pre_binary(bAddr root){
	if (root!=NULL){
		printf(" %s.", root->info);
		Pre_binary(root->left);
		Pre_binary(root->right);
	}
}

void In_binary(bAddr root){
	if (root!=NULL){
		Pre_binary(root->left);
		printf(" %s.", root->info);
		Pre_binary(root->right);
	}
}

void view_traversal_binary(bAddr root){
    if(root==NULL){
        printf("\n\tTree belum dibuat!");
    }
    printf("\n\tBinary Tree");
    printf("\n\tPOSTORDER : ");
    Post_binary(root); printf("\n");
    printf("\tINORDER   : ");
    In_binary(root);   printf("\n");
    printf("\tPREORDER  : ");
    Pre_binary(root);  printf("\n");
}

/* Delete Node */



/* Modul Pembantu */

/* Search dengan mengembalikan address Node tertentu */

bAddr bSearch(bAddr root, nbType src){
	bAddr nSrc;
	if (root!=NULL){
		if (strcmp(root->info, src)==0)
			return root;
		else{
			nSrc=bSearch(root->left,src);
			if (nSrc==NULL)
				return bSearch(root->right,src);
			else
				return nSrc;
		}
	}
	else{
		return NULL;
	}
}

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

void list_parent(nbAddr root){
	if (root!=NULL){
		printf(" \n\t> %s.", root->nama);
		list_parent(root->fs);
		list_parent(root->nb);
	}
}


/* Update Tree */

void updatetree(nbTree *root){
    nbTree memberlist;
    nbAddr change;
    nbType srcnama, newname;
    char pil;

    if((*root).root == NULL){
        printf("\n\tTree belum dibuat!");
    } else {
        repeat:
        memberlist=(*root);
        list_parent(memberlist.root);
        printf("\n\n\tNama (*Akan diupdate)   : "); scanf(" %[^\n]", srcnama);
        change=nbSearch(memberlist.root, srcnama);
        if (change!=NULL)
        {
        printf("\tMasukan Nama Baru       : ");
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
}

void nbInput(nbTree *tRoot){
nbType nama;
nbType parent;
    printf("\n\tMasukan Nama      : ",nama);
    scanf(" %[^\n]", &nama);
    if((*tRoot).root == NULL){
        Insertnode(&(*tRoot), nbSearch((*tRoot).root,0), nama);
    } else {
        printf("\n\n\tDAFTAR PARENTS");
        list_parent((*tRoot).root); printf("\n");
inprt:
        printf("\tMasukan Parent    : ");
        scanf(" %[^\n]", &parent);
            if(nbSearch((*tRoot).root,parent) == NULL){
                printf("\n\tInput Gagal! Masukkan Parent yang sesuai\n");
                goto inprt;
            } else {
                Insertnode(&(*tRoot), nbSearch((*tRoot).root,parent), nama);
                printf("\n\tInput Berhasil!");
            }
    }
}


