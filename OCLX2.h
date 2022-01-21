#include<iostream> //basic input and output and also varibles
#include<windows.h> //main function of the game engine namespace
#include<dos.h> //cmd control
#include<conio.h>//input and output kbhit and all
#include<stdlib.h>/*std lib for user*/
#include<Sddl.h>//one and all sddl for user no use in game engine
#include<cstdlib>//casting things
#include<debug/map>//maps
#include<process.h>//processing hardcore
#include<wingdi.h>//windows gdi for gui
#include<stdio.h>//also for other
#include <unistd.h>//other functions
#include<math.h>//math functions used in game engine and game asset
#include<vector>//vector to boost up things and make high quility 2d
#include<time.h>//time.h for time statement
#include<thread>//threads for making threads in c++
#include<complex>//complex functions
#define SaveFile(filename,text) ofstream(File) \
File.open(filename); \
File<<text<<endl; \
File.close();
#include<fstream>//saving files
#include<GL/gl.h>//no use
#define flsuh system("cls");//clear console 16bit framebuffer flickers
#include <tchar.h>//tchar or universal
#include<wchar.h>//wchar for universal
#if defined(UNICODE) && !defined(_UNICODE)
#define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
#define UNICODE
#endif
#include <tchar.h>
#include<chrono>
#define Flush Screen[userwidth*userheight -1] = L'P';\
WriteConsoleOutputCharacter(hConsole,Screen,userwidth*userheight,{0,0},&dwBytesWritten);
#define ALSO cout<<"SUBCRIBE"<<endl;
#define PI 3.14
using namespace std;//auto std for all c++
enum Color {//color funciton for console game engine
FG_WHITE=7,
FG_BLACK=0,
FG_BLUE=1,
FG_GREEN=2,
FG_Cyan=3,
FG_RED=4,
FG_Purple=5,
FG_Yellow=6,
FG_GRAY=8,
FG_LightBlue=9,
FG_LightGreen=10,
FG_Ice=11,
FG_LightRed=12,
FG_LightPurple=13,
FG_LightYellow=14,
FG_BrightWhite=15,
BG_Blue=16,
};

	enum Shape { //shape function for console game engine
		PIXEL_SOLID = 219,//solid block
		PIXEL_Meshed = 178,//pixel meshed used for making diffrent solid type pixels
		PIXEL_FACE=1,//face draws an happy face
        PIXEL_HALF2=223,//the half  draws on down
        PIXEL_HALF_RIGHT=221,//draws half on right
        PIXEL_HALF_LEFT=222,//draws half on left
        PIXEL_HALF_CENTER=254,//draws on center

	};
	enum FontWeight {
	NORMOLF=400,
	BIGF=600,
	};
