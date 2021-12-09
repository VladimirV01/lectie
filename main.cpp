#include <cmath>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cstring>
#include <io.h>

using namespace std;
/*
// Program care citeste din fisier si numara lungimea fiecarui rand.
int main()
{
    const char* path = "test.txt";
    int c;
    int len = 0, cnt = 0;
    FILE* in;
    if (fopen_s(&in, path, "r") != NULL)
        cout << "The file cannot be opened";
    else
    {
        while (!feof(in))
        {
            c = fgetc(in);
            if (c == '\n')
            {
                cnt++;
                cout << "String " << cnt
                << " length=" << len
                << "\n";
                len = 0;
            }
            else
            {
                len++;
            }
        }
        if (len)
        {
            cnt++;
            cout << "String " << cnt << " length="
            << len << "\n";
        }
    }
    return 0;
}

// Program care citeste din fisier si numara lungimea fiecarui rand.
// Printeaza fiecare rand.
// Copie fisierul in al fisier nou.
int main()
{
    const char* path = "test.txt";
    int c;
    int len = 0, cnt = 0;
    FILE * in;
    FILE * out;
    out = fopen("copie.txt", "w");
    if (fopen_s(&in, path, "r") != NULL)
        cout << "The file cannot be opened";
    else
    {
        while (!feof(in))
        {
            c = fgetc(in);
            if (c == '\n')
            {
                cnt++;
                cout << "\tString " << cnt
                << " length=" << len
                << "\n";
                len = 0;
                if (out != NULL)
                {
                    fputc('\n', out);
                }
            }
            else
            {
                if (out != NULL)
                {
                    fputc(c, out);
                }
                cout << char(c);
                len++;
            }
        }
        if (len)
        {
            cnt++;
            cout << "String " << cnt << " length="
            << len << "\n";
        }
    }
    return 0;
}
*/

