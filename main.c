#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree node;

struct tree{
    char data;
    node *left;
    node *right;
};

//fungsi cari
node *search (node *root, char data);

//fungsi data
void insert(node **tree, char val);

//fungsi print
void preorder(node *tree);
void inorder(node *tree);
void postorder(node *tree);

//fungsi menu
void mainMenu(node *root);
void menuCari(node *root);

//user input
void input(node **root);

char loop = 'y';

int main()
{
    node *root = NULL;

    input(&root);

    while(loop == 'y' || loop == 'Y'){
        mainMenu(root);
    }

    do{
        menuCari(root);
    }while(loop == 'y' || loop == 'Y');

    return 0;
}

void menuCari(node *root)
{
    char x;
    node *tmp;

    printf("Masukkan data yang dicari : ");
    scanf("%c", &x);
    fflush(stdin);
    printf("\nMencari data....\n");

    tmp = search(root, x);

    if(tmp != NULL)
        printf("\nData %c ditemukan\n", tmp->data);
    else
        printf("\nData tidak ditemukan\n");

    printf("Ingin Mencari data yang lain ? [y/t] ");
    scanf("%c", &loop);
    fflush(stdin);
}

void mainMenu(node *root)
{
    int pilihMenu;

    printf("MENU\n");
    printf("1. Preorder\n");
    printf("2. Inorder\n");
    printf("3. PostOrder\n");
    printf("Pilih Menu : ");
    scanf("%d", &pilihMenu);

    switch(pilihMenu)
        {
        case 1:
            printf("\nPRINT PRE ORDER:\n");
            preorder(root);
            break;

        case 2:
            printf("\nPRINT IN ORDER:\n");
            inorder(root);
            break;

        case 3:
            printf("\nPRINT POST ORDER:\n");
            postorder(root);
            break;

        default:
            puts("\nMenu tidak ada\n");
        }
        printf("\nIngin mencoba lagi? [y/t] ");
        scanf(" %c", &loop);
        puts("");
        fflush(stdin);
}

void input(node **root)
{
    char data[100];
    printf("Masukkan data (Harap Data Dipisahkan oleh spasi :) ) : ");
    gets(data);
    for(int i = 0; i < strlen(data); i++){
        if(data[i] != ' ')
            insert(&*root, data[i]);
    }
}

void insert(node **tree, char val)
{
    node *temp = NULL;
    if(!(*tree)){
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }
    if (val < (*tree)->data)
        insert(&(*tree)->left, val);
    else if (val > (*tree)->data)
        insert(&(*tree)->right, val);
}

void preorder(node *tree)
{
    if (tree != NULL){
        printf("%c ", tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void inorder(node *tree)
{
    if (tree != NULL){
        inorder(tree->left);
        printf("%c ", tree->data);
        inorder(tree->right);
    }
}

void postorder(node *tree)
{
    if(tree != NULL){
        postorder(tree->left);
        postorder(tree->right);
        printf("%c ", tree->data);
    }
}

node *search (node *root, char data)
{
    if(!(root))
        return NULL;
    else if(data < (root)->data)
        return (search((root)->left, data));
    else if(data > (root)->data)
        return (search((root)->right, data));
    else if(data == (root)->data)
        return (root);
}
