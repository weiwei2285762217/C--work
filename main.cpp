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
	//console控制台的登陆注册操作
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
	
		//--------------------------------------------------------------------------准备
		cout << "欢迎使用点餐系统" << endl;
	begin:
		cout << "输入1注册2登陆" << endl;
		int flag;
		cin >> flag;
		switch (flag)
		{
		case 1:cout << "注册" << endl; goto reg; break;
		case 2:cout << "登陆" << endl; goto log; break;
		}
	reg:
		cout << "输入注册用户种类1客户2店铺3配送人员" << endl;
		cin >> kind;
		switch (kind)
		{
		case 1:Register(Chead); CN++; break;
		case 2:Register(Shead); SN++; break;
		case 3:Register(Ehead); EN++; break;
		default:cout << "error" << endl; goto reg;
		}
	log:
		cout << "选择你的用户类型登陆1客户2店铺3配送人员" << endl;
		cin >> kind;
		switch (kind)
		{
		case 1:kind = Login(Chead);
			if (kind == 0) { cout << "账号或密码错误" << endl; goto begin; }
			else goto window1; break;
		case 2:kind = Login(Shead);
			if (kind == 0) { cout << "账号或密码错误" << endl; goto begin; }
			else goto window2; break;
		case 3:kind = Login(Ehead);
			if (kind == 0) { cout << "账号或密码错误" << endl; goto begin; }
			else goto window3; break;
		default:cout << "error" << endl; goto log;
		}
	window1:
		cout << "登陆成功：顾客" << endl;
		p->for_customer(Shead, SN);

	window2:
		cout << "登陆成功：店主" << endl;


	window3:
		cout << "登陆成功：快递员" << endl;
		cout << "已收到的订单" << endl;



		//-------------------------------------------------------------------------------结束
		writeto(filename, Chead, CN);
		writeto("expressman.txt", Ehead, EN);
		writeto("shop.txt", Shead, SN);
		return 0;
	}
	//可视化操作
	//数据准备
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
	//以上头指针和计数定义以及文件读入
	Customer* point1 = Chead; Shop* point2 = Shead; Expressman* point3 = Ehead; Order_form* point4 = Ohead;//当前指向
	Order_form* point5 = NULL;
	Customer* point6=NULL; Shop* point7 = NULL; Expressman* point8 = NULL;
	Order_form from;
	int yy1, xx1 = 60, fk;
	int checknum = 0, num2 = 0, num1=0;
	string foodkind;
	//其他中间所需中间数据
	
	//开始
	Widget w(352, 288);
	

login_window://登录窗口
	
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
		/*if (w.set_checkbox(mouse, 55, 20, 75, 40, "顾客"))
		{

			b1 = 1;
			cout << b1;
		}
		else b1 = 0;
		if (b2 = w.set_checkbox(mouse, 135, 20, 155, 40, "店主"))
		{
			
			b2 = 2;
			cout << b2;
		}
		else b2 = 0;
		if (b3 = w.set_checkbox(mouse, 210, 20, 230, 40, "快递员"))
		{
		
			b3 = 3;
			cout << b3;
		}
		else b3 = 0;*/
		/*if(w.set_checkbox(mouse, 55, 20, 75, 40, "顾客"))
		{
			if (checkbox_flag == 2)
			{
				w.set_checkbox(mouse2, 135, 20, 155, 40, "店主");
				cout << "A2"<<endl;
			}
			if (checkbox_flag == 3)
			{
				w.set_checkbox(mouse3, 210, 20, 230, 40, "快递员");
				cout << "A3" << endl;
			}
			checkbox_flag = 1;
			cout << checkbox_flag;
		}
		if(w.set_checkbox(mouse, 135, 20, 155, 40, "店主"))
		{
			if (checkbox_flag == 1)
			{
				cout << "B1" << endl;
				w.set_checkbox(mouse1, 55, 20, 75, 40, "顾客");
			}
			if (checkbox_flag == 3)
			{
				cout << "B3" << endl;
				w.set_checkbox(mouse3, 210, 20, 230, 40, "快递员");
			}
			checkbox_flag = 2;
			cout << checkbox_flag;
		}
		if(w.set_checkbox(mouse, 210, 20, 230, 40, "快递员"))
		{
			if (checkbox_flag == 1)
			{
				cout << "C1" << endl;
				w.set_checkbox(mouse1, 55, 20, 75, 40, "顾客");
			}
			if (checkbox_flag == 2)
			{
				cout << "C2" << endl;
				w.set_checkbox(mouse2, 135, 20, 155, 40, "店主");
			}
			checkbox_flag = 3;
			cout << checkbox_flag;
		}*/
		
		w.set_title("登陆");
		w.output("用户名：", 70, 80);
		w.output("密    码：", 70, 125);
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
		if (w.set_button(mouse, 100, 170, 250, 190, "没有账号？点击注册"))
		{
			string message;
			message = w.message_info(a, 10, "输入您想要注册的身份1顾客2店主3快递员");
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

		if (w.set_button(mouse, 64, 214, 136, 234, "    登 陆    "))
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
				message = w.message_info(a, 10, "输入您的身份1顾客2店主3快递员");
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
						w.message_warn(a, 20, "账号或密码错误");
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
						w.message_warn(a, 20, "账号或密码错误");
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
						w.message_warn(a, 20, "账号或密码错误");
						goto login_window;
					}
				}
			}
			check++;
		}

		if (w.set_button(mouse, 200, 214, 272, 234, "    退 出    "))
		{
			if (check% 4 == 0)
			{
				if (w.message_question(a, 10, "确认退出？"))
				{
					w.delet();
					goto end;
				}
			}
			check++;
			
		}
		

	}
	
