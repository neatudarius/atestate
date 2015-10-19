//  Programming in C++
//  By Roxana Florentina Soare

// Windows forms && console
#include "stdafx.h"
#include <windows.h>
#include "wtypes.h"

//Header files for algorithms etc
#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;
using namespace System;


#define Terminated 1
#define Restarted 1
#define BeerBreak (long double)(3.5)


int ScreenBuffer = 0; // no of printed characters per line
long double timeStart, timeFinish;
int ReadyToSleep, RestartSystem;

void Run();

int main()
{
	// Define windows size
	int width = 150, height = 50;

	//Set window size
	Console::SetWindowSize(width, height);

	//Set window color
	Console::BackgroundColor = System::ConsoleColor::Cyan;

	//Set text color
	Console::ForegroundColor = System::ConsoleColor::Black;

	// Number of printed characters per line
	ScreenBuffer = Console::BufferWidth;

	// This is my program
	Run(); 

	return 0;
}

void Menu(), ShowTheTime();
void Run()
{
	timeStart = clock();
	while (!ReadyToSleep || RestartSystem) {
		Menu();
		if (!ReadyToSleep || RestartSystem)ReadyToSleep = RestartSystem = 0;
	}
	ShowTheTime();
}

void WhaitUntilCommandIsPrompt();
bool ReturnToMainWasPrompted();
void Trademark(), Title(char* title), WhaitForSomePeriod(const long double &period);
void ShowSomeString(const string &someString);
void ShowCHeader(), ShowCppHeader(), C_History(), CPP_History(), ShowSTLDoc();
void Vector(), Algorithm(), ProblemSet(), GraphMenu();

void Menu()
{
	Console::Clear();
	Title("Programming in C++");
	Trademark();
	printf("\n                 MENIU \n\n");
	printf("    Alege una din urmatoarele optiuni!\n");
	printf("    1 - pentru ISTORIE C\n");
	printf("    2 - pentru HEADERE C\n");
	printf("    3 - pentru ISTORIE C++\n");
	printf("    4 - pentru HEADERE C++\n");
	printf("    5 - pentru DOCUMENTATIE STL\n");
	printf("    6 - pentru DIRECTIVUL <vector>\n");
	printf("    7 - pentru DIRECTIVUL <algorithm>\n");
	printf("    8 - pentru PROBLEME\n");
	printf("    9 - pentru GRAFURI\n");
	printf("   10 - pentru a incheia programul!\n");
	printf("\n\n");
	int option;
	do { cout << "option = "; cin >> option; } while (option<1 || option>10);
	switch (option)
	{
	case 1: C_History();
		break;
	case 2: ShowCHeader();
		break;
	case 3: CPP_History();
		break;
	case 4: ShowCppHeader();
		break;
	case 5: ShowSTLDoc();
		break;
	case 6: Vector();
		break;
	case 7: Algorithm();
		break;
	case 8: ProblemSet();
		break;
	case 9: GraphMenu();
		break;
	case 10:ReadyToSleep = Terminated;
		break;
		break;
	}
}

void WhaitUntilCommandIsPrompt()
{
	printf("\n");
	printf("Apasati 0 - pentru a continua.\n");
	printf("Apasati 1 - pentru a restarta programul.\n");
	printf("Apasati 2 - pentru a inchide programul.\n");
	int option;
	do { cout << "option = "; cin >> option; } while (option<0 || option>2);
	switch (option)
	{
	case 0:
		Console::Clear();
		break;
	case 1: RestartSystem = Restarted;
		Console::Clear();
		break;
	case 2: ReadyToSleep = Terminated;
		break;
		printf("%d nu e o optiune valida! \n", option);
		break;
	}
}

bool ReturnToMainWasPrompted()
{
	if (ReadyToSleep || RestartSystem)return 1;
	else return 0;
}

void ShowSomeString(const string &someString)
{
	int Max = someString.size();
	for (int i = 0; i<Max; ++i)
	{
		int j = i + ScreenBuffer;
		if (j >= Max)j = Max;
		else for (j; someString[j] != ' '; --j);
		for (int k = i; k <= j; ++k)
			if (someString[k] == '\n') { j = k; break; }
		for (; i<j; ++i)cout << someString[i];
		cout << "\n";
	}
}

void WhaitForSomePeriod(const long double &period)
{
	long double timeFinish = (long double)(clock() + period * 1000);
	while (clock()<timeFinish);
}

void ShowTheTime()
{
	Console::Clear();
	timeFinish = clock();
	long double howLong = 1.0*(timeFinish - timeStart) / CLOCKS_PER_SEC;
	int hours = 0, minutes = 0, seconds = 0, miliseconds = 0, nanoseconds = 0;
	hours = howLong / 3600;
	minutes = (howLong - hours * 3600) / 60;
	seconds = howLong - hours * 3600 - minutes * 60;
	miliseconds = (howLong - hours * 3600 - minutes * 60 - seconds) * 1000;
	cout << "\n\n\n\n\n";
	cout << "            Programul a durat exact ";
	if (hours)
		if (hours != 1)cout << hours << " ore ";
		else cout << hours << " ora ";
		if (minutes)
			if (minutes != 1)cout << minutes << " minute ";
			else cout << minutes << " minut ";
			if (seconds)
				if (seconds != 1)cout << seconds << " secunde ";
				else cout << seconds << " secunda ";
				if (miliseconds)
					if (miliseconds != 1)cout << miliseconds << " milisecunde!!!\n\n\n";
					else cout << miliseconds << " milisecunda!!!\n\n\n";
					Trademark();
					WhaitForSomePeriod(BeerBreak);
}

