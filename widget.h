#pragma once
#include<ctime>
#include<string>
#include<graphics.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;
class Widget//ģ��QT������EasyX��ͼ������ƵĴ�����
{
	int check_cinbox;
	int check_checkbox;//�����Ϣ���
public:
	Widget() {
		check_cinbox = 0;
		check_checkbox = 0;
		//initgraph(480, 640, SHOWCONSOLE);
		initgraph(480, 640);
		setbkcolor(RGB(255, 255, 255));
		cleardevice();
	};
	Widget(int w, int h) {
		check_cinbox = 0;
		check_checkbox = 0;
		//initgraph(w, h, SHOWCONSOLE);
		initgraph(w, h);
		setbkcolor(RGB(240, 240, 240));
		cleardevice();
	};//���ڳ�ʼ��
	//���뺯��
	string input(char* str, int max, LPCTSTR message = NULL, LPCTSTR title = NULL, LPCTSTR def = NULL, int wideth = 0, int height = 0, bool b = true);
	//�������
	void output(string st, int x = 0, int y = 0);
	//���Ĵ��ڱ���
	void set_title(string str);
	//���ð�ť����
	bool set_button(MOUSEMSG mouse, int x1 = 0, int y1 = 0, int x2 = 20, int y2 = 10,string str=" ");
	//����ѡ��ť����(ѡ���ж���������)
	bool set_checkbox(MOUSEMSG mouse, int x1 = 0, int y1 = 0, int x2 = 20, int y2 = 20, string str = " ");
	//�����������
	string cinbox(MOUSEMSG mouse, int x1 = 0, int y1 = 0, int x2 = 30, int y2 = 10, string str=" ");
	//������Ϣ��ʾ����
	void message_warn(char* str, int max, LPCTSTR message, LPCTSTR title = "����", LPCTSTR def = NULL, int wideth = 0, int height = 0, bool b = true);
	bool message_question(char* str, int max, LPCTSTR message, LPCTSTR title = "ѯ��", LPCTSTR def = NULL, int wideth = 0, int height = 0, bool b = false);
	string message_info(char* str, int max, LPCTSTR message, LPCTSTR title = "��ʾ", LPCTSTR def = NULL, int wideth = 0, int height = 0, bool b = true);
	//��������
	void clear() { cleardevice(); };
	//ɾ�����������ã�
	void delet() { closegraph(); };
	//���������������
	void play_music(int i);
	//���Ӻ�����ģ��QT���źŲۻ��ƣ��������⣩
	void connect(void (*p)(), bool b = true);
};