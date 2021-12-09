#include <cmath>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cstring>
#include <io.h>
#include <conio.h>
#include <windows.h>

using namespace std;
/*
Sarcina 1: Se da un fisier textual. De numarat cite cuvinte din fisier se incep cu o
litera introdusa de la tastatura. (De prevazut sa se tinacont de litera mare si mica.)
Sarcina 2: Se da un fisier textual. De copiat din el, in alt fisier, toate cuvintele care sunt
mai lungi de o valoare introdusa de la tastatura.

Sarcina optionala:
    Cifrul lui Caesar: Fiecare litera din cuvant se muta dupa alfabat cu un nr de pozitii. Nr pe
    pozitii este cheia cifrului.
    Fie un fisier textual. De codificat cu ajutorul cifrului lui Caesar. Cheia cifrului introdusa de
    la tastatura.



int main()
//Rezolvarea sarcinii 2 de mai sus.
{
    FILE * in;
    FILE * out;
    const char * filename = "test.txt";
    const char * out_filename = "copied.txt";
    int counter = 0;
    int word_length;
    char line[101];
    char * check_word;
    cout << "Introduceti lungimea cuvantelor care se vor copia: ";
    cin >> word_length;

    in = fopen(filename, "r");
    out = fopen(out_filename, "w");
    if(in != NULL)
    {
        while(!feof(in))
        {
            fscanf(in, "%s", line);
            if(strlen(line) > word_length)
            {
                if(out != NULL)
                {
                    fprintf(out, "%s ", line);
                }
            }
        }
        fclose(in);
        fclose(out);
    }
    else
    {
        cout << "Fisierul nu a putut fi deschis.";
    }
    cout << "Done!";
    return 0;
}

int main()
{
    //Redarea sunetului cu ajutorul bibliotecii windows.h
    Beep(500,20);
    Beep(1000,50);
    Beep(10200,20);
    Beep(5000,20);
    //cout << "\a";
    return 0;
}
*/

//De creat un meniu pentru utilizator prin care se poate naviga
//cu ajutorul butoanelor w pentru sus si s pentru jos.
int options_nr=7;
char ** options = new char* [options_nr]{
    "Aduna 2 numere",
    "Scade 2 numere",
    "Inmulteste 2 numere",
    "Imparte 2 numere",
    "Radacina patrata",
    "Ridicare la putere",
    "Logaritm natural"
};

void print_menu(int pos)
{
    cout << "\tUse up and dow arrows to navigate up and down." << endl;
    cout << "\tUse Enter for selecting the option and Esc to exit the program." << endl;
    for(int i = 0; i < options_nr; i++)
    {
        if (i == pos - 1)
        {
            cout << "->";
        }
        //cout << "\t\tOption " << i + 1 << endl;
        cout << "\t\t" << options[i] << endl;
    }
}


int main()
{
    int pos = 1;
    int choice;
    do
    {
        system("cls");
        print_menu(pos);
        choice = getch();
        if (choice == 72 && pos > 1)
        {
            pos--;
        }else
        if(choice == 80 && pos < options_nr)
        {
            pos++;
        }else
        if(choice == 13)
        {
            //cout << "Selected option: " << pos << ".";
            cout << options[pos - 1];
            getch();
        }
    }while (choice != 27);


    return 0;
}

