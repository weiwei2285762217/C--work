#include"user.h"
#include<iostream>
using namespace std;
//�������ݴ���
void User::SetData(int k)//�����˺�����
{
	cout << "�˺�" << endl;
	cin >> this->username;
	cout << "����" << endl;
	cin >> this->password;
	this->kind = k;
}
void Person::SetData(int k)//���ø�����Ϣ
{
	cout << "����" << endl;
	cin >> this->name;
	cout << "����" << endl;
	cin >> this->age;
	cout << "�Ա�" << endl;
	cin >> this->sex;
	cout << "��ϵ��ʽ" << endl;
	cin >> this->tel;
	this->User::SetData(k);
}
void Customer::SetData(int k)//�����û���Ϣ
{
	this->Person::SetData(k);
	cout << "��ַ" << endl;
	cin >> this->address;
}
void Customer::SetData(Customer cus)//�û���Ϣ���ƣ����ӻ�ʹ�ã�
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
void Expressman::SetData(int k)//����������Ա��Ϣ
{
	this->Person::SetData(k);
	cout << "����ʱ��" << endl;
	cin >> this->worktime;
}
void Expressman::SetData(Expressman cus)//������Ա���ƺ��������ӻ�ʹ�ã�
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
void Food::SetData()//���ò�Ʒ
{
	cout << "����" << endl;
	cin >> this->name;
	cout << "�۸�" << endl;
	cin >> this->price;
}
void Food::SetData(Food f)//��Ʒ���ƺ���(���ӻ�ʹ��)
{
	this->name = f.name;
	this->price = f.price;
}
void Food::SetData(string na, float pr)//��Ʒ���ú���
{
	this->name = na;
	this->price = pr;
}
void Shop::SetData(int k)//�������ú���
{
	this->Person::SetData(k);
	cout << "��Ʒ����" << endl;
	cin >> this->fnumber;
	this->fhead = new Food[this->fnumber];
	for (int i = 0; i < this->fnumber; i++)
	{
		cout << "��" << i + 1 << "����" << endl;
		this->fhead[i].SetData();
	}
	cout << "����" << endl;
	cin >>this->score ;
	cout << "�ۿ�" << endl;
	cin >>this->discount;
	cout << "����" << endl;
	cin >>this->shopname;
}
void Shop::SetData(Shop cus)//�������ƺ���
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
void Order_form::SetData(Order_form o)//�������ƺ��������ӻ�ʹ�ã�
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
}//�������ڲ����ںڿ��²���������δ���������������ݺ���
//����Ϊչʾ������ϸ���ݵĺ���������δ��ƣ�
void User::Show()
{
	cout << "�ǳƣ�" << this->username << endl;
	switch (this->kind)
	{
	case 1:cout << "�˿�" << endl; break;
	case 2:cout << "����" << endl; break;
	case 3:cout << "������Ա" << endl; break;
	}
}
void Person::Show()
{
	this->User::Show();
	cout << "����" << this->name << endl;
	cout << "����" << this->age << endl;
	cout << "�Ա�" << this->sex << endl;
	cout << "��ϵ��ʽ" << this->tel << endl;
}
void Customer::Show()
{
	this->Person::Show();
	cout << "��ַ" << this->address << endl;
}
void Expressman::Show()
{
	this->Person::Show();
	cout << "����ʱ��" << this->worktime << endl;
}
void Food::Show()
{
	cout << "����" << this->name << endl;
	cout << "�۸�" << this->price << endl;
	cout << "---------------------------" << endl;
}
void Shop::Show()
{
	this->Person::Show();
	for (int i = 0; i < this->fnumber; i++)
	{
		cout << i+1 << ":"; this->fhead[i].Show();
	}
	cout << "����" << this->score << endl;
	cout << "�ۿ�" << this->discount << endl;
	cout << "����" << this->shopname << endl;
}