//-------------------------------------------------
root://管理员登陆界面
	w.set_title("尊敬的管理员，您好");
	for (; 1;)
	{
		mouse = GetMouseMsg();
		w.output("选择你要查看的类型",100,80);
		int rx1 = 126, rx2 = 85, ry1=120, ry2=ry1+20;
		if (w.set_button(mouse,rx1,ry1, rx1+rx2,ry2," 查看  客户 "))
		{
			if (check % 4 == 0)
			{
				Widget w2(352, 469);
				goto show_c;
			}
			check++;
		}
		if (w.set_button(mouse, rx1, ry1+=50, rx1 + rx2, ry2+=50, " 查看  商店 "))
		{
			if (check % 4 == 0)
			{
				Widget w2(352, 469);
				goto show_s;
			}
			check++;
		}
		if (w.set_button(mouse, rx1, ry1 += 50, rx1 + rx2, ry2 += 50, "查看快递员"))
		{
			if (check % 4 == 0)
			{
				Widget w2(352, 469);
				goto show_e;
			}
			check++;
		}
		if (w.set_button(mouse, rx1, ry1 += 50, rx1 + rx2, ry2 += 50, " 查看  订单 "))
		{
			if (check % 4 == 0)
			{
				Widget w2(352, 469);
				goto orderfrom_r;
			}
			check++;
		}
		if (w.set_button(mouse, rx1, ry1 += 50, rx1 + rx2, ry2 += 50, "     返  回     "))
		{
			
				w.clear();
				Widget w(352, 288);
				goto login_window;
			
		}
	}
	getchar();