#define Nmax 109
int N, M, CComponents;
int Graph[Nmax][Nmax];
vector < int > CC[Nmax]; // Connected components
bitset < Nmax > visited;
void BuildGraph(), AddEdge(), DeleteEdge(), ListGraph(), DeleteGraph(), DepthFirstSearch();

void GraphMenu()
{
	if (ReturnToMainWasPrompted())return;
	Console::Clear();
	Title("Grafuri\0");
	printf("    Alege una din urmatoarele optiuni! \n");
	printf("    1 - pentru a construi un graf neorientat\n");
	printf("    2 - pentru a adauga o muchie la graful deja existent\n");
	printf("    3 - pentru a sterge o muchie din graf\n");
	printf("    4 - pentru a afisa numarul de muchii din graf\n");
	printf("    5 - pentru a afisa graful sub forma listelor de adiacenta\n");
	printf("    6 - pentru a afisa componentele conexe ale grafului\n");
	printf("    7 - pentru a sterge graful si a construi altul\n");
	printf("    8 - pentru a reveni la meniul anterior\n");
	Trademark();
	while (1)
	{
		int option;
		do { cout << "\n     option ="; cin >> option; } while (option<1 || option>8);
		printf("\n     Ai ales optiunea %d\n", option);
		switch (option)
		{
		case 1: BuildGraph();
			break;
		case 2: AddEdge();
			break;
		case 3: DeleteEdge();
			break;
		case 4: printf("\nSunt %d muchii in graf! \n", M);
			break;
		case 5: ListGraph();
			break;
		case 6: DepthFirstSearch();
			break;
		case 7: DeleteGraph();
			printf("Asteapt cu nerabdare noul graf\n");
			break;
		case 8: printf("Reset!\n");
			RestartSystem = Restarted;
			WhaitForSomePeriod(BeerBreak);
			return;
			break;
			break;
		}
	}
}

void DeleteGraph()
{
	N = M = CComponents = 0;
	memset(Graph, 0, sizeof(Graph));
	for (int i = 0; i <= 100; ++i)visited[i] = 0, CC[i].clear();
}

void DFS(const int &node)
{
	visited[node] = 1;  CC[CComponents].push_back(node);
	for (int node2 = 1; node2 <= N; ++node2)
		if (node != node2 && Graph[node][node2] && !visited[node2])DFS(node2);
}

void DepthFirstSearch()
{
	for (int i = 1; i <= N; ++i) { visited[i] = 0;  CC[i].clear(); }
	CComponents = 0;
	for (int node = 1; node <= N; ++node)
		if (!visited[node]) { ++CComponents; DFS(node); }
	printf("Graful are %d componente conexe! \n ", CComponents);
	for (int i = 1; i <= CComponents; ++i)
	{
		printf("Componenta cu numarul %d : ", i);
		for (vector<int>::iterator it = CC[i].begin(); it != CC[i].end(); ++it)
			printf("%d ", *it);
		printf("\n");
	}
}

void ListGraph()
{
	for (int i = 1; i <= N; ++i)
	{
		bool ok = 0;
		printf("Lista nodului %d : ", i);
		for (int j = 1; j <= N; ++j)
			if (Graph[i][j]) { printf("%d ", j); ok = 1; }
		if (ok)printf("\n");
		else printf(" Ups... nod izolat\n");
	}
}

void DeleteEdge()
{
	int x, y;
	printf("Dati cele doua noduri \n");
	do { cout << "nod1= "; cin >> x; } while (x<1 || x>N);
	do { cout << "nod2= "; cin >> y; } while (y<1 || y>N);
	if (x == y) { printf("NU exista muchii de forma x--x !\n"); return; }
	if (Graph[x][y])
	{
		--M;  Graph[x][y] = Graph[y][x] = 0;
		printf("Muchia [ %d - %d ] a fost eliminata cu succes!\n", x, y);
	}
	else printf("Muchia [ %d - %d ] nu exista!\n", x, y);
}

void AddEdge()
{
	int x, y;
	printf("Dati cele doua noduri\n");
	do { cout << "nod1= "; cin >> x; } while (x<1 || x>N);
	do { cout << "nod2= "; cin >> y; } while (y<1 || y>N);
	if (x == y)
	{
		printf("NU poti duce muchie de la un nod la el insusi! Operatie neefectuata!\n");
		return;
	}
	if (!Graph[x][y])
	{
		++M;  Graph[x][y] = Graph[y][x] = 1;
		printf("Muchia [ %d - %d ] a fost adaugata cu succes!\n", x, y);
	}
	else printf("Muchia [ %d - %d ] deja exista!\n", x, y);
}

