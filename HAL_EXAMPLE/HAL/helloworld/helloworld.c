#include<errno.h>
#include<cutils/log.h>
#include<hardware/helloworld.h>

#define MODULE_NAME "HelloWorld"
#define MODULE_DES "HELLO: Implemnet Add function"
#define MODULE_AUTHOR "kiraychao@gmail.com"

//module open and close function
static int helloworld_open(const struct hw_module_t* module, const char* name, struct hw_device_t** device);
static int helloworld_close(struct hw_device_t* device);


//module function method
static int helloworld_add(struct helloworld_device_t* dev, int a,int b,int *c);

static struct hw_module_methods_t helloworld_module_methods={
	open: helloworld_open
};

//module struct
struct helloworld_module_t HAL_MODULE_INFO_SYM={
	common: {
		tag: HARDWARE_MODULE_TAG,
	     	version_major: 1,
   		version_minor: 0,
		id: HELLOWORLD_HARDWARE_MODULE_ID,
		name: MODULE_NAME,
   		author: MODULE_AUTHOR,
		methods: &helloworld_module_methods,		
	},
	description: MODULE_DES,
	methodsNum: 3,
};

//module open function
static int helloworld_open(const struct hw_module_t *module, 
		const char *name,struct hw_device_t **device){
	//1. New a helloworld_device_t
	struct helloworld_device_t* dev;
	dev = (struct helloworld_device_t*)malloc(sizeof(struct helloworld_device_t));
	if(!dev){
		ALOGE("Helloworld open: failed to alloc device space");
		return -EFAULT;
	}
	//2. Set Value to hello_device_t
	memset(dev, 0, sizeof(struct helloworld_device_t));
	dev->common.tag = HARDWARE_DEVICE_TAG;
	dev->common.version = 0;
	dev->common.module = (hw_module_t*)module;//set the module
	dev->common.close = helloworld_close;//set the close function
	dev->helloworld_add = helloworld_add;

	*device = &(dev->common);
	ALOGI("Helloworld open: open driver file successfully.");
	return 0;
}
//module close function
static int helloworld_close(struct hw_device_t *device){
	//1. device Type change
	struct helloworld_device_t* helloworld_device = 
				(struct helloworld_device_t*) device;

	//2. free the device memory, close driver file
	if(helloworld_device){
		free(helloworld_device);
		ALOGI("Helloworld close: close driver file successfully.");
	}
	return 0;
}

static int helloworld_add(struct helloworld_device_t* dev, int a,int b, int *c){
	ALOGI("Helloworld add: value %d + %d",a,b);
	*c = a + b;
	return 0;
}