show_c://所有客户信息
	w.set_title("查看客户");
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
				cout << "注册";
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
		w.set_button(mouse, 90, 40, 157, 60, "客户名称");
		w.set_button(mouse, 215, 40, 250, 60, "地址");
		w.output("搜索", 218, 4);
		s1=w.cinbox(mouse,253,1,353,21,user);
		if (s1 != "")
		{
			user = s1;
			if (Find(Chead, user) == NULL)
			{
				user = "未查询到";

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
			if (w.set_button(mouse, xx1 + 235, 40 + 40 * i, xx1 + 275, 40 * i + 60, "删除"))
			{
				if (check % 4 == 0)
				{
					if (w.message_question(a, 20, "确认删除"))
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
		if (w.set_button(mouse, 40, 400, 110, 420, "  上一页  "))
		{
			if (checknum % 4 == 0 && num2 > 0)
			{
				w.clear();

				num2--;
				//cout << num2;
			}
			checknum++;
		}
		if (w.set_button(mouse, 215, 400, 285, 420, "  下一页  "))
		{
			if (checknum % 4 == 0 && (8 * num2 < CN - 8))
			{
				w.clear();
				num2++;
				//cout << num2;
			}
			checknum++;
		}
		if (w.set_button(mouse, 130, 400, 195, 420, "   返 回   "))
		{
			user = "";
			Widget w2(352, 469);
			goto root;
		}

	}
	getchar();
show_c2://查看某一客户信息
	w.set_title("亲爱的顾客，您好");
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
		w.output("账        号：", 70, 80);
		w.output("密        码：", 70, 125);
		w.output("姓        名：", 70, 170);
		w.output("年        龄：", 70, 215);
		w.output("性        别：", 70, 260);
		w.output("联系方式：", 70, 305);
		w.output("地        址：", 70, 350);
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
				w.message_warn(a, 20, "该账号已存在");

			}
		}
		s1 = w.cinbox(mouse, 145, 123, 266, 143, password);
		if (s1 != "")
		{
			if (s1.length() < 6)
			{
				w.message_warn(a, 20, "密码需大于等于6位");
			}
			else if (Check(s1))
			{
				password = s1;
			}
			else
			{
				w.message_warn(a, 20, "请输入字母或数字作为密码");
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
			else w.message_warn(a, 20, "请输入正确姓名");
		}
		s1 = w.cinbox(mouse, 145, 214, 266, 234, age);
		if (s1 != "")
		{
			if ((s1 >= "10" && s1.length() == 2) || (s1 <= "120" && s1.length() == 3))
			{


				age = s1;
			}
			else w.message_warn(a, 20, "请输入正确年龄");
		}
		s1 = w.cinbox(mouse, 145, 258, 266, 278, sex);
		if (s1 != "")
		{
			if (s1 == "woman" || s1 == "man" || s1 == "女" || s1 == "男" || s1 == "male" || s1 == "female")
			{
				sex = s1;
			}
			else w.message_warn(a, 20, "请输入正确性别");
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
			else w.message_warn(a, 20, "请输入正确手机号");
		}
		s1 = w.cinbox(mouse, 145, 348, 266, 368, adress);
		if (s1 != "")
		{
			adress = s1;
		}

		if (w.set_button(mouse, 64, 395, 136, 415, "    修 改    "))
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
		if (w.set_button(mouse, 200, 395, 272, 415, "    返 回    "))
		{
			Widget w2(352, 469);
			user = password = name = age = sex = tel = adress = "";
			goto show_c;
		}
		
	}
	getchar();
show_s://所有店铺信息
	w.set_title("查看店铺");
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
				cout << "注册";
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
		w.set_button(mouse, 90, 40, 157, 60, "餐厅名称");
		w.set_button(mouse, 215, 40, 250, 60, "评分");
		w.output("搜索", 218, 4);
		s1 = w.cinbox(mouse, 253, 1, 353, 21, user);
		if (s1 != "")
		{
			user = s1;
			if (Find(Shead, user) == NULL)
			{
				user = "未查询到";

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
			if (w.set_button(mouse, xx1 + 235, 40 + 40 * i, xx1 + 275, 40 * i + 60, "删除"))
			{
				if (check % 4 == 0)
				{
					if (w.message_question(a, 20, "确认删除"))
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
		if (w.set_button(mouse, 40, 400, 110, 420, "  上一页  "))
		{
			if (checknum % 4 == 0 && num2 > 0)
			{
				w.clear();

				num2--;
				//cout << num2;
			}
			checknum++;
		}
		if (w.set_button(mouse, 215, 400, 285, 420, "  下一页  "))
		{
			if (checknum % 4 == 0 && (8 * num2 < SN - 8))
			{
				w.clear();
				num2++;
				//cout << num2;
			}
			checknum++;
		}
		if (w.set_button(mouse, 130, 400, 195, 420, "   返 回   "))
		{
			user = "";
			Widget w2(352, 469);
			goto root;
		}

	}
	getchar();
show_s2://显示某一店铺信息
	w.set_title("亲爱的店主，您好");
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
		w.output("账        号：", 70, 80);
		w.output("密        码：", 70, 125);
		w.output("姓        名：", 70, 170);
		w.output("年        龄：", 70, 215);
		w.output("性        别：", 70, 260);
		w.output("联系方式：", 70, 305);
		w.output("商店名称：", 70, 350);
		w.output("商店折扣：", 70, 395);

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
		s1 = w.cinbox(mouse, 145, 348, 266, 368, adress);//店名
		if (s1 != "")
		{
			adress = s1;
		}
		s1 = w.cinbox(mouse, 145, 393, 266, 413, dis);//折扣
		if (s1 != "")
		{
			dis = s1;
		}

		w.output("菜品1：", 400, 80);
		w.output("菜品2：", 400, 125);
		w.output("菜品3：", 400, 170);
		w.output("菜品4：", 400, 215);
		w.output("菜品5：", 400, 260);
		w.output("菜品6：", 400, 305);
		w.output("菜品7：", 400, 350);
		w.output("菜品8：", 400, 395);
		w.output("价格", 595, 50);
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

		if (w.set_button(mouse, 114, 440, 186, 460, "    修 改    "))
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
			//Register(Shead, customer);//很奇怪的读入问题，除了iage全部写入文件丢失数据。
			//cout << "reg" << endl;
			//pcus->Show();
			Widget w(352, 288);
			goto login_window;
		}
		if (w.set_button(mouse, 500, 440, 572, 460, "    返 回    "))
		{
			Widget w2(352, 469);
			user = password = name = age = sex = tel = adress = dis = "";
			goto show_s;
		}
	}
	getchar();
show_e://所有配送人员信息
	w.set_title("查看快递员");
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
				cout << "注册";
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
		w.set_button(mouse, 90, 40, 157, 60, "人员名称");
		w.set_button(mouse, 215, 40, 250, 60, "时间");
		w.output("搜索", 218, 4);
		s1 = w.cinbox(mouse, 253, 1, 353, 21, user);
		if (s1 != "")
		{
			user = s1;
			if (Find(Ehead, user) == NULL)
			{
				user = "未查询到";

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
			if (w.set_button(mouse, xx1 + 235, 40 + 40 * i, xx1 + 275, 40 * i + 60, "删除"))
			{
				if (check % 4 == 0)
				{
					if (w.message_question(a, 20, "确认删除"))
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
		if (w.set_button(mouse, 40, 400, 110, 420, "  上一页  "))
		{
			if (checknum % 4 == 0 && num2 > 0)
			{
				w.clear();

				num2--;
				//cout << num2;
			}
			checknum++;
		}
		if (w.set_button(mouse, 215, 400, 285, 420, "  下一页  "))
		{
			if (checknum % 4 == 0 && (8 * num2 < EN - 8))
			{
				w.clear();
				num2++;
				//cout << num2;
			}
			checknum++;
		}
		if (w.set_button(mouse, 130, 400, 195, 420, "   返 回   "))
		{
			user = "";
			Widget w2(352, 469);
			goto root;
		}

	}
	getchar();
show_e2://显示某一配送人员信息
	w.set_title("亲爱的快递员，您好");
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
		w.output("账        号：", 70, 80);
		w.output("密        码：", 70, 125);
		w.output("姓        名：", 70, 170);
		w.output("年        龄：", 70, 215);
		w.output("性        别：", 70, 260);
		w.output("联系方式：", 70, 305);
		w.output("工作时间：", 70, 350);
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

		if (w.set_button(mouse, 64, 395, 136, 415, "    修 改    "))
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
		if (w.set_button(mouse, 200, 395, 272, 415, "    返 回    "))
		{
			Widget w2(352, 469);
			user = password = name = age = sex = tel = adress = "";
			goto show_e;
		}
	}
	getchar();
customer://顾客登陆界面
	w.set_title("亲爱的顾客，您好");
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
		w.output("账        号：", 70, 80);
		w.output("密        码：", 70, 125);
		w.output("姓        名：", 70, 170);
		w.output("年        龄：", 70, 215);
		w.output("性        别：", 70, 260);
		w.output("联系方式：", 70, 305);
		w.output("地        址：", 70, 350);
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
				w.message_warn(a, 20, "该账号已存在");

			}
		}
		s1 = w.cinbox(mouse, 145, 123, 266, 143, "********");
		/*if (s1 != "")
		{
			if (s1.length() < 6)
			{
				w.message_warn(a, 20, "密码需大于等于6位");
			}
			else if (Check(s1))
			{
				password = s1;
			}
			else
			{
				w.message_warn(a, 20, "请输入字母或数字作为密码");
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
			else w.message_warn(a, 20, "请输入正确姓名");
		}
		s1 = w.cinbox(mouse, 145, 214, 266, 234, age);
		if (s1 != "")
		{
			if ((s1 >= "10" && s1.length() == 2) || (s1 <= "120" && s1.length() == 3))
			{


				age = s1;
			}
			else w.message_warn(a, 20, "请输入正确年龄");
		}
		s1 = w.cinbox(mouse, 145, 258, 266, 278, sex);
		if (s1 != "")
		{
			if (s1 == "woman" || s1 == "man" || s1 == "女" || s1 == "男" || s1 == "male" || s1 == "female")
			{
				sex = s1;
			}
			else w.message_warn(a, 20, "请输入正确性别");
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
			else w.message_warn(a, 20, "请输入正确手机号");
		}
		s1 = w.cinbox(mouse, 145, 348, 266, 368, adress);
		if (s1 != "")
		{
			adress = s1;
		}

		if (w.set_button(mouse, 64, 395, 136, 415, "    修 改    "))
		{
			if (check % 4 == 0)
			{
				if (user == "" || password == "" || name == "" || age == "" || sex == "" || tel == "" || adress == "")
				{
					w.play_music(3);
					w.message_warn(a, 20, "请不要漏填");
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
		if (w.set_button(mouse, 200, 395, 272, 415, "    登 出    "))
		{
			Widget w(352, 288);
			user = password = name = age = sex = tel = adress = "";
			goto login_window;
		}
		if (w.set_button(mouse, 126, 35, 210, 55, "     下  单     "))
		{
			Widget w(352, 461);
			goto order1;
		}
		if (w.set_button(mouse, 283, 0, 469, 20, "查看订单"))
		{
			Widget w2(352, 469);
			goto orderfrom_c;
		}
	}
	getchar();

shop://店主登陆界面
	w.set_title("亲爱的店主，您好");
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
		w.output("账        号：", 70, 80);
		w.output("密        码：", 70, 125);
		w.output("姓        名：", 70, 170);
		w.output("年        龄：", 70, 215);
		w.output("性        别：", 70, 260);
		w.output("联系方式：", 70, 305);
		w.output("商店名称：", 70, 350);
		w.output("商店折扣：", 70, 395);
	
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
				w.message_warn(a, 20, "该账号已存在");

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
			else w.message_warn(a, 20, "请输入正确姓名");
		}
		s1 = w.cinbox(mouse, 145, 214, 266, 234, age);
		if (s1 != "")
		{
			if ((s1 >= "10" && s1.length() == 2) || (s1 <= "120" && s1.length() == 3))
			{


				age = s1;
			}
			else w.message_warn(a, 20, "请输入正确年龄");
		}
		s1 = w.cinbox(mouse, 145, 258, 266, 278, sex);
		if (s1 != "")
		{
			if (s1 == "woman" || s1 == "man" || s1 == "女" || s1 == "男" || s1 == "male" || s1 == "female")
			{
				sex = s1;
			}
			else w.message_warn(a, 20, "请输入正确性别");
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
			else w.message_warn(a, 20, "请输入正确手机号");
		}
		s1 = w.cinbox(mouse, 145, 348, 266, 368, adress);//店名
		if (s1 != "")
		{
			adress = s1;
		}
		s1 = w.cinbox(mouse, 145, 393, 266, 413, dis);//折扣
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
				w.message_warn(a, 20, "请输入正确折扣例如0.8==八折");
			}

		}

		w.output("菜品1：", 400, 80);
		w.output("菜品2：", 400, 125);
		w.output("菜品3：", 400, 170);
		w.output("菜品4：", 400, 215);
		w.output("菜品5：", 400, 260);
		w.output("菜品6：", 400, 305);
		w.output("菜品7：", 400, 350);
		w.output("菜品8：", 400, 395);
		w.output("价格", 595, 50);
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
				w.message_warn(a, 20, "请输入正确价格");
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
				w.message_warn(a, 20, "请输入正确价格");
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
				w.message_warn(a, 20, "请输入正确价格");
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
				w.message_warn(a, 20, "请输入正确价格");
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
				w.message_warn(a, 20, "请输入正确价格");
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
				w.message_warn(a, 20, "请输入正确价格");
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
				w.message_warn(a, 20, "请输入正确价格");
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
				w.message_warn(a, 20, "请输入正确价格");
			}
		}

		if (w.set_button(mouse, 114, 440, 186, 460, "    修 改    "))
		{
			if (check % 4 == 0)
			{
				if (user == "" || password == "" || name == "" || age == "" || sex == "" || tel == "" || adress == "" || dis == "")
				{
					w.play_music(3);
					w.message_warn(a, 20, "请不要漏填");
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
				//Register(Shead, customer);//很奇怪的读入问题，除了iage全部写入文件丢失数据。
				//cout << "reg" << endl;
				//pcus->Show();
				Widget w(352, 288);
				goto login_window;
			}
		}
		if (w.set_button(mouse, 500, 440, 572, 460, "    返 回    "))
		{
			Widget w(352, 288);
			user = password = name = age = sex = tel = adress = dis = "";
			goto login_window;
		}
		if (w.set_button(mouse, 303, 0, 383, 20, "查看订单"))
		{
			Widget w2(352, 469);
			goto orderfrom_s;
		}
	}
	getchar();

expressman://配送人员登陆界面
	w.set_title("亲爱的快递员，您好");
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
		w.output("账        号：", 70, 80);
		w.output("密        码：", 70, 125);
		w.output("姓        名：", 70, 170);
		w.output("年        龄：", 70, 215);
		w.output("性        别：", 70, 260);
		w.output("联系方式：", 70, 305);
		w.output("工作时间：", 70, 350);
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
				w.message_warn(a, 20, "该账号已存在");

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
			else w.message_warn(a, 20, "请输入正确姓名");
		}
		s1 = w.cinbox(mouse, 145, 214, 266, 234, age);
		if (s1 != "")
		{
			if ((s1 >= "10" && s1.length() == 2) || (s1 <= "120" && s1.length() == 3))
			{


				age = s1;
			}
			else w.message_warn(a, 20, "请输入正确年龄");
		}
		s1 = w.cinbox(mouse, 145, 258, 266, 278, sex);
		if (s1 != "")
		{
			if (s1 == "woman" || s1 == "man" || s1 == "女" || s1 == "男" || s1 == "male" || s1 == "female")
			{
				sex = s1;
			}
			else w.message_warn(a, 20, "请输入正确性别");
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
			else w.message_warn(a, 20, "请输入正确手机号");
		}
		s1 = w.cinbox(mouse, 145, 348, 266, 368, adress);
		if (s1 != "")
		{
			adress = s1;
		}

		if (w.set_button(mouse, 64, 395, 136, 415, "    修 改    "))
		{
			if (check % 4 == 0)
			{
				if (user == "" || password == "" || name == "" || age == "" || sex == "" || tel == "" || adress == "")
				{
					w.play_music(3);
					w.message_warn(a, 20, "请不要漏填");
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
		if (w.set_button(mouse, 200, 395, 272, 415, "    返 回    "))
		{
			Widget w(352, 288);
			user = password = name = age = sex = tel = adress = "";
			goto login_window;
		}
		if (w.set_button(mouse, 283, 0, 469, 20, "查看订单"))
		{
			Widget w2(352, 469);
			goto orderfrom_e;
		}
	}
	getchar();

orderfrom_r://所有订单
	w.set_title("查看订单");
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
				cout << "注册";
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
		w.set_button(mouse, 90, 40, 157, 60, "点餐顾客");
		w.set_button(mouse, 215, 40, 250, 60, "店铺");
		w.output("搜索", 218, 4);
		s1 = w.cinbox(mouse, 253, 1, 353, 21, user);
		if (s1 != "")
		{
			user = s1;
			
			//cout<< stoi(user);
			if (Find(Ohead, ("9999999" <= user || user == "" ? 0 : stoi(user))) == NULL)
			{
				user = "未查询到";

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
			if (w.set_button(mouse, xx1 + 235, 40 + 40 * i, xx1 + 275, 40 * i + 60, "删除"))
			{
				if (check % 4 == 0)
				{
					if (w.message_question(a, 20, "确认删除"))
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
		if (w.set_button(mouse, 40, 400, 110, 420, "  上一页  "))
		{
			if (checknum % 4 == 0 && num2 > 0)
			{
				w.clear();

				num2--;
				//cout << num2;
			}
		}
		if (w.set_button(mouse, 215, 400, 285, 420, "  下一页  "))
		{
			if (checknum % 4 == 0 && (8 * num2 < ON - 8))
			{
				w.clear();
				num2++;
				//cout << num2;
			}
		}
		if (w.set_button(mouse, 130, 400, 195, 420, "   返 回   "))
		{
			user = "";
			Widget w2(352, 469);
			goto root;
		}

	}
	getchar();

orderfrom_r2://查看某一订单
	for (int i = 0; i < 9; i++) { food[i] = price[i] = ""; }
	user = "查看订单" + to_string(point4->Getnumber());
	w.set_title(user);
	user = point4->Getcusname();
	password = point4->Getshopname();
	name = point4->Getmanname();
	age = to_string(point4->Getcost());
	if (point4->Getflag() == 1)
	{
		sex = "已下单";
	}
	if (point4->Getflag() == 2)
	{
		sex = "已派发";
	}
	if (point4->Getflag() == 3)
	{
		sex = "已收到";
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
		w.output("下单顾客：", 70, 80);
		w.output("点单商店：", 70, 125);
		w.output("收单人员：", 70, 170);
		w.output("订单花费：", 70, 215);
		w.output("订单状态：", 70, 260);
		//w.output("联系方式：", 70, 305);
		//w.output("商店名称：", 70, 350);
		//w.output("商店折扣：", 70, 395);

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
		s1 = w.cinbox(mouse, 145, 348, 266, 368, adress);//店名
		if (s1 != "")
		{
			adress = s1;
		}
		s1 = w.cinbox(mouse, 145, 393, 266, 413, dis);//折扣
		if (s1 != "")
		{
			dis = s1;
		}*/

		w.output("菜品1：", 400, 80);
		w.output("菜品2：", 400, 125);
		w.output("菜品3：", 400, 170);
		w.output("菜品4：", 400, 215);
		w.output("菜品5：", 400, 260);
		w.output("菜品6：", 400, 305);
		w.output("菜品7：", 400, 350);
		w.output("菜品8：", 400, 395);
		w.output("价格", 595, 50);
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

		if (w.set_button(mouse, 114, 440, 186, 460, "    确 认    "))
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
		if (w.set_button(mouse, 500, 440, 572, 460, "    返 回    "))
		{
			
			user = password = name = age = sex = tel = adress = dis = "";
			Widget w2(352, 469);
			w2.clear();
			goto orderfrom_r;
		}
	}
	getchar();

orderfrom_c://顾客有关订单
	w.set_title("查看订单");

	//cout << point1->Getname();
	point5 = new Order_form;
	point4 = Ohead->next;
	for (int i = 0 ;point4!=NULL&&i<ON;point4=point4->next,i++)
	{
		if (point4->Getcusname() == point1->Getname())
		{
			//cout << "注册";
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
			w.message_warn(a, 20, "您还没有下单");
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
		
		
		w.set_button(mouse, 90, 40, 157, 60, "点餐顾客");
		w.set_button(mouse, 215, 40, 250, 60, "店铺");

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
			if (w.set_button(mouse, xx1 + 235, 40 + 40 * i, xx1 + 275, 40 * i + 60, "确认"))
			{
				if (check % 4 == 0)
				{
					if (point4->Getflag() == 2)
					{
						Find(Ohead,point4->Getnumber())->next->mark(3);
						w.message_warn(a, 20, "已签收");
					}
					else
					{
						w.message_warn(a,20,"配送人员尚未接受");
					}
				}
				check++;
				//cout << check;
			}
		}
		w.output("您已消费：",40,440);
		w.output(to_string(allcost).substr(0,5),130,440);
		if (w.set_button(mouse, 40, 400, 110, 420, "  上一页  "))
		{
			if (checknum % 4 == 0 && num2 > 0)
			{
				w.clear();

				num2--;
				//cout << num2;
			}
		}
		if (w.set_button(mouse, 215, 400, 285, 420, "  下一页  "))
		{
			if (checknum % 4 == 0 && (8 * num2 < ON - 8))
			{
				w.clear();
				num2++;
				//cout << num2;
			}
		}
		if (w.set_button(mouse, 130, 400, 195, 420, "   返 回   "))
		{
		
			
			Widget w2(352, 469);
			w2.clear();
			goto customer;
		
		}
	

	}

	getchar();

orderfrom_c2://查看某一订单
	for (int i = 0; i < 9; i++) { food[i] = price[i] = ""; }
	user = "查看订单" + to_string(point4->Getnumber());
	w.set_title(user);
	user = point4->Getcusname();
	password = point4->Getshopname();
	name = point4->Getmanname();
	age = to_string(point4->Getcost());
	if (point4->Getflag() == 1)
	{
		sex = "已下单";
	}
	if (point4->Getflag() == 2)
	{
		sex = "已派发";
	}
	if (point4->Getflag() == 3)
	{
		sex = "已收到";
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
		w.output("下单顾客：", 70, 80);
		w.output("点单商店：", 70, 125);
		w.output("收单人员：", 70, 170);
		w.output("订单花费：", 70, 215);
		w.output("订单状态：", 70, 260);
		//w.output("联系方式：", 70, 305);
		//w.output("商店名称：", 70, 350);
		//w.output("商店折扣：", 70, 395);

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
		s1 = w.cinbox(mouse, 145, 348, 266, 368, adress);//店名
		if (s1 != "")
		{
			adress = s1;
		}
		s1 = w.cinbox(mouse, 145, 393, 266, 413, dis);//折扣
		if (s1 != "")
		{
			dis = s1;
		}*/

		w.output("菜品1：", 400, 80);
		w.output("菜品2：", 400, 125);
		w.output("菜品3：", 400, 170);
		w.output("菜品4：", 400, 215);
		w.output("菜品5：", 400, 260);
		w.output("菜品6：", 400, 305);
		w.output("菜品7：", 400, 350);
		w.output("菜品8：", 400, 395);
		w.output("价格", 595, 50);
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

		if (w.set_button(mouse, 114, 440, 186, 460, "    确 认    "))
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
		if (w.set_button(mouse, 500, 440, 572, 460, "    返 回    "))
		{

			user = password = name = age = sex = tel = adress = dis = "";
			Widget w2(352, 469);
			w2.clear();
			goto orderfrom_c;
		}
	}
	getchar();
orderfrom_s://店铺有关订单
	w.set_title("查看订单");

	//cout << point1->Getname();
	point5 = new Order_form;
	
	point4 = Ohead->next;
	
	for (int i = 0; point4 != NULL && i < ON; point4 = point4->next, i++)
	{
		if (point4->Getshopname() == point2->Getshopname())
		{
			cout << "注册";
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
			w.message_warn(a, 20, "没有收到订单");
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
		w.set_button(mouse, 90, 40, 157, 60, "点餐顾客");
		w.set_button(mouse, 215, 40, 250, 60, "店铺");

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
		w.output("您已收入：", 40, 440);
		w.output(to_string(allgain).substr(0, 5), 130, 440);
		if (w.set_button(mouse, 40, 400, 110, 420, "  上一页  "))
		{
			if (checknum % 4 == 0 && num2 > 0)
			{
				w.clear();

				num2--;
				//cout << num2;
			}
		}
		if (w.set_button(mouse, 215, 400, 285, 420, "  下一页  "))
		{
			if (checknum % 4 == 0 && (8 * num2 < ON - 8))
			{
				w.clear();
				num2++;
				//cout << num2;
			}
		}
		if (w.set_button(mouse, 130, 400, 195, 420, "   返 回   "))
		{


			Widget w2(700, 514);
			w2.clear();
			goto shop;

		}


	}

	getchar();
orderfrom_s2://查看某一订单
	for (int i = 0; i < 9; i++) { food[i] = price[i] = ""; }
	user = "查看订单" + to_string(point4->Getnumber());
	w.set_title(user);
	user = point4->Getcusname();
	password = point4->Getshopname();
	name = point4->Getmanname();
	age = to_string(point4->Getcost());
	if (point4->Getflag() == 1)
	{
		sex = "已下单";
	}
	if (point4->Getflag() == 2)
	{
		sex = "已派发";
	}
	if (point4->Getflag() == 3)
	{
		sex = "已收到";
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
		w.output("下单顾客：", 70, 80);
		w.output("点单商店：", 70, 125);
		w.output("收单人员：", 70, 170);
		w.output("订单花费：", 70, 215);
		w.output("订单状态：", 70, 260);
		//w.output("联系方式：", 70, 305);
		//w.output("商店名称：", 70, 350);
		//w.output("商店折扣：", 70, 395);

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
		s1 = w.cinbox(mouse, 145, 348, 266, 368, adress);//店名
		if (s1 != "")
		{
			adress = s1;
		}
		s1 = w.cinbox(mouse, 145, 393, 266, 413, dis);//折扣
		if (s1 != "")
		{
			dis = s1;
		}*/

		w.output("菜品1：", 400, 80);
		w.output("菜品2：", 400, 125);
		w.output("菜品3：", 400, 170);
		w.output("菜品4：", 400, 215);
		w.output("菜品5：", 400, 260);
		w.output("菜品6：", 400, 305);
		w.output("菜品7：", 400, 350);
		w.output("菜品8：", 400, 395);
		w.output("价格", 595, 50);
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

		if (w.set_button(mouse, 114, 440, 186, 460, "    确 认    "))
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
		if (w.set_button(mouse, 500, 440, 572, 460, "    返 回    "))
		{
	
			user = password = name = age = sex = tel = adress = dis = "";
	
			Widget w(352, 469);

			w.clear();

			goto orderfrom_s;
		}
	}
	getchar();

orderfrom_e://配送人员有关订单
	w.set_title("查看订单");

	//cout << point1->Getname();
	point5 = new Order_form;
	point4 = Ohead->next;
	for (int i = 0; point4 != NULL && i < ON; point4 = point4->next, i++)
	{
		if (point4->Getmanname() == point3->Getname())
		{
			cout << "注册";
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
			w.message_warn(a, 20, "您还没有收到订单");
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
		w.set_button(mouse, 90, 40, 157, 60, "点餐顾客");
		w.set_button(mouse, 215, 40, 250, 60, "店铺");

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
			if (w.set_button(mouse, xx1 + 235, 40 + 40 * i, xx1 + 275, 40 * i + 60, "接受"))
			{
				if (check % 4 == 0)
				{
					Find(Ohead,point4->Getnumber())->next->mark(2);
					w.message_warn(a, 20, "已接受");
				}
				check++;
				//cout << check;
			}
		}
		if (w.set_button(mouse, 40, 400, 110, 420, "  上一页  "))
		{
			if (checknum % 4 == 0 && num2 > 0)
			{
				w.clear();

				num2--;
				//cout << num2;
			}
		}
		if (w.set_button(mouse, 215, 400, 285, 420, "  下一页  "))
		{
			if (checknum % 4 == 0 && (8 * num2 < ON - 8))
			{
				w.clear();
				num2++;
				//cout << num2;
			}
		}
		if (w.set_button(mouse, 130, 400, 195, 420, "   返 回   "))
		{


			Widget w2(352, 469);
			w2.clear();
			goto expressman;

		}


	}

	getchar();

orderfrom_e2://查看某一订单
	for (int i = 0; i < 9; i++) { food[i] = price[i] = ""; }
	user = "查看订单" + to_string(point4->Getnumber());
	w.set_title(user);
	user = point4->Getcusname();
	password = point4->Getshopname();
	name = point4->Getmanname();
	age = to_string(point4->Getcost());
	if (point4->Getflag() == 1)
	{
		sex = "已下单";
	}
	if (point4->Getflag() == 2)
	{
		sex = "已派发";
	}
	if (point4->Getflag() == 3)
	{
		sex = "已收到";
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
		w.output("下单顾客：", 70, 80);
		w.output("点单商店：", 70, 125);
		w.output("收单人员：", 70, 170);
		w.output("订单花费：", 70, 215);
		w.output("订单状态：", 70, 260);
		//w.output("联系方式：", 70, 305);
		//w.output("商店名称：", 70, 350);
		//w.output("商店折扣：", 70, 395);

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
		s1 = w.cinbox(mouse, 145, 348, 266, 368, adress);//店名
		if (s1 != "")
		{
			adress = s1;
		}
		s1 = w.cinbox(mouse, 145, 393, 266, 413, dis);//折扣
		if (s1 != "")
		{
			dis = s1;
		}*/

		w.output("菜品1：", 400, 80);
		w.output("菜品2：", 400, 125);
		w.output("菜品3：", 400, 170);
		w.output("菜品4：", 400, 215);
		w.output("菜品5：", 400, 260);
		w.output("菜品6：", 400, 305);
		w.output("菜品7：", 400, 350);
		w.output("菜品8：", 400, 395);
		w.output("价格", 595, 50);
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

		if (w.set_button(mouse, 114, 440, 186, 460, "    确 认    "))
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
		if (w.set_button(mouse, 500, 440, 572, 460, "    返 回    "))
		{

			user = password = name = age = sex = tel = adress = dis = "";
			Widget w2(352, 469);
			w2.clear();
			goto orderfrom_e;
		}
	}
	getchar();
//-----------------------------------------------
rcustomer://顾客注册
	for (; 1;)
	{
		mouse = GetMouseMsg();
		w.set_title("顾客注册");
		w.output("账        号：", 70, 80);
		w.output("密        码：", 70, 125);
		w.output("姓        名：", 70, 170);
		w.output("年        龄：", 70, 215);
		w.output("性        别：", 70, 260);
		w.output("联系方式：", 70, 305);
		w.output("地        址：", 70, 350);
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
				w.message_warn(a, 20, "该账号已存在");
				
			}
		}
		s1=w.cinbox(mouse, 145, 123, 266, 143,password);
		if (s1 != "")
		{
			if (s1.length() < 6)
			{
				w.message_warn(a, 20, "密码需大于等于6位");
			}
			else if (Check(s1))
			{
				password = s1;
			}
			else
			{
				w.message_warn(a,20,"请输入字母或数字作为密码");
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
			else w.message_warn(a,20,"请输入正确姓名");
		}
		s1=w.cinbox(mouse, 145, 214, 266, 234,age);
		if (s1 != "")
		{
			if ((s1 >= "10"&&s1.length()==2) || (s1 <= "120"&&s1.length()==3))
			{


				age = s1;
			}
			else w.message_warn(a, 20, "请输入正确年龄");
		}
		s1=w.cinbox(mouse, 145, 258, 266, 278,sex);
		if (s1 != "")
		{
			if (s1 == "woman" || s1 == "man" || s1 == "女" || s1 == "男" || s1 == "male" || s1 == "female")
			{
				sex = s1;
			}
			else w.message_warn(a, 20, "请输入正确性别");
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
			else w.message_warn(a,20,"请输入正确手机号");
		}
		s1=w.cinbox(mouse, 145, 348, 266, 368,adress);
		if (s1 != "")
		{
			adress = s1;
		}

		if (w.set_button(mouse, 64, 395, 136, 415, "    注 册    ")) 
		{
			if (check % 4 == 0)
			{
				if (user == "" || password == "" || name == "" || age == "" || sex == "" || tel == "" || adress == "")
				{
					w.play_music(3);
					w.message_warn(a,20,"请不要漏填");
					goto rcustomer;
				}

				int iage = stoi(age);
				Customer customer(user, password, 3, name, sex, iage, tel, adress);
				//Expressman* pcus = &customer;
				//customer.Show();
				Register(Chead, customer);//很奇怪的读入问题，除了iage全部写入文件丢失数据。
				//pcus->Show();
				CN++;
				Widget w(352, 288);
				goto login_window;
			}
		}
		if (w.set_button(mouse, 200, 395, 272, 415, "    返 回    "))
		{
			Widget w(352, 288);
			user = password = name = age = sex = tel = adress = "";
			goto login_window;
		}
	}
	getchar();

rshop://店主注册
	for (; 1;)
	{
		mouse = GetMouseMsg();
		w.set_title("店主注册");
		w.output("账        号：", 70, 80);
		w.output("密        码：", 70, 125);
		w.output("姓        名：", 70, 170);
		w.output("年        龄：", 70, 215);
		w.output("性        别：", 70, 260);
		w.output("联系方式：", 70, 305);
		w.output("商店名称：", 70, 350);
		w.output("商店折扣：", 70, 395);
		
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
				w.message_warn(a, 20, "该账号已存在");

			}
		}
		s1 = w.cinbox(mouse, 145, 123, 266, 143, password);
		if (s1 != "")
		{
			if (s1.length() < 6)
			{
				w.message_warn(a, 20, "密码需大于等于6位");
			}
			else if (Check(s1))
			{
				password = s1;
			}
			else
			{
				w.message_warn(a, 20, "请输入字母或数字作为密码");
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
			else w.message_warn(a, 20, "请输入正确姓名");
		}
		s1 = w.cinbox(mouse, 145, 214, 266, 234, age);
		if (s1 != "")
		{
			if ((s1 >= "10" && s1.length() == 2) || (s1 <= "120" && s1.length() == 3))
			{


				age = s1;
			}
			else w.message_warn(a, 20, "请输入正确年龄");
		}
		s1 = w.cinbox(mouse, 145, 258, 266, 278, sex);
		if (s1 != "")
		{
			if (s1 == "woman" || s1 == "man" || s1 == "女" || s1 == "男" || s1 == "male" || s1 == "female")
			{
				sex = s1;
			}
			else w.message_warn(a, 20, "请输入正确性别");
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
			else w.message_warn(a, 20, "请输入正确手机号");
		}
		s1 = w.cinbox(mouse, 145, 348, 266, 368, adress);//店名
		if (s1 != "")
		{
			adress = s1;
		}
		s1 = w.cinbox(mouse, 145, 393, 266, 413, dis);//折扣
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
				w.message_warn(a, 20, "请输入正确折扣例如0.8==八折");
			}
			
		}
		
		w.output("菜品1：", 400, 80);
		w.output("菜品2：", 400, 125);
		w.output("菜品3：", 400, 170);
		w.output("菜品4：", 400, 215);
		w.output("菜品5：", 400, 260);
		w.output("菜品6：", 400, 305);
		w.output("菜品7：", 400, 350);
		w.output("菜品8：", 400, 395);
		w.output("价格",595, 50);
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
				w.message_warn(a, 20, "请输入正确价格");
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
				w.message_warn(a, 20, "请输入正确价格");
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
				w.message_warn(a, 20, "请输入正确价格");
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
				w.message_warn(a, 20, "请输入正确价格");
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
				w.message_warn(a, 20, "请输入正确价格");
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
				w.message_warn(a, 20, "请输入正确价格");
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
				w.message_warn(a, 20, "请输入正确价格");
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
				w.message_warn(a, 20, "请输入正确价格");
			}
		}

		if (w.set_button(mouse, 114, 440, 186, 460, "    注 册    "))
		{
			if (check % 4 == 0)
			{
				if (user == "" || password == "" || name == "" || age == "" || sex == "" || tel == "" || adress == ""|| dis == "")
				{
					w.play_music(3);
					w.message_warn(a, 20, "请不要漏填");
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
		if (w.set_button(mouse, 500, 440, 572, 460, "    返 回    "))
		{
			Widget w(352, 288);
			user = password = name = age = sex = tel = adress = dis= "";
			goto login_window;
		}
	}
	getchar();

rexpressman://配送人员注册
	for (; 1;)
	{
		mouse = GetMouseMsg();
		w.set_title("快递员注册");
		w.output("账        号：", 70, 80);
		w.output("密        码：", 70, 125);
		w.output("姓        名：", 70, 170);
		w.output("年        龄：", 70, 215);
		w.output("性        别：", 70, 260);
		w.output("联系方式：", 70, 305);
		w.output("工作时间：", 70, 350);
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
				w.message_warn(a, 20, "该账号已存在");

			}
		}
		s1 = w.cinbox(mouse, 145, 123, 266, 143, password);
		if (s1 != "")
		{
			if (s1.length() < 6)
			{
				w.message_warn(a, 20, "密码需大于等于6位");
			}
			else if (Check(s1))
			{
				password = s1;
			}
			else
			{
				w.message_warn(a, 20, "请输入字母或数字作为密码");
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
			else w.message_warn(a, 20, "请输入正确姓名");
		}
		s1 = w.cinbox(mouse, 145, 214, 266, 234, age);
		if (s1 != "")
		{
			if ((s1 >= "10" && s1.length() == 2) || (s1 <= "120" && s1.length() == 3))
			{


				age = s1;
			}
			else w.message_warn(a, 20, "请输入正确年龄");
		}
		s1 = w.cinbox(mouse, 145, 258, 266, 278, sex);
		if (s1 != "")
		{
			if (s1 == "woman" || s1 == "man" || s1 == "女" || s1 == "男" || s1 == "male" || s1 == "female")
			{
				sex = s1;
			}
			else w.message_warn(a, 20, "请输入正确性别");
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
			else w.message_warn(a, 20, "请输入正确手机号");
		}
		s1 = w.cinbox(mouse, 145, 348, 266, 368, adress);
		if (s1 != "")
		{
			adress = s1;
		}

		if (w.set_button(mouse, 64, 395, 136, 415, "    注 册    "))
		{
			if (check % 4 == 0)
			{
				if (user == "" || password == "" || name == "" || age == "" || sex == "" || tel == "" || adress == "")
				{
					w.play_music(3);
					w.message_warn(a, 20, "请不要漏填");
					goto rexpressman;
				}
				int iage = stoi(age);
				Expressman customer(user, password, 3, name, sex, iage, tel, 2.5, adress);
				Expressman* pcus = &customer;
				//customer.Show();
				Register(Ehead, customer);//很奇怪的读入问题，除了iage全部写入文件丢失数据。
				//pcus->Show();
				EN++;
				Widget w(352, 288);
				goto login_window;
			}
		}
		if (w.set_button(mouse, 200, 395, 272, 415, "    返 回    "))
		{
			Widget w(352, 288);
			user = password = name = age = sex = tel = adress = "";
			goto login_window;
		}
	}
	getchar();


order1://点单步骤1:选择店铺
	//cout << SN;
	w.set_title("选择店铺");
	num2 = 0;
	for (; 1;)
	{
		
		point2 = Shead->next;
		for (int i = 1; i <= 8 * num2; i++,point2=point2->next)
		{

		}
		mouse = GetMouseMsg();
		w.set_button(mouse,90,40,157,60,"餐厅名称");
		w.set_button(mouse,215,40,250,60,"评分");
		
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
		if (w.set_button(mouse, 40, 400, 110, 420, "  上一页  "))
		{
			if (checknum % 4 == 0&&num2>0)
			{
				w.clear();
				
				num2--;
				//cout << num2;
			}
		}
		if (w.set_button(mouse, 215, 400, 285, 420, "  下一页  "))
		{
			if (checknum % 4 == 0&&(8*num2<SN-8))
			{
				w.clear();
				num2++;
				//cout << num2;
			}
		}
		if (w.set_button(mouse, 130, 400, 195, 420, "   返 回   "))
		{
			Widget w2(352, 469);
			goto customer;
		}
		
	}
	getchar();

order2://点单步骤2:选择菜品
	w.set_title("选择菜品");
	for (int i = 0; i < 8; i++)
	{
		p_food[i].SetData("",0);
	}
	for (; 1;)
	{
		mouse = GetMouseMsg();
		w.set_button(mouse, 80, 40, 147, 60, "菜品名称");
		w.set_button(mouse, 225, 40, 260, 60, "价格");
		if (w.set_button(mouse, 300, 40, 335, 60, "清空"))
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
		if (w.set_button(mouse, 40, 400, 110, 420, "   选 择   "))
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
				if (w.message_question(a, 9, "您选择了", "确认", allfood.c_str()))
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
				
				//w.message_question(a,9,"您选择了","确认","例如675");
		
				//cout << fk;
			}
			checknum++;

		}
		if (w.set_button(mouse, 215, 400, 285, 420, "   返 回   "))
		{
			//cout << "fanhui";
			Widget w(352, 461);
			goto order1;
		}
		Sleep(10);
	}
	getchar();

end://结束录入文件
	writeto(filename, Chead, CN);
	writeto("expressman.txt", Ehead, EN);
	writeto("shop.txt", Shead, SN);
	writeto("order.txt", Ohead, ON);
	return 0;
}