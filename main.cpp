#include "draw.hpp"
#include <iostream>

// I'm a bit too lazy to switch to Windows

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: drawBmp <path_to_bmp>" << std::endl;
        return 1;
    }

    std::string fileName = argv[1];

    std::unique_ptr<Image> image = ImageFactory::createImage();

    if (!image->load(fileName)) {
        return EXIT_FAILURE;
    }

    image->display();

    return EXIT_SUCCESS;
}
