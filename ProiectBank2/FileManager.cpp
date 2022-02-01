#include "FileManager.h"

void FileManager::WriteToCSV(std::string nume, std::string prenume, std::string iban)
{
	std::fstream csv_file;
	csv_file.open("ConturiDataBase.csv", std::ios::out | std::ios::app);
	if (csv_file.is_open())
	{
		csv_file << nume << ',' << prenume << ',' << iban << '\n';
	}
	else
	{
		std::cout << "Eroare, fille is not open!!!\n";
	}
}