void BuildGraph()
{
	memset(Graph, 0, sizeof(Graph));
	printf("Dati numarul de noduri (N) si numarul de muchii (M). Dati macar 4 noduri si 3 muchii!\n");
	do { cout << "N= "; cin >> N; } while (N<4);
	do { cout << "M= "; cin >> M; } while (M<3);
	printf("Dati cele M perechi distincte de noduri intre care se duc muchii, pentru a face un graf\n");
	for (int i = 1; i <= M; ++i)
	{
		int x, y;
		printf("\n Muchia %d\n", i);
		do
		{
			do { cout << "nod1= "; cin >> x; } while (x<1 || x>N);
			do { cout << "nod2= "; cin >> y; } while (y<1 || y>N);
			if (x == y)
				printf("NU poti duce muchie de la un nod la el insusi! Operatie neefectuata! Programul asteapta valori corecte!\n");
			if (Graph[x][y])
				printf("Muchia [ %d - %d ] deja exista!\n", x, y);

		} while (x == y || Graph[x][y]);

		Graph[x][y] = Graph[y][x] = 1;
	}
}

void Ausoara(), PeluzaSud();
bool isPrime(const unsigned long long &X);

void ProblemSet()
{
	if (ReturnToMainWasPrompted())return;
	Console::Clear();
	Title("PROBLEME\0");
	printf("        Alege una din urmatoarele probleme!\n");
	printf("        1 - AUSOARA - ONI 2013 TIMISOARA\n");
	printf("        2 - PELUZA SUD - FMI NO STRESS 4\n");
	printf("        3 - Trimite-l pe Gigel inapoi in Meniu!\n");
	Trademark();
	int option;
	do { cout << "option ="; cin >> option; } while (option<1 || option>3);
	switch (option)
	{
	case 1: Ausoara();
		break;
	case 2: PeluzaSud();
		break;
	case 3: printf("I-ai taiat bucuria lui Gigel de a rezolva probleme!\n");
		WhaitForSomePeriod(BeerBreak);
		return;
		break;
		break;
	}
}

void PeluzaSud()
{
	if (ReturnToMainWasPrompted())return;
	Console::Clear();
	string someString = "                             Peluza Sud \n \n \n ";
	ShowSomeString(someString);
	someString = "                    Gigel vrea sa-si cumpere bilete la Peluza Sud. El si prietenii sai, care ii impartasesc parerile puternice despre numere, doresc o secventa de N locuri consecutive, printre care sa nu se afle niciun numar prim.De-asemenea,ei ar dori ca locurile sa aiba numere mai mari decat X, deoarece locurile cu numere pana in X sunt ocupate de fani dinamovisti.Gigel si prietenii sai au vazut de suficente ori filmul <<300>> incat sa stie ca nu trebuie sa-i provoci pe caini :D.\n		Restrictii\n		* Hai Steaua! \n		* 1<=N<=30 \n		* 1<=X<=10^14 \n		* Peluza Sud are doar 10^15 locuri.Astfel,va rugam ca locurile pe care le alegeti sa se afle \n in intervalul [X+1,10^15].\n              * Daca sunt mai multe solutii, se poate afisa oricare dintre acestea.\n ";
	ShowSomeString(someString);
	someString = "\n \n \n \n                 Ne vine ideea bruta si trivila sa parcurgem toate numerele din intervalul [X+1,10^15], insa constatam ca intervalul poate avea lungimea 10^15. O incercare care va dupa un timp colosal. Prin urmare aceasta ideea nu ne poate ajuta, decat daca prin noroc chior si taraneste gasim cele N numere compuse consecutive foarte repede, ceea ce este improbabil!\n ";
	ShowSomeString(someString);
	someString = "\n \n                 Cheia problemei este data de restrictiile date. Evident, prima este cea mai importanta! Un stelist adevarat merge la meci! Ne ajunta in si ultima precizare, prin care ni se comunica ca solutia nu e unica.";
	ShowSomeString(someString);
	someString = "\n \n                 Sa luam un exemplu. N=4 X=15. Cele primele numere care dau solutie sunt 24,25,26,27. Daca iteram mai departe gasim si 25,26,27,28 sau 32,33,34,35. Ce onservam ca ultima este solutie si pentru X=1,2,..,31. Si prin urmate vom cauta cel mai mare numar Y>X care este solutie pentru orice test!\n";
	ShowSomeString(someString);
	someString = "\n \n                 Dupa doar 10 000 de iteratii se gaseste ca cel mai mare numar Y pentru care avei 30 de numere compuse consecutive incepand cu el este Y=999999999990000. Astfel daca X<Y atunci indiferent de valoarea lui N raspunsul este Y, iar daca X>=Y atunci in mod cert N<30 si atunci vom proceda analog sa gasim pe Y'.\n ";
	ShowSomeString(someString);
	printf("\n\n                  Iata o sursa demonstrativa\n\n \n                 int main() \n { \n    cin>>N>>X; \n    if(X<Y)cout<<Y<<'\\n'; \n     else \n\n    {  \n        unsigned long long nr=0,sol=Y+10000,Max=Y+10000; \n    for(unsigned long long i=Y+10000;i>X;--i) \n     {  \n              if(!isPrime(i))++nr; \n             else \n             { \n                 if(nr>Max) \n                  { \n                      Max=nr; \n                     sol=i+1; \n                  } \n                  nr=0; \n              } \n          } \n        cout<<sol<<'\\n'; \n    } \n");
	someString = "                      Pentru a stii daca mai sunt bilete pentru tine si pentru cei N-1 prieteni ai tai, introdu numarul prietenilor si numarul X care va confera siguranta, sa va spunem daca mai sunt bilete pentru voi!\n ";
	ShowSomeString(someString);
	printf("\n\n\n");
	printf("    Vreti sa verifici daca va puteti duceti la meci? \n");
	printf("1 - pentru ca Gigel sa va gaseasca locuri pe National Arena\n");
	printf("2 - daca sunteti un dinamovist, si evident va este greu sa mergeti la meciuri din UCL ale echipei FC STEAUA BUCURESTI\n");
	int option;
	do { cout << "option ="; cin >> option; } while (option<1 || option>2);
	if (option == 2)
	{
		printf("Recomandam romanul SF <Dinamo in Uefa Champions League>\n");
		WhaitForSomePeriod(BeerBreak);
		return;
	}
	int N; long long X;
	do { cout << "N= "; cin >> N; cout << "X= "; cin >> X; } while (N<1 || X<1);
	long long Y = 999999999990000;
	if (X >= Y)
	{
		int Max = 0, nr = 0;
		for (long long i = Y + 10000; i>X; --i)
			if (!isPrime(i))++nr;
			else
			{
				if (nr>Max)
				{
					Max = nr;
					if (nr == N)Y = i + 1;
				}
				nr = 0;
			}
	}
	printf("Vei gasi cele %d N locuri in tribuna,daca vei cere %d bilete consecutive incepand cu %lld!\n", N, N, Y);
	someString = "HAI STEAUA!!!HAI STEAUA!!!HAI STEAUA!!!HAI STEAUA!!!HAI STEAUA!!!";
	ShowSomeString(someString);
	WhaitUntilCommandIsPrompt();
}

