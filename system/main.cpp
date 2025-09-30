

#include "pico/stdlib.h"
#include "engine.hpp"
#include "tusb.h"
#include "tusb_config.h"


static Engine engine;


int main()
{
  
  // init device stack on configured roothub port
   tusb_rhport_init_t dev_init = {
    .role = TUSB_ROLE_DEVICE,
    .speed = TUSB_SPEED_AUTO
  };
  tusb_init(BOARD_TUD_RHPORT, &dev_init);

 
  
  while(1)
  {
    engine.run();
    
  }

  return 0;



}







