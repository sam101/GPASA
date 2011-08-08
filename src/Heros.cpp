#include <iostream>
#include <string>
#include "Heros.h"

Heros::Heros(std::string nomHeros) :
_ageHeros(0),
_vieHeros(0),
_manaHeros(0),
_enduranceHeros(0),
_points(0)
{
	_nomHeros = nomHeros;
}

std::string Heros::nomHeros()const
{
	std::string nom = _nomHeros;
	return nom;
}

std::string Heros::prenomHeros()const
{
	std::string prenom = _prenomHeros;
	return prenom;
}

int Heros::ageHeros()const
{
	int age = _ageHeros;
	return age;
}

int Heros::vieHeros()const
{
	int vie = _vieHeros;
	return vie;
}

int Heros::manaHeros()const
{
	int mana = _manaHeros;
	return mana;
}

int Heros::enduranceHeros()const
{
	int endurance = _enduranceHeros;
	return endurance;
}

std::string Heros::getMonde()const
{
	std::string monde = _monde;
	return monde;
}

std::string Heros::getZone()const
{
	std::string zone = _zone;
	return zone;
}

std::string Heros::getQuestion()const
{
	std::string question = _question;
	return question;
}

void Heros::setNomHeros(const std::string &nomHeros)
{
    _nomHeros = nomHeros;
}

void Heros::setPrenomHeros(const std::string &prenomHeros)
{
	_prenomHeros = prenomHeros;
}

void Heros::setAgeHeros(const int &ageHeros)
{
	_ageHeros = ageHeros;
}

void Heros::setVieHeros(const int &vieHeros)
{
	_vieHeros = vieHeros;
}

void Heros::setManaHeros(const int &manaHeros)
{
	_manaHeros = manaHeros;
}

void Heros::setEnduranceHeros(const int &enduranceHeros)
{
	_enduranceHeros = enduranceHeros;
}

void Heros::setMonde(const std::string &monde)
{
	_monde = monde;
}

void Heros::setZone(const std::string &zone)
{
	_zone = zone;
}

void Heros::setQuestion(const std::string &question)
{
	_question = question;
}

