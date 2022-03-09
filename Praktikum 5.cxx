#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct simpul Node;
struct simpul{
	int data;
	Node *next;
};

Node *head = NULL, *p;
void cari();
void mengurutkan();
void alokasi();
void akhir();
void tampil();
void hapus_tertentu();

int main(){
	char jwb;
	int pil;
	puts("Program single linked list dengan prinsip LIFO\n");
	do{
		printf("1. Insert tertentu secara urut\n");
		printf("2. Pencarian data\n");
		printf("3. Delete data\n");
		printf("4. Keluar\n");
		printf("Masukkan pilihan anda : ");
		scanf("%d", &pil);
		fflush(stdin);
		
	switch (pil){
		case 1:
		fflush(stdin);
		alokasi();
		akhir();
		mengurutkan();
		fflush(stdin);
		tampil();
		puts("");
		break;
		case 2:
		if (head == NULL){
			printf("SLL masih kosong silahkan isi\n\n");
		}else{
			fflush(stdin);
			cari();
			fflush(stdin);
			puts("");
		}
		break;
		case 3:
		if (head == NULL){
			puts("SLL masih kosong tolong isikan");
		}else{
			fflush(stdin);
			hapus_tertentu();
			tampil();
			puts("");
		}
		break;
		default:
		printf("\nPROGRAM EXIT\n");
		exit(0);
	}
	} while (pil != 4);
return 0;
}

void cari(){
	Node *find;
	int cek = 0, x;
	printf("Masukkan data yang dicari");
	scanf("%d", &x);
	find = head;
	
	while (find->next != NULL){
		if (find->data == x){
			cek = cek + 1;
			find = find->next;
		}else{
			find = find->next;
		}
		}
		
	if (cek > 0){
		printf("\n Data %d ditemukan sebanyak %d kali", x, cek);
	}else{
		printf("Data %d tidak ada");
	}
}

void mengurutkan(){
	Node *i, *j;
	int cari;
	
	for (i = head; i->next != NULL; i = i->next){
		for (j = i->next; j != NULL; j = j->next){
			if (i->data > j->data){
				cari = i->data;
				i->data = j->data;
				j->data = cari;
			}
		}
	}
}

void alokasi(){
	int x;
	printf("Data yang mau disimpan : ");
	scanf("%d", &x);
	p = (Node *)malloc(sizeof(Node));
	
	if (p == NULL){
		puts("Alokasi Gagal\n");
		exit(0);
	}else{
		p->data = x;
		p->next = NULL;
	}
}

void tampil(){
	Node *baca;
	printf("\n\tTampilan LIFO\n");
	baca = head;
	
	while (baca != NULL){
		printf(" %d", baca->data);
		baca = baca->next;
	}
}

void akhir(){
	Node *tail;
	
	if (head == NULL){
		head = p;
	}else{
		tail = head;
		while (tail->next != NULL){
			tail = tail->next;
		}
		tail->next = p;
		tail = tail->next;
	}
}

void bebas(Node *a){
	free(a);
	a = NULL;
}

void hapus_tertentu(){
	Node *hapus, *phapus;
	int key;
	printf("\nData yang mau dihapus ? ");
	scanf("%d", &key);
	hapus = head;
	
	if (hapus->data == key){
	head = hapus->next;
	}else{
		while (hapus->data != key){
			if (hapus->next == NULL){
				printf("%d tidak ada dalam SLL\n", key);
				main();
			}else{
				phapus = hapus;
				hapus = hapus->next;
			}
		}
	phapus->next = hapus->next;
	}
	bebas(hapus);
}