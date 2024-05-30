#include <iostream>
#include <stdlib.h>
using namespace std;

struct Buku
{
    string judul, pengarang;
    int tahunTerbit;
    Buku *next;
};

Buku *head, *tail, *cur, *newNode, *del, *before;

void createSLL(string judul, string pengarang, int tB)
{
    head = new Buku();
    head->judul = judul;
    head->pengarang = pengarang;
    head->tahunTerbit = tB;
    head->next = NULL;
    tail = head;
}

int countSLL()
{
    cur = head;
    int jumlah = 0;
    while (cur != NULL)
    {
        jumlah++;
        cur = cur->next;
    }
    return jumlah;
}

void addFirst(string judul, string pengarang, int tB)
{
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit = tB;
    newNode->next = head;
    head = newNode;
}

void addLast(string judul, string pengarang, int tB)
{
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit = tB;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

void addMidle(string judul, string pengarang, int tB, int posisi)
{
    if (posisi < 1 || posisi > countSLL())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        newNode = new Buku();
        newNode->judul = judul;
        newNode->pengarang = pengarang;
        newNode->tahunTerbit = tB;
        cur = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            cur = cur->next;
            nomor++;
        }
        newNode->next = cur->next;
        cur->next = newNode;
    }
}

void removeFirst()
{
    del = head;
    head = head->next;
    delete del;
}

void removeLast()
{
    del = tail;
    cur = head;
    while (cur->next != tail)
    {
        cur = cur->next;
    }
    tail = cur;
    tail->next = NULL;
    delete del;
}

void removeMiddle(int posisi)
{
    if (posisi < 1 || posisi > countSLL())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        cur = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                before = cur;
            }
            if (nomor == posisi)
            {
                del = cur;
            }
            cur = cur->next;
            nomor++;
        }
        before->next = cur;
        delete del;
    }
}

void changeFirst(string judul, string pengarang, int tB)
{
    head->judul = judul;
    head->pengarang = pengarang;
    head->tahunTerbit = tB;
}

void changeLast(string judul, string pengarang, int tB)
{
    tail->judul = judul;
    tail->pengarang = pengarang;
    tail->tahunTerbit = tB;
}

void changeMiddle(string judul, string pengarang, int tB, int posisi)
{
    if (posisi < 1 || posisi > countSLL())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1 || posisi == countSLL())
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        cur = head;
        while (nomor < posisi)
        {
            cur = cur->next;
            nomor++;
        }
        cur->judul = judul;
        cur->pengarang = pengarang;
        cur->tahunTerbit = tB;
    }
}

void printSLL()
{
    cout << "Jumlah data ada : " << countSLL() << endl;
    cur = head;
    while (cur != NULL)
    {
        cout << "------------------" << endl;
        cout << "Judul Buku        : " << cur->judul << endl;
        cout << "Pengarang Buku    : " << cur->pengarang << endl;
        cout << "Tahun Terbit Buku : " << cur->tahunTerbit << endl;
        cout << "------------------" << endl;
        cur = cur->next;
    }
}

