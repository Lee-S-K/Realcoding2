add_executable ( led_main  led_main.c led_green.c led_yellow.c)
target_link_libraries ( led_main pthread wiringPi)
