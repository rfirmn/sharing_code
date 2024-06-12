#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct data{
    char* nomor;
    char* nama;
    char* domisili;
    char* gender;
}data;

typedef struct node{
    char* admin;
    struct node *right;
    struct node *left;
    struct data *biodata;
}node;

node* create_node(char* value, data* point){
    struct node *new_node = (node*)malloc(sizeof(struct node));
    new_node->admin = strdup(value);
    new_node->right = NULL;
    new_node->left = NULL;
    new_node->biodata = point;

    printf("\ndata telah dibuat\n");

    return new_node;
}

data* create_data(char* nomor, char* nama, char* domisili, char* gender){
    data* new_data = (data*)malloc(sizeof(data));
    new_data->nomor = strdup(nomor);
    new_data->nama = strdup(nama);
    new_data->domisili = strdup(domisili);
    new_data->gender = strdup(gender);

    return new_data;
}

node* insert(node* point, char* value){

    if(point == NULL){
        printf("\nmasukkan data kontak darurat: \n");

        char nomor[100], nama[100], domisili[100], gender[100];
        printf("masukkan nomor: ");
        scanf("%s", nomor);
        printf("masukkan nama: ");
        scanf("%s", nama);
        printf("masukkan domisili saat ini: ");
        scanf("%s", domisili);
        printf("masukkan jenis kelamin: ");
        scanf("%s", gender);
        data* new_data = create_data(nomor, nama, domisili, gender);
        return create_node(value, new_data);
    }

    if(strcmp(value, point->admin) == 0){
        printf("Data sudah ada");
        return point;
    }

    if(strcmp(value, point->admin) < 0){
        point->left = insert(point->left, value);
    } else if(strcmp(value, point->admin) > 0){
        point->right = insert(point->right, value);
    }
    return point;
}

void print_data(data* temp){
    printf("\nnomor: %s\n", temp->nomor);
    printf("nama: %s\n", temp->nama);
    printf("domisili: %s\n", temp->domisili);
    printf("jenis kelamin: %s\n", temp->gender);
}

data* search(node* point, char* value){

    if(point == NULL){
        printf("\ndata tidak ditemukan\n");
        return NULL;
    }

    if(strcmp(point->admin, value) == 0){
        printf("\nBiodata kontak darurat:\n");
        print_data(point->biodata);
        return point->biodata;
    }

    if(strcmp(value, point->admin) < 0){
        return search(point->left, value);
    } else{
        return search(point->right, value);
    }

}

void in_order(node* point){
    if(point == NULL){
        return;
    }

    in_order(point->left);

    printf("\nNama: %s\n", point->admin);
    printf("biodata nomor darurat:");
    print_data(point->biodata);
    
    in_order(point->right);
}

void pre_order(node* point){
    if(point == NULL){
        return;
    }

    printf("\nNama: %s\n", point->admin);
    printf("biodata nomor darurat:");
    print_data(point->biodata);

    pre_order(point->left);

    pre_order(point->right);

}

void post_order(node* point){
    if(point == NULL){
        return;
    }
    
    post_order(point->left);

    post_order(point->right);

    printf("\nNama: %s\n", point->admin);
    printf("biodata nomor darurat:");
    print_data(point->biodata);
}

int main(){
    struct node* root = NULL;

    char nama[100];

    bool loop = true;
    int pilihan;

    while(loop){
        printf("\n1. insert\n2. search\n3. in order\n4. pre order\n5. post order\n6. exit\n");
        printf("masukkan angka: ");
        scanf("%i", &pilihan);
        switch(pilihan){
            case 1:
                printf("masukkan nama: ");
                scanf("%s", nama);
                root = insert(root, nama);
                break;
            case 2:
                printf("masukkan nama yang ingin dicari: ");
                scanf("%s", nama);
                search(root, nama);
                break;
            case 3:
                in_order(root);
                break;
            case 4:
                pre_order(root);
                break;
            case 5:
                post_order(root);
                break;  
            case 6:
                loop = false;
                break;
            default:
                printf("pilihan tidak ada\n");
                break;
        }

    }

    return 0;
}