int main()
{
    int pilih, update, delets, ch;
    string judul, pengarang;
    int tahunTerbit, posisi;
menu:
    cout << "-------------------------------------------------" << endl;
    cout << "|                                               |" << endl;
    cout << "|~    WELCOME TO THE BOOK WAREHOUSE PROGRAM    ~|" << endl;
    cout << "|                                               |" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "|1. CREATE                                      |" << endl;
    cout << "|2. SHOW                                        |" << endl;
    cout << "|3. UPDATE                                      |" << endl;
    cout << "|4. CHANGE                                      |" << endl;
    cout << "|5. DELETE                                      |" << endl;
    cout << "|6. EXIT                                        |" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "|           PLEASE INPUT YOUR CHOICES           |" << endl;
    cout << "-------------------------------------------------" << endl;
    cin >> pilih;
    switch (pilih)
    {
    case 1:
        if (head != NULL)
        {
            cout << "LIST ALREADY CREATED !" << endl;
            cout << "ADVICE : USE UPDATE MENU TO ADD MORE BOOKS!" << endl;
        }
        else
        {
            cout << "JUDUL        : ";
            cin >> judul;
            cout << "PENGARANG    : ";
            cin >> pengarang;
            cout << "TAHUN TERBIT : ";
            cin >> tahunTerbit;
            createSLL(judul, pengarang, tahunTerbit);
        }
        system("pause");
        goto menu;
        break;
    case 2:
        printSLL();
        system("pause");
        goto menu;
        break;
    case 3:
    updates:
        system("cls");
        cout << "-------------------------------------------------" << endl;
        cout << "|~                 UPDATE MENU                 ~|" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "|1. ADD FIRST                                   |" << endl;
        cout << "|2. ADD MIDDLE                                  |" << endl;
        cout << "|3. ADD LAST                                    |" << endl;
        cout << "|4. BACk TO MAIN MENU                           |" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "|           PLEASE INPUT YOUR CHOICES           |" << endl;
        cout << "-------------------------------------------------" << endl;
        cin >> update;
        switch (update)
        {
        case 1:
            cout << "JUDUL        : ";
            cin >> judul;
            cout << "PENGARANG    : ";
            cin >> pengarang;
            cout << "TAHUN TERBIT : ";
            cin >> tahunTerbit;
            addFirst(judul, pengarang, tahunTerbit);
            system("pause");
            goto updates;
            break;
        case 2:
            cout << "JUDUL        : ";
            cin >> judul;
            cout << "PENGARANG    : ";
            cin >> pengarang;
            cout << "TAHUN TERBIT : ";
            cin >> tahunTerbit;
            cout << "POSISI : ";
            cin >> posisi;
            addMidle(judul, pengarang, tahunTerbit, posisi);
            system("pause");
            goto updates;
            break;
        case 3:
            cout << "JUDUL        : ";
            cin >> judul;
            cout << "PENGARANG    : ";
            cin >> pengarang;
            cout << "TAHUN TERBIT : ";
            cin >> tahunTerbit;
            addLast(judul, pengarang, tahunTerbit);
            system("pause");
            goto updates;
            break;
        case 4:
            system("pause");
            goto menu;
            break;
        default:
            system("cls");
            cout << "Invalid input" << endl;
            system("pause");
            goto updates;
            break;
        }
        system("pause");
        goto menu;
        break;
    case 4:
    changes:
        system("cls");
        cout << "-------------------------------------------------" << endl;
        cout << "|~                 CHANGE MENU                 ~|" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "|1. CHANGE FIRST                                |" << endl;
        cout << "|2. CHANGE MIDDLE                               |" << endl;
        cout << "|3. CHANGE LAST                                 |" << endl;
        cout << "|4. BACK TO MAIN MENU                           |" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "|           PLEASE INPUT YOUR CHOICES           |" << endl;
        cout << "-------------------------------------------------" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "JUDUL        : ";
            cin >> judul;
            cout << "PENGARANG    : ";
            cin >> pengarang;
            cout << "TAHUN TERBIT : ";
            cin >> tahunTerbit;
            changeFirst(judul, pengarang, tahunTerbit);
            system("pause");
            goto changes;
            break;
        case 2:
            cout << "JUDUL        : ";
            cin >> judul;
            cout << "PENGARANG    : ";
            cin >> pengarang;
            cout << "TAHUN TERBIT : ";
            cin >> tahunTerbit;
            cout << "POSISI : ";
            cin >> posisi;
            changeMiddle(judul, pengarang, tahunTerbit, posisi);
            system("pause");
            goto changes;
            break;
        case 3:
            cout << "JUDUL        : ";
            cin >> judul;
            cout << "PENGARANG    : ";
            cin >> pengarang;
            cout << "TAHUN TERBIT : ";
            cin >> tahunTerbit;
            changeLast(judul, pengarang, tahunTerbit);
            system("pause");
            goto changes;
            break;
        case 4:
            system("pause");
            goto menu;
            break;
        default:
            system("cls");
            cout << "Invalid input" << endl;
            system("pause");
            goto changes;
            break;
        }
    case 5:
    deleted:
        system("cls");
        cout << "-------------------------------------------------" << endl;
        cout << "|~                 DELETE MENU                 ~|" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "|1. DELETE FIRST                                |" << endl;
        cout << "|2. DELETE MIDDLE                               |" << endl;
        cout << "|3. DELETE LAST                                 |" << endl;
        cout << "|4. BACK TO MAIN MENU                           |" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "|           PLEASE INPUT YOUR CHOICES           |" << endl;
        cout << "-------------------------------------------------" << endl;
        cin >> delets;
        switch (delets)
        {
        case 1:
            removeFirst();
            system("pause");
            goto deleted;
            break;
        case 2:
            cout << "POSISI : ";
            cin >> posisi;
            removeMiddle(posisi);
            system("pause");
            goto deleted;
            break;
        case 3:
            removeLast();
            system("pause");
            goto deleted;
            break;
        case 4:
            system("pause");
            goto menu;
            break;
        default:
            system("cls");
            cout << "Invalid input" << endl;
            system("pause");
            goto deleted;
            break;
        }
        system("pause");
        goto menu;
        break;
    case 6:
        system("cls");
        cout << "Thank you for using this program\nRegards,\nULIL ABSOR_23.61.0259_23BCI01" << endl;
        system("pause");
        system("exit");
        break;
    default:
        system("cls");
        cout << "Invalid input" << endl;
        system("pause");
        goto menu;
        break;
    }
}