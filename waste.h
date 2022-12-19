#ifndef _WASTE_H_
#define _WASTE_H_

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
		
		Waste ();
		
}


class Glass: public Waste
{
	public:
		
		Waste ();
}


class Plastic: public Waste
{
	public:
		
		Waste ();
}


class Organic: public Waste
{
	public:
		
		Waste ();
};

#endif _WASTE_H_