void Ausoara()
{
	if (ReturnToMainWasPrompted())return;
	Console::Clear();
	Title("Ausoara\0");
	string someString = "              Saracul Gigel vrea sa se angajeze.El a dat un interviu la Darius Corporation (TM) si a primit urmatoarea problema: dandu-se N siruri de numere sortate crescator sa se gaseasca cel mai lung subsir comun al acestor.\n             Rezolvati aceasta problema pe care Gigel a considerat-o destul de usoara. \n ";
	ShowSomeString(someString);
	someString = "\n                    Se va introduce: pe prima linie numarul natural nenul N cu semnificatia din enunt. \n Se vor citi apoi cele N siruri de numere: linia i+1 reprezinta codificarea sirului i si va fi de formata din M+1 numere";
	ShowSomeString(someString);
	someString = "            Evident ca Gigel va sare in ajutor. Bucuros ca a luat interviul el va spune cum a rezolvat problema : solutia este data de interclasarea celor N siruri , solutie optima ce are o complexitate O(N). De asemenea, el va recomanda sa folositi functia set_intersection() din STL deoarece a constatat el ca este optima. \n";
	ShowSomeString(someString);
	someString = "            De asemenea el va ofera chiar codul sursa scris la interviu. \n cin>>n; \n vector < int > sol; \n for (int i=0; i<n; i++) \n { \n cin>>nr; \n vector < int > v(nr); \n vector < int > aux(nr); \n for (int j=0; j<nr; j++) cin>>v[j]; \n if (i==0) sol=v; \n set_intersection(sol.begin(), sol.end(), v.begin(), v.end(), aux.begin()); \n swap(sol, aux); \n } \n int rez=sol.size()-1; \n while (sol[rez]==0) --rez; \n cout<<rez+1<<' '; \n for (int i=0; i<=rez; i++) \n cout<<sol[i]<<' '; \n";
	ShowSomeString(someString);
	printf("\n\n\n");
	printf("    Vreti sa verificati daca codul lui e bun? \n");
	printf("1 - pentru a va demonstra ca Gigel nu a intrat pe pile la  Darius Corporation (TM)\n");
	printf("2 - daca sunteti convins ca Gigel a dat spaga si vreti sa va intoarceti in Meniu\n");
	int option;
	do { cout << "option ="; cin >> option; } while (option<1 || option>2);
	if (option == 2)
	{
		printf("Gigel va merge la DNA si apoi la inchisoare , unde va fi coleg de celula cu Adrian Nastase\n");
		WhaitForSomePeriod(BeerBreak);
		return;
	}
	int N;
	do { cout << "Cate siruri vreti? N= "; cin >> N; } while (N<1);
	vector < int > sol;
	for (int i = 0; i<N; ++i)
	{
		printf("Dati sirul cu numarul %d \n", i + 1);
		int M = 0;
		do { cout << "M= "; cin >> M; } while (M<1);
		vector < int > v(M), aux(M);
		for (int j = 0; j<M; ++j) { cout << "urmatorul element este= "; cin >> v[j]; }
		if (i == 0) sol = v;
		set_intersection(sol.begin(), sol.end(), v.begin(), v.end(), aux.begin());
		swap(sol, aux);
	}
	int rez = sol.size() - 1;
	while (sol[rez] == 0)--rez;
	cout << rez + 1 << "\n";
	for (int i = 0; i <= rez; ++i) cout << sol[i] << " "; cout << "\n";
	WhaitUntilCommandIsPrompt();
}

