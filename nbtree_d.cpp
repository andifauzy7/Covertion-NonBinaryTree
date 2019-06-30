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

Addr Convert_nbtree(nbAddr root, Addr *avl_root){
    Addr First = (Addr)malloc(sizeof(BinaryTree));
    First->left = First->right = NULL;
    nbAddr pCur;
	boolean arah;
	arah=0;
    if(root == NULL){
        return NULL;
    }
	pCur=root;
	First = insert_btree(First, pCur);
	(*avl_root) = input_nodeAVL((*avl_root), pCur->nama);
	do{
		if(pCur->fs!=NULL && arah==0){
			pCur=pCur->fs;
			First = insert_btree(First, pCur);
			(*avl_root) = input_nodeAVL((*avl_root), pCur->nama);
		}else{
			arah=0;
			if (pCur->nb!= NULL){
				pCur=pCur->nb;
				First = insert_btree(First, pCur);
				(*avl_root) = input_nodeAVL((*avl_root), pCur->nama);
			}else{
				pCur=pCur->parent;
				arah=1;
			}
		}
	}while(pCur!=NULL);
    return First;
}

/* Modul Alokasi untuk sebuah Node. */

Addr insert_btree(Addr First, nbAddr nonbinary){
    Addr temp = (Addr)malloc(sizeof(BinaryTree));
    temp->left = temp->right = NULL;
    if(nonbinary->parent==NULL){
        // Jika tidak memiliki Parent == Menjadi Root.
        strcpy(First->info, nonbinary->nama);
        First->left = First->right = NULL;
    } else {
        // Jika memiliki Parent.
        Addr parent = (Addr)malloc(sizeof(BinaryTree));
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

/* Kedalaman */

int bDepth(Addr root){
    if (root == NULL)
        return 0;
    else {
        int l_depth = bDepth(root->left);
        int r_depth = bDepth(root->right);

        if (l_depth > r_depth){
            return(l_depth + 1);
        }else {
            return(r_depth + 1);
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

void Post_binary(Addr root){
	if (root!=NULL){
		Post_binary(root->left);
		Post_binary(root->right);
		printf(" %s.", root->info);
	}
}

void Pre_binary(Addr root){
	if (root!=NULL){
		printf(" %s.", root->info);
		Pre_binary(root->left);
		Pre_binary(root->right);
	}
}

void In_binary(Addr root){
	if (root!=NULL){
		Pre_binary(root->left);
		printf(" %s.", root->info);
		Pre_binary(root->right);
	}
}

void view_traversal_binary(Addr root){
    if(root==NULL){
        printf("\n\tTree belum dibuat!");
    }
    printf("\n\tPOSTORDER : ");
    Post_binary(root); printf("\n");
    printf("\tINORDER   : ");
    In_binary(root);   printf("\n");
    printf("\tPREORDER  : ");
    Pre_binary(root);  printf("\n");
    printf("\tKEDALAMAN :  %d\n",bDepth(root));
}

/* Delete Node */

/* Search dengan mengembalikan address Node tertentu */

Addr bSearch(Addr root, nbType src){
	Addr nSrc;
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

/* Modul Pembantu Untuk AVL Tree */

int max(int a, int b){
	return (a > b)? a : b;
}

Addr build_node(nbType value){
	Addr node = (Addr)malloc(sizeof(BinaryTree));
	strcpy(node->info, value);
	node->left = node->right = NULL;
	node->height = 1;
	return(node);
}

int height_node(Addr root){
	if (root == NULL)
		return 0;
	return root->height;
}

Addr rotasi_kanan(Addr y){
	Addr x = y->left;
	Addr T2 = x->right;

	x->right = y;
	y->left = T2;

    // Melakukan Update Height karena ada perubahan dari rotasi.
	y->height = max(height_node(y->left), height_node(y->right))+1;
	x->height = max(height_node(x->left), height_node(x->right))+1;
	return x;
}

Addr rotasi_kiri(Addr x){
	Addr y = x->right;
	Addr T2 = y->left;

	y->left = x;
	x->right = T2;

	// Melakukan Update Height karena ada perubahan dari rotasi.
	x->height = max(height_node(x->left), height_node(x->right))+1;
	y->height = max(height_node(y->left), height_node(y->right))+1;
	return y;
}

int get_different(Addr N){
	if (N == NULL)
		return 0;
	return height_node(N->left) - height_node(N->right);
}

Addr input_nodeAVL(Addr node, nbType value){
	// Umumnya Proses Input sama seperti BST, Perbedaan pada modul ini yaitu melakukan otomatis Balancing setelah Input.
	if (node == NULL)
		return(build_node(value));
	if (strcmp(value, node->info)<0)
		node->left = input_nodeAVL(node->left, value);
	else if (strcmp(value, node->info)>0)
		node->right = input_nodeAVL(node->right, value);
	else
		return node;

	// Melakukan Update Height setelah proses input kedalam tree.
	node->height = 1 + max(height_node(node->left),height_node(node->right));

	// Mendapatkan selisih antara node kiri dan kanan.
	int balance = get_different(node);

	// Left Left Case
	if (balance > 1 && strcmp(value, node->left->info)<0)
		return rotasi_kanan(node);

	// Right Right Case
	if (balance < -1 && strcmp(value, node->right->info)>0)
		return rotasi_kiri(node);

	// Left Right Case
	if (balance > 1 && strcmp(value, node->left->info)>0){
		node->left = rotasi_kiri(node->left);
		return rotasi_kanan(node);
	}

	// Right Left Case
	if (balance < -1 && strcmp(value, node->right->info)<0){
		node->right = rotasi_kanan(node->right);
		return rotasi_kiri(node);
	}

	return node;
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

Addr b_delete(Addr root, nbType value)
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

Addr value_minimum(Addr root){
    Addr temp=root;
    while(temp && temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
