#pragma once
#include <string>
#include <iostream>
enum class TipModeda
{
	RON,
	EUR,
	USD
};
class ContBancar

{
private:
	std::string m_Nume;
	std::string m_Prenume;
	float m_sold;
	std::string m_IBAN;
	//TODO: Tipul soldului va trebui sa fie modificat intrun enum 0=ron 1=eur
	TipModeda m_tipSold;
public:
	ContBancar(std::string nume, std::string prenume, std::string IBAN);

	std::string getNume() const;
	std::string getPrenume() const;
	std::string getIban() const;
	float getSold() const;
	void depunere(float suma);
	void retragere(float suma);


};