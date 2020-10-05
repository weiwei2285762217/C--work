#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include"widget.h"

using namespace std;
class User//账号密码基类
{
protected:
	string username, password;
	int kind;
public:
	User() { username = " "; password = " "; kind = 0; };
	User(string st1, string st2, int in) { username = st1, password = st2, kind = in; };
	void SetData(int kind);
	void Show();
	string Getuser() { return this->username; };
	int Getkind() { return this->kind; };
	string Getpassword(int i) { if (i == 567)return this->password; else return ""; };
	int Login(string username, string password);
};
class Person:public User//个人信息基类
{
protected:
	string name;
	string sex;
	int age;
	string tel;//联系方式
public:
	Person(string st1, string st2, int in,string str, string c, int i, string str2):User(st1,st2,in) { name = str; sex = c, age = i, tel = str2; };
	Person():User() { name = ""; sex = ""; age = 0; tel = "00000000000"; };
	void SetData(int kind);
	void Show();
	string Getname() { return this->name; };
	string Getsex() { return this->sex; };
	string Gettel() { return this->tel; };
	int Getage() { return this->age; };
	~Person() { cout << "本程序由季家伟8207190819编写" << endl; };
};
class Customer :virtual public Person//顾客类
{
	friend class Order_form;
	string address;//地址
public:
	Customer* next;
	Customer(string st1, string st2, int in, string str, string c, int i, string str2, string add) :Person(st1, st2, in, str, c, i, str2) { address = add; next = NULL; };
	Customer() :Person() { address = "  "; next = NULL;};
	void SetData(int kind);
	void SetData(Customer cus);
	void Show();
	string Getaddress() { return this->address; };
	friend ifstream& operator>>(ifstream& scin, Customer& cus) 
	{
		scin >> cus.name;
		scin >> cus.age;
		scin >> cus.sex;
		scin >> cus.tel;
		scin >> cus.address;
		scin >> cus.username;
		scin >> cus.password;
		scin >> cus.kind;
		return scin;
	};
	friend ofstream& operator<<(ofstream& scout, Customer& cus) 
	{
		scout << cus.name << endl;
		scout << cus.age << endl;
		scout << cus.sex << endl;
		scout << cus.tel << endl;
		scout << cus.address << endl;
		scout << cus.username << endl;
		scout << cus.password << endl;
		scout << cus.kind << endl;
		return scout;
	};
};
class Expressman :virtual public Person//配送人员类
{
	friend class Order_form;
	float score;//评分
	string worktime;
public:
	Expressman* next;
	Expressman(string st1, string st2, int in, string str, string c, int i, string str2, float sco, string time) :Person(st1, st2, in, str, c, i, str2) { score = sco; worktime = time; next = NULL; };
	Expressman() :Person() { score = 0.0; next = NULL; worktime = 0.0; };
	void SetData(int kind);
	void SetData(Expressman exp);
	void Show();
	string Gettime() { return this->worktime; };
	float Getscore() { return this->score; };
	friend ifstream& operator>>(ifstream& scin, Expressman& cus)
	{
		scin >> cus.name;
		scin >> cus.age;
		scin >> cus.sex;
		scin >> cus.tel;
		scin >> cus.worktime;
		scin >> cus.score;
		scin >> cus.username;
		scin >> cus.password;
		scin >> cus.kind;
		return scin;
	};
	friend ofstream& operator<<(ofstream& scout, Expressman& cus)
	{
		scout << cus.name << endl;
		scout << cus.age << endl;
		scout << cus.sex << endl;
		scout << cus.tel << endl;
		scout << cus.worktime << endl;
		scout << cus.score << endl;
		scout << cus.username << endl;
		scout << cus.password << endl;
		scout << cus.kind << endl;
		return scout;
	};
};
class Food//菜品类
{
	string name;
	float price;
public:
	Food(string str, float f) { name = str; price = f; };
	Food() { name = "", price = 0.0; };
	void Show();
	void SetData();
	void SetData(Food f);
	void SetData(string na, float pr);
	string Getname() { return this->name; };
	float Getprice() { return this->price; };
	~Food() {};
	friend ifstream& operator>>(ifstream& scin, Food& cus)
	{
		scin >> cus.name;
		scin >> cus.price;
		return scin;
	}
	friend ofstream& operator<<(ofstream& scout, Food& cus)
	{
		scout << cus.name << endl;
		scout << cus.price;
		return scout;
	}
};
class Shop:virtual public Person//店主类
{
	friend class Order_form;
	Food *fhead;
	int fnumber;
	float score; 
	float discount;
	string shopname;
public:
	Shop* next;
	Shop(string st1, string st2, int in, string str, string c, int i, string str2, float s1, float s2, string s3, Food * p,int foodnum) :Person(st1, st2, in,str,c,i,str2) { fhead = p; next = NULL; score = s1; discount = s2; shopname = s3, fnumber = foodnum; };
	Shop() :Person() { fhead = NULL; next = NULL; score = 0; discount = 0; shopname = " "; fnumber = 0; };
	void Show();
	void Show_mian();
	void SetData(int kind);
	void SetData(Shop s);
	float Getscore() { return this->score; };
	int Getfoodnum() { return this->fnumber; };
	float Getdiscount() { return this->discount; };
	string Getshopname() { return this->shopname; };
	Food* Getfood() { return this->fhead; };
	friend ifstream& operator>>(ifstream& scin, Shop& cus)
	{
		scin >> cus.fnumber;
		cus.fhead = new Food[cus.fnumber];
		for (int i = 0; i < cus.fnumber; i++)
		{
			scin >> cus.fhead[i];
		}
		scin >> cus.score;
		scin >> cus.discount;
		scin >> cus.shopname;
		scin >> cus.name;
		scin >> cus.age;
		scin >> cus.sex;
		scin >> cus.tel;
		scin >> cus.username;
		scin >> cus.password;
		scin >> cus.kind;
		return scin;
	}
	friend ofstream& operator<<(ofstream& scout, Shop& cus)
	{
		scout << cus.fnumber << endl;
		for (int i = 0; i < cus.fnumber; i++)
		{
			scout << cus.fhead[i] << endl;
		}
		scout << cus.score << endl;
		scout << cus.discount << endl;
		scout << cus.shopname << endl;
		scout << cus.name << endl;
		scout << cus.age << endl;
		scout << cus.sex << endl;
		scout << cus.tel << endl;
		scout << cus.username << endl;
		scout << cus.password << endl;
		scout << cus.kind << endl;
		return scout;
	}
};
class Order_form//订单类
{
	int number;
	string cusname;
	string manname;
	string shopname;
	Food* fhead;
	int fnum;
	float cost;
	int flag;//订单状态1下单2接受3收到
public:
	Order_form* next;
	Order_form() { number = 0; fhead = NULL; cost = 0; fnum = flag = 0; shopname = cusname = manname = ""; next = NULL; };
	Order_form(int num, string s1, string s2, string s3, int fn, Food* p, float c, int f) { number = num, cusname = s1, manname = s2, shopname =s3, fnum = fn, fhead = p, cost = c, flag = f; next = NULL; };
	void mark(int i) { this->flag = i; };
	void SetData(Order_form o);
	void for_customer(Shop* Chead,int SN);
	void for_shop();
	void for_expressman();
	void Setflag();
	string Getcusname() { return this->cusname; };
	string Getmanname() { return this->manname; };
	string Getshopname() { return this->shopname; };
	int Getnumber() { return this->number; };
	int Getfnum() { return this->fnum; };
	int Getflag() { return this->flag; };
	float Getcost() { return this->cost; };
	Food* Getfhead() { return this->fhead; };
	friend ifstream& operator>>(ifstream& scin, Order_form& cus)
	{
		scin >> cus.number;
		scin >> cus.fnum;
		cus.fhead = new Food[cus.fnum];
		for (int i = 0; i < cus.fnum; i++)
		{
			scin >> cus.fhead[i];
		}
		scin >> cus.cusname;
		scin >> cus.manname;
		scin >> cus.shopname;
		scin >> cus.cost;
		scin >> cus.flag;
		
		return scin;
	}
	friend ofstream& operator<<(ofstream& scout, Order_form& cus)
	{
		scout << cus.number << endl;
		scout << cus.fnum << endl;
		for (int i = 0; i < cus.fnum; i++)
		{
			scout << cus.fhead[i] << endl;
		}
		scout << cus.cusname << endl;
		scout << cus.manname << endl;
		scout << cus.shopname << endl;
		scout << cus.cost << endl;
		scout << cus.flag << endl;
		
		return scout;
	}

};