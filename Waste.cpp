#include <string>
#include <iostream>


#include "Waste.h"

using namespace std;

Waste ::	Waste ()
		{
			price = 0;
			attributes = "default";
		}
		
 Waste :: ~Waste () {}
		
 float Waste :: GetPrice (){
	return (price);
}
		
string Waste :: GetAttributes (){
	return (attributes);
}
		
void Waste :: SetPrice (float x){
	price = x;
}
		
void Waste :: SetAttributes (string att){
	attributes = att;
}
		
void Waste:: CalculatePrice (){
	if (attributes == "default")
	{
		price = 1.0;
	}

	}



		
Paper :: Paper(){
	amount = 0;
	price = 0;
	attributes = "default";
}
		
Paper :: ~Paper (){}
		
int Paper :: GetAmount (){
	return (amount);
}
		
void Paper :: SetAmount (int z){
	amount = z;
}

string Paper :: GetAttributes ()
{
	return (attributes);
}

void Paper :: SetAttributes (string str)
{
	attributes = str;
}

void Paper:: CalculatePrice ()
{
		if (attributes == "default")
	{
		price = amount * 1.0;
	}
		else if (attributes == "Cardboard")
	{
		price = amount * 5.0;
	}

		else if (attributes == "Paper")
	{
		price = amount * 2;
	}

	else
	{
		price = amount * 1.0;
	}
}


		
Glass :: Glass(){
	amount = 0;
	price = 0;
	attributes = "default";
}
		
Glass :: ~Glass (){}
	    
int Glass::	GetAmount (){
	return (amount);
}
		
void Glass:: SetAmount (int z){
	amount = z;
}

string Glass :: GetAttributes ()
{
	return (attributes);
}

void Glass :: SetAttributes (string str)
{
	attributes = str;
}

void Glass:: CalculatePrice ()
{
		if (attributes == "default")
	{
		price = amount * 1.0;
	}
		else if (attributes == "Whole")
	{
		price = amount * 7.0;
	}

		else if (attributes == "Broken")
	{
		price = amount * 3.5;
	}
		else
	{
		price = amount * 1.0;
	}
}


		
Plastic :: Plastic(){
	amount = 0;
}
		
Plastic :: ~Plastic (){}
		
int Plastic :: GetAmount(){
	return (amount);
}
		
void Plastic ::SetAmount (int z){
	amount = z;
}

string Plastic :: GetAttributes ()
{
	return (attributes);
}

void Plastic :: SetAttributes (string str)
{
	attributes = str;
}



Organic :: Organic(){
	weight = 0.0;
	price = 0;
	attributes = "default";
}

Organic :: ~Organic () {}

void Organic:: CalculatePrice ()
{
		if (attributes == "default")
	{
		price = weight * 1.0;
	}
		else if (attributes == "Fresh")
	{
		price = weight * 8.0;
	}

		else if (attributes == "Rotten")
	{
		price = weight * 4.5;
	}
		else
	{
		price = weight * 1.0;
	}
}

float Organic :: GetWeight (){
	return (weight);
}

void Organic :: SetWeight (float y){
	weight = y;
}

string Organic :: GetAttributes ()
{
	return (attributes);
}

void Organic :: SetAttributes (string str)
{
	attributes = str;
}


