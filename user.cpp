#include"user.h"
#include<iostream>
using namespace std;
//基础数据处理
void User::SetData(int k)//设置账号密码
{
	cout << "账号" << endl;
	cin >> this->username;
	cout << "密码" << endl;
	cin >> this->password;
	this->kind = k;
}
void Person::SetData(int k)//设置个人信息
{
	cout << "姓名" << endl;
	cin >> this->name;
	cout << "年龄" << endl;
	cin >> this->age;
	cout << "性别" << endl;
	cin >> this->sex;
	cout << "联系方式" << endl;
	cin >> this->tel;
	this->User::SetData(k);
}
void Customer::SetData(int k)//设置用户信息
{
	this->Person::SetData(k);
	cout << "地址" << endl;
	cin >> this->address;
}
void Customer::SetData(Customer cus)//用户信息复制（可视化使用）
{
	this->username = cus.username;
	this->password = cus.password;
	this->kind = cus.kind;
	this->name = cus.name;
	this->age = cus.age;
	this->sex = cus.sex;
	this->tel = cus.tel;
	this->address = cus.address;
}
void Expressman::SetData(int k)//设置配送人员信息
{
	this->Person::SetData(k);
	cout << "工作时间" << endl;
	cin >> this->worktime;
}
void Expressman::SetData(Expressman cus)//配送人员复制函数（可视化使用）
{
	this->username = cus.username;
	this->password = cus.password;
	this->kind = cus.kind;
	this->name = cus.name;
	this->age = cus.age;
	this->sex = cus.sex;
	this->tel = cus.tel;
	this->worktime = cus.worktime;
	this->score = cus.score;
}
void Food::SetData()//设置菜品
{
	cout << "菜名" << endl;
	cin >> this->name;
	cout << "价格" << endl;
	cin >> this->price;
}
void Food::SetData(Food f)//菜品复制函数(可视化使用)
{
	this->name = f.name;
	this->price = f.price;
}
void Food::SetData(string na, float pr)//菜品设置函数
{
	this->name = na;
	this->price = pr;
}
void Shop::SetData(int k)//餐厅设置函数
{
	this->Person::SetData(k);
	cout << "菜品数量" << endl;
	cin >> this->fnumber;
	this->fhead = new Food[this->fnumber];
	for (int i = 0; i < this->fnumber; i++)
	{
		cout << "第" << i + 1 << "道菜" << endl;
		this->fhead[i].SetData();
	}
	cout << "分数" << endl;
	cin >>this->score ;
	cout << "折扣" << endl;
	cin >>this->discount;
	cout << "店名" << endl;
	cin >>this->shopname;
}
void Shop::SetData(Shop cus)//餐厅复制函数
{
	//cout << 1;
	this->username = cus.username;
	this->password = cus.password;
	this->kind = cus.kind;
	this->name = cus.name;
	this->age = cus.age;
	this->sex = cus.sex;
	this->tel = cus.tel;
	this->score = cus.score;
	this->discount = cus.discount;
	this->fnumber = cus.fnumber;
	//cout << 2;
	this->fhead = new Food[this->fnumber];
	//cout << 3;
	for (int i = 0; i < this->fnumber; i++)
	{
		//cout << 4;
		this->fhead[i].SetData(cus.fhead[i]);
	}
	this->shopname = cus.shopname;
}
void Order_form::SetData(Order_form o)//订单复制函数（可视化使用）
{
	this->number = o.number;
	this->cusname = o.cusname;
	this->manname = o.manname;
	this->shopname = o.shopname;
	this->cost = o.cost;
	this->flag = o.flag;
	this->fnum = o.fnum;
	this->fhead = new Food[this->fnum];
	for (int i = 0; i < this->fnum; i++)
	{
		//cout << 4;
		this->fhead[i].SetData(o.fhead[i]);
	}
}//订单由于并不在黑框下操作，所以未设置其他设置数据函数
//以下为展示各类详细数据的函数（订单未设计）
void User::Show()
{
	cout << "昵称：" << this->username << endl;
	switch (this->kind)
	{
	case 1:cout << "顾客" << endl; break;
	case 2:cout << "店铺" << endl; break;
	case 3:cout << "配送人员" << endl; break;
	}
}
void Person::Show()
{
	this->User::Show();
	cout << "姓名" << this->name << endl;
	cout << "年龄" << this->age << endl;
	cout << "性别" << this->sex << endl;
	cout << "联系方式" << this->tel << endl;
}
void Customer::Show()
{
	this->Person::Show();
	cout << "地址" << this->address << endl;
}
void Expressman::Show()
{
	this->Person::Show();
	cout << "工作时间" << this->worktime << endl;
}
void Food::Show()
{
	cout << "菜名" << this->name << endl;
	cout << "价格" << this->price << endl;
	cout << "---------------------------" << endl;
}
void Shop::Show()
{
	this->Person::Show();
	for (int i = 0; i < this->fnumber; i++)
	{
		cout << i+1 << ":"; this->fhead[i].Show();
	}
	cout << "评分" << this->score << endl;
	cout << "折扣" << this->discount << endl;
	cout << "店名" << this->shopname << endl;
}

