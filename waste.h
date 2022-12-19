#ifndef _WASTE_H_
#define _WASTE_H_
#include <string>

using namespace std;

class Waste
{	

	protected:

		double price;
		double weight;
		int amount;
		string attributes;
        
	public:

		Waste ();
		~Waste ();
		
		double GetPrice ();
		double GetWeight ();
		int GetAmount ();
		string GetAttributes ();
		
		void SetPrice (double x);
		void SetWeight (double y);
		void SetAmount (int z);
		void SetAttributes (string att);
	
};

class Paper: public Waste
{
	public:
		
		Paper();
		
};


class Glass: public Waste
{
	public:
		
		Glass();
};


class Plastic: public Waste
{
	public:
		
		Plastic();
};


class Organic: public Waste
{
	public:
		
		Organic();
};

 #endif _WASTE_H_
