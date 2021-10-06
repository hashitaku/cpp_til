/*stb */
#include<vector>
#include<random>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include"stb/stb_image_write.h"

class RGBA{
    private:
        unsigned char r_, g_, b_, a_;
    public:
        RGBA() : r_(), g_(), b_(), a_() {}
        RGBA(int r, int g, int b, int a) : r_(r), g_(g), b_(b), a_(a) {}

        unsigned char getR(){ return r_; }
        unsigned char getG(){ return g_; }
        unsigned char getB(){ return b_; }
        unsigned char getA(){ return a_; }
};

int main(){
    
    std::vector<RGBA> image(600 * 600);

    auto engine = std::mt19937_64{std::random_device{}()};

    for(auto&& e : image){
        RGBA tmp(static_cast<unsigned char>(engine()), static_cast<unsigned char>(engine()), static_cast<unsigned char>(engine()), 255);
        e = tmp;
    }

    stbi_write_png("image.png", 600, 600, static_cast<int>(sizeof(RGBA)), image.data(), 0);
    
    return 0;
}
