#include <iostream>
using namespace std;
#define MAX_QUEUE 1000

// Struktur Queue :
struct Queue {
    string elemen[MAX_QUEUE];
    int rear;
    int front;
    int jml;
};

// Pembuatan Queue baru:
void createQ(Queue &q) {
    q.front = 0;
    q.rear = -1;
    q.jml = 0;
}

// Pengecekan jika queue penuh:
bool isFull(Queue q) {
    return q.jml == MAX_QUEUE;
}

// Pengecekan jika queue kosong:
bool isEmpty(Queue q) {
    return q.jml == 0;
}

// Proses enqueue:
void enQ(Queue &q, string i) {
    if (isFull(q)) {
        cout << "Queue sudah penuh, tidak bisa menambahkan elemen." << endl;
        return;
    }
    q.rear++;
    q.elemen[q.rear] = i;
    q.jml++;
}

// Proses dequeue:
void deQ(Queue &q, string &i) {
    if (isEmpty(q)) {
        cout << "Queue kosong, tidak ada elemen untuk dihapus." << endl;
        return;
    }
    cout<<"Deque..."<<endl;
    i = q.elemen[q.front];
    q.front++;
    q.jml--;
}

// Menampilkan isi Queue
void display(Queue q) {
    if (isEmpty(q)) {
        cout << "Queue kosong." << endl;
        return;
    }
    cout << "Isi Queue: ";
    for (int i = q.front; i <= q.rear; i++) {
        cout << q.elemen[i] << " ";
    }
    cout << endl;
}

void ui();

int main() {
    Queue q;
    createQ(q); // Inisialisasi Queue
    int choice;
    string n;

    do {
        ui();
        cin >> choice;
        cin.ignore();
        cin.clear();
        system("clear");
        switch (choice) {
            case 1: {
                cout << "Masukkan data yang akan dimasukkan: ";
                getline(cin,n);
                enQ(q, n);
                cout << "Data dengan nilai " << n << " berhasil ditambahkan." << endl;
                system("sleep 1.5");
                break;
            }
            case 2: {
                deQ(q, n);
                system("sleep 2");
                break;
            }
            case 3: {
                display(q);
                system("sleep 2");
                break;
            }
        }
    } while (choice != 4);

    return 0;
}

void ui() {
    system("clear");
    cout << "Implementasi Queue pada Array" << endl;
    cout << "==============================" << endl << endl;
    cout << "Menu:" << endl;
    cout << "1. Enq" << endl;
    cout << "2. Deq" << endl;
    cout << "3. Tampilkan Isi Queue" << endl;
    cout << "4. Keluar" << endl;
    cout << "Masukkan Pilihan: ";
}