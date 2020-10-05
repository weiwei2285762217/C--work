#include"user.h"
#include<iostream>
#include<fstream>
using namespace std;
void Register(Customer*);
void Register(Customer*,Customer);
void Register(Expressman*);
void Register(Expressman*, Expressman);
void Register(Shop*);
void Register(Shop*, Shop);
void Register(Order_form*, Order_form);

int Login(Customer*);
Customer* Login(Customer*, string, string);
int Login(Expressman*);
Expressman* Login(Expressman*, string, string);
int Login(Shop*);
Shop* Login(Shop*, string, string);

Customer* Find(Customer* c, string user);
Expressman* Find(Expressman* c, string user);
Shop* Find(Shop* c, string user);
Order_form* Find(Order_form* c, int n);

int delet(Customer*, int);
int delet(Shop*, int);
int delet(Expressman*, int);
int delet(Order_form*, int);

Customer* Check(Customer* c, string user);
Expressman* Check(Expressman* c, string user);
Shop* Check(Shop* c, string user);
bool Check(string);

void writeto(string, Customer*,int);
int readfrom(string, Customer*);
void writeto(string, Expressman*, int);
int readfrom(string, Expressman*);
void writeto(string, Shop*, int);
int readfrom(string, Shop*);
void writeto(string, Order_form*, int);
int readfrom(string, Order_form*);
int main()
{
	//_set_error_mode(_OUT_TO_MSGBOX);
	//console����̨�ĵ�½ע�����
	if (false)
	{


		Customer* Chead = NULL; Expressman* Ehead = NULL; Shop* Shead = NULL; Order_form* Ohead = NULL;
		Chead = new Customer;
		Ehead = new Expressman;
		Shead = new Shop;
		Ohead = new Order_form;
		Order_form* p = new Order_form;
		if (Chead == NULL || Shead == NULL || Ehead == NULL || Ohead == NULL)
		{
			cout << "head->error" << endl;
		}
		int CN, EN, SN, ON; CN = EN = SN = ON = 0;
		int kind; string filename; filename = "customer.txt";
		CN = readfrom(filename, Chead);
		EN = readfrom("expressman.txt", Ehead);
		SN = readfrom("shop.txt", Shead);
	
		//--------------------------------------------------------------------------׼��
		cout << "��ӭʹ�õ��ϵͳ" << endl;
	begin:
		cout << "����1ע��2��½" << endl;
		int flag;
		cin >> flag;
		switch (flag)
		{
		case 1:cout << "ע��" << endl; goto reg; break;
		case 2:cout << "��½" << endl; goto log; break;
		}
	reg:
		cout << "����ע���û�����1�ͻ�2����3������Ա" << endl;
		cin >> kind;
		switch (kind)
		{
		case 1:Register(Chead); CN++; break;
		case 2:Register(Shead); SN++; break;
		case 3:Register(Ehead); EN++; break;
		default:cout << "error" << endl; goto reg;
		}
	log:
		cout << "ѡ������û����͵�½1�ͻ�2����3������Ա" << endl;
		cin >> kind;
		switch (kind)
		{
		case 1:kind = Login(Chead);
			if (kind == 0) { cout << "�˺Ż��������" << endl; goto begin; }
			else goto window1; break;
		case 2:kind = Login(Shead);
			if (kind == 0) { cout << "�˺Ż��������" << endl; goto begin; }
			else goto window2; break;
		case 3:kind = Login(Ehead);
			if (kind == 0) { cout << "�˺Ż��������" << endl; goto begin; }
			else goto window3; break;
		default:cout << "error" << endl; goto log;
		}
	window1:
		cout << "��½�ɹ����˿�" << endl;
		p->for_customer(Shead, SN);

	window2:
		cout << "��½�ɹ�������" << endl;


	window3:
		cout << "��½�ɹ������Ա" << endl;
		cout << "���յ��Ķ���" << endl;



		//-------------------------------------------------------------------------------����
		writeto(filename, Chead, CN);
		writeto("expressman.txt", Ehead, EN);
		writeto("shop.txt", Shead, SN);
		return 0;
	}
	//���ӻ�����
	//����׼��
	Customer* Chead = NULL; Expressman* Ehead = NULL; Shop* Shead = NULL; Order_form* Ohead = NULL;
	Chead = new Customer;
	Ehead = new Expressman;
	Shead = new Shop;
	Ohead = new Order_form;
	Order_form* p = new Order_form;
	if (Chead == NULL || Shead == NULL || Ehead == NULL || Ohead == NULL)
	{
		cout << "head->error" << endl;
	}
	int CN, EN, SN, ON; CN = EN = SN = ON = 0;
	int kind; string filename; filename = "customer.txt";
	CN = readfrom(filename, Chead);
	EN = readfrom("expressman.txt", Ehead);
	SN = readfrom("shop.txt", Shead);
	ON = readfrom("order.txt", Ohead);
	//����ͷָ��ͼ��������Լ��ļ�����
	Customer* point1 = Chead; Shop* point2 = Shead; Expressman* point3 = Ehead; Order_form* point4 = Ohead;//��ǰָ��
	Order_form* point5 = NULL;
	Customer* point6=NULL; Shop* point7 = NULL; Expressman* point8 = NULL;
	Order_form from;
	int yy1, xx1 = 60, fk;
	int checknum = 0, num2 = 0, num1=0;
	string foodkind;
	//�����м������м�����
	
	//��ʼ
	Widget w(352, 288);
	

login_window://��¼����
	
	MOUSEMSG mouse,mouse1,mouse2,mouse3;
	/*mouse1.x = 56; mouse1.y = 21; mouse1.mkLButton = true;
	mouse2.x = 136; mouse2.y = 21; mouse3.mkLButton = true;
	mouse3.x = 211; mouse3.y = 21; mouse3.mkLButton = true;*/
	int b1 ,b2 ,b3;
	b1 = b2 = b3 = 0;
	string user = "", password = "",name = "",sex = "",age="",tel="",adress="",dis="", s1,s2,s3,s4,s5,s6,s7,s8;
	string food[9],price[9];
	Food* p_food = new Food[8];
	for (int i = 0; i < 9; i++){food[i] = price[i] ="";}
	char a[10];
	int checkbox_flag = 0, check=0;
	for (; 1;)
	{
		mouse = GetMouseMsg();
		//cout << mouse.x << "/" << mouse.y << endl;
		/*if (w.set_checkbox(mouse, 55, 20, 75, 40, "�˿�"))
		{

			b1 = 1;
			cout << b1;
		}
		else b1 = 0;
		if (b2 = w.set_checkbox(mouse, 135, 20, 155, 40, "����"))
		{
			
			b2 = 2;
			cout << b2;
		}
		else b2 = 0;
		if (b3 = w.set_checkbox(mouse, 210, 20, 230, 40, "���Ա"))
		{
		
			b3 = 3;
			cout << b3;
		}
		else b3 = 0;*/
		/*if(w.set_checkbox(mouse, 55, 20, 75, 40, "�˿�"))
		{
			if (checkbox_flag == 2)
			{
				w.set_checkbox(mouse2, 135, 20, 155, 40, "����");
				cout << "A2"<<endl;
			}
			if (checkbox_flag == 3)
			{
				w.set_checkbox(mouse3, 210, 20, 230, 40, "���Ա");
				cout << "A3" << endl;
			}
			checkbox_flag = 1;
			cout << checkbox_flag;
		}
		if(w.set_checkbox(mouse, 135, 20, 155, 40, "����"))
		{
			if (checkbox_flag == 1)
			{
				cout << "B1" << endl;
				w.set_checkbox(mouse1, 55, 20, 75, 40, "�˿�");
			}
			if (checkbox_flag == 3)
			{
				cout << "B3" << endl;
				w.set_checkbox(mouse3, 210, 20, 230, 40, "���Ա");
			}
			checkbox_flag = 2;
			cout << checkbox_flag;
		}
		if(w.set_checkbox(mouse, 210, 20, 230, 40, "���Ա"))
		{
			if (checkbox_flag == 1)
			{
				cout << "C1" << endl;
				w.set_checkbox(mouse1, 55, 20, 75, 40, "�˿�");
			}
			if (checkbox_flag == 2)
			{
				cout << "C2" << endl;
				w.set_checkbox(mouse2, 135, 20, 155, 40, "����");
			}
			checkbox_flag = 3;
			cout << checkbox_flag;
		}*/
		
		w.set_title("��½");
		w.output("�û�����", 70, 80);
		w.output("��    �룺", 70, 125);
		s1 = w.cinbox(mouse, 130, 78, 266, 98, user);
		if (s1 != "")
		{
			user = s1;
			//cout << user;
		}
		s1 = w.cinbox(mouse, 130, 123, 266, 143, password);
		if (s1 != "")
		{
			password = s1;
			//cout << password;
		}
		if (w.set_button(mouse, 100, 170, 250, 190, "û���˺ţ����ע��"))
		{
			string message;
			message = w.message_info(a, 10, "��������Ҫע������1�˿�2����3���Ա");
			if (message == "1")
			{
				w.clear(); user = password = "";
				Widget w2(352, 469);
				goto rcustomer;
			}
			if (message == "2")
			{
				w.clear(); user = password = "";
				Widget w2(700, 514);
				goto rshop;
			}
			if (message == "3")
			{
				w.clear(); user = password = "";
				Widget w2(352, 469);
				goto rexpressman;
			}
		}

		if (w.set_button(mouse, 64, 214, 136, 234, "    �� ½    "))
		{
			if (check % 4 == 0)
			{
				if (user=="root"&&password=="root")
				{
					user = password = "";
					
					Widget w2(352, 469);
					w.play_music(1);
					goto root;
				}
				string message;
				message = w.message_info(a, 10, "�����������1�˿�2����3���Ա");
				if (message == "1")
				{
					if ((point1 = Login(Chead, user, password))->Getname()!="")
					{
						
						point1 = Login(Chead, user, password);
						//point1->Show();
						user = password = "";
						w.clear();
						Widget w2(352, 469);
						w.play_music(1);
						goto customer;
					}
					else
					{
						w.message_warn(a, 20, "�˺Ż��������");
						goto login_window;
					}
				}
				if (message == "2")
				{
					if (Login(Shead, user, password)->Getname() != "")
					{
						point2 = Login(Shead, user, password);
						user = password = "";
					
						w.clear();
						Widget w2(700, 514);
						w.play_music(1);
						goto shop;
					}
					else
					{
						w.message_warn(a, 20, "�˺Ż��������");
						goto login_window;
					}
				}
				if (message == "3")
				{
					if ((point3 = Login(Ehead, user, password))->Getname()!="")
					{
						
						point3 = Login(Ehead, user, password);
						user = password = "";
						w.clear();
						Widget w2(352, 469);
						w.play_music(1);
						goto expressman;
					}
					else
					{
						w.message_warn(a, 20, "�˺Ż��������");
						goto login_window;
					}
				}
			}
			check++;
		}

		if (w.set_button(mouse, 200, 214, 272, 234, "    �� ��    "))
		{
			if (check% 4 == 0)
			{
				if (w.message_question(a, 10, "ȷ���˳���"))
				{
					w.delet();
					goto end;
				}
			}
			check++;
			
		}
		

	}
	
//-------------------------------------------------
root://����Ա��½����
	w.set_title("�𾴵Ĺ���Ա������");
	for (; 1;)
	{
		mouse = GetMouseMsg();
		w.output("ѡ����Ҫ�鿴������",100,80);
		int rx1 = 126, rx2 = 85, ry1=120, ry2=ry1+20;
		if (w.set_button(mouse,rx1,ry1, rx1+rx2,ry2," �鿴  �ͻ� "))
		{
			if (check % 4 == 0)
			{
				Widget w2(352, 469);
				goto show_c;
			}
			check++;
		}
		if (w.set_button(mouse, rx1, ry1+=50, rx1 + rx2, ry2+=50, " �鿴  �̵� "))
		{
			if (check % 4 == 0)
			{
				Widget w2(352, 469);
				goto show_s;
			}
			check++;
		}
		if (w.set_button(mouse, rx1, ry1 += 50, rx1 + rx2, ry2 += 50, "�鿴���Ա"))
		{
			if (check % 4 == 0)
			{
				Widget w2(352, 469);
				goto show_e;
			}
			check++;
		}
		if (w.set_button(mouse, rx1, ry1 += 50, rx1 + rx2, ry2 += 50, " �鿴  ���� "))
		{
			if (check % 4 == 0)
			{
				Widget w2(352, 469);
				goto orderfrom_r;
			}
			check++;
		}
		if (w.set_button(mouse, rx1, ry1 += 50, rx1 + rx2, ry2 += 50, "     ��  ��     "))
		{
			
				w.clear();
				Widget w(352, 288);
				goto login_window;
			
		}
	}
	getchar();

show_c://���пͻ���Ϣ
	w.set_title("�鿴�ͻ�");
	num2 = 0;
	
	for (; 1;)
	{

		point6 = new Customer;
		point1 = Chead->next;
		for (int i = 0; point1 != NULL && i < CN; point1 = point1->next, i++)
		{
			if (point1->Getname() == user)
			{
				cout << user;
				cout << "ע��";
				Customer orderform = *point1;
				Register(point6, orderform);
			}
			if (i == CN)
			{
				point1 = NULL;
			}
		}
		if (point6->next== NULL)
		{
			point1 = Chead->next;
		}
		else
		{
			point1 = point6->next;
		}
		for (int i = 1; i <= 8 * num2; i++, point1 = point1->next)
		{

		}
		mouse = GetMouseMsg();
		w.set_button(mouse, 90, 40, 157, 60, "�ͻ�����");
		w.set_button(mouse, 215, 40, 250, 60, "��ַ");
		w.output("����", 218, 4);
		s1=w.cinbox(mouse,253,1,353,21,user);
		if (s1 != "")
		{
			user = s1;
			if (Find(Chead, user) == NULL)
			{
				user = "δ��ѯ��";

			}
			else
			{
				w.clear();
				Widget w2(352, 469);
				goto show_c;
				
				
				
			}
		}
		for (int i = 1, num1 = num2 * 8 + 1; i <= 8 && point1 != NULL; num1++, i++, point1 = point1->next)
		{

			w.set_button(mouse, 40, 40 + 40 * i, xx1 + 10, 40 * i + 60, to_string(num1));
			if (w.set_button(mouse, xx1, 40 + 40 * i, xx1 + 120, 40 * i + 60, point1->Getname()))
			{
				Widget w2(352, 469);
				goto show_c2;
			}
			w.set_button(mouse, xx1 + 140, 40 + 40 * i, xx1 + 210, 40 * i + 60, point1->Getaddress().substr(0, point1->Getaddress().length()- (point1->Getaddress().length()-6)));
			if (w.set_button(mouse, xx1 + 235, 40 + 40 * i, xx1 + 275, 40 * i + 60, "ɾ��"))
			{
				if (check % 4 == 0)
				{
					if (w.message_question(a, 20, "ȷ��ɾ��"))
					{
						delet(Find(Chead, point1->Getname()), CN);
						w.clear();
						check++;
						break;
						//Widget w2(352, 469);
						//goto show_c;
						
					}
					cout << num1;
				}
				check++;
				cout << check;
			}
		}
		if (w.set_button(mouse, 40, 400, 110, 420, "  ��һҳ  "))
		{
			if (checknum % 4 == 0 && num2 > 0)
			{
				w.clear();

				num2--;
				//cout << num2;
			}
			checknum++;
		}
		if (w.set_button(mouse, 215, 400, 285, 420, "  ��һҳ  "))
		{
			if (checknum % 4 == 0 && (8 * num2 < CN - 8))
			{
				w.clear();
				num2++;
				//cout << num2;
			}
			checknum++;
		}
		if (w.set_button(mouse, 130, 400, 195, 420, "   �� ��   "))
		{
			user = "";
			Widget w2(352, 469);
			goto root;
		}

	}
	getchar();
show_c2://�鿴ĳһ�ͻ���Ϣ
	w.set_title("�װ��Ĺ˿ͣ�����");
	user = point1->Getuser();
	password = point1->Getpassword(567);
	name = point1->Getname();
	age = to_string(point1->Getage());
	sex = point1->Getsex();
	tel = point1->Gettel();
	adress = point1->Getaddress();
	for (; 1;)
	{
		mouse = GetMouseMsg();
		w.output("��        �ţ�", 70, 80);
		w.output("��        �룺", 70, 125);
		w.output("��        ����", 70, 170);
		w.output("��        �䣺", 70, 215);
		w.output("��        ��", 70, 260);
		w.output("��ϵ��ʽ��", 70, 305);
		w.output("��        ַ��", 70, 350);
		s1 = w.cinbox(mouse, 145, 78, 266, 98, user);
		if (s1 != "")
		{
			if (Check(Chead, s1) == NULL)
			{
				//cout << Check(Chead, s1)->next->Getuser();
				user = s1;
			}
			else
			{
				w.play_music(2);
				w.message_warn(a, 20, "���˺��Ѵ���");

			}
		}
		s1 = w.cinbox(mouse, 145, 123, 266, 143, password);
		if (s1 != "")
		{
			if (s1.length() < 6)
			{
				w.message_warn(a, 20, "��������ڵ���6λ");
			}
			else if (Check(s1))
			{
				password = s1;
			}
			else
			{
				w.message_warn(a, 20, "��������ĸ��������Ϊ����");
			}
		}
		s1 = w.cinbox(mouse, 145, 168, 266, 188, name);
		if (s1 != "")
		{
			int j = 0;
			for (int i = 0; i < s1.length(); i++)
			{
				if ((s1[i] > 64 && s1[i] < 91) || (s1[i] > 96 && s1[i] < 123) || (s1[i] <= 0 && s1[i] > -90))
				{

				}
				else j = 1;
			}
			if (j == 0 && s1.length() > 3)
			{
				name = s1;
			}
			else w.message_warn(a, 20, "��������ȷ����");
		}
		s1 = w.cinbox(mouse, 145, 214, 266, 234, age);
		if (s1 != "")
		{
			if ((s1 >= "10" && s1.length() == 2) || (s1 <= "120" && s1.length() == 3))
			{


				age = s1;
			}
			else w.message_warn(a, 20, "��������ȷ����");
		}
		s1 = w.cinbox(mouse, 145, 258, 266, 278, sex);
		if (s1 != "")
		{
			if (s1 == "woman" || s1 == "man" || s1 == "Ů" || s1 == "��" || s1 == "male" || s1 == "female")
			{
				sex = s1;
			}
			else w.message_warn(a, 20, "��������ȷ�Ա�");
		}
		s1 = w.cinbox(mouse, 145, 303, 266, 323, tel);
		if (s1 != "")
		{
			int j = 0;
			for (int i = 0; i < s1.length(); i++)
			{
				if (s1[i] < 48 || s1[i]>57)
				{
					j = 1;
				}
			}
			if (j == 0 && s1.length() == 11)
			{
				tel = s1;
			}
			else w.message_warn(a, 20, "��������ȷ�ֻ���");
		}
		s1 = w.cinbox(mouse, 145, 348, 266, 368, adress);
		if (s1 != "")
		{
			adress = s1;
		}

		if (w.set_button(mouse, 64, 395, 136, 415, "    �� ��    "))
		{
			int iage = stoi(age);
			password = point1->Getpassword(567);
			Customer customer(user, password, 1, name, sex, iage, tel, adress);
			//customer.Show();
			point1->SetData(customer);
			//point1->Show();
			//customer.Show();
			//pcus->Show();
		}
		if (w.set_button(mouse, 200, 395, 272, 415, "    �� ��    "))
		{
			Widget w2(352, 469);
			user = password = name = age = sex = tel = adress = "";
			goto show_c;
		}
		
	}
	getchar();
show_s://���е�����Ϣ
	w.set_title("�鿴����");
	num2 = 0;
	for (; 1;)
	{
		point7 = new Shop;
		point2 = Shead->next;
		for (int i = 0; point2 != NULL && i < CN; point2 = point2->next, i++)
		{
			if (point2->Getshopname() == user)
			{
				cout << user;
				cout << "ע��";
				Shop orderform = *point2;
				Register(point7, orderform);
			}
			if (i == CN)
			{
				point2 = NULL;
			}
		}
		if (point7->next == NULL)
		{
			cout << 1;
			point2 = Shead->next;
		}
		else
		{
			cout << 2;
			point2 = point7->next;
		}
		for (int i = 1; i <= 8 * num2; i++, point2 = point2->next)
		{

		}
		mouse = GetMouseMsg();
		w.set_button(mouse, 90, 40, 157, 60, "��������");
		w.set_button(mouse, 215, 40, 250, 60, "����");
		w.output("����", 218, 4);
		s1 = w.cinbox(mouse, 253, 1, 353, 21, user);
		if (s1 != "")
		{
			user = s1;
			if (Find(Shead, user) == NULL)
			{
				user = "δ��ѯ��";

			}
			else
			{
				w.clear();
				Widget w2(352, 469);
				goto show_s;



			}
		}
		for (int i = 1, num1 = num2 * 8 + 1; i <= 8 && point2 != NULL; num1++, i++, point2 = point2->next)
		{

			w.set_button(mouse, 40, 40 + 40 * i, xx1 + 10, 40 * i + 60, to_string(num1));
			if (w.set_button(mouse, xx1, 40 + 40 * i, xx1 + 120, 40 * i + 60, point2->Getshopname()))
			{
				Widget w2(700, 514);
				goto show_s2;
			}
			w.set_button(mouse, xx1 + 140, 40 + 40 * i, xx1 + 210, 40 * i + 60, to_string(point2->Getscore()));
			if (w.set_button(mouse, xx1 + 235, 40 + 40 * i, xx1 + 275, 40 * i + 60, "ɾ��"))
			{
				if (check % 4 == 0)
				{
					if (w.message_question(a, 20, "ȷ��ɾ��"))
					{
						delet(Find(Shead, point2->Getshopname()), SN);
						w.clear();
						check++;
						break;
						//Widget w2(352, 469);
						//goto show_c;

					}
					//cout << num1;
				}
				check++;
				//cout << check;
			}
		}
		if (w.set_button(mouse, 40, 400, 110, 420, "  ��һҳ  "))
		{
			if (checknum % 4 == 0 && num2 > 0)
			{
				w.clear();

				num2--;
				//cout << num2;
			}
			checknum++;
		}
		if (w.set_button(mouse, 215, 400, 285, 420, "  ��һҳ  "))
		{
			if (checknum % 4 == 0 && (8 * num2 < SN - 8))
			{
				w.clear();
				num2++;
				//cout << num2;
			}
			checknum++;
		}
		if (w.set_button(mouse, 130, 400, 195, 420, "   �� ��   "))
		{
			user = "";
			Widget w2(352, 469);
			goto root;
		}

	}
	getchar();
show_s2://��ʾĳһ������Ϣ
	w.set_title("�װ��ĵ���������");
	user = point2->Getuser();
	password = point2->Getpassword(567);
	name = point2->Getname();
	age = to_string(point2->Getage());
	sex = point2->Getsex();
	tel = point2->Gettel();
	adress = point2->Getshopname();
	dis = to_string(point2->Getdiscount());
	p_food = point2->Getfood();
	for (int i = 0; i < point2->Getfoodnum(); i++)
	{
		food[i] = p_food[i].Getname();
		price[i] = to_string(p_food[i].Getprice()).substr(0,5);
	}
	for (; 1;)
	{
		mouse = GetMouseMsg();
		w.output("��        �ţ�", 70, 80);
		w.output("��        �룺", 70, 125);
		w.output("��        ����", 70, 170);
		w.output("��        �䣺", 70, 215);
		w.output("��        ��", 70, 260);
		w.output("��ϵ��ʽ��", 70, 305);
		w.output("�̵����ƣ�", 70, 350);
		w.output("�̵��ۿۣ�", 70, 395);

		s1 = w.cinbox(mouse, 145, 78, 266, 98, user);
		if (s1 != "")
		{
			user = s1;
		}
		s1 = w.cinbox(mouse, 145, 123, 266, 143, password);
		if (s1 != "")
		{
			password = s1;
		}
		s1 = w.cinbox(mouse, 145, 168, 266, 188, name);
		if (s1 != "")
		{
			name = s1;
		}
		s1 = w.cinbox(mouse, 145, 214, 266, 234, age);
		if (s1 != "")
		{
			age = s1;
		}
		s1 = w.cinbox(mouse, 145, 258, 266, 278, sex);
		if (s1 != "")
		{
			sex = s1;
		}
		s1 = w.cinbox(mouse, 145, 303, 266, 323, tel);
		if (s1 != "")
		{
			tel = s1;
		}
		s1 = w.cinbox(mouse, 145, 348, 266, 368, adress);//����
		if (s1 != "")
		{
			adress = s1;
		}
		s1 = w.cinbox(mouse, 145, 393, 266, 413, dis);//�ۿ�
		if (s1 != "")
		{
			dis = s1;
		}

		w.output("��Ʒ1��", 400, 80);
		w.output("��Ʒ2��", 400, 125);
		w.output("��Ʒ3��", 400, 170);
		w.output("��Ʒ4��", 400, 215);
		w.output("��Ʒ5��", 400, 260);
		w.output("��Ʒ6��", 400, 305);
		w.output("��Ʒ7��", 400, 350);
		w.output("��Ʒ8��", 400, 395);
		w.output("�۸�", 595, 50);
		s1 = w.cinbox(mouse, 455, 78, 575, 98, food[0]);
		if (s1 != "")
		{
			food[0] = s1;
		}
		s1 = w.cinbox(mouse, 455, 123, 575, 143, food[1]);
		if (s1 != "")
		{
			food[1] = s1;
		}
		s1 = w.cinbox(mouse, 455, 168, 575, 188, food[2]);
		if (s1 != "")
		{
			food[2] = s1;
		}
		s1 = w.cinbox(mouse, 455, 214, 575, 234, food[3]);
		if (s1 != "")
		{
			food[3] = s1;
		}
		s1 = w.cinbox(mouse, 455, 258, 575, 278, food[4]);
		if (s1 != "")
		{
			food[4] = s1;
		}
		s1 = w.cinbox(mouse, 455, 303, 575, 323, food[5]);
		if (s1 != "")
		{
			food[5] = s1;
		}
		s1 = w.cinbox(mouse, 455, 348, 575, 368, food[6]);
		if (s1 != "")
		{
			food[6] = s1;
		}
		s1 = w.cinbox(mouse, 455, 393, 575, 413, food[7]);
		if (s1 != "")
		{
			food[7] = s1;
		}
		s1 = w.cinbox(mouse, 593, 78, 673, 98, price[0]);
		if (s1 != "")
		{
			price[0] = s1;
		}
		s1 = w.cinbox(mouse, 593, 123, 673, 143, price[1]);
		if (s1 != "")
		{
			price[1] = s1;
		}
		s1 = w.cinbox(mouse, 593, 168, 673, 188, price[2]);
		if (s1 != "")
		{
			price[2] = s1;
		}
		s1 = w.cinbox(mouse, 593, 214, 673, 234, price[3]);
		if (s1 != "")
		{
			price[3] = s1;
		}
		s1 = w.cinbox(mouse, 593, 258, 673, 278, price[4]);
		if (s1 != "")
		{
			price[4] = s1;
		}
		s1 = w.cinbox(mouse, 593, 303, 673, 323, price[5]);
		if (s1 != "")
		{
			price[5] = s1;
		}
		s1 = w.cinbox(mouse, 593, 348, 673, 368, price[6]);
		if (s1 != "")
		{
			price[6] = s1;
		}
		s1 = w.cinbox(mouse, 593, 393, 673, 413, price[7]);
		if (s1 != "")
		{
			price[7] = s1;
		}

		if (w.set_button(mouse, 114, 440, 186, 460, "    �� ��    "))
		{
			float disc = stof(dis);
			int iage = stoi(age);
			int foodnum = 0;
			Food* pfood = new Food[8];
			for (int i = 0; i < 8; i++)
			{
				if (food[i] != "" && price[i] != "")
				{
					cout << "food";
					float pr = stof(price[i]);
					pfood[i].SetData(food[i], pr);
					foodnum++;
				}
			}
			password = point2->Getpassword(567);
			Shop customer(user, password, 2, name, sex, iage, tel, 2.5, disc, adress, pfood, foodnum);
			point2->SetData(customer);
			//Shop(string st1, string st2, int in, string str, string c, int i, string str2, float s1, float s2, string s3, Food * p,int foodnum) :
			//Shop* pcus = &customer;
			//cout << "r" << endl;
			//customer.Show();
			//Register(Shead, customer);//����ֵĶ������⣬����iageȫ��д���ļ���ʧ���ݡ�
			//cout << "reg" << endl;
			//pcus->Show();
			Widget w(352, 288);
			goto login_window;
		}
		if (w.set_button(mouse, 500, 440, 572, 460, "    �� ��    "))
		{
			Widget w2(352, 469);
			user = password = name = age = sex = tel = adress = dis = "";
			goto show_s;
		}
	}
	getchar();
show_e://����������Ա��Ϣ
	w.set_title("�鿴���Ա");
	num2 = 0;
	for (; 1;)
	{
		point8 = new Expressman;
		point3 = Ehead->next;
		for (int i = 0; point3 != NULL && i < CN; point3 = point3->next, i++)
		{
			if (point3->Getname() == user)
			{
				cout << user;
				cout << "ע��";
				Expressman orderform = *point3;
				Register(point8, orderform);
			}
			if (i == CN)
			{
				point3 = NULL;
			}
		}
		if (point8->next == NULL)
		{
			point3 = Ehead->next;
		}
		else
		{
			point3 = point8->next;
		}
		for (int i = 1; i <= 8 * num2; i++, point3 = point3->next)
		{

		}
		
		
		mouse = GetMouseMsg();
		w.set_button(mouse, 90, 40, 157, 60, "��Ա����");
		w.set_button(mouse, 215, 40, 250, 60, "ʱ��");
		w.output("����", 218, 4);
		s1 = w.cinbox(mouse, 253, 1, 353, 21, user);
		if (s1 != "")
		{
			user = s1;
			if (Find(Ehead, user) == NULL)
			{
				user = "δ��ѯ��";

			}
			else
			{
				w.clear();
				Widget w2(352, 469);
				goto show_e;



			}
		}
		for (int i = 1, num1 = num2 * 8 + 1; i <= 8 && point3 != NULL; num1++, i++, point3 = point3->next)
		{

			w.set_button(mouse, 40, 40 + 40 * i, xx1 + 10, 40 * i + 60, to_string(num1));
			if (w.set_button(mouse, xx1, 40 + 40 * i, xx1 + 120, 40 * i + 60, point3->Getname()))
			{
				Widget w2(352, 469);
				goto show_e2;
			}
			w.set_button(mouse, xx1 + 140, 40 + 40 * i, xx1 + 210, 40 * i + 60, point3->Gettime());
			if (w.set_button(mouse, xx1 + 235, 40 + 40 * i, xx1 + 275, 40 * i + 60, "ɾ��"))
			{
				if (check % 4 == 0)
				{
					if (w.message_question(a, 20, "ȷ��ɾ��"))
					{
						delet(Find(Ehead, point3->Getname()), EN);
						w.clear();
						check++;
						break;
						//Widget w2(352, 469);
						//goto show_c;

					}
					//cout << num1;
				}
				check++;
				//cout << check;
			}
		}
		if (w.set_button(mouse, 40, 400, 110, 420, "  ��һҳ  "))
		{
			if (checknum % 4 == 0 && num2 > 0)
			{
				w.clear();

				num2--;
				//cout << num2;
			}
			checknum++;
		}
		if (w.set_button(mouse, 215, 400, 285, 420, "  ��һҳ  "))
		{
			if (checknum % 4 == 0 && (8 * num2 < EN - 8))
			{
				w.clear();
				num2++;
				//cout << num2;
			}
			checknum++;
		}
		if (w.set_button(mouse, 130, 400, 195, 420, "   �� ��   "))
		{
			user = "";
			Widget w2(352, 469);
			goto root;
		}

	}
	getchar();
show_e2://��ʾĳһ������Ա��Ϣ
	w.set_title("�װ��Ŀ��Ա������");
	user = point3->Getuser();
	password = point3->Getpassword(567);
	name = point3->Getname();
	age = to_string(point3->Getage());
	sex = point3->Getsex();
	tel = point3->Gettel();
	adress = point3->Gettime();
	for (; 1;)
	{
		mouse = GetMouseMsg();
		w.output("��        �ţ�", 70, 80);
		w.output("��        �룺", 70, 125);
		w.output("��        ����", 70, 170);
		w.output("��        �䣺", 70, 215);
		w.output("��        ��", 70, 260);
		w.output("��ϵ��ʽ��", 70, 305);
		w.output("����ʱ�䣺", 70, 350);
		s1 = w.cinbox(mouse, 145, 78, 266, 98, user);
		if (s1 != "")
		{
			user = s1;
		}
		s1 = w.cinbox(mouse, 145, 123, 266, 143, password);
		if (s1 != "")
		{
			password = s1;
		}
		s1 = w.cinbox(mouse, 145, 168, 266, 188, name);
		if (s1 != "")
		{
			name = s1;
		}
		s1 = w.cinbox(mouse, 145, 214, 266, 234, age);
		if (s1 != "")
		{
			age = s1;
		}
		s1 = w.cinbox(mouse, 145, 258, 266, 278, sex);
		if (s1 != "")
		{
			sex = s1;
		}
		s1 = w.cinbox(mouse, 145, 303, 266, 323, tel);
		if (s1 != "")
		{
			tel = s1;
		}
		s1 = w.cinbox(mouse, 145, 348, 266, 368, adress);
		if (s1 != "")
		{
			adress = s1;
		}

		if (w.set_button(mouse, 64, 395, 136, 415, "    �� ��    "))
		{
			int iage = stoi(age);
			password = point3->Getpassword(567);
			Expressman customer(user, password, 1, name, sex, iage, tel, 2.5, adress);
			//customer.Show();
			point3->SetData(customer);
			//point2->Show();
			//Expressman* pcus = &customer;
			//customer.Show();
			//pcus->Show();
			goto end;
		}
		if (w.set_button(mouse, 200, 395, 272, 415, "    �� ��    "))
		{
			Widget w2(352, 469);
			user = password = name = age = sex = tel = adress = "";
			goto show_e;
		}
	}
	getchar();
customer://�˿͵�½����
	w.set_title("�װ��Ĺ˿ͣ�����");
	user = point1->Getuser();
	password = "**********";
	name = point1->Getname();
	age = to_string(point1->Getage());
	sex = point1->Getsex();
	tel = point1->Gettel();
	adress = point1->Getaddress();
	for (; 1;)
	{
		mouse = GetMouseMsg();
		w.output("��        �ţ�", 70, 80);
		w.output("��        �룺", 70, 125);
		w.output("��        ����", 70, 170);
		w.output("��        �䣺", 70, 215);
		w.output("��        ��", 70, 260);
		w.output("��ϵ��ʽ��", 70, 305);
		w.output("��        ַ��", 70, 350);
		s1 = w.cinbox(mouse, 145, 78, 266, 98, user);
		if (s1 != "")
		{
			if (Check(Chead, s1) == NULL)
			{
				//cout << Check(Chead, s1)->next->Getuser();
				user = s1;
			}
			else
			{
				w.play_music(2);
				w.message_warn(a, 20, "���˺��Ѵ���");

			}
		}
		s1 = w.cinbox(mouse, 145, 123, 266, 143, "********");
		/*if (s1 != "")
		{
			if (s1.length() < 6)
			{
				w.message_warn(a, 20, "��������ڵ���6λ");
			}
			else if (Check(s1))
			{
				password = s1;
			}
			else
			{
				w.message_warn(a, 20, "��������ĸ��������Ϊ����");
			}
		}*/
		s1 = w.cinbox(mouse, 145, 168, 266, 188, name);
		if (s1 != "")
		{
			int j = 0;
			for (int i = 0; i < s1.length(); i++)
			{
				if ((s1[i] > 64 && s1[i] < 91) || (s1[i] > 96 && s1[i] < 123) || (s1[i] <= 0 && s1[i] > -90))
				{

				}
				else j = 1;
			}
			if (j == 0 && s1.length() > 3)
			{
				name = s1;
			}
			else w.message_warn(a, 20, "��������ȷ����");
		}
		s1 = w.cinbox(mouse, 145, 214, 266, 234, age);
		if (s1 != "")
		{
			if ((s1 >= "10" && s1.length() == 2) || (s1 <= "120" && s1.length() == 3))
			{


				age = s1;
			}
			else w.message_warn(a, 20, "��������ȷ����");
		}
		s1 = w.cinbox(mouse, 145, 258, 266, 278, sex);
		if (s1 != "")
		{
			if (s1 == "woman" || s1 == "man" || s1 == "Ů" || s1 == "��" || s1 == "male" || s1 == "female")
			{
				sex = s1;
			}
			else w.message_warn(a, 20, "��������ȷ�Ա�");
		}
		s1 = w.cinbox(mouse, 145, 303, 266, 323, tel);
		if (s1 != "")
		{
			int j = 0;
			for (int i = 0; i < s1.length(); i++)
			{
				if (s1[i] < 48 || s1[i]>57)
				{
					j = 1;
				}
			}
			if (j == 0 && s1.length() == 11)
			{
				tel = s1;
			}
			else w.message_warn(a, 20, "��������ȷ�ֻ���");
		}
		s1 = w.cinbox(mouse, 145, 348, 266, 368, adress);
		if (s1 != "")
		{
			adress = s1;
		}

		if (w.set_button(mouse, 64, 395, 136, 415, "    �� ��    "))
		{
			if (check % 4 == 0)
			{
				if (user == "" || password == "" || name == "" || age == "" || sex == "" || tel == "" || adress == "")
				{
					w.play_music(3);
					w.message_warn(a, 20, "�벻Ҫ©��");
					goto customer;
				}
				int iage = stoi(age);
				password = point1->Getpassword(567);
				Customer customer(user, password, 1, name, sex, iage, tel, adress);
				//customer.Show();
				point1->SetData(customer);
				//point1->Show();
				//customer.Show();
				//pcus->Show();
				Widget w(352, 288);
				goto login_window;
			}
		}
		if (w.set_button(mouse, 200, 395, 272, 415, "    �� ��    "))
		{
			Widget w(352, 288);
			user = password = name = age = sex = tel = adress = "";
			goto login_window;
		}
		if (w.set_button(mouse, 126, 35, 210, 55, "     ��  ��     "))
		{
			Widget w(352, 461);
			goto order1;
		}
		if (w.set_button(mouse, 283, 0, 469, 20, "�鿴����"))
		{
			Widget w2(352, 469);
			goto orderfrom_c;
		}
	}
	getchar();

shop://������½����
	w.set_title("�װ��ĵ���������");
	user = point2->Getuser();
	password = "**********";
	name = point2->Getname();
	age = to_string(point2->Getage());
	sex = point2->Getsex();
	tel = point2->Gettel();
	adress = point2->Getshopname();
	dis = to_string(point2->Getdiscount());
	p_food = point2->Getfood();
	for (int i = 0; i < point2->Getfoodnum(); i++)
	{
		food[i] = p_food[i].Getname();
		price[i] = to_string(p_food[i].Getprice()).substr(0,5);//.substr(to_string(p_food[i].Getprice()).length()-(to_string(p_food[i].Getprice()).length()-6));
	}
	for (; 1;)
	{
		mouse = GetMouseMsg();
		w.output("��        �ţ�", 70, 80);
		w.output("��        �룺", 70, 125);
		w.output("��        ����", 70, 170);
		w.output("��        �䣺", 70, 215);
		w.output("��        ��", 70, 260);
		w.output("��ϵ��ʽ��", 70, 305);
		w.output("�̵����ƣ�", 70, 350);
		w.output("�̵��ۿۣ�", 70, 395);
	
		s1 = w.cinbox(mouse, 145, 78, 266, 98, user);
		if (s1 != "")
		{
			if (Check(Shead, s1) == NULL)
			{
				//cout << Check(Chead, s1)->next->Getuser();
				user = s1;
			}
			else
			{
				w.play_music(2);
				w.message_warn(a, 20, "���˺��Ѵ���");

			}
		}
		s1 = w.cinbox(mouse, 145, 123, 266, 143, "********");
		
		s1 = w.cinbox(mouse, 145, 168, 266, 188, name);
		if (s1 != "")
		{
			int j = 0;
			for (int i = 0; i < s1.length(); i++)
			{
				if ((s1[i] > 64 && s1[i] < 91) || (s1[i] > 96 && s1[i] < 123) || (s1[i] <= 0 && s1[i] > -90))
				{

				}
				else j = 1;
			}
			if (j == 0 && s1.length() > 3)
			{
				name = s1;
			}
			else w.message_warn(a, 20, "��������ȷ����");
		}
		s1 = w.cinbox(mouse, 145, 214, 266, 234, age);
		if (s1 != "")
		{
			if ((s1 >= "10" && s1.length() == 2) || (s1 <= "120" && s1.length() == 3))
			{


				age = s1;
			}
			else w.message_warn(a, 20, "��������ȷ����");
		}
		s1 = w.cinbox(mouse, 145, 258, 266, 278, sex);
		if (s1 != "")
		{
			if (s1 == "woman" || s1 == "man" || s1 == "Ů" || s1 == "��" || s1 == "male" || s1 == "female")
			{
				sex = s1;
			}
			else w.message_warn(a, 20, "��������ȷ�Ա�");
		}
		s1 = w.cinbox(mouse, 145, 303, 266, 323, tel);
		if (s1 != "")
		{
			int j = 0;
			for (int i = 0; i < s1.length(); i++)
			{
				if (s1[i] < 48 || s1[i]>57)
				{
					j = 1;
				}
			}
			if (j == 0 && s1.length() == 11)
			{
				tel = s1;
			}
			else w.message_warn(a, 20, "��������ȷ�ֻ���");
		}
		s1 = w.cinbox(mouse, 145, 348, 266, 368, adress);//����
		if (s1 != "")
		{
			adress = s1;
		}
		s1 = w.cinbox(mouse, 145, 393, 266, 413, dis);//�ۿ�
		if (s1 != "")
		{
			int j = 0;
			for (int i = 0; i < s1.length(); i++)
			{
				if (s1[i] > 57 || s1[i] < 48)
				{
					if (s1[i] == 46)
					{

					}
					else
					{
						j = 1;
					}
				}
			}
			if (j == 0)
			{
				dis = s1;
			}
			else
			{
				w.message_warn(a, 20, "��������ȷ�ۿ�����0.8==����");
			}

		}

		w.output("��Ʒ1��", 400, 80);
		w.output("��Ʒ2��", 400, 125);
		w.output("��Ʒ3��", 400, 170);
		w.output("��Ʒ4��", 400, 215);
		w.output("��Ʒ5��", 400, 260);
		w.output("��Ʒ6��", 400, 305);
		w.output("��Ʒ7��", 400, 350);
		w.output("��Ʒ8��", 400, 395);
		w.output("�۸�", 595, 50);
		s1 = w.cinbox(mouse, 455, 78, 575, 98, food[0]);
		if (s1 != "")
		{
			food[0] = s1;
		}
		s1 = w.cinbox(mouse, 455, 123, 575, 143, food[1]);
		if (s1 != "")
		{
			food[1] = s1;
		}
		s1 = w.cinbox(mouse, 455, 168, 575, 188, food[2]);
		if (s1 != "")
		{
			food[2] = s1;
		}
		s1 = w.cinbox(mouse, 455, 214, 575, 234, food[3]);
		if (s1 != "")
		{
			food[3] = s1;
		}
		s1 = w.cinbox(mouse, 455, 258, 575, 278, food[4]);
		if (s1 != "")
		{
			food[4] = s1;
		}
		s1 = w.cinbox(mouse, 455, 303, 575, 323, food[5]);
		if (s1 != "")
		{
			food[5] = s1;
		}
		s1 = w.cinbox(mouse, 455, 348, 575, 368, food[6]);
		if (s1 != "")
		{
			food[6] = s1;
		}
		s1 = w.cinbox(mouse, 455, 393, 575, 413, food[7]);
		if (s1 != "")
		{
			food[7] = s1;
		}
		s1 = w.cinbox(mouse, 593, 78, 633, 98, price[0]);
		if (s1 != "")
		{
			int j = 0;
			for (int i = 0; i < s1.length(); i++)
			{
				if (s1[i] > 57 || s1[i] < 48)
				{
					if (s1[i] == 46)
					{

					}
					else
					{
						j = 1;
					}
				}
			}
			if (j == 0)
			{
				price[0] = s1;
			}
			else
			{
				w.message_warn(a, 20, "��������ȷ�۸�");
			}
		}
		s1 = w.cinbox(mouse, 593, 123, 633, 143, price[1]);
		if (s1 != "")
		{
			int j = 0;
			for (int i = 0; i < s1.length(); i++)
			{
				if (s1[i] > 57 || s1[i] < 48)
				{
					if (s1[i] == 46)
					{

					}
					else
					{
						j = 1;
					}
				}
			}
			if (j == 0)
			{
				price[1] = s1;
			}
			else
			{
				w.message_warn(a, 20, "��������ȷ�۸�");
			}

		}
		s1 = w.cinbox(mouse, 593, 168, 633, 188, price[2]);
		if (s1 != "")
		{
			int j = 0;
			for (int i = 0; i < s1.length(); i++)
			{
				if (s1[i] > 57 || s1[i] < 48)
				{
					if (s1[i] == 46)
					{

					}
					else
					{
						j = 1;
					}
				}
			}
			if (j == 0)
			{
				price[2] = s1;
			}
			else
			{
				w.message_warn(a, 20, "��������ȷ�۸�");
			}
		}
		s1 = w.cinbox(mouse, 593, 214, 633, 234, price[3]);
		if (s1 != "")
		{
			int j = 0;
			for (int i = 0; i < s1.length(); i++)
			{
				if (s1[i] > 57 || s1[i] < 48)
				{
					if (s1[i] == 46)
					{

					}
					else
					{
						j = 1;
					}
				}
			}
			if (j == 0)
			{
				price[3] = s1;
			}
			else
			{
				w.message_warn(a, 20, "��������ȷ�۸�");
			}
		}
		s1 = w.cinbox(mouse, 593, 258, 633, 278, price[4]);
		if (s1 != "")
		{
			int j = 0;
			for (int i = 0; i < s1.length(); i++)
			{
				if (s1[i] > 57 || s1[i] < 48)
				{
					if (s1[i] == 46)
					{

					}
					else
					{
						j = 1;
					}
				}
			}
			if (j == 0)
			{
				price[4] = s1;
			}
			else
			{
				w.message_warn(a, 20, "��������ȷ�۸�");
			}
		}
		s1 = w.cinbox(mouse, 593, 303, 633, 323, price[5]);
		if (s1 != "")
		{
			int j = 0;
			for (int i = 0; i < s1.length(); i++)
			{
				if (s1[i] > 57 || s1[i] < 48)
				{
					if (s1[i] == 46)
					{

					}
					else
					{
						j = 1;
					}
				}
			}
			if (j == 0)
			{
				price[5] = s1;
			}
			else
			{
				w.message_warn(a, 20, "��������ȷ�۸�");
			}
		}
		s1 = w.cinbox(mouse, 593, 348, 633, 368, price[6]);
		if (s1 != "")
		{
			int j = 0;
			for (int i = 0; i < s1.length(); i++)
			{
				if (s1[i] > 57 || s1[i] < 48)
				{
					if (s1[i] == 46)
					{

					}
					else
					{
						j = 1;
					}
				}
			}
			if (j == 0)
			{
				price[6] = s1;
			}
			else
			{
				w.message_warn(a, 20, "��������ȷ�۸�");
			}
		}
		s1 = w.cinbox(mouse, 593, 393, 633, 413, price[7]);
		if (s1 != "") {
			int j = 0;
			for (int i = 0; i < s1.length(); i++)
			{
				if (s1[i] > 57 || s1[i] < 48)
				{
					if (s1[i] == 46)
					{

					}
					else
					{
						j = 1;
					}
				}
			}
			if (j == 0)
			{
				price[7] = s1;
			}
			else
			{
				w.message_warn(a, 20, "��������ȷ�۸�");
			}
		}

		if (w.set_button(mouse, 114, 440, 186, 460, "    �� ��    "))
		{
			if (check % 4 == 0)
			{
				if (user == "" || password == "" || name == "" || age == "" || sex == "" || tel == "" || adress == "" || dis == "")
				{
					w.play_music(3);
					w.message_warn(a, 20, "�벻Ҫ©��");
					goto shop;
				}
				float disc = stof(dis);
				int iage = stoi(age);
				int foodnum = 0;
				Food* pfood = new Food[8];
				for (int i = 0; i < 8; i++)
				{
					if (food[i] != "" && price[i] != "")
					{
						cout << "food";
						float pr = stof(price[i]);
						pfood[i].SetData(food[i], pr);
						foodnum++;
					}
				}
				password = point2->Getpassword(567);
				Shop customer(user, password, 2, name, sex, iage, tel, 2.5, disc, adress, pfood, foodnum);
				point2->SetData(customer);
				//Shop(string st1, string st2, int in, string str, string c, int i, string str2, float s1, float s2, string s3, Food * p,int foodnum) :
				//Shop* pcus = &customer;
				//cout << "r" << endl;
				//customer.Show();
				//Register(Shead, customer);//����ֵĶ������⣬����iageȫ��д���ļ���ʧ���ݡ�
				//cout << "reg" << endl;
				//pcus->Show();
				Widget w(352, 288);
				goto login_window;
			}
		}
		if (w.set_button(mouse, 500, 440, 572, 460, "    �� ��    "))
		{
			Widget w(352, 288);
			user = password = name = age = sex = tel = adress = dis = "";
			goto login_window;
		}
		if (w.set_button(mouse, 303, 0, 383, 20, "�鿴����"))
		{
			Widget w2(352, 469);
			goto orderfrom_s;
		}
	}
	getchar();

expressman://������Ա��½����
	w.set_title("�װ��Ŀ��Ա������");
	user = point3->Getuser();
	cout << user;
	password = "**********";
	name = point3->Getname();
	age = to_string(point3->Getage());
	sex = point3->Getsex();
	tel = point3->Gettel();
	adress = point3->Gettime();
	for (; 1;)
	{
		mouse = GetMouseMsg();
		w.output("��        �ţ�", 70, 80);
		w.output("��        �룺", 70, 125);
		w.output("��        ����", 70, 170);
		w.output("��        �䣺", 70, 215);
		w.output("��        ��", 70, 260);
		w.output("��ϵ��ʽ��", 70, 305);
		w.output("����ʱ�䣺", 70, 350);
		s1 = w.cinbox(mouse, 145, 78, 266, 98, user);
		if (s1 != "")
		{
			if (Check(Ehead, s1) == NULL)
			{
				//cout << Check(Chead, s1)->next->Getuser();
				user = s1;
			}
			else
			{
				w.play_music(2);
				w.message_warn(a, 20, "���˺��Ѵ���");

			}
		}
		s1 = w.cinbox(mouse, 145, 123, 266, 143, "********");

		s1 = w.cinbox(mouse, 145, 168, 266, 188, name);
		if (s1 != "")
		{
			int j = 0;
			for (int i = 0; i < s1.length(); i++)
			{
				if ((s1[i] > 64 && s1[i] < 91) || (s1[i] > 96 && s1[i] < 123) || (s1[i] <= 0 && s1[i] > -90))
				{

				}
				else j = 1;
			}
			if (j == 0 && s1.length() > 3)
			{
				name = s1;
			}
			else w.message_warn(a, 20, "��������ȷ����");
		}
		s1 = w.cinbox(mouse, 145, 214, 266, 234, age);
		if (s1 != "")
		{
			if ((s1 >= "10" && s1.length() == 2) || (s1 <= "120" && s1.length() == 3))
			{


				age = s1;
			}
			else w.message_warn(a, 20, "��������ȷ����");
		}
		s1 = w.cinbox(mouse, 145, 258, 266, 278, sex);
		if (s1 != "")
		{
			if (s1 == "woman" || s1 == "man" || s1 == "Ů" || s1 == "��" || s1 == "male" || s1 == "female")
			{
				sex = s1;
			}
			else w.message_warn(a, 20, "��������ȷ�Ա�");
		}
		s1 = w.cinbox(mouse, 145, 303, 266, 323, tel);
		if (s1 != "")
		{
			int j = 0;
			for (int i = 0; i < s1.length(); i++)
			{
				if (s1[i] < 48 || s1[i]>57)
				{
					j = 1;
				}
			}
			if (j == 0 && s1.length() == 11)
			{
				tel = s1;
			}
			else w.message_warn(a, 20, "��������ȷ�ֻ���");
		}
		s1 = w.cinbox(mouse, 145, 348, 266, 368, adress);
		if (s1 != "")
		{
			adress = s1;
		}

		if (w.set_button(mouse, 64, 395, 136, 415, "    �� ��    "))
		{
			if (check % 4 == 0)
			{
				if (user == "" || password == "" || name == "" || age == "" || sex == "" || tel == "" || adress == "")
				{
					w.play_music(3);
					w.message_warn(a, 20, "�벻Ҫ©��");
					goto expressman;
				}
				int iage = stoi(age);
				password = point3->Getpassword(567);
				Expressman customer(user, password, 1, name, sex, iage, tel, 2.5, adress);
				//customer.Show();
				point3->SetData(customer);
				//point2->Show();
				//Expressman* pcus = &customer;
				//customer.Show();
				//pcus->Show();
				Widget w(352, 288);
				goto login_window;
			}
		}
		if (w.set_button(mouse, 200, 395, 272, 415, "    �� ��    "))
		{
			Widget w(352, 288);
			user = password = name = age = sex = tel = adress = "";
			goto login_window;
		}
		if (w.set_button(mouse, 283, 0, 469, 20, "�鿴����"))
		{
			Widget w2(352, 469);
			goto orderfrom_e;
		}
	}
	getchar();

orderfrom_r://���ж���
	w.set_title("�鿴����");
	num2 = 0;
	for (; 1;)
	{
		point5 = new Order_form;
		point4 = Ohead->next;
		for (int i = 0; point4 != NULL && i < CN; point4 = point4->next, i++)
		{
			if (point4->Getnumber() == ("9999999"<=user||user=="" ? 0 : stoi(user) ))
			{
				cout << user;
				cout << "ע��";
				Order_form orderform = *point4;
				Register(point5, orderform);
			}
			if (i == CN)
			{
				point4 = NULL;
			}
		}
		if (point5->next == NULL)
		{
			point4 = Ohead->next;
		}
		else
		{
			point4 = point5->next;
		}
		for (int i = 1; i <= 8 * num2; i++, point4 = point4->next)
		{

		}
	
		mouse = GetMouseMsg();
		w.set_button(mouse, 90, 40, 157, 60, "��͹˿�");
		w.set_button(mouse, 215, 40, 250, 60, "����");
		w.output("����", 218, 4);
		s1 = w.cinbox(mouse, 253, 1, 353, 21, user);
		if (s1 != "")
		{
			user = s1;
			
			//cout<< stoi(user);
			if (Find(Ohead, ("9999999" <= user || user == "" ? 0 : stoi(user))) == NULL)
			{
				user = "δ��ѯ��";

			}
			else
			{
				w.clear();
				Widget w2(352, 469);
				goto orderfrom_r;



			}
		}
		for (int i = 1, num1 = num2 * 8 + 1; i <= 8 && point4 != NULL; num1++, i++, point4 = point4->next)
		{

			w.set_button(mouse, 40, 40 + 40 * i, xx1 + 10, 40 * i + 60, to_string(num1));
			if (w.set_button(mouse, xx1, 40 + 40 * i, xx1 + 120, 40 * i + 60, point4->Getcusname()))
			{
				w.clear();
				Widget w2(700, 514);
				goto orderfrom_r2;
			}
			w.set_button(mouse, xx1 + 140, 40 + 40 * i, xx1 + 210, 40 * i + 60, (point4->Getshopname()));
			if (w.set_button(mouse, xx1 + 235, 40 + 40 * i, xx1 + 275, 40 * i + 60, "ɾ��"))
			{
				if (check % 4 == 0)
				{
					if (w.message_question(a, 20, "ȷ��ɾ��"))
					{
						delet(Find(Ohead, point4->Getnumber()), ON);
						w.clear();
						check++;
						break;
						//Widget w2(352, 469);
						//goto show_c;

					}
					//cout << num1;
				}
				check++;
				//cout << check;
			}
		}
		if (w.set_button(mouse, 40, 400, 110, 420, "  ��һҳ  "))
		{
			if (checknum % 4 == 0 && num2 > 0)
			{
				w.clear();

				num2--;
				//cout << num2;
			}
		}
		if (w.set_button(mouse, 215, 400, 285, 420, "  ��һҳ  "))
		{
			if (checknum % 4 == 0 && (8 * num2 < ON - 8))
			{
				w.clear();
				num2++;
				//cout << num2;
			}
		}
		if (w.set_button(mouse, 130, 400, 195, 420, "   �� ��   "))
		{
			user = "";
			Widget w2(352, 469);
			goto root;
		}

	}
	getchar();

orderfrom_r2://�鿴ĳһ����
	for (int i = 0; i < 9; i++) { food[i] = price[i] = ""; }
	user = "�鿴����" + to_string(point4->Getnumber());
	w.set_title(user);
	user = point4->Getcusname();
	password = point4->Getshopname();
	name = point4->Getmanname();
	age = to_string(point4->Getcost());
	if (point4->Getflag() == 1)
	{
		sex = "���µ�";
	}
	if (point4->Getflag() == 2)
	{
		sex = "���ɷ�";
	}
	if (point4->Getflag() == 3)
	{
		sex = "���յ�";
	}
	//tel = point2->Gettel();
	//adress = point2->Getshopname();
	//dis = to_string(point2->Getdiscount());
	p_food = point4->Getfhead();
	for (int i = 0; i < point4->Getfnum(); i++)
	{
		food[i] = p_food[i].Getname();
		price[i] = to_string(p_food[i].Getprice()).substr(0,5);
	}
	for (; 1;)
	{
		mouse = GetMouseMsg();
		w.output("�µ��˿ͣ�", 70, 80);
		w.output("�㵥�̵꣺", 70, 125);
		w.output("�յ���Ա��", 70, 170);
		w.output("�������ѣ�", 70, 215);
		w.output("����״̬��", 70, 260);
		//w.output("��ϵ��ʽ��", 70, 305);
		//w.output("�̵����ƣ�", 70, 350);
		//w.output("�̵��ۿۣ�", 70, 395);

		s1 = w.cinbox(mouse, 145, 78, 266, 98, user);
		//if (s1 != ""){user = s1;}
		s1 = w.cinbox(mouse, 145, 123, 266, 143, password);
		//if (s1 != ""){password = s1;}
		s1 = w.cinbox(mouse, 145, 168, 266, 188, name);
		//if (s1 != ""){name = s1;}
		s1 = w.cinbox(mouse, 145, 214, 266, 234, age);
		/*if (s1 != "")
		{
			age = s1;
		}*/
		s1 = w.cinbox(mouse, 145, 258, 266, 278, sex);
		/*if (s1 != "")
		{
			sex = s1;
		}*/
		/*s1 = w.cinbox(mouse, 145, 303, 266, 323, tel);
		if (s1 != "")
		{
			tel = s1;
		}
		s1 = w.cinbox(mouse, 145, 348, 266, 368, adress);//����
		if (s1 != "")
		{
			adress = s1;
		}
		s1 = w.cinbox(mouse, 145, 393, 266, 413, dis);//�ۿ�
		if (s1 != "")
		{
			dis = s1;
		}*/

		w.output("��Ʒ1��", 400, 80);
		w.output("��Ʒ2��", 400, 125);
		w.output("��Ʒ3��", 400, 170);
		w.output("��Ʒ4��", 400, 215);
		w.output("��Ʒ5��", 400, 260);
		w.output("��Ʒ6��", 400, 305);
		w.output("��Ʒ7��", 400, 350);
		w.output("��Ʒ8��", 400, 395);
		w.output("�۸�", 595, 50);
		s1 = w.cinbox(mouse, 455, 78, 575, 98, food[0]);
		if (s1 != "")
		{
			food[0] = s1;
		}
		s1 = w.cinbox(mouse, 455, 123, 575, 143, food[1]);
		if (s1 != "")
		{
			food[1] = s1;
		}
		s1 = w.cinbox(mouse, 455, 168, 575, 188, food[2]);
		if (s1 != "")
		{
			food[2] = s1;
		}
		s1 = w.cinbox(mouse, 455, 214, 575, 234, food[3]);
		if (s1 != "")
		{
			food[3] = s1;
		}
		s1 = w.cinbox(mouse, 455, 258, 575, 278, food[4]);
		if (s1 != "")
		{
			food[4] = s1;
		}
		s1 = w.cinbox(mouse, 455, 303, 575, 323, food[5]);
		if (s1 != "")
		{
			food[5] = s1;
		}
		s1 = w.cinbox(mouse, 455, 348, 575, 368, food[6]);
		if (s1 != "")
		{
			food[6] = s1;
		}
		s1 = w.cinbox(mouse, 455, 393, 575, 413, food[7]);
		if (s1 != "")
		{
			food[7] = s1;
		}
		s1 = w.cinbox(mouse, 593, 78, 673, 98, price[0]);
		if (s1 != "")
		{
			price[0] = s1;
		}
		s1 = w.cinbox(mouse, 593, 123, 673, 143, price[1]);
		if (s1 != "")
		{
			price[1] = s1;
		}
		s1 = w.cinbox(mouse, 593, 168, 673, 188, price[2]);
		if (s1 != "")
		{
			price[2] = s1;
		}
		s1 = w.cinbox(mouse, 593, 214, 673, 234, price[3]);
		if (s1 != "")
		{
			price[3] = s1;
		}
		s1 = w.cinbox(mouse, 593, 258, 673, 278, price[4]);
		if (s1 != "")
		{
			price[4] = s1;
		}
		s1 = w.cinbox(mouse, 593, 303, 673, 323, price[5]);
		if (s1 != "")
		{
			price[5] = s1;
		}
		s1 = w.cinbox(mouse, 593, 348, 673, 368, price[6]);
		if (s1 != "")
		{
			price[6] = s1;
		}
		s1 = w.cinbox(mouse, 593, 393, 673, 413, price[7]);
		if (s1 != "")
		{
			price[7] = s1;
		}

		if (w.set_button(mouse, 114, 440, 186, 460, "    ȷ ��    "))
		{
			user = password = name = age = sex = tel = adress = dis = "";
			Widget w2(352, 469);
			w2.clear();
			goto orderfrom_r;
			/*float disc = stof(dis);
			int iage = stoi(age);
			int foodnum = 0;
			Food* pfood = new Food[8];
			for (int i = 0; i < 8; i++)
			{
				if (food[i] != "" && price[i] != "")
				{
					cout << "food";
					float pr = stof(price[i]);
					pfood[i].SetData(food[i], pr);
					foodnum++;
				}
			}
			password = point2->Getpassword(567);
			Shop customer(user, password, 2, name, sex, iage, tel, 2.5, disc, adress, pfood, foodnum);
			point2->SetData(customer);
			Widget w(352, 288);
			goto login_window;*/
		}
		if (w.set_button(mouse, 500, 440, 572, 460, "    �� ��    "))
		{
			
			user = password = name = age = sex = tel = adress = dis = "";
			Widget w2(352, 469);
			w2.clear();
			goto orderfrom_r;
		}
	}
	getchar();

orderfrom_c://�˿��йض���
	w.set_title("�鿴����");

	//cout << point1->Getname();
	point5 = new Order_form;
	point4 = Ohead->next;
	for (int i = 0 ;point4!=NULL&&i<ON;point4=point4->next,i++)
	{
		if (point4->Getcusname() == point1->Getname())
		{
			//cout << "ע��";
			Order_form orderform = *point4;
			Register(point5, orderform);
		}
		if (i == CN)
		{
			point4 = NULL;
		}
	}
	num2 = 0;
	float allcost;
	
	for (; 1;)
	{
		allcost = 0;
		if (point5->next==NULL)
		{
			w.message_warn(a, 20, "����û���µ�");
			Widget w2(352, 469);
			w2.clear();
			goto customer;
		}
		else
		{
			point4 = point5->next;
		}
		for (int i = 1; i <= 8 * num2; i++, point4 = point4->next)
		{

		}
		mouse = GetMouseMsg();
		
		
		w.set_button(mouse, 90, 40, 157, 60, "��͹˿�");
		w.set_button(mouse, 215, 40, 250, 60, "����");

		for (int i = 1, num1 = num2 * 8 + 1; i <= 8 && point4 != NULL; num1++, i++, point4 = point4->next)
		{
			allcost += point4->Getcost();
			w.set_button(mouse, 40, 40 + 40 * i, xx1 + 10, 40 * i + 60, to_string(num1));
			if (w.set_button(mouse, xx1, 40 + 40 * i, xx1 + 120, 40 * i + 60, point4->Getcusname()))
			{
				w.clear();
				Widget w2(700, 514);
				goto orderfrom_c2;
			}
			w.set_button(mouse, xx1 + 140, 40 + 40 * i, xx1 + 210, 40 * i + 60, (point4->Getshopname()));
			if (w.set_button(mouse, xx1 + 235, 40 + 40 * i, xx1 + 275, 40 * i + 60, "ȷ��"))
			{
				if (check % 4 == 0)
				{
					if (point4->Getflag() == 2)
					{
						Find(Ohead,point4->Getnumber())->next->mark(3);
						w.message_warn(a, 20, "��ǩ��");
					}
					else
					{
						w.message_warn(a,20,"������Ա��δ����");
					}
				}
				check++;
				//cout << check;
			}
		}
		w.output("�������ѣ�",40,440);
		w.output(to_string(allcost).substr(0,5),130,440);
		if (w.set_button(mouse, 40, 400, 110, 420, "  ��һҳ  "))
		{
			if (checknum % 4 == 0 && num2 > 0)
			{
				w.clear();

				num2--;
				//cout << num2;
			}
		}
		if (w.set_button(mouse, 215, 400, 285, 420, "  ��һҳ  "))
		{
			if (checknum % 4 == 0 && (8 * num2 < ON - 8))
			{
				w.clear();
				num2++;
				//cout << num2;
			}
		}
		if (w.set_button(mouse, 130, 400, 195, 420, "   �� ��   "))
		{
		
			
			Widget w2(352, 469);
			w2.clear();
			goto customer;
		
		}
	

	}

	getchar();

orderfrom_c2://�鿴ĳһ����
	for (int i = 0; i < 9; i++) { food[i] = price[i] = ""; }
	user = "�鿴����" + to_string(point4->Getnumber());
	w.set_title(user);
	user = point4->Getcusname();
	password = point4->Getshopname();
	name = point4->Getmanname();
	age = to_string(point4->Getcost());
	if (point4->Getflag() == 1)
	{
		sex = "���µ�";
	}
	if (point4->Getflag() == 2)
	{
		sex = "���ɷ�";
	}
	if (point4->Getflag() == 3)
	{
		sex = "���յ�";
	}
	//tel = point2->Gettel();
	//adress = point2->Getshopname();
	//dis = to_string(point2->Getdiscount());
	p_food = point4->Getfhead();
	for (int i = 0; i < point4->Getfnum(); i++)
	{
		food[i] = p_food[i].Getname();
		price[i] = to_string(p_food[i].Getprice()).substr(0,5);
	}
	for (; 1;)
	{
		mouse = GetMouseMsg();
		w.output("�µ��˿ͣ�", 70, 80);
		w.output("�㵥�̵꣺", 70, 125);
		w.output("�յ���Ա��", 70, 170);
		w.output("�������ѣ�", 70, 215);
		w.output("����״̬��", 70, 260);
		//w.output("��ϵ��ʽ��", 70, 305);
		//w.output("�̵����ƣ�", 70, 350);
		//w.output("�̵��ۿۣ�", 70, 395);

		s1 = w.cinbox(mouse, 145, 78, 266, 98, user);
		//if (s1 != ""){user = s1;}
		s1 = w.cinbox(mouse, 145, 123, 266, 143, password);
		//if (s1 != ""){password = s1;}
		s1 = w.cinbox(mouse, 145, 168, 266, 188, name);
		//if (s1 != ""){name = s1;}
		s1 = w.cinbox(mouse, 145, 214, 266, 234, age);
		/*if (s1 != "")
		{
			age = s1;
		}*/
		s1 = w.cinbox(mouse, 145, 258, 266, 278, sex);
		/*if (s1 != "")
		{
			sex = s1;
		}*/
		/*s1 = w.cinbox(mouse, 145, 303, 266, 323, tel);
		if (s1 != "")
		{
			tel = s1;
		}
		s1 = w.cinbox(mouse, 145, 348, 266, 368, adress);//����
		if (s1 != "")
		{
			adress = s1;
		}
		s1 = w.cinbox(mouse, 145, 393, 266, 413, dis);//�ۿ�
		if (s1 != "")
		{
			dis = s1;
		}*/

		w.output("��Ʒ1��", 400, 80);
		w.output("��Ʒ2��", 400, 125);
		w.output("��Ʒ3��", 400, 170);
		w.output("��Ʒ4��", 400, 215);
		w.output("��Ʒ5��", 400, 260);
		w.output("��Ʒ6��", 400, 305);
		w.output("��Ʒ7��", 400, 350);
		w.output("��Ʒ8��", 400, 395);
		w.output("�۸�", 595, 50);
		s1 = w.cinbox(mouse, 455, 78, 575, 98, food[0]);
		if (s1 != "")
		{
			food[0] = s1;
		}
		s1 = w.cinbox(mouse, 455, 123, 575, 143, food[1]);
		if (s1 != "")
		{
			food[1] = s1;
		}
		s1 = w.cinbox(mouse, 455, 168, 575, 188, food[2]);
		if (s1 != "")
		{
			food[2] = s1;
		}
		s1 = w.cinbox(mouse, 455, 214, 575, 234, food[3]);
		if (s1 != "")
		{
			food[3] = s1;
		}
		s1 = w.cinbox(mouse, 455, 258, 575, 278, food[4]);
		if (s1 != "")
		{
			food[4] = s1;
		}
		s1 = w.cinbox(mouse, 455, 303, 575, 323, food[5]);
		if (s1 != "")
		{
			food[5] = s1;
		}
		s1 = w.cinbox(mouse, 455, 348, 575, 368, food[6]);
		if (s1 != "")
		{
			food[6] = s1;
		}
		s1 = w.cinbox(mouse, 455, 393, 575, 413, food[7]);
		if (s1 != "")
		{
			food[7] = s1;
		}
		s1 = w.cinbox(mouse, 593, 78, 673, 98, price[0]);
		if (s1 != "")
		{
			price[0] = s1;
		}
		s1 = w.cinbox(mouse, 593, 123, 673, 143, price[1]);
		if (s1 != "")
		{
			price[1] = s1;
		}
		s1 = w.cinbox(mouse, 593, 168, 673, 188, price[2]);
		if (s1 != "")
		{
			price[2] = s1;
		}
		s1 = w.cinbox(mouse, 593, 214, 673, 234, price[3]);
		if (s1 != "")
		{
			price[3] = s1;
		}
		s1 = w.cinbox(mouse, 593, 258, 673, 278, price[4]);
		if (s1 != "")
		{
			price[4] = s1;
		}
		s1 = w.cinbox(mouse, 593, 303, 673, 323, price[5]);
		if (s1 != "")
		{
			price[5] = s1;
		}
		s1 = w.cinbox(mouse, 593, 348, 673, 368, price[6]);
		if (s1 != "")
		{
			price[6] = s1;
		}
		s1 = w.cinbox(mouse, 593, 393, 673, 413, price[7]);
		if (s1 != "")
		{
			price[7] = s1;
		}

		if (w.set_button(mouse, 114, 440, 186, 460, "    ȷ ��    "))
		{
			user = password = name = age = sex = tel = adress = dis = "";
			Widget w2(352, 469);
			w2.clear();
			goto orderfrom_c;
			/*float disc = stof(dis);
			int iage = stoi(age);
			int foodnum = 0;
			Food* pfood = new Food[8];
			for (int i = 0; i < 8; i++)
			{
				if (food[i] != "" && price[i] != "")
				{
					cout << "food";
					float pr = stof(price[i]);
					pfood[i].SetData(food[i], pr);
					foodnum++;
				}
			}
			password = point2->Getpassword(567);
			Shop customer(user, password, 2, name, sex, iage, tel, 2.5, disc, adress, pfood, foodnum);
			point2->SetData(customer);
			Widget w(352, 288);
			goto login_window;*/
		}
		if (w.set_button(mouse, 500, 440, 572, 460, "    �� ��    "))
		{

			user = password = name = age = sex = tel = adress = dis = "";
			Widget w2(352, 469);
			w2.clear();
			goto orderfrom_c;
		}
	}
	getchar();
orderfrom_s://�����йض���
	w.set_title("�鿴����");

	//cout << point1->Getname();
	point5 = new Order_form;
	
	point4 = Ohead->next;
	
	for (int i = 0; point4 != NULL && i < ON; point4 = point4->next, i++)
	{
		if (point4->Getshopname() == point2->Getshopname())
		{
			cout << "ע��";
			Order_form orderform = *point4;
			Register(point5, orderform);
			cout << "wanhcneg";
		}
		if (i == CN)
		{
			point4 = NULL;
		}
	}
	num2 = 0;
	float allgain;
	for (; 1;)
	{
		allgain = 0;
		if (point5->next->Getcusname() == "")
		{
			cout << 2;
			w.message_warn(a, 20, "û���յ�����");
			Widget w2(700, 514);
			w2.clear();
			goto shop;
		}
		else
		{
			cout << 3;
			point4 = point5->next;
		}
		
		for (int i = 1; i <= 8 * num2; i++, point4 = point4->next)
		{

		}
		mouse = GetMouseMsg();
		w.set_button(mouse, 90, 40, 157, 60, "��͹˿�");
		w.set_button(mouse, 215, 40, 250, 60, "����");

		for (int i = 1, num1 = num2 * 8 + 1; i <= 8 && point4 != NULL; num1++, i++, point4 = point4->next)
		{
			allgain += point4->Getcost();
			w.set_button(mouse, 40, 40 + 40 * i, xx1 + 10, 40 * i + 60, to_string(num1));
			if (w.set_button(mouse, xx1, 40 + 40 * i, xx1 + 120, 40 * i + 60, point4->Getcusname()))
			{
				w.clear();
				Widget w2(700, 514);
				goto orderfrom_s2;
			}
			w.set_button(mouse, xx1 + 140, 40 + 40 * i, xx1 + 210, 40 * i + 60, (point4->Getshopname()));

		}
		w.output("�������룺", 40, 440);
		w.output(to_string(allgain).substr(0, 5), 130, 440);
		if (w.set_button(mouse, 40, 400, 110, 420, "  ��һҳ  "))
		{
			if (checknum % 4 == 0 && num2 > 0)
			{
				w.clear();

				num2--;
				//cout << num2;
			}
		}
		if (w.set_button(mouse, 215, 400, 285, 420, "  ��һҳ  "))
		{
			if (checknum % 4 == 0 && (8 * num2 < ON - 8))
			{
				w.clear();
				num2++;
				//cout << num2;
			}
		}
		if (w.set_button(mouse, 130, 400, 195, 420, "   �� ��   "))
		{


			Widget w2(700, 514);
			w2.clear();
			goto shop;

		}


	}

	getchar();
orderfrom_s2://�鿴ĳһ����
	for (int i = 0; i < 9; i++) { food[i] = price[i] = ""; }
	user = "�鿴����" + to_string(point4->Getnumber());
	w.set_title(user);
	user = point4->Getcusname();
	password = point4->Getshopname();
	name = point4->Getmanname();
	age = to_string(point4->Getcost());
	if (point4->Getflag() == 1)
	{
		sex = "���µ�";
	}
	if (point4->Getflag() == 2)
	{
		sex = "���ɷ�";
	}
	if (point4->Getflag() == 3)
	{
		sex = "���յ�";
	}
	//tel = point2->Gettel();
	//adress = point2->Getshopname();
	//dis = to_string(point2->Getdiscount());
	p_food = point4->Getfhead();
	for (int i = 0; i < point4->Getfnum(); i++)
	{
		food[i] = p_food[i].Getname();
		price[i] = to_string(p_food[i].Getprice()).substr(0,5);
	}
	for (; 1;)
	{
		mouse = GetMouseMsg();
		w.output("�µ��˿ͣ�", 70, 80);
		w.output("�㵥�̵꣺", 70, 125);
		w.output("�յ���Ա��", 70, 170);
		w.output("�������ѣ�", 70, 215);
		w.output("����״̬��", 70, 260);
		//w.output("��ϵ��ʽ��", 70, 305);
		//w.output("�̵����ƣ�", 70, 350);
		//w.output("�̵��ۿۣ�", 70, 395);

		s1 = w.cinbox(mouse, 145, 78, 266, 98, user);
		//if (s1 != ""){user = s1;}
		s1 = w.cinbox(mouse, 145, 123, 266, 143, password);
		//if (s1 != ""){password = s1;}
		s1 = w.cinbox(mouse, 145, 168, 266, 188, name);
		//if (s1 != ""){name = s1;}
		s1 = w.cinbox(mouse, 145, 214, 266, 234, age);
		/*if (s1 != "")
		{
			age = s1;
		}*/
		s1 = w.cinbox(mouse, 145, 258, 266, 278, sex);
		/*if (s1 != "")
		{
			sex = s1;
		}*/
		/*s1 = w.cinbox(mouse, 145, 303, 266, 323, tel);
		if (s1 != "")
		{
			tel = s1;
		}
		s1 = w.cinbox(mouse, 145, 348, 266, 368, adress);//����
		if (s1 != "")
		{
			adress = s1;
		}
		s1 = w.cinbox(mouse, 145, 393, 266, 413, dis);//�ۿ�
		if (s1 != "")
		{
			dis = s1;
		}*/

		w.output("��Ʒ1��", 400, 80);
		w.output("��Ʒ2��", 400, 125);
		w.output("��Ʒ3��", 400, 170);
		w.output("��Ʒ4��", 400, 215);
		w.output("��Ʒ5��", 400, 260);
		w.output("��Ʒ6��", 400, 305);
		w.output("��Ʒ7��", 400, 350);
		w.output("��Ʒ8��", 400, 395);
		w.output("�۸�", 595, 50);
		s1 = w.cinbox(mouse, 455, 78, 575, 98, food[0]);
		if (s1 != "")
		{
			food[0] = s1;
		}
		s1 = w.cinbox(mouse, 455, 123, 575, 143, food[1]);
		if (s1 != "")
		{
			food[1] = s1;
		}
		s1 = w.cinbox(mouse, 455, 168, 575, 188, food[2]);
		if (s1 != "")
		{
			food[2] = s1;
		}
		s1 = w.cinbox(mouse, 455, 214, 575, 234, food[3]);
		if (s1 != "")
		{
			food[3] = s1;
		}
		s1 = w.cinbox(mouse, 455, 258, 575, 278, food[4]);
		if (s1 != "")
		{
			food[4] = s1;
		}
		s1 = w.cinbox(mouse, 455, 303, 575, 323, food[5]);
		if (s1 != "")
		{
			food[5] = s1;
		}
		s1 = w.cinbox(mouse, 455, 348, 575, 368, food[6]);
		if (s1 != "")
		{
			food[6] = s1;
		}
		s1 = w.cinbox(mouse, 455, 393, 575, 413, food[7]);
		if (s1 != "")
		{
			food[7] = s1;
		}
		s1 = w.cinbox(mouse, 593, 78, 673, 98, price[0]);
		if (s1 != "")
		{
			price[0] = s1;
		}
		s1 = w.cinbox(mouse, 593, 123, 673, 143, price[1]);
		if (s1 != "")
		{
			price[1] = s1;
		}
		s1 = w.cinbox(mouse, 593, 168, 673, 188, price[2]);
		if (s1 != "")
		{
			price[2] = s1;
		}
		s1 = w.cinbox(mouse, 593, 214, 673, 234, price[3]);
		if (s1 != "")
		{
			price[3] = s1;
		}
		s1 = w.cinbox(mouse, 593, 258, 673, 278, price[4]);
		if (s1 != "")
		{
			price[4] = s1;
		}
		s1 = w.cinbox(mouse, 593, 303, 673, 323, price[5]);
		if (s1 != "")
		{
			price[5] = s1;
		}
		s1 = w.cinbox(mouse, 593, 348, 673, 368, price[6]);
		if (s1 != "")
		{
			price[6] = s1;
		}
		s1 = w.cinbox(mouse, 593, 393, 673, 413, price[7]);
		if (s1 != "")
		{
			price[7] = s1;
		}

		if (w.set_button(mouse, 114, 440, 186, 460, "    ȷ ��    "))
		{
			user = password = name = age = sex = tel = adress = dis = "";
			Widget w2(352, 469);
			w2.clear();
			goto orderfrom_s;
			/*float disc = stof(dis);
			int iage = stoi(age);
			int foodnum = 0;
			Food* pfood = new Food[8];
			for (int i = 0; i < 8; i++)
			{
				if (food[i] != "" && price[i] != "")
				{
					cout << "food";
					float pr = stof(price[i]);
					pfood[i].SetData(food[i], pr);
					foodnum++;
				}
			}
			password = point2->Getpassword(567);
			Shop customer(user, password, 2, name, sex, iage, tel, 2.5, disc, adress, pfood, foodnum);
			point2->SetData(customer);
			Widget w(352, 288);
			goto login_window;*/
		}
		if (w.set_button(mouse, 500, 440, 572, 460, "    �� ��    "))
		{
	
			user = password = name = age = sex = tel = adress = dis = "";
	
			Widget w(352, 469);

			w.clear();

			goto orderfrom_s;
		}
	}
	getchar();

orderfrom_e://������Ա�йض���
	w.set_title("�鿴����");

	//cout << point1->Getname();
	point5 = new Order_form;
	point4 = Ohead->next;
	for (int i = 0; point4 != NULL && i < ON; point4 = point4->next, i++)
	{
		if (point4->Getmanname() == point3->Getname())
		{
			cout << "ע��";
			Order_form orderform = *point4;
			Register(point5, orderform);
		}
		if (i == CN)
		{
			point4 = NULL;
		}
	}
	num2 = 0;
	for (; 1;)
	{

		if (point5->next->Getcusname() == "")
		{
			w.message_warn(a, 20, "����û���յ�����");
			Widget w2(352, 469);
			w2.clear();
			goto expressman;
		}
		else
		{
			point4 = point5->next;
		}
		for (int i = 1; i <= 8 * num2; i++, point4 = point4->next)
		{

		}
		mouse = GetMouseMsg();
		w.set_button(mouse, 90, 40, 157, 60, "��͹˿�");
		w.set_button(mouse, 215, 40, 250, 60, "����");

		for (int i = 1, num1 = num2 * 8 + 1; i <= 8 && point4 != NULL; num1++, i++, point4 = point4->next)
		{

			w.set_button(mouse, 40, 40 + 40 * i, xx1 + 10, 40 * i + 60, to_string(num1));
			if (w.set_button(mouse, xx1, 40 + 40 * i, xx1 + 120, 40 * i + 60, point4->Getcusname()))
			{
				w.clear();
				Widget w2(700, 514);
				goto orderfrom_e2;
			}
			w.set_button(mouse, xx1 + 140, 40 + 40 * i, xx1 + 210, 40 * i + 60, (point4->Getshopname()));
			if (w.set_button(mouse, xx1 + 235, 40 + 40 * i, xx1 + 275, 40 * i + 60, "����"))
			{
				if (check % 4 == 0)
				{
					Find(Ohead,point4->Getnumber())->next->mark(2);
					w.message_warn(a, 20, "�ѽ���");
				}
				check++;
				//cout << check;
			}
		}
		if (w.set_button(mouse, 40, 400, 110, 420, "  ��һҳ  "))
		{
			if (checknum % 4 == 0 && num2 > 0)
			{
				w.clear();

				num2--;
				//cout << num2;
			}
		}
		if (w.set_button(mouse, 215, 400, 285, 420, "  ��һҳ  "))
		{
			if (checknum % 4 == 0 && (8 * num2 < ON - 8))
			{
				w.clear();
				num2++;
				//cout << num2;
			}
		}
		if (w.set_button(mouse, 130, 400, 195, 420, "   �� ��   "))
		{


			Widget w2(352, 469);
			w2.clear();
			goto expressman;

		}


	}

	getchar();

orderfrom_e2://�鿴ĳһ����
	for (int i = 0; i < 9; i++) { food[i] = price[i] = ""; }
	user = "�鿴����" + to_string(point4->Getnumber());
	w.set_title(user);
	user = point4->Getcusname();
	password = point4->Getshopname();
	name = point4->Getmanname();
	age = to_string(point4->Getcost());
	if (point4->Getflag() == 1)
	{
		sex = "���µ�";
	}
	if (point4->Getflag() == 2)
	{
		sex = "���ɷ�";
	}
	if (point4->Getflag() == 3)
	{
		sex = "���յ�";
	}
	//tel = point2->Gettel();
	//adress = point2->Getshopname();
	//dis = to_string(point2->Getdiscount());
	p_food = point4->Getfhead();
	for (int i = 0; i < point4->Getfnum(); i++)
	{
		food[i] = p_food[i].Getname();
		price[i] = to_string(p_food[i].Getprice()).substr(0,5);
	}
	for (; 1;)
	{
		mouse = GetMouseMsg();
		w.output("�µ��˿ͣ�", 70, 80);
		w.output("�㵥�̵꣺", 70, 125);
		w.output("�յ���Ա��", 70, 170);
		w.output("�������ѣ�", 70, 215);
		w.output("����״̬��", 70, 260);
		//w.output("��ϵ��ʽ��", 70, 305);
		//w.output("�̵����ƣ�", 70, 350);
		//w.output("�̵��ۿۣ�", 70, 395);

		s1 = w.cinbox(mouse, 145, 78, 266, 98, user);
		//if (s1 != ""){user = s1;}
		s1 = w.cinbox(mouse, 145, 123, 266, 143, password);
		//if (s1 != ""){password = s1;}
		s1 = w.cinbox(mouse, 145, 168, 266, 188, name);
		//if (s1 != ""){name = s1;}
		s1 = w.cinbox(mouse, 145, 214, 266, 234, age);
		/*if (s1 != "")
		{
			age = s1;
		}*/
		s1 = w.cinbox(mouse, 145, 258, 266, 278, sex);
		/*if (s1 != "")
		{
			sex = s1;
		}*/
		/*s1 = w.cinbox(mouse, 145, 303, 266, 323, tel);
		if (s1 != "")
		{
			tel = s1;
		}
		s1 = w.cinbox(mouse, 145, 348, 266, 368, adress);//����
		if (s1 != "")
		{
			adress = s1;
		}
		s1 = w.cinbox(mouse, 145, 393, 266, 413, dis);//�ۿ�
		if (s1 != "")
		{
			dis = s1;
		}*/

		w.output("��Ʒ1��", 400, 80);
		w.output("��Ʒ2��", 400, 125);
		w.output("��Ʒ3��", 400, 170);
		w.output("��Ʒ4��", 400, 215);
		w.output("��Ʒ5��", 400, 260);
		w.output("��Ʒ6��", 400, 305);
		w.output("��Ʒ7��", 400, 350);
		w.output("��Ʒ8��", 400, 395);
		w.output("�۸�", 595, 50);
		s1 = w.cinbox(mouse, 455, 78, 575, 98, food[0]);
		if (s1 != "")
		{
			food[0] = s1;
		}
		s1 = w.cinbox(mouse, 455, 123, 575, 143, food[1]);
		if (s1 != "")
		{
			food[1] = s1;
		}
		s1 = w.cinbox(mouse, 455, 168, 575, 188, food[2]);
		if (s1 != "")
		{
			food[2] = s1;
		}
		s1 = w.cinbox(mouse, 455, 214, 575, 234, food[3]);
		if (s1 != "")
		{
			food[3] = s1;
		}
		s1 = w.cinbox(mouse, 455, 258, 575, 278, food[4]);
		if (s1 != "")
		{
			food[4] = s1;
		}
		s1 = w.cinbox(mouse, 455, 303, 575, 323, food[5]);
		if (s1 != "")
		{
			food[5] = s1;
		}
		s1 = w.cinbox(mouse, 455, 348, 575, 368, food[6]);
		if (s1 != "")
		{
			food[6] = s1;
		}
		s1 = w.cinbox(mouse, 455, 393, 575, 413, food[7]);
		if (s1 != "")
		{
			food[7] = s1;
		}
		s1 = w.cinbox(mouse, 593, 78, 673, 98, price[0]);
		if (s1 != "")
		{
			price[0] = s1;
		}
		s1 = w.cinbox(mouse, 593, 123, 673, 143, price[1]);
		if (s1 != "")
		{
			price[1] = s1;
		}
		s1 = w.cinbox(mouse, 593, 168, 673, 188, price[2]);
		if (s1 != "")
		{
			price[2] = s1;
		}
		s1 = w.cinbox(mouse, 593, 214, 673, 234, price[3]);
		if (s1 != "")
		{
			price[3] = s1;
		}
		s1 = w.cinbox(mouse, 593, 258, 673, 278, price[4]);
		if (s1 != "")
		{
			price[4] = s1;
		}
		s1 = w.cinbox(mouse, 593, 303, 673, 323, price[5]);
		if (s1 != "")
		{
			price[5] = s1;
		}
		s1 = w.cinbox(mouse, 593, 348, 673, 368, price[6]);
		if (s1 != "")
		{
			price[6] = s1;
		}
		s1 = w.cinbox(mouse, 593, 393, 673, 413, price[7]);
		if (s1 != "")
		{
			price[7] = s1;
		}

		if (w.set_button(mouse, 114, 440, 186, 460, "    ȷ ��    "))
		{
			user = password = name = age = sex = tel = adress = dis = "";
			Widget w2(352, 469);
			w2.clear();
			goto orderfrom_e;
			/*float disc = stof(dis);
			int iage = stoi(age);
			int foodnum = 0;
			Food* pfood = new Food[8];
			for (int i = 0; i < 8; i++)
			{
				if (food[i] != "" && price[i] != "")
				{
					cout << "food";
					float pr = stof(price[i]);
					pfood[i].SetData(food[i], pr);
					foodnum++;
				}
			}
			password = point2->Getpassword(567);
			Shop customer(user, password, 2, name, sex, iage, tel, 2.5, disc, adress, pfood, foodnum);
			point2->SetData(customer);
			Widget w(352, 288);
			goto login_window;*/
		}
		if (w.set_button(mouse, 500, 440, 572, 460, "    �� ��    "))
		{

			user = password = name = age = sex = tel = adress = dis = "";
			Widget w2(352, 469);
			w2.clear();
			goto orderfrom_e;
		}
	}
	getchar();
//-----------------------------------------------
rcustomer://�˿�ע��
	for (; 1;)
	{
		mouse = GetMouseMsg();
		w.set_title("�˿�ע��");
		w.output("��        �ţ�", 70, 80);
		w.output("��        �룺", 70, 125);
		w.output("��        ����", 70, 170);
		w.output("��        �䣺", 70, 215);
		w.output("��        ��", 70, 260);
		w.output("��ϵ��ʽ��", 70, 305);
		w.output("��        ַ��", 70, 350);
		s1=w.cinbox(mouse, 145, 78, 266, 98,user);
		if (s1 != "")
		{
			if (Check(Chead, s1) == NULL)
			{
				//cout << Check(Chead, s1)->next->Getuser();
				user = s1;
			}
			else
			{
				w.play_music(2);
				w.message_warn(a, 20, "���˺��Ѵ���");
				
			}
		}
		s1=w.cinbox(mouse, 145, 123, 266, 143,password);
		if (s1 != "")
		{
			if (s1.length() < 6)
			{
				w.message_warn(a, 20, "��������ڵ���6λ");
			}
			else if (Check(s1))
			{
				password = s1;
			}
			else
			{
				w.message_warn(a,20,"��������ĸ��������Ϊ����");
			}
		}
		s1=w.cinbox(mouse, 145, 168, 266, 188,name);
		if (s1 != "")
		{
			int j = 0;
			for (int i = 0; i < s1.length(); i++)
			{
				if ((s1[i] > 64 && s1[i] < 91) || (s1[i] > 96 && s1[i] < 123) || (s1[i] <= 0 && s1[i] > -90))
				{

				}
				else j = 1;
			}
			if (j == 0&&s1.length()>3)
			{
				name = s1;
			}
			else w.message_warn(a,20,"��������ȷ����");
		}
		s1=w.cinbox(mouse, 145, 214, 266, 234,age);
		if (s1 != "")
		{
			if ((s1 >= "10"&&s1.length()==2) || (s1 <= "120"&&s1.length()==3))
			{


				age = s1;
			}
			else w.message_warn(a, 20, "��������ȷ����");
		}
		s1=w.cinbox(mouse, 145, 258, 266, 278,sex);
		if (s1 != "")
		{
			if (s1 == "woman" || s1 == "man" || s1 == "Ů" || s1 == "��" || s1 == "male" || s1 == "female")
			{
				sex = s1;
			}
			else w.message_warn(a, 20, "��������ȷ�Ա�");
		}
		s1=w.cinbox(mouse, 145, 303, 266, 323,tel);
		if (s1 != "")
		{
			int j=0;
			for (int i = 0; i < s1.length(); i++)
			{
				if (s1[i] < 48 || s1[i]>57)
				{
					j = 1;
				}
			}
			if (j == 0&&s1.length()==11)
			{
				tel = s1;
			}
			else w.message_warn(a,20,"��������ȷ�ֻ���");
		}
		s1=w.cinbox(mouse, 145, 348, 266, 368,adress);
		if (s1 != "")
		{
			adress = s1;
		}

		if (w.set_button(mouse, 64, 395, 136, 415, "    ע ��    ")) 
		{
			if (check % 4 == 0)
			{
				if (user == "" || password == "" || name == "" || age == "" || sex == "" || tel == "" || adress == "")
				{
					w.play_music(3);
					w.message_warn(a,20,"�벻Ҫ©��");
					goto rcustomer;
				}

				int iage = stoi(age);
				Customer customer(user, password, 3, name, sex, iage, tel, adress);
				//Expressman* pcus = &customer;
				//customer.Show();
				Register(Chead, customer);//����ֵĶ������⣬����iageȫ��д���ļ���ʧ���ݡ�
				//pcus->Show();
				CN++;
				Widget w(352, 288);
				goto login_window;
			}
		}
		if (w.set_button(mouse, 200, 395, 272, 415, "    �� ��    "))
		{
			Widget w(352, 288);
			user = password = name = age = sex = tel = adress = "";
			goto login_window;
		}
	}
	getchar();

rshop://����ע��
	for (; 1;)
	{
		mouse = GetMouseMsg();
		w.set_title("����ע��");
		w.output("��        �ţ�", 70, 80);
		w.output("��        �룺", 70, 125);
		w.output("��        ����", 70, 170);
		w.output("��        �䣺", 70, 215);
		w.output("��        ��", 70, 260);
		w.output("��ϵ��ʽ��", 70, 305);
		w.output("�̵����ƣ�", 70, 350);
		w.output("�̵��ۿۣ�", 70, 395);
		
		s1 = w.cinbox(mouse, 145, 78, 266, 98, user);
		if (s1 != "")
		{
			if (Check(Shead, s1) == NULL)
			{
				//cout << Check(Chead, s1)->next->Getuser();
				user = s1;
			}
			else
			{
				w.play_music(2);
				w.message_warn(a, 20, "���˺��Ѵ���");

			}
		}
		s1 = w.cinbox(mouse, 145, 123, 266, 143, password);
		if (s1 != "")
		{
			if (s1.length() < 6)
			{
				w.message_warn(a, 20, "��������ڵ���6λ");
			}
			else if (Check(s1))
			{
				password = s1;
			}
			else
			{
				w.message_warn(a, 20, "��������ĸ��������Ϊ����");
			}
		}
		s1 = w.cinbox(mouse, 145, 168, 266, 188, name);
		if (s1 != "")
		{
			int j = 0;
			for (int i = 0; i < s1.length(); i++)
			{
				if ((s1[i] > 64 && s1[i] < 91) || (s1[i] > 96 && s1[i] < 123) || (s1[i] <= 0 && s1[i] > -90))
				{

				}
				else j = 1;
			}
			if (j == 0 && s1.length() > 3)
			{
				name = s1;
			}
			else w.message_warn(a, 20, "��������ȷ����");
		}
		s1 = w.cinbox(mouse, 145, 214, 266, 234, age);
		if (s1 != "")
		{
			if ((s1 >= "10" && s1.length() == 2) || (s1 <= "120" && s1.length() == 3))
			{


				age = s1;
			}
			else w.message_warn(a, 20, "��������ȷ����");
		}
		s1 = w.cinbox(mouse, 145, 258, 266, 278, sex);
		if (s1 != "")
		{
			if (s1 == "woman" || s1 == "man" || s1 == "Ů" || s1 == "��" || s1 == "male" || s1 == "female")
			{
				sex = s1;
			}
			else w.message_warn(a, 20, "��������ȷ�Ա�");
		}
		s1 = w.cinbox(mouse, 145, 303, 266, 323, tel);
		if (s1 != "")
		{
			int j = 0;
			for (int i = 0; i < s1.length(); i++)
			{
				if (s1[i] < 48 || s1[i]>57)
				{
					j = 1;
				}
			}
			if (j == 0 && s1.length() == 11)
			{
				tel = s1;
			}
			else w.message_warn(a, 20, "��������ȷ�ֻ���");
		}
		s1 = w.cinbox(mouse, 145, 348, 266, 368, adress);//����
		if (s1 != "")
		{
			adress = s1;
		}
		s1 = w.cinbox(mouse, 145, 393, 266, 413, dis);//�ۿ�
		if (s1 != "")
		{
			int j = 0;
			for (int i = 0; i < s1.length(); i++)
			{
				if (s1[i] > 57 || s1[i] < 48)
				{
					if (s1[i] == 46)
					{

					}
					else
					{
						j = 1;
					}
				}
			}
			if (j == 0)
			{
				dis = s1;
			}
			else
			{
				w.message_warn(a, 20, "��������ȷ�ۿ�����0.8==����");
			}
			
		}
		
		w.output("��Ʒ1��", 400, 80);
		w.output("��Ʒ2��", 400, 125);
		w.output("��Ʒ3��", 400, 170);
		w.output("��Ʒ4��", 400, 215);
		w.output("��Ʒ5��", 400, 260);
		w.output("��Ʒ6��", 400, 305);
		w.output("��Ʒ7��", 400, 350);
		w.output("��Ʒ8��", 400, 395);
		w.output("�۸�",595, 50);
		s1 = w.cinbox(mouse, 455, 78, 575, 98, food[0]);
		if (s1 != "")
		{
			food[0] = s1;
		}
		s1 = w.cinbox(mouse, 455, 123, 575, 143, food[1]);
		if (s1 != "")
		{
			food[1] = s1;
		}
		s1 = w.cinbox(mouse, 455, 168, 575, 188, food[2]);
		if (s1 != "")
		{
			food[2] = s1;
		}
		s1 = w.cinbox(mouse, 455, 214, 575, 234, food[3]);
		if (s1 != "")
		{
			food[3] = s1;
		}
		s1 = w.cinbox(mouse, 455, 258, 575, 278, food[4]);
		if (s1 != "")
		{
			food[4] = s1;
		}
		s1 = w.cinbox(mouse, 455, 303, 575, 323, food[5]);
		if (s1 != "")
		{
			food[5] = s1;
		}
		s1 = w.cinbox(mouse, 455, 348, 575, 368, food[6]);
		if (s1 != "")
		{
			food[6] = s1;
		}
		s1 = w.cinbox(mouse, 455, 393, 575, 413, food[7]);
		{
			food[7] = s1;
		}
		s1 = w.cinbox(mouse, 593, 78, 633, 98, price[0]);
		if (s1 != "")
		{
			int j = 0;
			for (int i = 0; i < s1.length(); i++)
			{
				if (s1[i]>57||s1[i]<48) 
				{
					if (s1[i] == 46)
					{

					}
					else
					{
						j = 1;
					}
				}
			}
			if (j == 0)
			{
				price[0] = s1;
			}
			else
			{
				w.message_warn(a, 20, "��������ȷ�۸�");
			}
		}
		s1 = w.cinbox(mouse, 593, 123, 633, 143, price[1]);
		if (s1 != "")
		{
			int j = 0;
			for (int i = 0; i < s1.length(); i++)
			{
				if (s1[i] > 57 || s1[i] < 48)
				{
					if (s1[i] == 46)
					{

					}
					else
					{
						j = 1;
					}
				}
			}
			if (j == 0)
			{
				price[1] = s1;
			}
			else
			{
				w.message_warn(a, 20, "��������ȷ�۸�");
			}
			
		}
		s1 = w.cinbox(mouse, 593, 168, 633, 188, price[2]);
		if (s1 != "")
		{
			int j = 0;
			for (int i = 0; i < s1.length(); i++)
			{
				if (s1[i] > 57 || s1[i] < 48)
				{
					if (s1[i] == 46)
					{

					}
					else
					{
						j = 1;
					}
				}
			}
			if (j == 0)
			{
				price[2] = s1;
			}
			else
			{
				w.message_warn(a, 20, "��������ȷ�۸�");
			}
		}
		s1 = w.cinbox(mouse, 593, 214, 633, 234, price[3]);
		if (s1 != "")
		{
			int j = 0;
			for (int i = 0; i < s1.length(); i++)
			{
				if (s1[i] > 57 || s1[i] < 48)
				{
					if (s1[i] == 46)
					{

					}
					else
					{
						j = 1;
					}
				}
			}
			if (j == 0)
			{
				price[3] = s1;
			}
			else
			{
				w.message_warn(a, 20, "��������ȷ�۸�");
			}
		}
		s1 = w.cinbox(mouse, 593, 258, 633, 278, price[4]);
		if (s1 != "")
		{
			int j = 0;
			for (int i = 0; i < s1.length(); i++)
			{
				if (s1[i] > 57 || s1[i] < 48)
				{
					if (s1[i] == 46)
					{

					}
					else
					{
						j = 1;
					}
				}
			}
			if (j == 0)
			{
				price[4] = s1;
			}
			else
			{
				w.message_warn(a, 20, "��������ȷ�۸�");
			}
		}
		s1 = w.cinbox(mouse, 593, 303, 633, 323, price[5]);
		if (s1 != "")
		{
			int j = 0;
			for (int i = 0; i < s1.length(); i++)
			{
				if (s1[i] > 57 || s1[i] < 48)
				{
					if (s1[i] == 46)
					{

					}
					else
					{
						j = 1;
					}
				}
			}
			if (j == 0)
			{
				price[5] = s1;
			}
			else
			{
				w.message_warn(a, 20, "��������ȷ�۸�");
			}
		}
		s1 = w.cinbox(mouse, 593, 348, 633, 368, price[6]);
		if (s1 != "")
		{
			int j = 0;
			for (int i = 0; i < s1.length(); i++)
			{
				if (s1[i] > 57 || s1[i] < 48)
				{
					if (s1[i] == 46)
					{

					}
					else
					{
						j = 1;
					}
				}
			}
			if (j == 0)
			{
				price[6] = s1;
			}
			else
			{
				w.message_warn(a, 20, "��������ȷ�۸�");
			}
		}
		s1 = w.cinbox(mouse, 593, 393, 633, 413, price[7]);
		if(s1!=""){
			int j = 0;
			for (int i = 0; i < s1.length(); i++)
			{
				if (s1[i] > 57 || s1[i] < 48)
				{
					if (s1[i] == 46)
					{

					}
					else
					{
						j = 1;
					}
				}
			}
			if (j == 0)
			{
				price[7] = s1;
			}
			else
			{
				w.message_warn(a, 20, "��������ȷ�۸�");
			}
		}

		if (w.set_button(mouse, 114, 440, 186, 460, "    ע ��    "))
		{
			if (check % 4 == 0)
			{
				if (user == "" || password == "" || name == "" || age == "" || sex == "" || tel == "" || adress == ""|| dis == "")
				{
					w.play_music(3);
					w.message_warn(a, 20, "�벻Ҫ©��");
					goto rshop;
				}
				float disc = stof(dis);
				int iage = stoi(age);
				int foodnum = 0;
				Food* pfood = new Food[8];
				for (int i = 0; i < 8; i++)
				{
					if (food[i] != "" && price[i] != "")
					{
						float pr = stof(price[i]);
						pfood[i].SetData(food[i], pr);
						foodnum++;
					}
				}

				Shop customer(user, password, 2, name, sex, iage, tel, 2.5, disc, adress, pfood, foodnum);
				//Shop(string st1, string st2, int in, string str, string c, int i, string str2, float s1, float s2, string s3, Food * p,int foodnum) :
				cout << "r" << endl;
				customer.Show();
				Register(Shead, customer);
				cout << "reg" << endl;
				customer.Show();
				SN++;
				Widget w(352, 288);
				goto login_window;
			}
		}
		if (w.set_button(mouse, 500, 440, 572, 460, "    �� ��    "))
		{
			Widget w(352, 288);
			user = password = name = age = sex = tel = adress = dis= "";
			goto login_window;
		}
	}
	getchar();

rexpressman://������Աע��
	for (; 1;)
	{
		mouse = GetMouseMsg();
		w.set_title("���Աע��");
		w.output("��        �ţ�", 70, 80);
		w.output("��        �룺", 70, 125);
		w.output("��        ����", 70, 170);
		w.output("��        �䣺", 70, 215);
		w.output("��        ��", 70, 260);
		w.output("��ϵ��ʽ��", 70, 305);
		w.output("����ʱ�䣺", 70, 350);
		s1 = w.cinbox(mouse, 145, 78, 266, 98, user);
		if (s1 != "")
		{
			if (Check(Ehead, s1) == NULL)
			{
				//cout << Check(Chead, s1)->next->Getuser();
				user = s1;
			}
			else
			{
				w.play_music(2);
				w.message_warn(a, 20, "���˺��Ѵ���");

			}
		}
		s1 = w.cinbox(mouse, 145, 123, 266, 143, password);
		if (s1 != "")
		{
			if (s1.length() < 6)
			{
				w.message_warn(a, 20, "��������ڵ���6λ");
			}
			else if (Check(s1))
			{
				password = s1;
			}
			else
			{
				w.message_warn(a, 20, "��������ĸ��������Ϊ����");
			}
		}
		s1 = w.cinbox(mouse, 145, 168, 266, 188, name);
		if (s1 != "")
		{
			int j = 0;
			for (int i = 0; i < s1.length(); i++)
			{
				if ((s1[i] > 64 && s1[i] < 91) || (s1[i] > 96 && s1[i] < 123) || (s1[i] <= 0 && s1[i] > -90))
				{

				}
				else j = 1;
			}
			if (j == 0 && s1.length() > 3)
			{
				name = s1;
			}
			else w.message_warn(a, 20, "��������ȷ����");
		}
		s1 = w.cinbox(mouse, 145, 214, 266, 234, age);
		if (s1 != "")
		{
			if ((s1 >= "10" && s1.length() == 2) || (s1 <= "120" && s1.length() == 3))
			{


				age = s1;
			}
			else w.message_warn(a, 20, "��������ȷ����");
		}
		s1 = w.cinbox(mouse, 145, 258, 266, 278, sex);
		if (s1 != "")
		{
			if (s1 == "woman" || s1 == "man" || s1 == "Ů" || s1 == "��" || s1 == "male" || s1 == "female")
			{
				sex = s1;
			}
			else w.message_warn(a, 20, "��������ȷ�Ա�");
		}
		s1 = w.cinbox(mouse, 145, 303, 266, 323, tel);
		if (s1 != "")
		{
			int j = 0;
			for (int i = 0; i < s1.length(); i++)
			{
				if (s1[i] < 48 || s1[i]>57)
				{
					j = 1;
				}
			}
			if (j == 0 && s1.length() == 11)
			{
				tel = s1;
			}
			else w.message_warn(a, 20, "��������ȷ�ֻ���");
		}
		s1 = w.cinbox(mouse, 145, 348, 266, 368, adress);
		if (s1 != "")
		{
			adress = s1;
		}

		if (w.set_button(mouse, 64, 395, 136, 415, "    ע ��    "))
		{
			if (check % 4 == 0)
			{
				if (user == "" || password == "" || name == "" || age == "" || sex == "" || tel == "" || adress == "")
				{
					w.play_music(3);
					w.message_warn(a, 20, "�벻Ҫ©��");
					goto rexpressman;
				}
				int iage = stoi(age);
				Expressman customer(user, password, 3, name, sex, iage, tel, 2.5, adress);
				Expressman* pcus = &customer;
				//customer.Show();
				Register(Ehead, customer);//����ֵĶ������⣬����iageȫ��д���ļ���ʧ���ݡ�
				//pcus->Show();
				EN++;
				Widget w(352, 288);
				goto login_window;
			}
		}
		if (w.set_button(mouse, 200, 395, 272, 415, "    �� ��    "))
		{
			Widget w(352, 288);
			user = password = name = age = sex = tel = adress = "";
			goto login_window;
		}
	}
	getchar();


order1://�㵥����1:ѡ�����
	//cout << SN;
	w.set_title("ѡ�����");
	num2 = 0;
	for (; 1;)
	{
		
		point2 = Shead->next;
		for (int i = 1; i <= 8 * num2; i++,point2=point2->next)
		{

		}
		mouse = GetMouseMsg();
		w.set_button(mouse,90,40,157,60,"��������");
		w.set_button(mouse,215,40,250,60,"����");
		
		for (int i=1,num1=num2*8+1; i <= 8 && point2!= NULL; num1++,i++,point2=point2->next)
		{
			
			w.set_button(mouse, 40, 40 + 40 * i, xx1 + 10, 40 * i + 60, to_string(num1));
			if (w.set_button(mouse, xx1, 40 + 40 * i, xx1 + 120, 40 * i + 60, point2->Getshopname()))
			{
				Widget w(352, 461);
				goto order2;
			}
			w.set_button(mouse, xx1+140, 40+40*i, xx1 + 210, 40*i + 60, to_string(point2->Getscore()));
			
		}
		if (w.set_button(mouse, 40, 400, 110, 420, "  ��һҳ  "))
		{
			if (checknum % 4 == 0&&num2>0)
			{
				w.clear();
				
				num2--;
				//cout << num2;
			}
		}
		if (w.set_button(mouse, 215, 400, 285, 420, "  ��һҳ  "))
		{
			if (checknum % 4 == 0&&(8*num2<SN-8))
			{
				w.clear();
				num2++;
				//cout << num2;
			}
		}
		if (w.set_button(mouse, 130, 400, 195, 420, "   �� ��   "))
		{
			Widget w2(352, 469);
			goto customer;
		}
		
	}
	getchar();

order2://�㵥����2:ѡ���Ʒ
	w.set_title("ѡ���Ʒ");
	for (int i = 0; i < 8; i++)
	{
		p_food[i].SetData("",0);
	}
	for (; 1;)
	{
		mouse = GetMouseMsg();
		w.set_button(mouse, 80, 40, 147, 60, "��Ʒ����");
		w.set_button(mouse, 225, 40, 260, 60, "�۸�");
		if (w.set_button(mouse, 300, 40, 335, 60, "���"))
		{
			if (check % 5 == 0)
			{
				w.clear();
				goto order2;
			}
			check++;
		}
		
		for (int i = 1,num1=1; i <= point2->Getfoodnum(); i++,num1++)
		{

			w.set_button(mouse, 40, 40 + 40 * i, xx1 + 10, 40 * i + 60, to_string(num1));
			if (w.set_button(mouse, xx1, 40 + 40 * i, xx1 + 120, 40 * i + 60, (point2->Getfood())[i-1].Getname()))
			{
				circle(xx1+250,40*i+50,5);
				p_food[i-1].SetData(point2->Getfood()[i - 1]);
				
			}
			w.set_button(mouse, xx1 + 150, 40 + 40 * i, xx1 + 220, 40 * i + 60, to_string((point2->Getfood())[i-1].Getprice()));

		}
		if (w.set_button(mouse, 40, 400, 110, 420, "   ѡ ��   "))
		{
			if (checknum % 4 == 0)
			{
				num2 = 0;
				for (int i = 0; i < 8; i++)
				{
					
					if (p_food[i].Getname() != "")
					{
						//cout << p_food[i].Getname()<<endl;
						num2++;
						//cout << num2<<endl;
					}

				}
				string allfood="";
				Food* o_food = new Food[num2];
				int j = 0;
				float cost = 0;;
				for (int i = 0; i < num2; i++)
				{
					
					for (; j < 8; j++)
					{
						if (p_food[j].Getname() != "")
						{
							o_food[i].SetData(p_food[j]);
							j++;
							break;
						}
						
						//cout << o_food[i].Getname() << endl;
					}
					cost += o_food[i].Getprice()*point2->Getdiscount();
					allfood += o_food[i].Getname();
					//cout << allfood << endl;
				}
				if (w.message_question(a, 9, "��ѡ����", "ȷ��", allfood.c_str()))
				{
					cout << "queren" << endl;
					srand((int)time(0));
					int randnum = rand() % (EN);
					cout << EN << endl;
					cout << randnum<<endl;
					point3 = Ehead->next;
					for (int i = 0; i < randnum; point3 = point3->next,i++)
					{
						cout << point3->Getname();
					}
					Order_form orderform(ON + 1, point1->Getname(),point3->Getname(),point2->Getshopname(),num2,o_food,cost,1);
					Register(Ohead, orderform);
					ON++;
					//Order_form(int num, string s1, string s2, int fn, Food* p, float c, int f) 
				}
				
				//w.message_question(a,9,"��ѡ����","ȷ��","����675");
		
				//cout << fk;
			}
			checknum++;

		}
		if (w.set_button(mouse, 215, 400, 285, 420, "   �� ��   "))
		{
			//cout << "fanhui";
			Widget w(352, 461);
			goto order1;
		}
		Sleep(10);
	}
	getchar();

end://����¼���ļ�
	writeto(filename, Chead, CN);
	writeto("expressman.txt", Ehead, EN);
	writeto("shop.txt", Shead, SN);
	writeto("order.txt", Ohead, ON);
	return 0;
}