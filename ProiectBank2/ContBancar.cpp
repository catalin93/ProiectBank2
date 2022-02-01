#include "ContBancar.h"

ContBancar::ContBancar(std::string nume, std::string prenume, std::string IBAN)
{
	m_Nume = nume;
	m_Prenume = prenume;
	m_IBAN = IBAN;
	m_sold = 0;
	m_tipSold = TipModeda::RON;
}

std::string ContBancar::getNume() const
{
	return m_Nume;
}

std::string ContBancar::getPrenume() const
{
	return m_Prenume;
}

float ContBancar::getSold() const
{
	return m_sold;
}

std::string ContBancar::getIban() const
{
	return m_IBAN;
}
void ContBancar::depunere(float suma)
{
	m_sold += suma;
}

void ContBancar::retragere(float suma)
{
	m_sold += suma;
}
