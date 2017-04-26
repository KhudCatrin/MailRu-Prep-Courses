#ifndef _PHONE_H_
#define _PHONE_H_

namespace phone{

 class Phone {
 public:
	Phone (const char* number, const char* fname, const char* sname, 
		const char* lname, const char* address, double ttown, double tinter); 
	Phone (const Phone&);
	~Phone();
	Phone& operator= (Phone& p1);
	char* GetFname();
	char* GetSname();
	char* GetLname();
	char* GetAddress();
	double GetTtown();
	double GetTinter();
	void SetFname( char* val );
	void SetSname( char* val );
	void SetLname( char* val );
	void SetAddress( char* val );
	void SetTtown( double val );
	void SetTinter( double val );
	void AddTtown ( double val );
	void AddTinter ( double val );
	void Show();
	bool IsTtownMore(double val);
	bool IsUseTinter();
	char* number_;

 private:
	char* fname_;
	char* sname_;
	char* lname_ ;
	char* address_;
	double ttown_;
	double tinter_;
};

}
#endif //_PHONE_H_