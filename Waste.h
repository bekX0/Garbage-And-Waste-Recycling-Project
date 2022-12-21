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
		virtual ~Waste ();
		
		virtual	float GetPrice ();
		virtual	string GetAttributes ();
		
		virtual	void SetPrice (float x);
		virtual	void SetAttributes (string att);
		
		virtual void CalculatePrice (float w, string str);

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
		~Paper ();
		
		int GetAmount ();
		void SetAmount (int z);
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
};


class Organic: public Waste
{
	private:
		float weight;
		
	public:
		
		Organic();
		~Organic ();
		
		float GetWeight ();
		void SetWeight (float y);
		void Exchange (int b, string str);
};

 #endif //_WASTE_H_