namespace GameEngine { //game engine function extensions
    class Console{
        private:
        bool constructconsole;
    public:
    void Sound(LPCSTR SOUNDFILE,DWORD FDWSOUND1){
    PlaySound(SOUNDFILE,NULL,SND_SYNC);
    }
    void ConstructEmptyConsole(){
    cout<<""<<endl;
    }
    void ConstructConsoleElements(bool showFlag){
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE),CONSOLE_FULLSCREEN_MODE,NULL);
    constructconsole=true;
    COORD cursorPosition;
cursorPosition.X = 0;
cursorPosition.Y = 0;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
  HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    }
    	void ConsoleGameHandlerX(int cx,int cy){
	if(cx==-1){
    cx+=1;
	}else if(cy==-1){
	cy+=1;
	}else {

	}
	}
	void Square(int Color,int width,int height,int posx,int posy){
    while(1){
	 HDC hdc = GetDC(GetConsoleWindow());
    for (int x = posx; x < width; ++x)
        for (int y = posy; y < height; ++y)
            SetPixel(hdc, x, y, RGB(Color, x, y));
    }
	}
	void SquarePixel() {//draws an square pixel on the screen
	    unsigned char PIXEL_SOLID1=PIXEL_SOLID;//unsinged char used for not letting value go neg always pos
		cout <<PIXEL_SOLID1<<endl;//output
	}
    void PIXELFACE(){
    char a=PIXEL_FACE;
	cout<<a<<endl;//output
	}
    void DrawPixel(int Pixel){
    char Pixel1=Pixel;
    cout<<Pixel1<<endl;
    }
	void PhysicsCheckF(int playery, int requiredplayery) {//creates physics falling physics for console
		if (playery == requiredplayery) {//take to int player y and requiredplayery is used for knowing when to fall
			playery -= requiredplayery;//then the falling functions -= the requiredlevel example 1 so it would go to 0
		}
		else {
			//do nothing
		}
	}
	void FONT_Consolas(int fontsize,int fontweight=NORMOLF){//change font family of anything and also write the text in cout
	CONSOLE_FONT_INFOEX cfi;
cfi.cbSize = sizeof(cfi);
cfi.nFont = 0;
cfi.dwFontSize.X = 0;                   // Width of each character in the font
cfi.dwFontSize.Y = fontsize;                  // Height
cfi.FontFamily = fontweight;
cfi.FontWeight = FW_NORMAL;
std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	}

	void Pos(short x,short y,short speed=1) {
		HANDLE poshandle = GetStdHandle(STD_OUTPUT_HANDLE);//handler function to handle inputs and everything
		COORD postion = { x,y };//cordinated map of x,y setting the pos as user need 0,0
		SetConsoleCursorPosition(poshandle, postion);//chaning cursor pos as user x,y user needs
		if(x==-1){
         x+=speed;
		}else if(y==-1){
		y+=speed;
		}
	}

	void PColor(int Color) {//color changer changes color of anything 16bit function
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);//get an handle ready for output in std
		SetConsoleTextAttribute(h, Color);//PColor RGB set text attribute color name to change it up
	}
	void Start(const char*_command1){
	system(_command1);
	}
	int AnimationText(string Text,int Color,int Color2){
    PColor(Color);
	cout<<Text<<endl;
	system("cls");
	PColor(Color2);
	cout<<Text<<endl;
	}
	void EventSystem(int eventrequired_value,int currentvalue,string message){//enter what and which event this only for rpg
	if(eventrequired_value>currentvalue){//event required greater than current = eventrequired -=currentvalue1;
    int currentvalue1;//so if player health is here it would go down
    currentvalue1+=currentvalue;
    currentvalue-=currentvalue1;
    system("cls");
    cout<<message<<endl;//your message after event
	}else if(eventrequired_value>currentvalue){


	}
	}
	void MapMaker(){

	}

	void AnimatePlayerMovment(char aframe,char bsecondframe,int keypressedr){//animation add animation to your game for cut scenes
	    int currentkeypressed;//this one is only for movement frames
      currentkeypressed+=keypressedr;
	    if(keypressedr==currentkeypressed){
         cout<<bsecondframe<<endl;
	    }else {
	     cout<<aframe<<endl;
	    }
	}
	void Pixel_Shaded(){
	char a=PIXEL_Meshed;
	cout<<a;
	}
	void CustomSprite(int sprite){
	unsigned char a=sprite;
	cout<<a;
	}
    void SpriteAdd(int spritex,int spritey,int player_npc,int color,int sprite1){
    if(player_npc=='1'){
    Pos(spritex,spritey);
     PColor(color);
     SquarePixel();
    }else if(player_npc=='2'){
    Pos(spritex,spritey);
    PColor(color);
    Pixel_Shaded();
    }else if(player_npc=='3'){
    Pos(spritex,spritey);
    PColor(color);
    CustomSprite(sprite1);

    }
    }
	void AnimateCutScenes(int x,int y,int movex,int movey,int shape1){
	    bool flag=true;
    while(flag){
        if(x==movex){
           flag=false;
        }else {
        flag=true;
        }
    char a=shape1;
    system("cls");
    x+=1;
    y+=1;
    Pos(x,y);
	cout<<a<<endl;
	}
	}
	void AddCharaters(int charaterx,int charatery,int color,int shape=PIXEL_FACE){
	Pos(charaterx,charatery);
char b=shape;
PColor(color);
cout<<b<<endl;
	}
	void ClearScreen1(int oldx,int oldy){
	 if(oldx>0||oldy>0){
        Pos(oldx,oldy);
        PColor(0);
        SquarePixel();
	 }else {

	 }
	}
	void framebuffer(int userwidth,int userheight){
	wchar_t *Screen=new wchar_t[userwidth*userheight];
HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ|GENERIC_WRITE,0,NULL,CONSOLE_TEXTMODE_BUFFER,NULL);
SetConsoleActiveScreenBuffer(hConsole);
DWORD dwBytesWritten=0;

	}

