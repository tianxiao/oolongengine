/*
Oolong Engine for the iPhone / iPod touch
Copyright (c) 2007-2008 Wolfgang Engel  http://code.google.com/p/oolongengine/

This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose, 
including commercial applications, and to alter it and redistribute it freely, 
subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/

#import <OpenGLES/EAGL.h>
#import <OpenGLES/ES1/gl.h>

//#include "Log.h"
#include "App.h"
#include "Mathematics.h"
#include "GraphicsDevice.h"
#include "UI.h"

#include "enet.h"

#include "Macros.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <sys/time.h>

CDisplayText * AppDisplayText;
int iCurrentTick = 0, iStartTick = 0, iFps = 0, iFrames = 0;

int frames;
float frameRate;

static int sMessageCounter;
static char* sMessageData;
static ENetHost* sClient;
static ENetPeer* sPeer;

const char* IP_ADDRESS = "74.14.6.40";
const int PORT = 9050;

bool CShell::InitApplication()
{
	AppDisplayText = new CDisplayText;  
	
	if(AppDisplayText->SetTextures(WindowHeight, WindowWidth))
				printf("Display text textures loaded\n");

	// Networking sample initialization
	sMessageCounter = 0;

	// Initialize enet and create a client
	if(enet_initialize() != 0)
	{
		printf("An error occurred while initializing ENet.\n");
	}
	
	// NULL address means no peers can connect to this host.  Bandwidth is set to no cap / unlimited.
	sClient = enet_host_create(NULL, 1, 0, 0);
	if(sClient == NULL)
	{
		printf("An error occurred while trying to create an ENet client host.\n");	
	}
	
	// IP Address and port to connect to
	ENetAddress address;
	enet_address_set_host(&address, IP_ADDRESS);
	address.port = PORT;
	
	sPeer = enet_host_connect(sClient, &address, 1);
	if(sPeer == NULL)
	{
		printf("No available peers for initializing an ENet connection.\n");
	}
	
	ENetEvent event;
	// waits 5 seconds to see if we connect (blocking)
	if(enet_host_service(sClient, &event, 5000) > 0 && event.type == ENET_EVENT_TYPE_CONNECT)
	{
		printf("Host connection successful!");
	}
	else
	{
		printf("Host connection failed!");
		enet_peer_reset(sPeer);
		return false;
	}
	// End of network initialization
	
	srand ( (unsigned int)time ( NULL ) );
	
	return true;
}

bool CShell::QuitApplication()
{
	AppDisplayText->ReleaseTextures();
	
	delete AppDisplayText;

	enet_deinitialize();
	
	return true;
}

bool CShell::InitView()
{
    glEnable(GL_DEPTH_TEST);
	glClearColor(0.3f, 0.3f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Set the OpenGL projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	MATRIX	MyPerspMatrix;
	MatrixPerspectiveFovRH(MyPerspMatrix, f2vt(70), f2vt(((float) 320 / (float) 480)), f2vt(0.1f), f2vt(1000.0f), 0);
	myglMultMatrix(MyPerspMatrix.f);

	
	static CFTimeInterval	startTime = 0;
	CFTimeInterval			time;
	
	//Calculate our local time
	time = CFAbsoluteTimeGetCurrent();
	if(startTime == 0)
	startTime = time;
	time = time - startTime;
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, - 10.0f);
	glRotatef(50.0f * fmod(time, 360.0), 0.0, 1.0, 1.0);

		
	return true;
}

bool CShell::ReleaseView()
{
	return true;
}

bool CShell::UpdateScene()
{
	// Update network
	ENetEvent event;
	
	if(enet_host_service(sClient, &event, 0) > 0 && event.type == ENET_EVENT_TYPE_RECEIVE)
	{
		delete sMessageData;
		sMessageData = new char[event.packet->dataLength];
		strncpy(sMessageData, (char*)event.packet->data, event.packet->dataLength);
		enet_packet_destroy(event.packet);
	}
	// End network update
	
 	static struct timeval time = {0,0};
	struct timeval currTime = {0,0};
 
 	frames++;
	gettimeofday(&currTime, NULL); // gets the current time passed since the last frame in seconds
	
	if (currTime.tv_usec - time.tv_usec) 
	{
		frameRate = ((float)frames/((currTime.tv_usec - time.tv_usec) / 1000000.0f));
		
		if(sMessageData != 0)
			AppDisplayText->DisplayText(0, 6, 0.4f, RGBA(255,255,255,255), "%s", sMessageData);
		time = currTime;
		frames = 0;
	}

	// Create and send a message to the server every 100 ticks
	if(sMessageCounter > 100)
	{
		int randomValue = 0;
		randomValue = (int)(101 * (double)rand() / (RAND_MAX + 1.0));
		
		std::string message = "Test Message, Random Number: ";
		
		std::ostringstream os;
		os << randomValue;
		std::string randomString = os.str();
		message.append(randomString);
		
		char* charMessage = new char[message.length() + 1];
		strcpy(charMessage, message.c_str());
		charMessage[message.length()] = '\0';
		
		ENetPacket* packet = enet_packet_create(charMessage, message.length() + 1, ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(sPeer, 0, packet);
		sMessageCounter = 0;
	}
	
	sMessageCounter++;
	
	return true;
}


bool CShell::RenderScene()
{
    const float verts[] =
    {
         1.0f, 1.0f,-1.0f,	
        -1.0f, 1.0f,-1.0f,	
        -1.0f, 1.0f, 1.0f,	
         1.0f, 1.0f, 1.0f,	

         1.0f,-1.0f, 1.0f,	
        -1.0f,-1.0f, 1.0f,	
        -1.0f,-1.0f,-1.0f,	
         1.0f,-1.0f,-1.0f,	

         1.0f, 1.0f, 1.0f,	
        -1.0f, 1.0f, 1.0f,	
        -1.0f,-1.0f, 1.0f,	
         1.0f,-1.0f, 1.0f,	

         1.0f,-1.0f,-1.0f,	
        -1.0f,-1.0f,-1.0f,	
        -1.0f, 1.0f,-1.0f,	
         1.0f, 1.0f,-1.0f,	

         1.0f, 1.0f,-1.0f,	
         1.0f, 1.0f, 1.0f,	
         1.0f,-1.0f, 1.0f,	
         1.0f,-1.0f,-1.0f,

        -1.0f, 1.0f, 1.0f,	
        -1.0f, 1.0f,-1.0f,	
        -1.0f,-1.0f,-1.0f,	
        -1.0f,-1.0f, 1.0f
     };

    glEnableClientState(GL_VERTEX_ARRAY);
    
    glColor4f(0, 1, 0, 1);
    glVertexPointer(3, GL_FLOAT, 0, verts);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    
    glColor4f(1, 0, 1, 1);
    glVertexPointer(3, GL_FLOAT, 0, verts + 12);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    
    glColor4f(0, 0, 1, 1);
    glVertexPointer(3, GL_FLOAT, 0, verts + 24);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    
    glColor4f(1, 1, 0, 1);
    glVertexPointer(3, GL_FLOAT, 0, verts + 36);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    
    glColor4f(1, 0, 0, 1);
    glVertexPointer(3, GL_FLOAT, 0, verts + 48);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    
    glColor4f(0, 1, 1, 1);
    glVertexPointer(3, GL_FLOAT, 0, verts + 60);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	
	// show text on the display
	AppDisplayText->DisplayDefaultTitle("ENet Networking", "", eDisplayTextLogoIMG);
	
	AppDisplayText->Flush();	
	
	return true;
}