void Algorithm()
{
	if (ReturnToMainWasPrompted())return;
	Console::Clear();
	Title(" Biblioteca <algorithm>\0");
	string someString;
	someString = "         Este o colectie de functii special realizate pentru a lucra cu obiecte";
	ShowSomeString(someString);
	someString = "         Voi arata care sunt cele mai utile si cunoscute functii\n";
	ShowSomeString(someString);
	someString = "\n              * functiile min/max  - numele sunt sugestive ; ex. int x=min(2,3); \n              *functia swap - care de asemenea primeste doi parametri, carora le interschimba valoarea \n int x=2,y=3; \n swap(x,y);  \n va rezulta x=3,y=2\n              *functia __gcd (great commun divisor)\n ex. int x=__gcd(30,36);  // x=6\n              *functia sort care ordoneaza implicit crescator un vector alocat static sau cu vector STL primind ca parametrii vectorul de sortat si pozitiile intre care se doreste sortarea\nint v[Nmax];\nf>>N;\nfor(int i=1;i<=N;++i)cin>>v[i];\nsort(v+1,v+1+N);\nfor(int i=1;i<=N;++i)cout<<v[i]<<'  ';'\nsau cu vector alocat cu STL\nvector < int >v;\nf>>N;\nfor(int i=1;i<=N;++i) \n{ int x;\nf>>x;\nv.push_back(x);\n}\nsort(v.begin(),v.end());for(int i=0;i<N;++i)cout<<v[i]<<'  '; \n              *functia next_permutation () - are aceeasi parametrii ca si sort. realizeaza urmatoare permutare a sirului in ordine lexico grafica si returneaza false daca permutarea obtinuta este ultima, sau true altfel\nEx.Sa se genereze toate permutarile multimii 1,2,...,n\nfor(int i=1;i<=N;++i)v[i]=i;\ndo\n{\n nfor(int i=1;i<=N;++i)cout<<v[i]<<'  ';\ng<<endl;\n}\nwhile(next_permutation(v+1,v+1+N));\n\n              *functia prev_permutation - analoaga functiei next_permutation\n              *functia binary_search(left,right,x) - intr-un sir ordinat se cauta aparitia numarului x intre pozitiile left si right, returnand pozitia pe care se afla x daca exista,sau 0 daca x nu se afla in sir\n ";
	ShowSomeString(someString);
	Trademark();
	WhaitUntilCommandIsPrompt();
}

void Vector()
{
	if (ReturnToMainWasPrompted())return;
	Console::Clear();
	Title("Biblioteca <vector>\0");
	string someString;
	ShowSomeString(someString);
	someString = "\n           *Elementele acestei biblioteci sunt containere-secvente care reprezinta un tablouri unidimensionale ce isi pot schimba capacitatea. \n           *Un vector din STL are elementele indexate de la 0 ! \n           *Este retinut faptul ca tipul elementelor poate fi oricare tip predefinit sau definit de utilizator. \n           *Alocarea numarului de elemente , se face dupa puterile lui 2. Astfel daca noi dorim alocarea a N pozitii in vector, compilatorul va aloca cea mai mica putere 2^k mai mare decat N. Exemplu: \n            vector < int > v; // am creat un tablou unidimensional v, cu elemente de tip int.\n           *Se poate adauga elemente doar la coada vectorului , folosind functia membra push_back(element); de asemenea se poate sterge doar ultimul element adauga , folosind functia pop_back().\n           *Alte functii membre utile sunt : \n           * clear()-sterge toate elementele adaugate in vector si elibereaza memoria rezervata de acesta \n           * size()-returneaza numarul de elemente adaugate in vector; \n           * capacity()-returneaza numarul de pozitii alocate in memorie de vectorului\n           *\n           *begin()-returneaza un iterator catre primul element din vector\n           *end()-returneaza un iterator catre ultimul element din vector\n";
	ShowSomeString(someString);
	Trademark();
	cout << "\n\n\n\n";
	someString = "             Doriti o exemplificare? Introduceti raspunsul 1 pentru a continua sau 0 pentru a reveni la meniul anterior  ";
	ShowSomeString(someString);
	string answer;
	do {
		cout << "option= ";
		cin >> answer;
	} while (answer != "1" && answer != "0");

	if (answer == "0")
		return;

	someString = "             Pentru exemplificare vom construi un vector. Introduceti un numar natural N nenul apoi N numere intregi. ";
	ShowSomeString(someString);

	int N;
	do {
		cin >> N;
	} while (N<1);
	printf("    Ati introdus valoarea %d\n", N);
	printf("    Introduceti pe rand elementele vectorului vector < int > v ; \n");
	vector < int > v;
	for (int i = 0; i<N; ++i)
	{
		int x;
		cout << "  x= ";
		cin >> x;
		v.push_back(x);
		printf("    A avut loc operatia v.push_back(%d)\n", x);
	}
	printf("Vectorul este :: ");
	for (int i = 0; i<N; ++i)printf("%d ", v[i]); printf("\n");
	printf("    Acum puteti goli,sorta,inversa vectorul etc\n");
	printf("    Veti putea face diverse operatii pana vectorul va fi gol. Cat timp este nevid puteti selecta una din urmatoarele optiuni\n");
	printf("    Alege una din urmatoarele optiuni!\n");
	printf("    1 - pentru sortarea crescatoare a vectorului\n");
	printf("    2 - pentru afisare\n");
	printf("    3 - pentru a adauga un element. In acest caz veti introduce si un numar\n");
	printf("    4 - pentru a sterge ultimul element din vector\n");
	printf("    5 - pentru a afisa numarul de elemente din vector \n");
	printf("    6 - pentru a afisa numarul de elemente alocate in memorie\n");
	printf("    7 - pentru a afisa elementul de pe pozitia i. introduceti pozitia i\n");
	printf("    8 - pentru a-i lua vectorul lui Gigel\n");
	Trademark();
	while (v.size())
	{
		int option, x;
		printf("\noption = "); scanf_s("%d", &option);
		switch (option)
		{
		case 1: sort(v.begin(), v.end());
			printf("Vectorul a fost sortat crescator!\n");
			break;
		case 2: printf("Vectorul este :: ");
			for (int i = 0; i<v.size(); ++i)printf("%d ", v[i]); printf("\n");
			break;
		case 3: printf("x = "); scanf_s("%d", &x); v.push_back(x); printf("OK : v.push_back(%d);\n", x);
			break;
		case 4: v.pop_back(); printf("OK : v.pop_back();\n");
			break;
		case 5: printf("In vector sunt %d elemente\n", (int)v.size());
			break;
		case 6: printf("Au fost alocate %d pozitii in memorie\n", (int)v.capacity());
			break;
		case 7: printf("i = "); scanf_s("%d", &x);
			printf("Elementul de pe pozitia %d este %d", x, v[x - 1]);
			break;
		case 8: printf("Gigele ia mana de pe vector!\n");
			WhaitForSomePeriod(BeerBreak);
			return;
			break;
			printf("Optiune invalida!\n");
			break;
		}
	}
}

