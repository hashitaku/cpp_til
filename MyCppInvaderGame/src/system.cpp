#include"include/system.hpp"

namespace inv::sys{

void resize(int width, int height){
    glutReshapeWindow(inv::constant::window_size_width, inv::constant::window_size_height);
}

void load_tex(const std::string& filename, unsigned int* id){

	glGenTextures(1, id);

    int width, height, channel;

    auto texture = stbi_load(filename.c_str(), &width, &height, &channel, STBI_default);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glBindTexture(GL_TEXTURE_2D, *id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture);

	stbi_image_free(texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}

}
