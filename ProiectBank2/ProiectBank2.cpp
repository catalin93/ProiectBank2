#include <iostream>
#include "ContBancar.h"
#include "ManagerConturi.h"
#include <thread>


/*1. O clasa cont bancar ce trebuie sa aibe atribute precum nume, prenume, sold, tip de cont(valuta sau lei) IBAN
Un cont trebuie neaparat sa aibe un nume, prenume si un IBAN care trebuie sa fie unic
2.in maine se afla terminalul principal al bancii in care trebuie sa avem urmatoarele optiunii
2.1 numar de conturi-- > ce ne da numarul de conturi inregistrate in banca
2.2 creare cont-- > cu aceasta optiune se poate crea un cont nou
2.2.1 -- > ar trebui un scrren diferit si un set de optiuni in care
operatorul bancii sa introduca datele pentru crearea contului.(trebuie ca aceasta procedura sa verifice daca exista deja contul ce
    se doreste creat iar daca da sa anunte opreatorul)
    2.2.2 -- > o optiune de return la main screen(ecranul cu optiunie principale)
    2.3 O optiune de modificare cont->in care operatorul poate sa modifice date despre cont(ex schimbare nume, schimbare sume etc)
    2.4 O optiune prin care un cont se poate sterge din sistemul bancii
    2.5 O optiune prin care un cont poate sa extraga sume - > vrei sa adaugi sau sa extragi o suma de bani
    2.6 O optiune prin care un cont sa vada care este suma din cont
    Trebuie cautat contul intordus iar daca exista se poate vizualiza
    Daca nu exista putem incepe o procedura de creare cont
    3. Un sistem in care putem sa salvam datele acestea intr - un fisier local(CSV file)*/
int main()
{

    int optiune;
    ManagerConturi manager;
    //TODO: Sa facem o functie pentru acest do while
    do {
        std::cout << "Alege-ti una din urmatoarele optiuni: " << std::endl;
        std::cout << "1- numar cont\n";
        std::cout << "2- Creare cont\n";
        std::cout << "3- Modificare cont\n";
        std::cout << "4- Stergere cont\n";
        std::cout << "5- Eliberare/Depunere\n";
        std::cout << "6- Detalii cont\n";
        std::cout << "0- Pentru a iesi din aplicatie\n";
        std::cout << "Introduce-ti operatia pe care o doriti: \n";
        std::cin >> optiune;

        switch (optiune)
        {
        case 0:
            system("cls");
            std::cout << "Multumim la revedere\n";
            break;
        case 1:
            std::cout << "Ati ales optiunea 1\n";
            std::cout << "Numarul total de conturi este " << manager.GetNumarConturi() << std::endl;
            break;
        case 2:
            std::cout << "Ati ales optiunea 2\n";
            system("cls");
            manager.adaugareCont();
            break;
        case 3:
            std::cout << "Ati ales optiunea 3\n";
            break;
        case 4:
            std::cout << "Ati ales optiunea 4\n";
            system("cls");
            manager.EraseAcount();
            break;
        case 5:
            std::cout << "Ati ales optiunea 5\n";
            manager.Eliberare_Depunere();
            break;
        case 6:
            std::cout << "Ati ales optiunea 6\n";
            manager.PrintAllConturi();
            break;
        default:

            std::cout << "Optiune invalida \n";

            system("cls");
            break;
        }
    } while (optiune != 0);



}