void ShowSTLDoc()
{
	if (ReturnToMainWasPrompted())return;
	Console::Clear();
	Title("Ce este STL (Standard Template Library) ?\0");
	string someString;
	someString = "        Creatorul limbajului C++, Bjarne Stroustrup, si-a pus problema sa adauge limbajului anumite elemente astfel incat scrierea programelor sa se faca rapid,strandardizat si programele obtinute sa fie performante.Atunci cand scriem programe, utilizam doua notiuni fundamentale: algoritmi si structuri de date.";
	ShowSomeString(someString);
	someString = "                De aici, rezulta ca: \n                *Limbajul trebuie sa contina anumite clase care sa gestioneze structurile de date frecvent utilizate. Astfel, vom avea clase specializate in gestionarea vectorilor,listelor liniare, stivelor, cozilor, heap-urilor, etc. Astfel de clase se numesc clase de tip container, iar obiectele generate prin instantierea lor se numesc containere.Prin urmare, o structura de tip lista liniara este un container, o structura de tip stiva este un container, s.a.m.d. \n                *Intrucat o structura de date trebuie sa opereze cu date de orice tip, clasele de tip container utilizeaza din plin mecanismul template. Astfel, la modul general, un container se defineste ca un obiect care poate retine alte obiecte. \n                *Asa cum am vazut, structurile de date nu sunt suficiente pentru realizarea programelor. Din acest motiv, este necesar sa avem anumite functii care “incorporeaza”  algoritmii cei mai des folositi. Functiile care incorporeaza algoritmii,trebuie sa poata lucra cu orice tip de data (la modul general cu orice obiect).Cerinta este satisfacuta daca aceste functii utilizeaza si ele mecanismul template.De asemenea, este foarte important ca aceste functii sa poata lucra cu datelestocate in containere.Ca terminologie, vom utiliza termenul “algoritm” si cu semnificatia de functie template care rezolva o anumita problema des intalnita in activitatea curenta si care, de regula, prelucreaza date (obiecte) stocate in containere. \n                *O problema foarte importanta este data de accesul la datele (obiectele) aflate in container. Daca la un container de tip vector, accesul se poate realiza usor, el este mai dificil la un container de tip lista liniara sau la unul de tip de arbore de cautare.Din acest motiv, s-au generalizat pointerii si s-a ajuns la iteratori. Un iterator indica un anumit obiect din container. Pornind de la el se pot accesa datele si, daca este cazul, metodele obiectului memorat. De asemenea, se poate obtine imediat, printr-o simpla incrementare, un iterator care indica obiectul urmator din container.";
	ShowSomeString(someString);
	someString = "\n\n\n          Prin STL (Standard Template Library) intelegem o colectie de clase de tip container, algoritmi si iteratori care poate fi folosita pentru a realiza rapid programe performante si standardizate. Orice compilator actual de C++ trebuie sa permita utilizarea STL-ului. Prin folosirea STL-ului, obtinem programe portabile (pot fi compilate, teoretic, cu orice compilator de C++) si, mai ales, usor de descifrat pentru oricine este familiarizat cu acest mod de lucru.\n\n\n          Containere. Un container este un obiect care retine alte obiecte. El rezulta prin instantierea unei clase de tip container. Containerele sunt de doua mari categorii: containere secventa si containere asociative. De asemenea, exista o categorie aparte de containere, numite adaptori.\n\n\n          Iteratori. Pentru a se accesa cu usurinta obiectele unui container (“a naviga” printre ele) se utilizeaza iteratorii. Iteratorii sunt asemanatori pointer-ilor, dar cu ei se pot face mult mai multe lucruri. Daca in cazul containerelor de tip secventa, iteratorii sunt aproape la fel ca pointerii, in cazul containerelor asociative, acestia permit “navigarea” usoara, printr-o simpla incrementare, printre nodurile unui arbore de cautare.\n\n\n";
	ShowSomeString(someString);
	Trademark();
	WhaitUntilCommandIsPrompt();
}