int User::Login(string username, string password)//登陆验证函数
{
	//cout << this->password << endl;
	if (this->username == username && this->password == password)
	{
		return 1;
	}
	else return 0;
}
//--------------------------------------
//订单操作(主要通过可视化进行，以下函数未完善)
void Shop::Show_mian() 
{
	cout <<"餐厅名"<<this->shopname << endl;
	for (int i = 0; i < this->fnumber; i++)
	{
		this->fhead[i].Show();
		cout << "*********************" << endl;
	}
}
void Order_form::for_customer(Shop* Shead, int SN)
{
	int kind;
	Shop* point = new Shop;
	point = Shead->next;
	for (int i = 0; i < SN; i++)
	{
		cout << i + 1;
		point->Show_mian();
		point = point->next;
	}
	cout << "输入餐厅序号" << endl;
	cin >> kind;
	point = Shead->next;
	for (int i = 0; i < SN; i++)
	{
		if (i + 1 == kind)
		{
			for (int j = 0; j < point->fnumber; j++)
			{
				point->fhead[j].Show();
			}
		}
		point = point->next;
	}
	cout << "输入菜名序号" << endl;
	cin >> kind;

}
void Order_form::for_expressman() 
{

}
void Order_form::for_shop()
{

}
void Order_form::Setflag()
{

}

