#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;

void zasady(){

    char ct;
    cout << "\t~~~GRA WISIELEC~~~\n\n";
    cout << "\tZASADY GRY:\n";
    cout << "\tODGADNIJ WYLOSOWANE HASŁO.\n";
    cout << "\tPRY KAZDYM ZŁYM ODGADNIĘCIU PROGRM NARYSUJE CZĘŚĆ WISIELCA\n";
    cout << "\tJAK WISIELEC ZOSTANIE W PEŁNI NARYSOWANY, GRA ZAKOŃCZY SIĘ\n";
    cout << "\tPOWODZENIA!" << endl;

    cout << "\tNACIŚNIJ X ABY PRZEJŚĆ DALEJ:-";
    cin >> ct;

    if (ct == 'x')
    system("clear");
}


void message (string tytul, bool top = true, bool bot = true ) // rysuje granice programu
{
    if(top){
        cout << "#------------------------#" << endl;
        cout << "| ";
    }
    else
    {
        cout << "|";
    }
    bool front = true;
    for (int i = tytul.length(); i < 23; i++)
    {
        if (front)
        {
            tytul = " " + tytul;
        }
        else
        {
            tytul = tytul + " ";
        }
        front = !front;
    }
    cout << tytul.c_str();

    if (bot)
    {
        cout << " |" << endl;
        cout << "#------------------------#" << endl;
    }
    else
    {
        cout << " |" << endl;
    }
}

void wisielec(int iloscprob = 0) // rysuje wisielca
{
    if
    (iloscprob >= 1)
    message("_ _", false, false);
    else
    message("", false, false);
     if
     (iloscprob >= 2)
    message("|  |", false, false);
    else
    message("", false, false);
    if
    (iloscprob >= 3)
    message("0  |", false, false);
    else
    message("", false, false);
    if
    (iloscprob >= 4)
    message("/|| |", false, false);
    else
    message("", false, false);
    if
    (iloscprob >= 5)
    message("|  |", false, false);
    else
    message("", false, false);
    if
    (iloscprob >= 5)
    message("/ | |", false, false);
    else
    message("", false, false);
    if
    (iloscprob >= 6)
    message("    |", false, false);
    else
    message("", false, false);
    if
    (iloscprob >= 7)
    message("    |", false, false);
    else
    message("", false, false);
    if
    (iloscprob >= 8)
    message("", false, false);
    else
    message("", false, false);
    if
    (iloscprob >= 9)
    message("", false, false);
    else
    message("", false, false);

  
}

 
void litery(string input, char from, char to)  // zakres liter
{
    string q;
    for(char i = from; i <= to; i++)
    {
        if(input.find(i) == string::npos)
        {
            q += i;
            q += " ";
        }
        else
        {
            q += " ";
        }
    }
    message(q, false, false);
}
void dostepnelitery(string zajete) // pokazuje dostepne litery i dzieli je na rzedy 
{
    message("Dostępne Litery:", true, true);
    litery(zajete, 'A', 'H');   
    litery(zajete, 'I', 'P');
    litery(zajete, 'Q', 'X');
    litery(zajete, 'Y', 'Z');
}
bool checkwin (string slowo, string odgadniete) //warunek wygrania
{
    bool wygrana = true;
    string s;
    for (int i = 0; i < slowo.length(); i++)
    {
        if (odgadniete.find(slowo[i]) == string::npos)
        {
            wygrana = false;
            s += "_ ";
        }
        else
        {
            s += slowo[i];
            s += " ";
        }
    }
    message(s, false);
    return wygrana;
}
string LoadRandomWord(string path) // losowanie słowa z pliku tesktowego
{
    int lineCount = 0;
    string word;
    vector<string> v;
    fstream plik;
	plik.open("hasla.txt");
    if (plik.good())
    {
        while (getline(plik, word))
            v.push_back(word);
 
        int randomLine = rand() % v.size();
 
        word = v.at(randomLine);
        plik.close();
    }
	cout<<word;
    return word;
} // ZASTĄP ALGORYTMEM NA LOSOWANIE SŁOW W KODZIE PROGRAMU, WYSZUKOWANIE Z PLIKU .TXT NIE DZIAŁA!!!!!!!!!!!!
int TriesLeft(string word, string guessed) // pozostałość prob
{
    int error = 0;
    for (int i = 0; i < guessed.length(); i++)
    {
        if (word.find(guessed[i]) == string::npos)
            error++;
    }
    return error;
}

int main(){
srand(time(0));
string proby;
string slowa_do_odgadniecia;
slowa_do_odgadniecia = LoadRandomWord("hasła.txt");
int tries = 0;              
    bool win = false;
    do
    {
        zasady();
        system("clear");  /// if windows type "cls" insttead of clear
        message("GRA_WISIELEC");
        wisielec(tries);
        dostepnelitery(proby);
        message("HSAŁO:", true, true);
        win = checkwin(slowa_do_odgadniecia, proby);
    if (win)
            break;
 
        char x;
        cout << ">"; cin >> x;
 
        if (proby.find(x) == string::npos)
            proby += x;
 
        tries = TriesLeft(slowa_do_odgadniecia, proby);
 
    } while (tries < 10);
 
    if (win)
        message("WYGRANA!");
    else
        message("GAME OVER");
 
    
    getchar();
    return 0;
}
