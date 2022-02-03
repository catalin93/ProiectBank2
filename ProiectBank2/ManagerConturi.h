#pragma once
#include "ContBancar.h"
#include<vector>
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include"FileManager.h"



class ManagerConturi
{
private:
	std::vector<ContBancar*> m_listaConturi;
	std::string CreareIBAN();
	//TODO: Metoda trebuie sa creeze un iban unic care trebuie folosit pentru a crea conturi
	ContBancar* FindAcount();
	FileManager* m_fileManager;
public:
	void adaugareCont();
	int GetNumarConturi();
	void PrintAllConturi();
	void EraseAcount();
	void Eliberare_Depunere();
	ManagerConturi();
	~ManagerConturi();
};

std::string CreareIBAN();