int User::Login(string username, string password)//��½��֤����
{
	//cout << this->password << endl;
	if (this->username == username && this->password == password)
	{
		return 1;
	}
	else return 0;
}
//--------------------------------------
//��������(��Ҫͨ�����ӻ����У����º���δ����)
void Shop::Show_mian() 
{
	cout <<"������"<<this->shopname << endl;
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
	cout << "����������" << endl;
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
	cout << "����������" << endl;
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
//������ӣ�һ������Ϊconsoleʹ�ã�����Ϊ���ӻ�ʹ��
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
//��¼��֤��һ������Ϊconsoleʹ�ã�����Ϊ���ӻ�ʹ��
int Login(Customer* c)
{
	string user,password;
	Customer* q;
	q = new Customer;
	if (q == NULL)
	{
		cout << "q->error" << endl;
	}
	cout << "�����ǳ�" << endl;
	cin >> user;
	cout << "��������" << endl;
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
	cout << "�����ǳ�" << endl;
	cin >> user;
	cout << "��������" << endl;
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
	cout << "�����ǳ�" << endl;
	cin >> user;
	cout << "��������" << endl;
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
//��Ӧ�Ĳ�ѯ����
Customer* Find(Customer* c, string user)//ͨ���û�����
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
Expressman* Find(Expressman* c, string user)//ͨ��������Ա����
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
Shop* Find(Shop* c, string user)//ͨ��������
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
Order_form* Find(Order_form* c, int n)//ͨ���������
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
//���������麯�������ӻ�ʹ�ã�
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
//ɾ������
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
//�ļ�д��
void writeto(string filename,Customer* c, int i)
{
	//setlocale(LC_ALL, "Chinese-simplified");
	char* old_locale = _strdup(setlocale(LC_CTYPE, NULL));
	setlocale(LC_CTYPE, "chs");//�趨
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
		abort();//�˳�����
	}
	file1 << i << endl;
	file1.close();
	ofstream file2(filename, ios::out | ios::_Nocreate | ios::app);
	if (!file2)
	{
		cerr << " open error!" << endl;
		abort();//�˳�����
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
	//setlocale(LC_ALL, "C");//��ԭ
	setlocale(LC_CTYPE, old_locale);
	free(old_locale);//��ԭ�����趨
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
		abort();//�˳�����
	}
	file1 << i << endl;
	file1.close();
	ofstream file2(filename, ios::out | ios::_Nocreate | ios::app);
	if (!file2)
	{
		cerr << " open error!" << endl;
		abort();//�˳�����
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
		abort();//�˳�����
	}
	file1 << i << endl;
	file1.close();
	ofstream file2(filename, ios::out | ios::_Nocreate | ios::app);
	if (!file2)
	{
		cerr << " open error!" << endl;
		abort();//�˳�����
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
		abort();//�˳�����
	}
	file1 << i << endl;
	file1.close();
	ofstream file2(filename, ios::out | ios::_Nocreate | ios::app);
	if (!file2)
	{
		cerr << " open error!" << endl;
		abort();//�˳�����
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
//�ļ���ȡ
int readfrom(string filename,Customer* c)
{
	//setlocale(LC_ALL, "Chinese-simplified");//�������Ļ���
	char* old_locale = _strdup(setlocale(LC_CTYPE, NULL));
	setlocale(LC_CTYPE, "chs");//�趨
	
	int cn;
	ifstream file(filename, ios::in | ios::_Nocreate);
	if (!file)
	{
		cerr << " open error!" << endl;
		abort();//�˳�����
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
	//setlocale(LC_ALL, "C");//��ԭ
	setlocale(LC_CTYPE, old_locale);
	free(old_locale);//��ԭ�����趨
}
int readfrom(string filename, Expressman* c)
{
	int cn;
	ifstream file(filename, ios::in | ios::_Nocreate);
	if (!file)
	{
		cerr << " open error!" << endl;
		abort();//�˳�����
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
		abort();//�˳�����
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
		abort();//�˳�����
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

