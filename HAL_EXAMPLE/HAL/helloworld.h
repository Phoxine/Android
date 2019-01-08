#ifndef ANDROID_HELLOWORLD_INTERFACE_H
#define ANDROID_HELLOWORLD_INTERFACE_H
#include<hardware/hardware.h>

__BEGIN_DECLS

//define modules ID
#define HELLOWORLD_HARDWARE_MODULE_ID "helloworld"

/*
 * Every hardware module must have a data  structure named
 * HAL_MODULE_INFO_SYM and the fields of this data structure
 * must begin with hw_module_t followed by module specific information
 */

//hardware module structure
struct helloworld_module_t{
	struct hw_module_t common;
	//add some specific information
	char *description;
	int methodsNum;	
};
/*
 * Every device data structure must begin with hw_device_t
 * followed by module specific public methods and attributes.
 */

//hardware interface structure
struct helloworld_device_t{
	struct hw_device_t common;
	//define our methods
	int (*helloworld_add) (struct helloworld_device_t *dev,
		       	int a,int b, int *c);
};


__END_DECLS

#endif


