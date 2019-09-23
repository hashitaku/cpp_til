#include"include/system.hpp"

namespace inv::sys{

void resize([[maybe_unused]]int width, [[maybe_unused]]int height){
    glutReshapeWindow(inv::constant::window_size_width, inv::constant::window_size_height);
}

void load_tex(const std::filesystem::path& filename, unsigned int* id){

	if(id == nullptr){
		std::cerr << "load_tex *id is nullptr" << std::endl;
		std::exit(1);
	}

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

void display(){
	inv::draw::line({0.0, 0.0}, {10.0, 10.0});
}

}
