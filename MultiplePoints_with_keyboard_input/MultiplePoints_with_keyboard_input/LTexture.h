#include<IL\il.h>
#include<IL\ilu.h>
#include<glut.h>
#include<iostream>

class LTexture
{
public: LTexture();
		~LTexture();
		void freeTexture();
		bool ImageToPixel(GLuint *pixel, GLuint width, GLuint height);
		bool LoadTextureFromImage(std::string path);
		void render(float x, float y);
		void rotate()
		{
			glPushMatrix();
			glTranslatef(100, 100, 200);
			glRotatef(angle, 0, 0, 1);
			render(100, 100);
			glPopMatrix();
		}
		GLuint getTextureID();
		GLuint getTextureWidth();
		GLuint getTextureHeight();
		int angle;
private: GLuint mTextureID;
		 GLuint mTextureWidth;
		 GLuint mTextureHeight;
		 
};


LTexture::LTexture()
{
	mTextureID = 0;
	mTextureHeight = 0;
	mTextureWidth = 0;
	angle = 0;
}

LTexture::~LTexture()
{
	freeTexture();
}


void LTexture::freeTexture()
{
	if (mTextureID != 0)
	{
		glDeleteTextures(1,&mTextureID);
		mTextureID = 0;
	}

	mTextureHeight = 0;
	mTextureWidth = 0;
}


bool LTexture::ImageToPixel(GLuint *pixel, GLuint width, GLuint height)
{

	freeTexture();
	mTextureWidth = width;
	mTextureHeight = height;

	glGenTextures(1, &mTextureID);
	glBindTexture(GL_TEXTURE_2D, mTextureID);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixel);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, NULL);

	GLenum error = glGetError();

	if (error != GL_NO_ERROR)
	{
		std::cout << "Error loading pixel";
		return false;
	}


	return true;

}


bool LTexture::LoadTextureFromImage(std::string path)
{

	ILuint mImageID;
	bool texture = false;
	ilGenImages(1, &mImageID);
	ilBindImage(mImageID);

	ILboolean success = ilLoadImage((ILstring)path.c_str());

	if (success == IL_TRUE)
	{
		success = ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
		if (success == IL_TRUE)
		{
			texture = ImageToPixel((GLuint *)ilGetData(), (GLuint)ilGetInteger(IL_IMAGE_WIDTH), (GLuint)ilGetInteger(IL_IMAGE_HEIGHT));
		}

		ilDeleteImages(1, &mImageID);
	}

	return texture;
}


void LTexture:: render(float x, float y)
{
	
	if (mTextureID != 0)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0, 0, 0, 1);
		glBindTexture(GL_TEXTURE_2D, mTextureID);
		glBegin(GL_QUADS);
		glTexCoord2f(0, 1); glVertex2f(-400, -400);
		glTexCoord2f(1, 1); glVertex2f(400, -400);
		glTexCoord2f(1, 0); glVertex2f(400, 400);
		glTexCoord2f(0, 0); glVertex2f(-400, 400);
		glEnd();
		glFlush();
	}

}

