#ifndef _WASTE_H_
#define _WASTE_H_
#include <string>

using namespace std;

class Waste
{	

	protected:
		double price;
		string attributes;
        
	public:

		Waste ();
		virtual ~Waste ();
		
		virtual	double GetPrice ();
		virtual	string GetAttributes ();
		
		virtual	void SetPrice (double x);
		virtual	void SetAttributes (string att);
		
		virtual void CalculatePrice (double w, string str);
		
	
};

class Paper: public Waste
{
	private:
		int amount;
	
	public:
		
		Paper();
		~Paper ();
		
		int GetAmount ();
		void SetAmount (int z);
		void Exchange (int a, string str);
};


class Glass: public Waste
{
	private:
		int amount;
		
	public:
		
		Glass();
	    ~Glass ();
	    
	    int GetAmount ();
		void SetAmount (int z);
		void Exchange (int a, string str);
};


class Plastic: public Waste
{
	private:
		int amount;
		
	public:
		
		Plastic();
		~Plastic ();
		
		int GetAmount ();
		void SetAmount (int z);
		void Exchange (int a, string str);
};


class Organic: public Waste
{
	private:
		double weight;
		
	public:
		
		Organic();
		~Organic ();
		
		double GetWeight ();
		void SetWeight (double y);
		void Exchange (int b, string str);
};

 #endif //_WASTE_H_
