#include "applicationclass.h"

ApplicationClass::ApplicationClass()
{
	m_Direct3D = 0;
	m_Camera = 0;
	//m_Model = 0;
	//m_LightShader = 0;
	//m_Lights = 0;
	//m_TextureShader = 0;
	//m_Bitmap = 0;
	//m_Sprite = 0;
	//m_Timer = 0;
	m_FontShader = 0;
	m_Font = 0;
	m_TextString1 = 0;
	m_TextString2 = 0;
	m_TextString3 = 0;
}

ApplicationClass::ApplicationClass(const ApplicationClass& other)
{
}

ApplicationClass::~ApplicationClass()
{
}

bool ApplicationClass::Initialize(int screenWidth, int screenHeight, HWND hwnd)
{
	//char modelFilename[128];
	//char textureFilename[128];
	//char bitmapFilename[128];
	//char spriteFilename[128];
	char testString1[32], testString2[32], testString3[32];
	bool result;

	// Create and initialize the Direct3D object.
	m_Direct3D = new D3DClass;

	result = m_Direct3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize Direct3D", L"Error", MB_OK);
		return false;
	}

	// Create the camera object.
	m_Camera = new CameraClass;

	// Set the initial position of the camera.
	m_Camera->SetPosition(0.0f, 0.0f, -10.0f);
	m_Camera->Render();

	//// Create and initialize the texture shader object.
	//m_TextureShader = new TextureShaderClass;

	//result = m_TextureShader->Initialize(m_Direct3D->GetDevice(), hwnd);
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the texture shader object.", L"Error", MB_OK);
	//	return false;
	//}

	// Set the name of the texture file that we will be loading.
	//strcpy_s(textureFilename, "my_img.tga");
	//strcpy_s(bitmapFilename, "my_img.tga");

	//// Set the file name of the model.
	//strcpy_s(modelFilename, "plane.txt");

	//// Create and initialize the model object.
	//m_Model = new ModelClass;

	//result = m_Model->Initialize(m_Direct3D->GetDevice(), m_Direct3D->GetDeviceContext(), modelFilename, textureFilename);

	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
	//	return false;
	//}

	// Create and initialize the bitmap object.
	//m_Bitmap = new BitmapClass;

	//result = m_Bitmap->Initialize(m_Direct3D->GetDevice(), m_Direct3D->GetDeviceContext(), screenWidth, screenHeight, bitmapFilename, 600, 300);
	//if (!result)
	//{
	//	return false;
	//}

	//// Set the sprite info file we will be using.
	//strcpy_s(spriteFilename, "Data/my_img_data.txt");

	//// Create and initialize the sprite object.
	//m_Sprite = new SpriteClass;

	//result = m_Sprite->Initialize(m_Direct3D->GetDevice(), m_Direct3D->GetDeviceContext(), screenWidth, screenHeight, spriteFilename, 600, 300);
	//if (!result)
	//{
	//	return false;
	//}

	//// Create and initialize the light shader object.
	//m_LightShader = new LightShaderClass;

	//result = m_LightShader->Initialize(m_Direct3D->GetDevice(), hwnd);
	//if (!result)
	//{
	//	MessageBox(hwnd, L"Could not initialize the light shader object.", L"Error", MB_OK);
	//	return false;
	//}

	//// Create and initialize the light object.
	//m_Light = new LightClass;

	//// 0.2f, 0.2f, 0.2f
	//// 0.0f, 0.0f, 0.0f
	//m_Light->SetAmbientColor(0.2f, 0.2f, 0.2f, 1.0f);
	//m_Light->SetDiffuseColor(1.0f, 1.0f, 1.0f, 1.0f);
	//m_Light->SetDirection(-1.0f, -1.0f, 1.0f);
	//m_Light->SetSpecularColor(1.0f, 0.0f, 1.0f, 1.0f);
	//m_Light->SetSpecularPower(16.0f);

	//// Set the number of lights we will use.
	//m_numLights = 5;

	//// Create and initialize the light objects array.
	//m_Lights = new LightClass[m_numLights];

	//// Manually set the color and position of each light.
	//m_Lights[0].SetDiffuseColor(1.0f, 0.0f, 0.0f, 1.0f);  // Red
	//m_Lights[0].SetPosition(-3.0f, 1.0f, 3.0f);

	//m_Lights[1].SetDiffuseColor(0.0f, 1.0f, 0.0f, 1.0f);  // Green
	//m_Lights[1].SetPosition(-3.0f, 1.0f, 3.0f);

	//m_Lights[2].SetDiffuseColor(0.0f, 0.0f, 1.0f, 1.0f);  // Blue
	//m_Lights[2].SetPosition(-3.0f, 1.0f, -3.0f);

	//m_Lights[3].SetDiffuseColor(1.0f, 1.0f, 1.0f, 1.0f);  // White
	//m_Lights[3].SetPosition(3.0f, 1.0f, -3.0f);

	//m_Lights[4].SetDiffuseColor(1.0f, 0.0f, 1.0f, 1.0f);  // puple	
	//m_Lights[4].SetPosition(3.0f, 1.0f, 3.0f);

	//// Create and initialize the timer object.
	//m_Timer = new TimerClass;

	//result = m_Timer->Initialize();
	//if (!result)
	//{
	//	return false;
	//}

	 // Create and initialize the font shader object.
	m_FontShader = new FontShaderClass;

	result = m_FontShader->Initialize(m_Direct3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the font shader object.", L"Error", MB_OK);
		return false;
	}

	// Create and initialize the font object.
	m_Font = new FontClass;

	result = m_Font->Initialize(m_Direct3D->GetDevice(), m_Direct3D->GetDeviceContext(), 0);
	if (!result)
	{
		return false;
	}

	// Set the strings we want to display.
	strcpy_s(testString1, "Hello");
	strcpy_s(testString2, "Goodbye");
	strcpy_s(testString3, "World!");

	// Create and initialize the first text object.
	m_TextString1 = new TextClass;

	result = m_TextString1->Initialize(m_Direct3D->GetDevice(), m_Direct3D->GetDeviceContext(), screenWidth, screenHeight, 32, m_Font, testString1, 200, 100, 0.0f, 1.0f, 0.0f);
	if (!result)
	{
		return false;
	}

	// Create and initialize the second text object.
	m_TextString2 = new TextClass;

	result = m_TextString2->Initialize(m_Direct3D->GetDevice(), m_Direct3D->GetDeviceContext(), screenWidth, screenHeight, 32, m_Font, testString2, 200, 150, 1.0f, 1.0f, 0.0f);
	if (!result)
	{
		return false;
	}

	// Create and initialize the second text object.
	m_TextString3 = new TextClass;

	int posX = (screenWidth - m_Font->GetSentencePixelLength(testString3)) / 2;
	int posY = (screenHeight - m_Font->GetFontHeight()) / 2;

	result = m_TextString3->Initialize(m_Direct3D->GetDevice(), m_Direct3D->GetDeviceContext(), screenWidth, screenHeight, 32, m_Font, testString3, posX, posY, 0.0f, 0.0f, 1.0f);
	if (!result)
	{
		return false;
	}

	return true;
}

