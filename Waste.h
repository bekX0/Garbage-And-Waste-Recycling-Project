#ifndef _WASTE_H_
#define _WASTE_H_



using namespace std;

class Waste
{	

	protected:
		float price;
		float weight;
		int amount;
		int value;
        string attributes;

	public:

		Waste ();
		virtual ~Waste ();
		
		virtual	float GetPrice ();
		virtual	string GetAttributes ();
		
		virtual	void SetPrice (float x);
		virtual	void SetAttributes (string att);
		
		virtual void CalculateValue () = 0;

		virtual int GetAmount ();
		virtual void SetAmount (int z);
		virtual float GetWeight ();
		virtual void SetWeight (float y);
		virtual float GetValue ();		
	
};

class Paper: public Waste
{
	private:
		//int amount;
	
	public:
		
		Paper();
		~Paper ();
		
		void CalculateValue ();
		int GetAmount ();
		void SetAmount (int z);
		float GetValue ();
		string GetAttributes ();
		void SetAttributes (string str);
		
};


class Glass: public Waste
{
	private:
		//int amount;
		
	public:
		
		Glass();
	    ~Glass ();
	    
		void CalculateValue ();
	    int GetAmount ();
		void SetAmount (int z);
		string GetAttributes ();
		void SetAttributes (string str);
		float GetValue ();
};


class Plastic: public Waste
{
	private:
		//int amount;
		
	public:
		
		Plastic();
		~Plastic ();
		
		void CalculateValue ();
		int GetAmount ();
		void SetAmount (int z);
		string GetAttributes ();
		void SetAttributes (string str);
		float GetValue ();
};


class Organic: public Waste
{
	private:
		float weight;
		
	public:
		
		Organic();
		~Organic ();
		
		void CalculateValue ();
		float GetWeight ();
		void SetWeight (float y);
		string GetAttributes ();
		void SetAttributes (string str);
		float GetValue ();
};

 #endif //_WASTE_H_
