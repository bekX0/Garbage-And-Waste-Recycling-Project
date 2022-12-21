#include <string>
#include <iostream>
#include "Waste.h"

using namespace std;

class Waste
{	

	protected:
		float price;
		string attributes;
        
	public:

		Waste ()
		{
			price = 0;
			attributes = "default";
		};
		
		virtual ~Waste ();
		
		virtual	float GetPrice ()
		{
			return (price);
		};
		
		virtual	string GetAttributes ()
		{
			return (attributes);
		};
		
		virtual	void SetPrice (float x)
		{
			price = x;
		};
		
		virtual	void SetAttributes (string att)
		{
			attributes = att;
		};
		
		virtual void CalculatePrice (float w, string str)
		{
			if (str == "default")
			{
				price = price * w * 1.0;
			}
			
			else if (str == "whole")
			{
				price = price * w * 4.0;
			}
			
			else if (str == "broken")
			{
				price = price * w * 2.0;
			}
			
			else if (str == "fresh")
			{
				price = price * w * 5.0;
			}
			
			else if (str == "rotten")
			{
				price = price * w * 2.0;
			}
			
		};
		
	
};

class Paper: public Waste
{
	private:
		int amount;
	
	public:
		
		Paper()
		{
			amount = 0;
		};
		
		~Paper ();
		
		int GetAmount ()
		{
			return (amount);
		};
		
		void SetAmount (int z)
		{
			amount = z;
		};
};


class Glass: public Waste
{
	private:
		int amount;
		
	public:
		
		Glass()
		{
			amount = 0;
		};
		
	    ~Glass ();
	    
	    int GetAmount ()
		{
			return (amount);
		};
		
		void SetAmount (int z)
		{
			amount = z;
		};

};


class Plastic : public Waste
{
	private:
		int amount;
		
	public:
		
		Plastic()
		{
			amount = 0;
		};
		
		~Plastic ();
		
		int GetAmount ()
		{
			return (amount);
		};
		
		void SetAmount (int z)
		{
			amount = z;
		};
};


class Organic: public Waste
{
	private:
		float weight;
		
	public:
		
		Organic()
		{
			weight = 0.0;
		};
		
		~Organic ();
		
		float GetWeight ()
		{
			return (weight);
		};
		
		void SetWeight (float y)
		{
			weight = y;
		};
};

