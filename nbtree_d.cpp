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

bool c=false;

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

bAddr bSearch(bAddr root, nbType src){
	if (root!=NULL){
		if (root->info==src)
			return root;
		else{
		    (src > root->info) ? bSearch(root->right,src) : bSearch(root->left,src);
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

/* non binary delete */

void nb_delete(nbTree *pTree){
    nbAddr pdel, temp, tempNb;
    pdel=pTree->root;
    nbType value;

    printf("\n\t Delete : ");
    scanf(" %[^\n]", value);

    if (pTree->root!=NULL){
        pdel=nbSearch(pTree->root, value);
        if(pdel->fs!=NULL){
            temp=pdel;
            while(temp->fs!=NULL){
                strcpy(temp->nama, temp->fs->nama);
                if(temp->fs->nb!=NULL){
                    tempNb=temp->fs->nb;
                }
                temp=temp->fs;

                if (pdel->fs->nama==pdel->nama){
                    pdel->fs=tempNb;
                    tempNb=pdel->fs;
                    while(temp->nb!=NULL){
                        tempNb=tempNb->nb;
                    }
                    if(temp->fs!=NULL){
                        tempNb->nb=temp;
                    }
                    pdel=temp;
                    temp->nb=NULL;
                }
            }
        }
        else if(pdel->fs==NULL){
            temp=pdel->parent;

            if(temp->fs==pdel){
                temp->fs=pdel->nb;
            }
            else{
                temp=temp->fs;
                while(temp->nb!=NULL){
                    if(temp->nb==pdel){
                        temp->nb=temp->nb->nb;
                    }
                    else{
                        temp=temp->nb;
                    }
                }
            }
        }
        free(pdel);
    }
    else{
        printf("\n\tTree Kosong mamang!!!");
    }
}

/* binary delete */

bAddr b_delete(bAddr root, nbType value)
{
	c=bSearch(root,value);
	if(root==NULL)
		return root;
	else if(value< root->info)
	{
		root->left= b_delete(root->left,value);
	}
	else if(value> root->info)
	{
		root->right= b_delete(root->right,value);
	}

	// Node deletion
	else
	{
		//case 1: Leaf Node
		if(root->left==NULL&&root->right==NULL)
		{
			delete root;
			root=NULL;
			return root;
		}
		//case 2: one child
		else if(root->left==NULL)
		{
			struct TreeNode* temp=root;
			root=root->right;
			delete temp;
			return root;
		}
		else if(root->right==NULL)
		{
			struct TreeNode* temp=root;
			root=root->left;
			delete temp;
			return root;
		}
		//case 3: 2 child
		else
		{
			struct TreeNode*temp=value_minimum(root->right);
			strcpy(root->info, temp->info);
			root->right=b_delete(root->right,temp->info);
		}
	}
	return root;

}

bAddr value_minimum(bAddr root){
    bAddr temp=root;
    while(temp && temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