void ApplicationClass::Shutdown()
{
	//// Release the timer object.
	//if (m_Timer)
	//{
	//	delete m_Timer;
	//	m_Timer = 0;
	//}

	//// Release the light object.
	//if (m_Light)
	//{
	//	delete m_Light;
	//	m_Light = 0;
	//}

	//// Release the light objects.
	//if (m_Lights)
	//{
	//	delete[] m_Lights;
	//	m_Lights = 0;
	//}

	//// Release the light shader object.
	//if (m_LightShader)
	//{
	//	m_LightShader->Shutdown();
	//	delete m_LightShader;
	//	m_LightShader = 0;
	//}

	//// Release the model object.
	//if (m_Model)
	//{
	//	m_Model->Shutdown();
	//	delete m_Model;
	//	m_Model = 0;
	//}

	//// Release the bitmap object.
	//if (m_Bitmap)
	//{
	//	m_Bitmap->Shutdown();
	//	delete m_Bitmap;
	//	m_Bitmap = 0;
	//}

	//// Release the sprite object.
	//if (m_Sprite)
	//{
	//	m_Sprite->Shutdown();
	//	delete m_Sprite;
	//	m_Sprite = 0;
	//}

	//// Release the texture shader object.
	//if (m_TextureShader)
	//{
	//	m_TextureShader->Shutdown();
	//	delete m_TextureShader;
	//	m_TextureShader = 0;
	//}

	// Release the text string objects.
	if (m_TextString3)
	{
		m_TextString3->Shutdown();
		delete m_TextString1;
		m_TextString1 = 0;
	}

	if (m_TextString2)
	{
		m_TextString2->Shutdown();
		delete m_TextString2;
		m_TextString2 = 0;
	}

	if (m_TextString1)
	{
		m_TextString1->Shutdown();
		delete m_TextString1;
		m_TextString1 = 0;
	}

	// Release the font object.
	if (m_Font)
	{
		m_Font->Shutdown();
		delete m_Font;
		m_Font = 0;
	}

	// Release the font shader object.
	if (m_FontShader)
	{
		m_FontShader->Shutdown();
		delete m_FontShader;
		m_FontShader = 0;
	}

	// Release the camera object.
	if (m_Camera)
	{
		delete m_Camera;
		m_Camera = 0;
	}

	// Release the Direct3D object.
	if (m_Direct3D)
	{
		m_Direct3D->Shutdown();
		delete m_Direct3D;
		m_Direct3D = 0;
	}

	return;
}

bool ApplicationClass::Frame()
{
	static float rotation = 180.0f;
	//float frameTime;
	bool result;


	//// Update the system stats.
	//m_Timer->Frame();

	//// Get the current frame time.
	//frameTime = m_Timer->GetTime();

	//// Update the sprite object using the frame time.
	//m_Sprite->Update(frameTime);

	// Update the rotation variable each frame.
	//rotation -= 0.0174532925f * 0.25f;
	//if (rotation < 0.0f)
	//{
	//	rotation += 360.0f;
	//}

	// Render the graphics scene.
	result = Render(rotation);
	if (!result)
	{
		return false;
	}

	return true;
}

