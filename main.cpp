
#include "ImageProcessor.hpp"
#include "Libraries/bitmap/bitmap_image.hpp"


//Currently only used for testing purposes (on this branch)
int main(void)
{ 
  std::cout << "Hello World 5" << std::endl;
 
  bitmap_image newImage(200,200);
  
  image_drawer draw(newImage);
    draw.pen_width(4);
    draw.pen_color(100, 0, 0);
    draw.circle(100, 100, 20);
 
    newImage.save_image("output.bmp");

    return 0;
};