/*
FUNCTII PENRU CITIRE/SCRIERE IN FISIER PE RAND:
char* fgets(char* s, int n, FILE * f) - Citirea se opreste cand se ajunge la byte-ul n-1 sau la new line.
char* s = adresa unde se afla sirul de caractere care trebuie scris in fisier
int n = numarul de bytes ce va fi scris in fisier
FILE * f = pointerul spre fisierul in carese va scrie.

int fputs(char * s, FILE * f)
char * s - sirul de caractere care trebuie scris
FILE * f - pointerul spre fisierul unde se va scrie informatia.


int main()
//Program ce citeste din fisier pe randuri si le printeaza in consola.
{
    const char* path = "test.txt";
    int len = 0;
    char buf[128];
    FILE* in;
    if (fopen_s(&in, path, "r") != NULL)
        cout << "The file cannot be opened";
    else
    {
        while (!feof(in))
        {
            fgets(buf, 127, in);
            len = strlen(buf);
            if(buf[len - 1] == '\n')
            {
                buf[len - 1] = '\0';
            }
            puts(buf);
        }
    }
    return 0;
}
*/
/*
FUNCTII PENTRU CITIRE/SCRIERE IN FORMAT BINAR:
fread - citeste bytes
fwrite - scrie bytes in fisier

In varianta de baza, functiile au urmatorii parametri:
 - Un pointer spre locul de pastrare a datelor
 - Dimensiunea, in bytes, a elementului citit/scris
 - Numarul maxim de elemente ce trebuie citite/scrise
 - Pointerul spre fisier.


int main()
//Program care scrie date in fisier in format binar.
{
    const char* path = "Datebinare.dat";
    const int n = 5;
    int arr[n] = {9, 8, 7, 4, 5};
    FILE* out;
    if (fopen_s(&out, path, "wb") != NULL)
        cout << "The file cannot be opened";
    else
    {
        //for (int i = 0; i < n; i++)
        //{
        //    fwrite(&arr[i], sizeof(int), 1, out);
        //}
        // Deoarece datele din masive sunt pastrate in memorie conscutiv,
        //ciclul de mai sus poate fi inlocuit cu o singura instructiune.
        fwrite(&arr[0], sizeof(int), n, out);
    }
    return 0;
}
*/
/*
Fseek - permite pozitionarea caretei in interiorul fisierului
int fseek(FILE * filename, long int offset, int origin)
FIle * filename - pointerul spre fisierul unde se executa operatiile
long int offset - numarul de bytes cu care se va muta careta in raport cu originea
int origin - poizita de unde se incepe numararea bytes pentru pozitionare.
        -- SEEK_SET - de la inceput de fisier.
        -- SEEK_CUR - de la pozitia curenta a caretei
        -- SEEK_END - de la sfarsitul fisierului
Functia va returna 0 daca careta a fost deplasata cu succes si un rezultat diferit de 0 in caz contrar.


int main()
{
    // Program care premite schimbarea cu locul a valorilor minim si maxim din fisier.
    const char* path = "Datebinare.dat";
    int n = 10, imax, imin, i;
    int* a, maxim, minim;
    FILE* f;
    if (fopen_s(&f, path, "wb") != NULL)
        cout << "The file cannot be opened";
    else
    {
        for (i = 0; i < n; i++)
        {
            fwrite(&i, sizeof(int), 1, f);
        }
        fclose(f);
    }
    if (fopen_s(&f, path, "r+b") != NULL)
        cout << "The file cannot be opened";
    else
    {
        a = new int[n];
        fread(a, sizeof(int), n, f);
        for (imax = imin = 0, maxim = minim = a[0], i = 1; i < n; i++)
        {
            if (a[i] > maxim)
            {
                maxim = a[i];
                imax = i;
            }
            if (a[i] < minim)
            {
                minim = a[i];
                imin = i;
            }
        }
        fseek(f, imax * sizeof(int), SEEK_SET);
        fwrite(&minim, sizeof(int), 1, f);
        fseek(f, imin * sizeof(int), SEEK_SET);
        fwrite(&maxim, sizeof(int), 1, f);
        fclose(f);
        delete[]a;
    }
    return 0;
}

int main()
{
    // Program care cauta primul fisier cu extensia .dat din directiva proiectului curent.
    struct _finddata_t myfileinfo;
    long done = _findfirst("*.dat", &myfileinfo);
    cout << myfileinfo.name;
    return 0;
}

int main()
{
    // Program ce cauta toate fisierele cu extensia dorita din directuva curenta a proiectului.
    struct _finddata_t fileinfo;
    char str[200] ="*.dat";

    long done = _findfirst(str, &fileinfo);
    if (done == -1)
    {
        cout << "The search was unsuccessful." << endl;
    }
    else
    {
        while (done!=-1)
        {
            cout << fileinfo.name<<"\n";
            done = _findnext(done, &fileinfo);
        }

    }
    return 0;
}


//Se da un fisier text. De copiat in alt fisier text totul in afara de ultimul rand.
int main()
{
    FILE * in;
    FILE * out;
    char line[255];
    int counter = 0, line_nr = 0;
    in = fopen("test.txt", "r");
    out = fopen("text_modificat.txt", "w");

    if(in != NULL && out != NULL)
    {
        while(!feof(in))
        {
            fgets(line, 254, in);
            counter++;
        }
        fseek(in, 0, SEEK_SET);

        while(!feof(in))
        {
            if (line_nr != counter-1)
            {
                fgets(line, 254, in);
                fputs(line, out);
                line_nr++;
            }else
            {
                fgets(line, 254, in);
                line_nr++;
            }

        }
        fclose(in);
        fclose(out);
    }
    else
    {
        cout << "Fisierul 1 sau 2 nu a putut fi deschis." << endl;
    }

    return 0;
}


//Se da un fisier text. De numarat cate caractere sunt in el.

int main()
{
    FILE * in;
    const char * filename = "test.txt";
    int counter = 0;
    in = fopen(filename, "r");
    if(in != NULL)
    {
        while(!feof(in))
        {
            fgetc(in);
            counter++;
        }
        fclose(in);
    }
    else
    {
        cout << "Fisierul nu a putut fi deschis.";
    }
    cout << "In fisierul " << filename << " sunt " << counter << " caractere.";
    return 0;
}

//Se da un fisier text. De determinat lungimea celui mai lung rand.
int main()
{
    FILE * in;
    const char * filename = "test.txt";
    int len=0, maxlen = 0;
    char c;

    in = fopen(filename, "r");
    if(in != NULL)
    {
        while(!feof(in))
        {
            c=fgetc(in);
            if(c == '\n')
            {
                if (len > maxlen)
                {
                    maxlen = len;
                }
                len = 0;
            }else
            {
                len++;
            }
        }
        if(len > maxlen)
            maxlen = len;
        fclose(in);
    }
    else
    {
        cout << "Fisierul nu a putut fi deschis.";
    }
    cout << "Cel mai lung rand din " << filename << " are " << maxlen << " caractere.";
    return 0;
}

//Se da un fisier text. De determinat de cate ori in fisier se intilneste un cuvant introdus de utilizator.
int main()
{
    FILE * in;
    const char * filename = "test.txt";
    int counter = 0;
    char cuvant[100];
    char line[101];
    char * check_word;
    cout << "Introduceti cuvantul: ";
    gets(cuvant);

    in = fopen(filename, "r");
    if(in != NULL)
    {
        while(!feof(in))
        {
            fgets(line, 100, in);
            check_word = strtok(line, " .");
            while (check_word)
            {
                if (strcmp(check_word, cuvant) == 0)
                {
                    counter++;
                }
                check_word = strtok(NULL, " .");
            }

        }
    }
    else
    {
        cout << "Fisierul nu a putut fi deschis.";
    }
    cout << "Cuvantul " << cuvant << " a fost intilnit de " << counter << " ori.";
    return 0;
}


Sarcina 1: Se da un fisier textual. De numarat cite cuvinte din fisier se incep cu o
litera introdusa de la tastatura. (De prevazut sa se tinacont de litera mare si mica.)
Sarcina 2: Se da un fisier textual. De copiat din el, in alt fisier, toate cuvintele care sunt
mai lungi de o valoare introdusa de la tastatura.

Sarcina optionala:
    Cifrul lui Caesar: Fiecare litera din cuvant se muta dupa alfabat cu un nr de pozitii. Nr pe
    pozitii este cheia cifrului.
    Fie un fisier textual. De codificat cu ajutorul cifrului lui Caesar. Cheia cifrului introdusa de
    la tastatura.

*/

    int main()
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
            /*
            fgets(line, 100, in);
            check_word = strtok(line, " .");
            while (check_word)
            {
                if (strcmp(check_word, cuvant) == 0)
                {
                    counter++;
                }
                check_word = strtok(NULL, " .");
            }
            */
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
