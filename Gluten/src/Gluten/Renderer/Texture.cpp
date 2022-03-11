#include "glutpch.h"
#include "Texture.h"

#include <glad/glad.h>

#include <windows.h>
#include <string>
#include <limits.h>
#include <iostream>

namespace Gluten::Renderer {


	Texture::Texture(const char* location)
		: m_Location(location)
	{

       std::string path = GLUT_CORE_ASSET_MANAGER_LOCATION;
       path.append(location);
       m_Location = path.c_str();
       GLUT_CORE_INFO("Creating Image: {0}", m_Location);

        unsigned int texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
        // set the texture wrapping parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // Set no border
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BORDER, GL_NONE);
        // set texture filtering parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        // load image, create texture and generate mipmaps
        int width, height, nrChannels;
        stbi_set_flip_vertically_on_load(1);
        unsigned char* data = stbi_load(m_Location, &width, &height, &nrChannels, 0);
        if (data)
        {
            if (nrChannels == 3) m_Format = GL_RGB;
            if (nrChannels == 4) m_Format = GL_RGBA;
            glTexImage2D(GL_TEXTURE_2D, 0, m_Format, width, height, 0, m_Format, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            GLUT_CORE_ERROR("Image Failed to Load: {0}", m_Location);
        }
        m_RendererID = texture;
        stbi_image_free(data);
	}
	void Texture::Bind()
	{
		glBindTexture(GL_TEXTURE_2D, m_RendererID);
	}
	void Texture::Unbind()
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}