void CPP_History()
{
	if (ReturnToMainWasPrompted())return;
	Console::Clear();
	Title("Limbajul C++.  Istorie.  Caracteristici\0");
	string someString;
	someString = "         Limbajul de programare C++ a fost initial derivat din C. Totusi, nu absolut orice program scris in C este valid C++. Deoarece C si C++ au evoluat independent, au aparut, din nefericire, o serie de incompatibilitati intre cele doua limbaje de programare. Cea mai ampla revizie a limbajui C, C99, a creat un numar suplimentar de conflicte. Diferentele fac sa fie greu de scris programe si biblioteci care sa fie compilate si sa ruleze corect in calitate de cod C sau C++, si produce confuzii celor care programeaza in ambele limbaje. Diferentele fac ca fiecare din cele doua limbaje de programare sa imprumute din caracteristicile celuilalt limbaj de programare.";
	ShowSomeString(someString);
	someString = "         Bjarne Stroustrup, creatorul limbajului C++, a sugerat de nenumarate ori  sa se reduca incompatibilitatile pe cat de mult posibil pentru a maximiza interoperabilitatea dintre cele doua limbaje de programare. Unii au argumentat ca C si C++ sunt doua limbaje de programare distincte, compatibilitatea dintre ele fiind utila dar nu vitala; potrivit acestei opinii, eforturile de a reduce incompatibilitatea nu trebuie sa reduca eforturile de a aduce elemente noi in mod independent celor doua limbaje de programare.";
	ShowSomeString(someString);
	someString = "         Cele mai importante diferente sunt:\n*        —functiile  apar in sectiunea de declarare a variabilelor globale in C++, iar in C acestea apar in asa zisele „fisiere statice“. \n*       Cuvantul cheie bool are in C99 propriul sau header, <stdbool.h>. În variantele anterioare de C tipul de date boolean nu era definit, in schimb erau folosite o serie de metode (incompatibile) pentru a simula acest tip de date. \n*       Constantele caracter (cuprinse intre apostrofuri) au dimensiunea unui int in C si char in C++. Cu alte cuvinte, in C, sizeof('a') == sizeof(int); in C++, sizeof('a') == sizeof(char). Chiar si in aceste conditii, valoarea acestui tip de constante nu va depasi valoarea maxima ce poata fi pastrata de char, deci o conversie de genul (char)'a' este sigura. \n*       Cuvinte cheie suplimentare au fost introduse in C++, deci acestea nu pot fi folosite ca identificatori asa cum ar putea fi folosite in C. (de exemplu, code>try, catch, template, new,delete, ...) \n*       In C++, compilatorul creeaza automat o „eticheta“ pentru orice structura (struct), uniune (union) sau enumeratie (enum), astfel incat struct S {}; in C++ este echivalent cu typedef struct S {} S; in C.";
	ShowSomeString(someString);
	someString = "         C99 a adoptat unele functionalitati ce au aparut initial in C++. Printre acestea se enumera:\n*       Declararea obligatorie a prototipului functiilor\n*       Cuvantul cheie \n*       Eliminarea variabilei implicite int ca valoare de intoarcere.";
	ShowSomeString(someString);
	someString = "         Ceea ce face C++ superior limbajul C, este multitudinea de functii,algoritmi,containere,structuri de date pe care C++ o aduce print STL (Standard Template Library).";
	ShowSomeString(someString);
	Trademark();
	WhaitUntilCommandIsPrompt();
}

