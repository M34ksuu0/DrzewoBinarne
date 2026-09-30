#include <iostream>
using namespace std;

// struktura liscia
struct Lisc
{
    int wartosc;
    Lisc* lewy;
    Lisc* prawy;
};
class drzewo
{
    public:
        Lisc* korzen;
        drzewo()
        {
            korzen=NULL;
        }
        Lisc* dodaj(Lisc* korzen, int wartosc)
        {
        //jesli drzewo jest puste
        if (korzen==NULL)
        {
            Lisc* nowy=new Lisc;
            nowy->wartosc=wartosc;
            nowy->lewy=NULL;
            nowy->prawy=NULL;
            return nowy;
        }
        //jesli liczba jest mniejsza od poprzedniej liczby
        if(wartosc<korzen->wartosc)
        {
            korzen->lewy=dodaj(korzen->lewy, wartosc);
        }
        //jesli liczba jest wieksza od poprzedniej liczby
        else
        {
            korzen->prawy=dodaj(korzen->prawy, wartosc);
        }
        return korzen;
        }
        // wyswietlanie drzewa
        void wyswietl(Lisc* korzen)
        {
            if (korzen==NULL)
            return;
            cout<<korzen->wartosc<<" ";
            wyswietl(korzen->lewy);
            wyswietl(korzen->prawy);
        }
        void dodaj(int wartosc)
        {
            korzen=dodaj(korzen, wartosc);
        }
        void wyswietl()
        {
            wyswietl(korzen);
        }
        //destruktor
        ~drzewo()
        {
        }
};
int main()
{
    drzewo korzen1;
    int ile;
    cout<<"Ile liczb: ";
    cin>>ile;
    for(int i=0; i<ile; i++)
    {
        int wartosc;
        cout<<"Podaj liczbe: ";
        cin>>wartosc;
        korzen1.dodaj(wartosc);
    }
    //wyswietlanie drzewa
    cout<<endl;
    cout<<"Drzewo: ";
    korzen1.wyswietl();

    return 0;
}
