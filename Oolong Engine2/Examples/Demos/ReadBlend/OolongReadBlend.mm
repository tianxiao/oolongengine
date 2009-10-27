/*
 GameKit .blend file reader for Oolong Engine
 Copyright (c) 2009 Erwin Coumans http://gamekit.googlecode.com
 
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

#include "OolongReadBlend.h"
#include "btBulletDynamicsCommon.h"


//#define SWAP_COORDINATE_SYSTEMS
#ifdef SWAP_COORDINATE_SYSTEMS

#define IRR_X 0
#define IRR_Y 2
#define IRR_Z 1

#define IRR_X_M 1.f
#define IRR_Y_M 1.f
#define IRR_Z_M 1.f

///also winding is different
#define IRR_TRI_0_X 0
#define IRR_TRI_0_Y 2
#define IRR_TRI_0_Z 1

#define IRR_TRI_1_X 0
#define IRR_TRI_1_Y 3
#define IRR_TRI_1_Z 2
#else
#define IRR_X 0
#define IRR_Y 1
#define IRR_Z 2

#define IRR_X_M 1.f
#define IRR_Y_M 1.f
#define IRR_Z_M 1.f

///also winding is different
#define IRR_TRI_0_X 0
#define IRR_TRI_0_Y 1
#define IRR_TRI_0_Z 2

#define IRR_TRI_1_X 0
#define IRR_TRI_1_Y 2
#define IRR_TRI_1_Z 3
#endif






struct BasicTexture
{
	unsigned char*	m_jpgData;
	int		m_jpgSize;
	
	int				m_width;
	int				m_height;
	GLuint			m_textureName;
	bool			m_initialized;
	
	//contains the uncompressed R8G8B8 pixel data
	unsigned char*	m_output;
	
	
	BasicTexture(unsigned char* jpgData,int jpgSize)
	: m_jpgData(jpgData),
	m_jpgSize(jpgSize),
	m_output(0),
	m_textureName(-1),
	m_initialized(false)
	{
		
	}
	
	virtual ~BasicTexture()
	{
		delete[] m_output;
	}
	
	//returns true if szFilename has the szExt extension
	bool checkExt(char const * szFilename, char const * szExt)
	{
		if (strlen(szFilename) > strlen(szExt))
		{
			char const * szExtension = &szFilename[strlen(szFilename) - strlen(szExt)];
			if (!strcmp(szExtension, szExt))
				return true;
		}
		return false;
	}
	
	void	loadTextureMemory(const char* fileName)
	{
		if (checkExt(fileName,".JPG") || checkExt(fileName,".jpg"))
		{
			loadJpgMemory();
		}
	}
	
	void	initOpenGLTexture()
	{
		if (m_initialized)
		{
			glBindTexture(GL_TEXTURE_2D,m_textureName);
		} else
		{
			m_initialized = true;
			
			glGenTextures(1, &m_textureName);
			glBindTexture(GL_TEXTURE_2D,m_textureName);
			
//			gluBuild2DMipmaps(GL_TEXTURE_2D,3,m_width,m_height,GL_RGB,GL_UNSIGNED_BYTE,m_output);
			glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,m_width,m_height,0,GL_RGBA,GL_UNSIGNED_BYTE,m_output);
			
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			
		}
		
	}
	
	void	loadJpgMemory()
	{
		
#define	USE_IPHONE_SDK_JPEGLIB
#ifdef  USE_IPHONE_SDK_JPEGLIB
		NSData *imageData = [NSData dataWithBytes:m_jpgData length:m_jpgSize];
		UIImage *uiImage = [UIImage imageWithData:imageData];
		
		CGImageRef textureImage;
		CGContextRef textureContext;

		if( uiImage ) {
			textureImage = uiImage.CGImage;
			
			m_width = CGImageGetWidth(textureImage);
			m_height = CGImageGetHeight(textureImage);
			
						
			if(textureImage) {
				m_output = (GLubyte *) malloc(m_width * m_height * 4);
				textureContext = CGBitmapContextCreate(m_output, m_width, m_height, 8, m_width * 4, CGImageGetColorSpace(textureImage), kCGImageAlphaPremultipliedLast);
				CGContextDrawImage(textureContext, CGRectMake(0.0, 0.0, (float)m_width, (float)m_height), textureImage);
			}
			
		}			

#else
		
		///use the jpeg library to 'manually' extract the image
		
		unsigned char **rowPtr=0;
		
		// allocate and initialize JPEG decompression object
		struct jpeg_decompress_struct cinfo;
		struct my_jpeg_error_mgr jerr;
		
		//We have to set up the error handler first, in case the initialization
		//step fails.  (Unlikely, but it could happen if you are out of memory.)
		//This routine fills in the contents of struct jerr, and returns jerr's
		//address which we place into the link field in cinfo.
		
		cinfo.err = jpeg_std_error(&jerr.pub);
		cinfo.err->error_exit = error_exit;
		cinfo.err->output_message = output_message;
		
		// compatibility fudge:
		// we need to use setjmp/longjmp for error handling as gcc-linux
		// crashes when throwing within external c code
		if (setjmp(jerr.setjmp_buffer))
		{
			// If we get here, the JPEG code has signaled an error.
			// We need to clean up the JPEG object and return.
			
			jpeg_destroy_decompress(&cinfo);
			
			
			// if the row pointer was created, we delete it.
			if (rowPtr)
				delete [] rowPtr;
			
			// return null pointer
			return ;
		}
		
		// Now we can initialize the JPEG decompression object.
		jpeg_create_decompress(&cinfo);
		
		// specify data source
		jpeg_source_mgr jsrc;
		
		// Set up data pointer
		jsrc.bytes_in_buffer = m_jpgSize;
		jsrc.next_input_byte = (JOCTET*)m_jpgData;
		cinfo.src = &jsrc;
		
		jsrc.init_source = init_source;
		jsrc.fill_input_buffer = fill_input_buffer;
		jsrc.skip_input_data = skip_input_data;
		jsrc.resync_to_restart = jpeg_resync_to_restart;
		jsrc.term_source = term_source;
		
		// Decodes JPG input from whatever source
		// Does everything AFTER jpeg_create_decompress
		// and BEFORE jpeg_destroy_decompress
		// Caller is responsible for arranging these + setting up cinfo
		
		// read file parameters with jpeg_read_header()
		jpeg_read_header(&cinfo, TRUE);
		
		cinfo.out_color_space=JCS_RGB;
		cinfo.out_color_components=3;
		cinfo.do_fancy_upsampling=FALSE;
		
		// Start decompressor
		jpeg_start_decompress(&cinfo);
		
		// Get image data
		unsigned short rowspan = cinfo.image_width * cinfo.out_color_components;
		m_width = cinfo.image_width;
		m_height = cinfo.image_height;
		
		// Allocate memory for buffer
		m_output = new unsigned char[rowspan * m_height];
		
		// Here we use the library's state variable cinfo.output_scanline as the
		// loop counter, so that we don't have to keep track ourselves.
		// Create array of row pointers for lib
		rowPtr = new unsigned char* [m_height];
		
		for( unsigned int i = 0; i < m_height; i++ )
			rowPtr[i] = &m_output[ i * rowspan ];
		
		unsigned int rowsRead = 0;
		
		while( cinfo.output_scanline < cinfo.output_height )
			rowsRead += jpeg_read_scanlines( &cinfo, &rowPtr[rowsRead], cinfo.output_height - rowsRead );
		
		delete [] rowPtr;
		// Finish decompression
		
		jpeg_finish_decompress(&cinfo);
		
		// Release JPEG decompression object
		// This is an important step since it will release a good deal of memory.
		jpeg_destroy_decompress(&cinfo);
		
		//		// convert image
		//		IImage* image = new CImage(ECF_R8G8B8,
		//			core::dimension2d<s32>(width, height), output);
		//
		//
		//		return image;
		
#endif
		
	}
	
};


GfxObject::GfxObject(GLuint vboId,btCollisionObject* colObj)
:m_colObj(colObj),
m_texture(0)
{
}


void GfxObject::render()
{
	
	if (m_texture)
	{
		m_texture->initOpenGLTexture();
		
		glBindTexture(GL_TEXTURE_2D,m_texture->m_textureName);
		
		glEnable(GL_TEXTURE_2D);
		//glDisable(GL_TEXTURE_GEN_S);
		//glDisable(GL_TEXTURE_GEN_T);
		//glDisable(GL_TEXTURE_GEN_R);
		
	} else
	{
		glDisable(GL_TEXTURE_2D);
	}
	
	glPushMatrix();
	float m[16];
	m_colObj->getWorldTransform().getOpenGLMatrix(m);
	
	glMultMatrixf(m);
		
//	glScalef(0.1,0.1,0.1);
	
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);	
	glTexCoordPointer(2, GL_FLOAT, sizeof(GfxVertex), &m_vertices[0].m_uv[0]);
	
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glColor4f(1, 1, 1, 1);
    glVertexPointer(3, GL_FLOAT, sizeof(GfxVertex), &m_vertices[0].m_position.getX());
 //   glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	
	for (int i=0;i<m_indices.size();i++)
	{
		if (m_indices[i] > m_vertices.size())
		{
			printf("out of bounds: m_indices[%d]=%d but m_vertices.size()=%d",i,m_indices[i],m_vertices.size());
		}
	}
	glDrawElements(GL_TRIANGLES,m_indices.size(),GL_UNSIGNED_SHORT,&m_indices[0]);

	glPopMatrix();

}
	


OolongBulletBlendReader::OolongBulletBlendReader(class btDynamicsWorld* destinationWorld)
:BulletBlendReader(destinationWorld)
{
	m_cameraTrans.setIdentity();
}
	
OolongBulletBlendReader::~OolongBulletBlendReader()
{
	for (int i=0;i<m_graphicsObjects.size();i++)
	{
		// Delete the VBO as it is no longer needed
//		glDeleteBuffers(1, &m_graphicsObjects[i].m_ui32Vbo);
//		delete m_graphicsObjects[i].m_texture;
		
	}
}

BasicTexture* OolongBulletBlendReader::findTexture(const char* fileName)
{
	
	BasicTexture** result = m_textures.find(fileName);
	if (result)
		return *result;
	
	return 0;
}

void* OolongBulletBlendReader::createGraphicsObject(_bObj* tmpObject, class btCollisionObject* bulletObject)
{
	GfxObject gfxobject(0,bulletObject);

	
#if 0
	
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
	
	GLfloat texcoords[] =
	{
		// Top - facing to +Y		// Texture Coord
		1.0f,0.0f,
		0.0f, 0.0f,	
		0.0f, 1.0f,
		1.0f, 1.0f,
		
		// Bottom - facing to -Y
		1.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 1.0f,
		
		// Front - facing to +Z
		1.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 1.0f,
		
		// Back - facing to -Z
		1.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 1.0f,
		
		// Right - facing to +X
		1.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 1.0f,
		
		// Left - facing to -X
		1.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 1.0f
	};

	gfxobject.m_vertices.resize(24);
	for (int i=0;i<24;i++)
	{
		gfxobject.m_vertices[i].m_position.setValue(verts[i*3],verts[i*3+1],verts[i*3+2]);
		gfxobject.m_vertices[i].m_uv[0] =texcoords[i*2];
		gfxobject.m_vertices[i].m_uv[1] =texcoords[i*2+1];
	}
	
	unsigned short int indices[]={
		0,1,2,
		0,2,3,
		4,5,6,
		4,6,7,
		8,9,10,
		8,10,11,
		12,13,14,
		12,14,15,
		16,17,18,
		16,18,19,
		20,21,22,
		20,22,23};
	
	for (int i=0;i<36;i++)
		gfxobject.m_indices.push_back(indices[i]);
	
	m_graphicsObjects.push_back(gfxobject);
	
#else

	
	/*
	btRigidBody* body = btRigidBody::upcast(bulletObject);
	IrrMotionState* newMotionState = 0;
	
	if (body)
	{
		if (!bulletObject->isStaticOrKinematicObject())
		{
			newMotionState = new IrrMotionState();
			newMotionState->setWorldTransform(body->getWorldTransform());
			body->setMotionState(newMotionState);
		}
	}
	 */
	
	
	
	if (tmpObject->data.mesh && tmpObject->data.mesh->vert_count && tmpObject->data.mesh->face_count)
	{
		if (tmpObject->data.mesh->vert_count> 16300)
		{
			printf("tmpObject->data.mesh->vert_count = %d\n",tmpObject->data.mesh->vert_count);
			return 0;
		}
		
		int maxVerts = btMin(16300,btMax(tmpObject->data.mesh->face_count*3*2,(tmpObject->data.mesh->vert_count-6)));
		
		GfxVertex* orgVertices= new GfxVertex[tmpObject->data.mesh->vert_count];
		
		for (int v=0;v<tmpObject->data.mesh->vert_count;v++)
		{
			float* vt3 = tmpObject->data.mesh->vert[v].xyz;
			orgVertices[v].m_position.setValue(IRR_X_M*vt3[IRR_X],	IRR_Y_M*vt3[IRR_Y],	IRR_Z_M*vt3[IRR_Z]);
		}
		
		
		int numTriangles=0;
		int numIndices = 0;
		int currentIndex = 0;
		
		int maxNumIndices = tmpObject->data.mesh->face_count*4*2;
		
		int totalVerts = 0;
		
		for (int t=0;t<tmpObject->data.mesh->face_count;t++)
		{
			totalVerts += (tmpObject->data.mesh->face[t].v[3]) ? 6 : 3;
		}
		
		gfxobject.m_vertices.resize(totalVerts);
		
		for (int t=0;t<tmpObject->data.mesh->face_count;t++)
		{
			if (currentIndex>maxNumIndices)
				break;
			
			int originalIndex = tmpObject->data.mesh->face[t].v[IRR_TRI_0_X];
			gfxobject.m_indices.push_back(currentIndex);
			gfxobject.m_vertices[currentIndex].m_position = orgVertices[originalIndex].m_position;
			gfxobject.m_vertices[currentIndex].m_uv[0] = tmpObject->data.mesh->face[t].uv[IRR_TRI_0_X][0];
			gfxobject.m_vertices[currentIndex].m_uv[1] = tmpObject->data.mesh->face[t].uv[IRR_TRI_0_X][1];
			numIndices++;
			currentIndex++;
						
			originalIndex = tmpObject->data.mesh->face[t].v[IRR_TRI_0_Y];
			gfxobject.m_indices.push_back(currentIndex);
			gfxobject.m_vertices[currentIndex].m_position = orgVertices[originalIndex].m_position;
			gfxobject.m_vertices[currentIndex].m_uv[0] = tmpObject->data.mesh->face[t].uv[IRR_TRI_0_Y][0];
			gfxobject.m_vertices[currentIndex].m_uv[1] = tmpObject->data.mesh->face[t].uv[IRR_TRI_0_Y][1];
			numIndices++;
			currentIndex++;
					
			originalIndex = tmpObject->data.mesh->face[t].v[IRR_TRI_0_Z];
			gfxobject.m_indices.push_back(currentIndex);
			gfxobject.m_vertices[currentIndex].m_position = orgVertices[originalIndex].m_position;
			gfxobject.m_vertices[currentIndex].m_uv[0] = tmpObject->data.mesh->face[t].uv[IRR_TRI_0_Z][0];
			gfxobject.m_vertices[currentIndex].m_uv[1] = tmpObject->data.mesh->face[t].uv[IRR_TRI_0_Z][1];
			numIndices++;
			currentIndex++;
			numTriangles++;
			
			if (tmpObject->data.mesh->face[t].v[3])
			{
				originalIndex = tmpObject->data.mesh->face[t].v[IRR_TRI_1_X];
				gfxobject.m_indices.push_back(currentIndex);
				gfxobject.m_vertices[currentIndex].m_position = orgVertices[originalIndex].m_position;
				gfxobject.m_vertices[currentIndex].m_uv[0] = tmpObject->data.mesh->face[t].uv[IRR_TRI_1_X][0];
				gfxobject.m_vertices[currentIndex].m_uv[1] = tmpObject->data.mesh->face[t].uv[IRR_TRI_1_X][1];
				numIndices++;
				currentIndex++;
				
				originalIndex = tmpObject->data.mesh->face[t].v[IRR_TRI_1_Y];
				gfxobject.m_indices.push_back(currentIndex);
				gfxobject.m_vertices[currentIndex].m_position = orgVertices[originalIndex].m_position;
				gfxobject.m_vertices[currentIndex].m_uv[0] = tmpObject->data.mesh->face[t].uv[IRR_TRI_1_Y][0];
				gfxobject.m_vertices[currentIndex].m_uv[1] = tmpObject->data.mesh->face[t].uv[IRR_TRI_1_Y][1];
				numIndices++;
				currentIndex++;
				
				originalIndex = tmpObject->data.mesh->face[t].v[IRR_TRI_1_Z];
				gfxobject.m_indices.push_back(currentIndex);
				gfxobject.m_vertices[currentIndex].m_position = orgVertices[originalIndex].m_position;
				gfxobject.m_vertices[currentIndex].m_uv[0] = tmpObject->data.mesh->face[t].uv[IRR_TRI_1_Z][0];
				gfxobject.m_vertices[currentIndex].m_uv[1] = tmpObject->data.mesh->face[t].uv[IRR_TRI_1_Z][1];
				
				numIndices++;
				currentIndex++;
				
				numTriangles++;
			}
			
			
		}
		delete[] orgVertices;
		
		if (numTriangles>0)
		{
			
			BasicTexture* texture0 = 0;
			
			if (tmpObject->data.mesh->face[0].m_image)
			{
				const char* fileName = tmpObject->data.mesh->face[0].m_image->m_imagePathName;
				
				texture0 = findTexture(fileName);
				
				if (!texture0)
				{
					void* jpgData = tmpObject->data.mesh->face[0].m_image->m_packedImagePtr;
					int jpgSize = tmpObject->data.mesh->face[0].m_image->m_sizePackedImage;
					if (jpgSize)
					{
						texture0 = new BasicTexture((unsigned char*)jpgData,jpgSize);
						printf("texture filename=%s\n",fileName);
						texture0->loadTextureMemory(fileName);
						
						m_textures.insert(fileName,texture0);
						
						
					}
				}
			}
			gfxobject.m_texture = texture0;
			
				//search for texture
			
//			static int once = true;
//			if (once)
				m_graphicsObjects.push_back(gfxobject);
//			once = false;
			
//			scene::ISceneNode* node = createMeshNode(newVertices,numVertices,indices,numIndices,numTriangles,bulletObject,tmpObject);
//			
//			if (!meshContainer)
//				meshContainer = new IrrlichtMeshContainer();
//			meshContainer->m_sceneNodes.push_back(node);
//			
//			if (newMotionState && node)
//				newMotionState->addIrrlichtNode(node);
			
			
		}
	}
	
	
#endif
	
	
	return 0;
}



void	OolongBulletBlendReader::addCamera(_bObj* tmpObject)
{
	m_cameraTrans.setOrigin(btVector3(tmpObject->location[IRR_X],tmpObject->location[IRR_Y],tmpObject->location[IRR_Z]));
	btMatrix3x3 mat;
	mat.setEulerZYX(tmpObject->rotphr[0],tmpObject->rotphr[1],tmpObject->rotphr[2]);
	m_cameraTrans.setBasis(mat);
}

	
void	OolongBulletBlendReader::addLight(_bObj* tmpObject)
{
	printf("added Light\n");
}

void	OolongBulletBlendReader::convertLogicBricks()
{
}

void	OolongBulletBlendReader::createParentChildHierarchy()
{
}