void C_History()
{
	if (ReturnToMainWasPrompted())return;
	Console::Clear();
	Title("Limbajul C.  Istorie.  Caracteristici\0");
	string someString;
	cout << "\n";
	someString = "        C este un limbaj de programare standardizat, compilat, de nivel mediu. Este implementat pe majoritatea platformelor de calcul existente azi, si este cel mai popular limbaj de programare pentru scrierea de software de sistem. Este apreciat pentru eficienta codului obiect pe care il poate genera, si pentru portabilitatea sa. A fost dezvoltat la inceputul anilor 1970 de Ken Thompson si Dennis Ritchie, care aveau nevoie de un limbaj simplu si portabil pentru scrierea nucleului sistemului de operare UNIX. Sintaxa limbajului C a stat la baza multor limbaje create ulterior si inca populare azi: C++, Java, JavaScript, C#. C este un limbaj de programare relativ minimalist ce opereaza in stransa legatura cu hardware-ul, fiind cel mai apropiat de limbajul de asamblare fata de majoritatea celorlalte limbaje de programare.";
	ShowSomeString(someString);
	someString = "        C a fost creat avand drept scop important de a face ca programele mari sa poata fi scrise mai usor si cu mai putine erori in paradigma programarii procedurale, dar fara a pune un obstacole in scrierea compilatorului de C, care este incarcat de caracteristicile complexe ale limbajului. C are urmatoarele caracteristici importante: ";
	ShowSomeString(someString);
	someString = "\n       *Este un limbaj de baza simplu, cu importante functionalitati cum ar fi functiile matematice sau cele de manipulare ale fisierelor \n       *Este focalizat pe paradigma programarii procedurale, care faciliteaza programarea intr-un mod structurat \n       *Utilizeaza un set simplu de tipuri de date ce impiedica multe operatii neintentionate \n       *Foloseste un limbaj preprocesor, preprocesorul C, pentru sarcini cum ar fi definirea de macrouri si includerea mai multor fisiere sursa \n       *Permite accesarea la nivel scazut a memoriei calculatorului prin utilizarea pointerilor \n       *Permite folosirea parametrilor, care sunt comunicati functiilor prin valoare si nu prin referinta \n       *Pointeri la functii, ce permit forme rudimentare de inchidere si polimorfism  \n       *Declararea variabilelor \n       *Structuri de date sau tipuri de date agregate, definite de utilizator prin (struct), ce permit ca date inrudite sa fie combinate si manipulate ca un intreg";
	ShowSomeString(someString);
	someString = "        Printre caracteristicile ce lipsesc in C, dar care pot fi gasite in alte limbaje de programare se enumera:\n       *Un sistem automat de colectare a reziduurilor\n       *Clasele si obiectele (programarea orientata pe obiecte)\n       *Un sistem avansat de tipuri de date\n       *Programarea generica\n       *Supraincarcarea\n       *Metaprogramarea\n       *Suport nativ pentru programarea multithreaded si functiile de retea\n       *Procesarea listelor";
	ShowSomeString(someString);
	someString = "        Obs. Desi lista minusurilor limbajului C este destul de lunga, aceasta nu reprezinta un dezavantaj suficient de mare pentru inhiba utilizarea limbajului C in practica, deoarece permite ca noi compilatoare sa poata fi scrise pe noi tipuri de platforme si pentru ca permite programatorului sa tina bine sub control programul pe care il scrie. Acesta este unul din motivele care face ca un cod scris in C sa fie mult mai eficient decat daca ar fi scris in alte limbaje de programare. Numai un cod scris cu foarte mare grija intr-un limbaj de asamblare poate fi mai performant, deoarece are control integral asupra masinii, dar performanta avansata a compilatoarelor, combinata cu complexitatea noilor tipuri de procesoare, a facut ca limbajul C sa fie preferat si sa fie acceptat din ce in ce mai mult de programatori.Una din consecintele acceptarii si eficientei C-ului este aceea ca multe compilatoare, biblioteci si interpretoare ale limbajelor de nivel inalt sunt adesea implementate in C.";
	ShowSomeString(someString);
	Trademark();
	WhaitUntilCommandIsPrompt();
}

void ShowCppHeader()
{
	if (ReturnToMainWasPrompted())return;
	Console::Clear();
	cout << "\n";
	cout << "    Standardul limbajul C++ defineste 33 de headere.\n\n";
	cout << "    <algorithm>    <iomanip>    <list>      <queue>       <streambuf>\n";
	cout << "    <bitset>       <ios>        <locale>    <set>         <string>\n";
	cout << "    <complex>      <iosfwd>     <map>       <sstream>     <typeinfo>\n";
	cout << "    <deque>        <iostream>   <memory>    <stack>       <utility>\n";
	cout << "    <exception>    <istream>    <new>       <stdexcept>   <valarray>\n";
	cout << "    <fstream>      <iterator>   <numeric>   <strstream>   <vector>\n";
	cout << "    <functional>   <limits>     <ostream>\n";
	cout << "\n";
	Trademark();
	WhaitUntilCommandIsPrompt();
}

void ShowCHeader()
{
	if (ReturnToMainWasPrompted())return;
	Console::Clear();
	cout << "\n";
	cout << "    Facilitatile Bibliotecii C Standard sunt furnizate de 18 headere aditionale.\n\n";
	cout << "    <cassert>   <ciso646>   <csetjmp>   <cstdio>  <ctime>\n";
	cout << "    <cctype>    <climits>   <csignal>   <cstdlib> <cwchar>\n";
	cout << "    <cerrno>    <clocale>   <cstdarg>   <cstring> <cwctype>\n";
	cout << "    <cfloat>    <cmath>     <cstddef>\n";
	cout << "\n";
	Trademark();
	WhaitUntilCommandIsPrompt();
}

bool isPrime(const unsigned long long &X)
{
	if (X<2)return 0;
	if (X == 2)return 1;
	if (X % 2 == 0)return 0;
	int size = sqrt(X + 1);
	for (int i = 3; i <= size; i += 2)
		if (X % i == 0)return 0;
	return 1;
}

void Title(char* title)
{
	for (int i = (ScreenBuffer - strlen(title)) / 2; i > 0; --i)
		printf(" ");
	printf("%s\n", title);
}

void Trademark()
{
	char tradeMark[100] = "By Roxana Florentina Soare\0";
	printf("\n");
	for (int i = strlen(tradeMark) + 5; i < ScreenBuffer; i++)
		printf(" ");
	printf("%s\n\n", tradeMark);
}

