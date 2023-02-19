
#include "ImageProcessor.hpp"
#include "Libraries/bitmap/bitmap_image.hpp"


//Currently only used for testing purposes (on this branch)
int main(void)
{
  ImageProcessor ip(500, 500);
  
  ip.image.save_image("output.bmp");

  return 0;
};