bool ApplicationClass::Render(float rotation)
{
	//XMMATRIX worldMatrix, viewMatrix, projectionMatrix, rotateMatrix, translateMatrix, scaleMatrix, srMatrix;
	//XMMATRIX worldMatrix, viewMatrix, projectionMatrix;
	XMMATRIX worldMatrix, viewMatrix, orthoMatrix;
	//XMFLOAT4 diffuseColor[5], lightPosition[5];
	//int i;
	bool result;

	// Clear the buffers to begin the scene.
	m_Direct3D->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);

	// Get the world, view, and projection matrices from the camera and d3d objects.
	m_Direct3D->GetWorldMatrix(worldMatrix);
	m_Camera->GetViewMatrix(viewMatrix);
	//m_Direct3D->GetProjectionMatrix(projectionMatrix);
	m_Direct3D->GetOrthoMatrix(orthoMatrix);

	// Disable the Z buffer and enable alpha blending for 2D rendering.
	m_Direct3D->TurnZBufferOff();
	m_Direct3D->EnableAlphaBlending();

	//// Put the bitmap vertex and index buffers on the graphics pipeline to prepare them for drawing.
	//result = m_Bitmap->Render(m_Direct3D->GetDeviceContext());
	//if (!result)
	//{
	//	return false;
	//}

	//// Put the sprite vertex and index buffers on the graphics pipeline to prepare them for drawing.
	//result = m_Sprite->Render(m_Direct3D->GetDeviceContext());
	//if (!result)
	//{
	//	return false;
	//}

	//// Render the bitmap with the texture shader.
	//result = m_TextureShader->Render(m_Direct3D->GetDeviceContext(), m_Bitmap->GetIndexCount(), worldMatrix, viewMatrix, orthoMatrix, m_Bitmap->GetTexture());
	//if (!result)
	//{
	//	return false;
	//}

	//// Render the sprite with the texture shader.
	//result = m_TextureShader->Render(m_Direct3D->GetDeviceContext(), m_Sprite->GetIndexCount(), worldMatrix, viewMatrix, orthoMatrix, m_Sprite->GetTexture());
	//if (!result)
	//{
	//	return false;
	//}

	// Render the first text string using the font shader.
	m_TextString1->Render(m_Direct3D->GetDeviceContext());

	result = m_FontShader->Render(m_Direct3D->GetDeviceContext(), m_TextString1->GetIndexCount(), worldMatrix, viewMatrix, orthoMatrix,
		m_Font->GetTexture(), m_TextString1->GetPixelColor());
	if (!result)
	{
		return false;
	}

	// Render the second text string using the font shader.
	m_TextString2->Render(m_Direct3D->GetDeviceContext());

	result = m_FontShader->Render(m_Direct3D->GetDeviceContext(), m_TextString2->GetIndexCount(), worldMatrix, viewMatrix, orthoMatrix,
		m_Font->GetTexture(), m_TextString2->GetPixelColor());
	if (!result)
	{
		return false;
	}

	// Render the second text string using the font shader.
	m_TextString3->Render(m_Direct3D->GetDeviceContext());

	result = m_FontShader->Render(m_Direct3D->GetDeviceContext(), m_TextString3->GetIndexCount(), worldMatrix, viewMatrix, orthoMatrix,
		m_Font->GetTexture(), m_TextString3->GetPixelColor());
	if (!result)
	{
		return false;
	}

	// Enable the Z buffer and disable alpha blending now that 2D rendering is complete.
	m_Direct3D->TurnZBufferOn();
	m_Direct3D->DisableAlphaBlending();

	//// Get the light properties.
	//for (i = 0; i < m_numLights; i++)
	//{
	//	// Create the diffuse color array from the four light colors.
	//	diffuseColor[i] = m_Lights[i].GetDiffuseColor();

	//	// Create the light position array from the four light positions.
	//	lightPosition[i] = m_Lights[i].GetPosition();
	//}

	//rotateMatrix = XMMatrixRotationY(rotation);  // Build the rotation matrix.
	//translateMatrix = XMMatrixTranslation(0.0f, 0.0f, 0.0f);  // Build the translation matrix.

	//// Multiply them together to create the final world transformation matrix.
	//worldMatrix = XMMatrixMultiply(translateMatrix, rotateMatrix);

	//// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	//m_Model->Render(m_Direct3D->GetDeviceContext());

	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), m_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, m_Model->GetTexture(),
	//	m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
	//	m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	//if (!result)
	//{
	//	return false;
	//}

	//// Render the model using the light shader.
	//result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), m_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, m_Model->GetTexture(),
	//	diffuseColor, lightPosition);
	//if (!result)
	//{
	//	return false;
	//}

	// Present the rendered scene to the screen.
	m_Direct3D->EndScene();

	return true;
}