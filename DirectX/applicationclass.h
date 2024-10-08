#ifndef _APPLICATIONCLASS_H_
#define _APPLICATIONCLASS_H_

#include "d3dclass.h"
#include "cameraclass.h"
//#include "modelclass.h"
//#include "lightshaderclass.h"
//#include "lightclass.h"
//#include "textureshaderclass.h"
//#include "bitmapclass.h"
//#include "spriteclass.h"
//#include "timerclass.h"
#include "fontshaderclass.h"
#include "fontclass.h"
#include "textclass.h"
#include "fpsclass.h"

const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = false;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.3f;

class ApplicationClass
{
public:
	ApplicationClass();
	ApplicationClass(const ApplicationClass&);
	~ApplicationClass();

	bool Initialize(int, int, HWND);
	void Shutdown();
	bool Frame();

private:
	bool Render(float);
	bool UpdateFps();

private:
	D3DClass* m_Direct3D;
	CameraClass* m_Camera;
	//ModelClass* m_Model;
	//LightShaderClass* m_LightShader;
	//LightClass* m_Light;
	//LightClass* m_Lights;
	//int m_numLights;
	//TextureShaderClass* m_TextureShader;
	//BitmapClass* m_Bitmap;
	//SpriteClass* m_Sprite;
	//TimerClass* m_Timer;
	FontShaderClass* m_FontShader;
	FontClass* m_Font;
	FpsClass* m_Fps;
	TextClass* m_FpsString;
	int m_previousFps;
};

#endif