void ClearScreenFlickerBeta()
  {
  HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Move the cursor home */
  SetConsoleCursorPosition( hStdOut, homeCoords );
  }

  		void collision(int cx,int cy,int playerx,int playery){
     if(playerx==cx){
        playerx-=1;
     }else if(playery==cy){
      playery-=1;
     }
	}
	void MakePixel(int ASCII_UseSolidShapeOrSomethingElse,int Length){
	char a=ASCII_UseSolidShapeOrSomethingElse;
for(int i=1;i<Length;i++){
 for(int j=1;j<=0;j++);
    cout<<a;
}
	}

	void Add_object(int obj,int x,int y,int color){
    //-----------------------------------------------
    //                    object engine
    //-----------------------------------------------
      char a=obj;
       Pos(x,y);
       PColor(color);
    cout<<a<<endl;
	}
	void Add_Background(int color,int x,int y){
    Pos(x,y);
     PColor(color);

	}

void drawRectangle(int parameterX, int parameterY,int r,int g,int b) {
   HWND myconsole1 = GetConsoleWindow();
    HDC hdc1 =GetDC(myconsole1);
   COLORREF Colors1= RGB(r,g,b);
// draw rectangle
for (int x = 0; x < parameterX; x++) {
    for (int y = 0; y < parameterY; y++) {
        SetPixel(hdc1,x, y,Colors1);
    }
  }
}


    };

}
void smoothfpstour(){
cout<<"auto tp1=chrono::system_clock::now();\
auto tp1=chrono::system_clock::now(); \
void ClearS(){ \
tp2=chrono::system_clock::now(); \
chrono::duration<int>elaspedtime=tp2-tp1; \
tp1=tp2; \
int iElaspedTime= elaspedtime.count();"<<endl;
}
namespace Extensions {//If user need something more he can use this
enum {
STRAGHIT=0,Curved=30
};
void CurveLines(int r,int g,int b,int curve){
while(1){
//Get a console handle
    HWND myconsole = GetConsoleWindow();
    //Get a handle to device context
    HDC mydc = GetDC(myconsole);

    int pixel =0;

    //Choose any color
    COLORREF COLOR= RGB(r,g,b);

    //Draw pixels
    for(double i = 0; i < PI * 4; i += 0.05)
    {
        SetPixel(mydc,pixel,(int)(curve+curve*cos(i)),COLOR);
        pixel+=1;
    }

    ReleaseDC(myconsole, mydc);
}
}
void Pixel(int x,int y,int r,int g,int b,int Length,int Pixel=1){
    if(Pixel=1){
   HWND myconsole = GetConsoleWindow();
    HDC hdc =GetDC(myconsole);
   COLORREF COLOR= RGB(r,g,b);
   for(int i=0;i<=Length;i++){
SetPixel(hdc, x, y, COLOR);
x+=1;
   }
    }else if(Pixel=2){
      HWND myconsole = GetConsoleWindow();
    HDC hdc =GetDC(myconsole);
   COLORREF COLOR= RGB(r,g,b);
   for(int i=0;i<=Length;i++){
SetPixel(hdc, x, y, COLOR);
y+=1;
   }
    }else if(Pixel=3){
      HWND myconsole = GetConsoleWindow();
    HDC hdc =GetDC(myconsole);
   COLORREF COLOR= RGB(r,g,b);
   for(int i=0;i<=Length;i++){
SetPixel(hdc, x, y, COLOR);
x+=1;
y+=1;
   }
    }
}
}
namespace FrameBuffersSPECIALEXTENION {
void ClearScreen()
  {
  HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Move the cursor home */
  SetConsoleCursorPosition( hStdOut, homeCoords );
  }

}

namespace AI_Functions {
class Ai {
private:
void Pos(short x,short y,short speed=1) {
		HANDLE poshandle = GetStdHandle(STD_OUTPUT_HANDLE);//handler function to handle inputs and everything
		COORD postion = { x,y };//cordinated map of x,y setting the pos as user need 0,0
		SetConsoleCursorPosition(poshandle, postion);//chaning cursor pos as user x,y user needs
		if(x==-1){
         x+=speed;
		}else if(y==-1){
		y+=speed;
		}
}

public:
void FollowPlayer(int npcx,int npcy,int playerx,int playery,int color,int Charater,bool flags){
char y=Charater;
int currentx;
while(flags){
system("cls");
currentx+=playerx;
currentx-=1;
npcy+=playery;
npcx+=currentx;
Ai ai;
ai.Pos(npcx,npcy);
cout<<y<<endl;
}
}
};
}
