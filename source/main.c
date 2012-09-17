#include <stdio.h>
#include <stdlib.h>
#include <input/input.h>
#include <xenos/xenos.h>
#include <console/console.h>  
#include <usb/usbmain.h>
#include <xenon_soc/xenon_power.h>
//#include <network/network.h>


void mainInit()
{ 
	//init
	xenos_init(VIDEO_MODE_AUTO);
	console_set_colors(CONSOLE_COLOR_BLUE,CONSOLE_COLOR_YELLOW);
	console_init();

	usb_init();
	usb_do_poll();
	xenon_make_it_faster(XENON_SPEED_FULL);

}
int main()
{
	mainInit();
	console_clrscr();
	printf( "Welcome to the beginning...\n\n"
		"A graphical interface coming\nsomewhere down the line.\n");

	struct controller_data_s c;
	while(1)
	{
		if (get_controller_data(&c, 0))
		{
			if(c.a) printf("A\n");
			if(c.b) printf("B\n");
			if(c.x) printf("X\n");
                        if(c.y) printf("Y\n");
                        if(c.logo) printf("Logo/Guide\n");
                        if(c.lb) printf("Left Bumper\n");
                        if(c.rb) printf("Right Bumper\n");
                        if(c.up) printf("Up\n");
                        if(c.down) printf("Down\n");
			if(c.left) printf("Left\n");
			if(c.right) printf("Right\n");
			if(c.lt) printf("Left Tigger\n");
                        if(c.rt) printf("Right Trigger\n");
                        if(c.start) printf("Start\n");
                        if(c.back) printf("Back/Select\n");
			if(c.s1_x) printf("Stick 1 X: %d\n",c.s1_x);
		}
		usb_do_poll();
	}
	return 0;
}
