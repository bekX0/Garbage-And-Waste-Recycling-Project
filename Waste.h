#ifndef _WASTE_H_
#define _WASTE_H_
#include <string>

using namespace std;

class Waste
{	

	protected:
		float price;
		string attributes;
        
	public:

		Waste ();
		//virtual ~Waste ();
		
		virtual	float GetPrice ();
		virtual	string GetAttributes ();
		
		virtual	void SetPrice (float x);
		virtual	void SetAttributes (string att);
		
		virtual void CalculatePrice ();

		virtual int GetAmount ();
		virtual void SetAmount (int z);
		virtual float GetWeight ();
		virtual void SetWeight (float y);
		
	
};

class Paper: public Waste
{
	private:
		int amount;
	
	public:
		
		Paper();
		//~Paper ();
		
		void CalculatePrice ();
		int GetAmount ();
		void SetAmount (int z);
		string GetAttributes ();
		void SetAttributes (string str);
};


class Glass: public Waste
{
	private:
		int amount;
		
	public:
		
		Glass();
	    //~Glass ();
	    
		void CalculatePrice ();
	    int GetAmount ();
		void SetAmount (int z);
		string GetAttributes ();
		void SetAttributes (string str);
};


class Plastic: public Waste
{
	private:
		int amount;
		
	public:
		
		Plastic();
		//~Plastic ();
		
		void CalculatePrice ();
		int GetAmount ();
		void SetAmount (int z);
		string GetAttributes ();
		void SetAttributes (string str);
};


class Organic: public Waste
{
	private:
		float weight;
		
	public:
		
		Organic();
		//~Organic ();
		
		void CalculatePrice ();
		float GetWeight ();
		void SetWeight (float y);
		string GetAttributes ();
		void SetAttributes (string str);
};

 #endif //_WASTE_H_
