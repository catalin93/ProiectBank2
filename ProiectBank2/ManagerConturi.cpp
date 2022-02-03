#include "ManagerConturi.h"




std::string ManagerConturi::CreareIBAN()
{
	std::string base = "RO44ItSchool";
	int tail;
	std::srand(time(0));
	tail = 10000 + (std::rand() % 99999);
	std::string tailString;
	tailString = std::to_string(tail);
	std::string body;
	body = base + tailString;

	for (auto& cont : m_listaConturi)
	{
		if (cont->getIban() == body)
		{
			return CreareIBAN();
		}
	}
	return body;
	
}

ContBancar* ManagerConturi::FindAcount()
{
	std::cout << "Numele titularului: \n";
	std::string nume;
	std::cin >> nume;
	//TODO: trebuie extins, fie facem o metoda care accepta nume sau prenume, fie facem cumva in aceasta metoda
	for (auto& cont : m_listaConturi)
	{
		if (cont->getNume() == nume)
			return cont;
	}
	std::cout << "Titularul contului nu a fost gasit \n";
	return nullptr;
}

void ManagerConturi::adaugareCont()
{
	std::string nume, prenume, iban;
	std::cout << "Introduceti numele dumneavoastra \n";
	std::cin >> nume;
	std::cout << "Introduceti prenumele dumneavoastra \n";
	std::cin >> prenume;
	//TODO: replace with create iban
	iban = CreareIBAN();
	ContBancar* cont = new ContBancar(nume, prenume, iban);

	m_listaConturi.push_back(cont);
	m_fileManager->WriteToCSV(nume, prenume, iban, cont->getSold());
	system("cls");
	
}

int ManagerConturi::GetNumarConturi()
{
	int n;
	n = m_listaConturi.size();
	return n;
}

void ManagerConturi::PrintAllConturi()
{
	/*for (auto it = m_listaConturi.begin(); it != m_listaConturi.end(); it++)
	{
		(*it)->getNume();
	}*/
	for (auto& cont : m_listaConturi)
	{
		std::cout << "Nume: " << cont->getNume() << std::endl;
		std::cout << "Prenume  " << cont->getPrenume() << std::endl;
		std::cout << "iban  " << cont->getIban() << std::endl;
	}
	std::cout << "Apasati tasta 0" << std::endl;
	char back;
	std::cin >> back;
}

void ManagerConturi::EraseAcount()
{
	std::cout << "Introduce-ti datele pentru contul ce urmeaza sa fie sters \n";
	ContBancar* cont = FindAcount();
	std::vector<ContBancar*>::iterator it = std::find(m_listaConturi.begin(), m_listaConturi.end(), cont);

	if (cont != nullptr)
	{
		m_listaConturi.erase(it);
		delete cont;
		system("cls");
	}
	else
	{
		system("cls");
	}
}

void ManagerConturi::Eliberare_Depunere()
{
	int valoare;
	std::cout << "Dati valoarea: ";
	std::cin >> valoare;
	ContBancar* cont = FindAcount();
	if (cont != nullptr)
	{
		cont->depunere(valoare);
	}
	else
	{
		cont->retragere(valoare);
	}
}

ManagerConturi::ManagerConturi()
{
	m_fileManager = new FileManager();
	//ContBancar* ptr = m_fileManager->ReadContBancarFromCSV();
	//while (ptr != nullptr)
	//{
	//	//populam lista conturi cu ce se afla in .csv
	//	m_listaConturi.push_back(ptr);
	//	ptr = m_fileManager->ReadContBancarFromCSV();
	//}
}

ManagerConturi::~ManagerConturi()
{
	delete m_fileManager;
}