//--------------------------------------
//数据添加：一个参数为console使用，两个为可视化使用
void Register(Customer* c)
{
	Customer* p, *q;
	q = new Customer;
	if (q == NULL)
	{
		cout << "q->error" << endl;
	}
	for (q = c; q->next != NULL; q = q->next)
	{

	}
	p = new Customer;
	if (p == NULL)
	{
		cout << "p->error" << endl;
	}
	p->SetData(1);
	q->next = p;
}
void Register(Customer* c, Customer cus)
{
	Customer* p, * q;
	q = new Customer;
	if (q == NULL)
	{
		cout << "q->error" << endl;
	}
	for (q = c; q->next != NULL; q = q->next)
	{

	}
	p = new Customer;
	if (p == NULL)
	{
		cout << "p->error" << endl;
	}
	p->SetData(cus);
	q->next = p;
}
void Register(Expressman* c)
{
	Expressman* p, * q;
	q = new Expressman;
	if (q == NULL)
	{
		cout << "q->error" << endl;
	}
	for (q = c; q->next != NULL; q = q->next)
	{

	}
	p = new Expressman;
	if (p == NULL)
	{
		cout << "p->error" << endl;
	}
	p->SetData(3);
	q->next = p;
}
void Register(Expressman* c,Expressman exp)
{
	Expressman* p, * q;
	q = new Expressman;
	if (q == NULL)
	{
		cout << "q->error" << endl;
	}
	for (q = c; q->next != NULL; q = q->next)
	{

	}
	p = new Expressman;
	if (p == NULL)
	{
		cout << "p->error" << endl;
	}
	p->SetData(exp);
	q->next = p;
}
void Register(Shop* c)
{
	Shop* p, * q;
	q = new Shop;
	if (q == NULL)
	{
		cout << "q->error" << endl;
	}
	for (q = c; q->next != NULL; q = q->next)
	{

	}
	p = new Shop;
	if (p == NULL)
	{
		cout << "p->error" << endl;
	}
	p->SetData(2);
	q->next = p;
}
void Register(Shop* c, Shop s)
{
	Shop* p, * q;
	q = new Shop;
	if (q == NULL)
	{
		cout << "q->error" << endl;
	}
	for (q = c; q->next != NULL; q = q->next)
	{

	}
	p = new Shop;
	if (p == NULL)
	{
		cout << "p->error" << endl;
	}
	p->SetData(s);
	//cout << "re"<<endl;
	//p->Show();
	q->next = p;
}
void Register(Order_form* c, Order_form o)
{
	Order_form* p, * q;
	q = new Order_form;
	if (q == NULL)
	{
		cout << "q->error" << endl;
	}
	for (q = c; q->next != NULL; q = q->next)
	{

	}
	p = new Order_form;
	if (p == NULL)
	{
		cout << "p->error" << endl;
	}
	p->SetData(o);
	//cout << "re"<<endl;
	//p->Show();
	q->next = p;
}
//登录验证：一个参数为console使用，三个为可视化使用
int Login(Customer* c)
{
	string user,password;
	Customer* q;
	q = new Customer;
	if (q == NULL)
	{
		cout << "q->error" << endl;
	}
	cout << "输入昵称" << endl;
	cin >> user;
	cout << "输入密码" << endl;
	cin >> password;
	for (q = c; q->next != NULL; q = q->next)
	{
		if ((q->next->Login(user, password)) == 1)
		{
			return 1;
		}
	}
	return 0;
}
Customer* Login(Customer* c,string user,string password)
{
	
	Customer* q;
	q = new Customer;
	if (q == NULL)
	{
		cout << "q->error" << endl;
	}
	
	for (q = c; q->next != NULL; q = q->next)
	{
		//cout << q->next->Getuser() << endl;
		if ((q->next->Login(user, password)) == 1)
		{
			
			return q->next;
		}
	}
	return c;
}
int Login(Expressman* c)
{
	string user, password;
	Expressman* q;
	q = new Expressman;
	if (q == NULL)
	{
		cout << "q->error" << endl;
	}
	cout << "输入昵称" << endl;
	cin >> user;
	cout << "输入密码" << endl;
	cin >> password;
	for (q = c; q->next != NULL; q = q->next)
	{
		if ((q->next->Login(user, password)) == 1)
		{
			return 1;
		}
	}
	return 0;
}
Expressman* Login(Expressman* c,string user, string password)
{
	Expressman* q;
	q = new Expressman;
	if (q == NULL)
	{
		cout << "q->error" << endl;
	}
	for (q = c; q->next != NULL; q = q->next)
	{
		if ((q->next->Login(user, password)) == 1)
		{
			cout << 4;
			return q->next;
		}
	}
	return c;
}
int Login(Shop* c)
{
	string user, password;
	Shop* q;
	q = new Shop;
	if (q == NULL)
	{
		cout << "q->error" << endl;
	}
	cout << "输入昵称" << endl;
	cin >> user;
	cout << "输入密码" << endl;
	cin >> password;
	for (q = c; q->next != NULL; q = q->next)
	{
		if ((q->next->Login(user, password)) == 1)
		{
			return 1;
		}
	}
	return 0;
}
Shop* Login(Shop* c, string user, string password)
{
	Shop* q;
	q = new Shop;
	if (q == NULL)
	{
		cout << "q->error" << endl;
	}
	for (q = c; q->next != NULL; q = q->next)
	{
		if ((q->next->Login(user, password)) == 1)
		{
			return q->next;
		}
	}
	return c;
}
//相应的查询函数
Customer* Find(Customer* c, string user)//通过用户姓名
{
	Customer* q;
	q = new Customer;
	if (q == NULL)
	{
		cout << "q->error" << endl;
	}

	for (q = c; q->next != NULL; q = q->next)
	{
		//cout << q->next->Getuser() << endl;
		if (q->next->Getname() == user)
		{

			return q;
		}
	}
	return NULL;
}
Expressman* Find(Expressman* c, string user)//通过配送人员姓名
{
	Expressman* q;
	q = new Expressman;
	if (q == NULL)
	{
		cout << "q->error" << endl;
	}
	for (q = c; q->next != NULL; q = q->next)
	{
		if (q->next->Getname()==user)
		{
			return q;
		}
	}
	return NULL;
}
Shop* Find(Shop* c, string user)//通过店铺名
{
	Shop* q;
	q = new Shop;
	if (q == NULL)
	{
		cout << "q->error" << endl;
	}
	for (q = c; q->next != NULL; q = q->next)
	{
		if (q->next->Getshopname()==user)
		{
			return q;
		}
	}
	return NULL;
}
Order_form* Find(Order_form* c, int n)//通过订单编号
{
	Order_form* q;
	q = new Order_form;
	if (q == NULL)
	{
		cout << "q->error" << endl;
	}
	for (q = c; q->next != NULL; q = q->next)
	{
		if (q->next->Getnumber() == n)
		{
			return q;
		}
	}
	return NULL;
}
//部分输入检查函数（可视化使用）
Customer* Check(Customer* c, string user)
{
	Customer* q;
	q = new Customer;
	if (q == NULL)
	{
		cout << "q->error" << endl;
	}

	for (q = c; q->next != NULL; q = q->next)
	{
		//cout << q->next->Getuser() << endl;
		if (q->next->Getuser() == user)
		{

			return q;
		}
	}
	return NULL;
}
Expressman* Check(Expressman* c, string user)
{
	Expressman* q;
	q = new Expressman;
	if (q == NULL)
	{
		cout << "q->error" << endl;
	}
	for (q = c; q->next != NULL; q = q->next)
	{
		if (q->next->Getuser() == user)
		{
			return q;
		}
	}
	return NULL;
}
Shop* Check(Shop* c, string user)
{
	Shop* q;
	q = new Shop;
	if (q == NULL)
	{
		cout << "q->error" << endl;
	}
	for (q = c; q->next != NULL; q = q->next)
	{
		if (q->next->Getuser() == user)
		{
			return q;
		}
	}
	return NULL;
}
bool Check(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (!((str[i] >= 48 && str[i] <= 57) || (str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)))
		{
			cout << str[i];
			return false;
			
		}
		
	}
	return true;
}
//删除函数
int delet(Customer* c,int i)
{
	i--;
	if (c->next->next != NULL)
	{
		c->next = c->next->next;
	}
	else
	{
		c->next = NULL;
	}
	return i;
}
int delet(Shop* c, int i)
{
	i--;
	if (c->next->next != NULL)
	{
		c->next = c->next->next;
	}
	else
	{
		c->next = NULL;
	}
	return i;
}
int delet(Expressman* c, int i)
{
	i--;
	if (c->next->next != NULL)
	{
		c->next = c->next->next;
	}
	else
	{
		c->next = NULL;
	}
	return i;
}
int delet(Order_form* c, int i)
{
	i--;
	if (c->next->next != NULL)
	{
		c->next = c->next->next;
	}
	else
	{
		c->next = NULL;
	}
	return i;
}
//文件写入
void writeto(string filename,Customer* c, int i)
{
	//setlocale(LC_ALL, "Chinese-simplified");
	char* old_locale = _strdup(setlocale(LC_CTYPE, NULL));
	setlocale(LC_CTYPE, "chs");//设定
	Customer* q, * p;
	p = new Customer;
	if (p == NULL)
	{
		cout << "p->error" << endl;
	}
	ofstream file1(filename, ios_base::out);
	if (!file1)
	{
		cerr << " open error!" << endl;
		abort();//退出程序
	}
	file1 << i << endl;
	file1.close();
	ofstream file2(filename, ios::out | ios::_Nocreate | ios::app);
	if (!file2)
	{
		cerr << " open error!" << endl;
		abort();//退出程序
	}
	Customer cus;
	p = c; q = c->next;
	for (; q != NULL; q = q->next)
	{
		cout << "duru";
		//q->Show();
		file2 << *q;
	}
	file2.close();
	//setlocale(LC_ALL, "C");//还原
	setlocale(LC_CTYPE, old_locale);
	free(old_locale);//还原区域设定
}
void writeto(string filename, Expressman* c, int i)
{
	Expressman* q, * p;
	p = new Expressman;
	if (p == NULL)
	{
		cout << "p->error" << endl;
	}
	ofstream file1(filename, ios_base::out);
	if (!file1)
	{
		cerr << " open error!" << endl;
		abort();//退出程序
	}
	file1 << i << endl;
	file1.close();
	ofstream file2(filename, ios::out | ios::_Nocreate | ios::app);
	if (!file2)
	{
		cerr << " open error!" << endl;
		abort();//退出程序
	}
	Expressman cus;
	p = c; q = c->next;
	for (; q != NULL; q = q->next)
	{
		file2 << *q;
	}
	file2.close();
}
void writeto(string filename, Shop* c, int i)
{
	Shop* q, * p;
	p = new Shop;
	if (p == NULL)
	{
		cout << "p->error" << endl;
	}
	ofstream file1(filename, ios_base::out);
	if (!file1)
	{
		cerr << " open error!" << endl;
		abort();//退出程序
	}
	file1 << i << endl;
	file1.close();
	ofstream file2(filename, ios::out | ios::_Nocreate | ios::app);
	if (!file2)
	{
		cerr << " open error!" << endl;
		abort();//退出程序
	}
	Shop cus;
	p = c; q = c->next;
	for (; q != NULL; q = q->next)
	{
		//cout << "write" << endl;
		//q->Show();
		file2 << *q;
	}
	file2.close();
}
void writeto(string filename, Order_form* c, int i)
{
	Order_form* q, * p;
	p = new Order_form;
	if (p == NULL)
	{
		cout << "p->error" << endl;
	}
	ofstream file1(filename, ios_base::out);
	if (!file1)
	{
		cerr << " open error!" << endl;
		abort();//退出程序
	}
	file1 << i << endl;
	file1.close();
	ofstream file2(filename, ios::out | ios::_Nocreate | ios::app);
	if (!file2)
	{
		cerr << " open error!" << endl;
		abort();//退出程序
	}
	Order_form cus;
	p = c; q = c->next;
	for (; q != NULL; q = q->next)
	{
		//cout << "write" << endl;
		//q->Show();
		file2 << *q;
	}
	file2.close();
}
//文件读取
int readfrom(string filename,Customer* c)
{
	//setlocale(LC_ALL, "Chinese-simplified");//设置中文环境
	char* old_locale = _strdup(setlocale(LC_CTYPE, NULL));
	setlocale(LC_CTYPE, "chs");//设定
	
	int cn;
	ifstream file(filename, ios::in | ios::_Nocreate);
	if (!file)
	{
		cerr << " open error!" << endl;
		abort();//退出程序
	}
	file >> cn;
	Customer* q, * p;
	p = new Customer;
	if (p == NULL)
	{
		cout << "p->error" << endl;
	}
	p = c; int i;
	for (i = 0; cn != 0; cn--, i++)
	{
		q = new Customer;
		if (q == NULL)
		{
			cout << "q->error" << endl;
		}
		file >> *q;
		p->next = q;
		p = q;
	}
	cn = i;
	file.close();
	return cn;
	//setlocale(LC_ALL, "C");//还原
	setlocale(LC_CTYPE, old_locale);
	free(old_locale);//还原区域设定
}
int readfrom(string filename, Expressman* c)
{
	int cn;
	ifstream file(filename, ios::in | ios::_Nocreate);
	if (!file)
	{
		cerr << " open error!" << endl;
		abort();//退出程序
	}
	file >> cn;
	Expressman* q, * p;
	p = new Expressman;
	if (p == NULL)
	{
		cout << "p->error" << endl;
	}
	p = c; int i;
	for (i = 0; cn != 0; cn--, i++)
	{
		q = new Expressman;
		if (q == NULL)
		{
			cout << "q->error" << endl;
		}
		file >> *q;
		p->next = q;
		p = q;
	}
	cn = i;
	file.close();
	return cn;
}
int readfrom(string filename, Shop* c)
{
	int cn;
	ifstream file(filename, ios::in | ios::_Nocreate);
	if (!file)
	{
		cerr << " open error!" << endl;
		abort();//退出程序
	}
	file >> cn;
	Shop* q, * p;
	p = new Shop;
	if (p == NULL)
	{
		cout << "p->error" << endl;
	}
	p = c; int i;
	for (i = 0; cn != 0; cn--, i++)
	{
		q = new Shop;
		if (q == NULL)
		{
			cout << "q->error" << endl;
		}
		file >> *q;
		p->next = q;
		p = q;
	}
	cn = i;
	file.close();
	return cn;
}
int readfrom(string filename, Order_form* c)
{
	int cn;
	ifstream file(filename, ios::in | ios::_Nocreate);
	if (!file)
	{
		cerr << " open error!" << endl;
		abort();//退出程序
	}
	file >> cn;
	Order_form* q, * p;
	p = new Order_form;
	if (p == NULL)
	{
		cout << "p->error" << endl;
	}
	p = c; int i;
	for (i = 0; cn != 0; cn--, i++)
	{
		q = new Order_form;
		if (q == NULL)
		{
			cout << "q->error" << endl;
		}
		file >> *q;
		p->next = q;
		p = q;
	}
	cn = i;
	file.close();
	return cn;
}

