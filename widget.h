#pragma once
#include<ctime>
#include<string>
#include<graphics.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;
class Widget//模仿QT，基于EasyX绘图函数设计的窗口类
{
	int check_cinbox;
	int check_checkbox;//鼠标消息检查
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
	};//窗口初始化
	//输入函数
	string input(char* str, int max, LPCTSTR message = NULL, LPCTSTR title = NULL, LPCTSTR def = NULL, int wideth = 0, int height = 0, bool b = true);
	//输出函数
	void output(string st, int x = 0, int y = 0);
	//更改窗口标题
	void set_title(string str);
	//放置按钮函数
	bool set_button(MOUSEMSG mouse, int x1 = 0, int y1 = 0, int x2 = 20, int y2 = 10,string str=" ");
	//放置选择按钮函数(选择判定存在问题)
	bool set_checkbox(MOUSEMSG mouse, int x1 = 0, int y1 = 0, int x2 = 20, int y2 = 20, string str = " ");
	//放置输入框函数
	string cinbox(MOUSEMSG mouse, int x1 = 0, int y1 = 0, int x2 = 30, int y2 = 10, string str=" ");
	//三个消息提示函数
	void message_warn(char* str, int max, LPCTSTR message, LPCTSTR title = "警告", LPCTSTR def = NULL, int wideth = 0, int height = 0, bool b = true);
	bool message_question(char* str, int max, LPCTSTR message, LPCTSTR title = "询问", LPCTSTR def = NULL, int wideth = 0, int height = 0, bool b = false);
	string message_info(char* str, int max, LPCTSTR message, LPCTSTR title = "提示", LPCTSTR def = NULL, int wideth = 0, int height = 0, bool b = true);
	//清屏函数
	void clear() { cleardevice(); };
	//删除函数（无用）
	void delet() { closegraph(); };
	//随机播放语音函数
	void play_music(int i);
	//链接函数（模仿QT的信号槽机制，存在问题）
	void connect(void (*p)(), bool b = true);
};