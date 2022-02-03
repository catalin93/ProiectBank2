#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include "ContBancar.h"

class FileManager
{
public:
	void WriteToCSV(std::string nume, std::string prenume, std::string iban, float sold);
	/*ContBancar* ReadContBancarFromCSV();*/


};

