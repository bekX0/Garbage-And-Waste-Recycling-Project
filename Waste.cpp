#include <string>
#include <iostream>


#include "Waste.h"

using namespace std;

Waste ::	Waste ()
		{
			price = 0;
			attributes = "default";
			weight = 0;
			amount = 0;
			value = 0;
		}
		
 Waste :: ~Waste () {}
		
 float Waste :: GetPrice (){
	return (price);
}
		
string Waste :: GetAttributes (){
	return (attributes);
}

float Waste :: GetValue ()
{
	return (value);
}
		
void Waste :: SetPrice (float x){
	price = x;  //TODO file yapilacak
}
		
void Waste :: SetAttributes (string att){
	attributes = att;
}
		
void Waste:: CalculateValue () {
	if (attributes == "default")
	{
		value = price * 1.0;
	}

	}



		
Paper :: Paper(){
	amount = 0;
	weight = 0;
	price = 0;
	attributes = "default";
	value = 0;			
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

float Paper :: GetValue ()
{
	return (value);
}

void Paper:: CalculateValue ()
{
		if (attributes == "default")
	{
		value = price * amount * 1.0;
	}
		else if (attributes == "Cardboard")
	{
		value = price * amount * 5.0;
	}

		else if (attributes == "Paper")
	{
		value = price * amount * 2;
	}

	else
	{
		value = price * amount * 1.0;
	}
}


		
Glass :: Glass(){
	amount = 0;
	weight = 0;
	price = 0;
	attributes = "default";
	value = 0;
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

float Glass :: GetValue ()
{
	return (value);
}

void Glass:: CalculateValue ()
{
		if (attributes == "default")
	{
		value = price * amount * 1.0;
	}
		else if (attributes == "Whole")
	{
		value = price * amount * 7.0;
	}

		else if (attributes == "Broken")
	{
		value = price * amount * 3.5;
	}
		else
	{
		value = price * amount * 1.0;
	}
}


		
Plastic :: Plastic(){
	amount = 0;
	weight = 0;
	price = 0;
	attributes = "default";
	value = 0;
}
		
Plastic :: ~Plastic (){}
		
int Plastic :: GetAmount(){
	return (amount);
}
		
void Plastic ::SetAmount (int z){
	amount = z;
}

void Plastic :: CalculateValue() 
{ 
	value = amount*price*1.0; 
}

string Plastic :: GetAttributes ()
{
	return (attributes);
}

void Plastic :: SetAttributes (string str)
{
	attributes = str;
}

float Plastic :: GetValue ()
{
	return (value);
}



Organic :: Organic(){
	weight = 0.0;
	price = 0;
	attributes = "default";
	value = 0;
}

Organic :: ~Organic () {}

void Organic:: CalculateValue ()
{
		if (attributes == "default")
	{
		value = price * weight * 1.0;
	}
		else if (attributes == "Fresh")
	{
		value = price * weight * 8.0;
	}

		else if (attributes == "Rotten")
	{
		value = price * weight * 4.5;
	}
		else
	{
		value = price * weight * 1.0;
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

float Organic :: GetValue ()
{
	return (value);
}

//düzenleme -berkin

void Waste :: SetAmount(int z) {this->amount=z;}
float Waste :: GetWeight() {return this->weight;}
void Waste :: SetWeight(float y) {this->weight= y;}
int Waste :: GetAmount() {return this->amount;}

