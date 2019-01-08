/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "HelloWorldService"

#include "jni.h"
#include "JNIHelp.h"
#include "android_runtime/AndroidRuntime.h"

#include <utils/misc.h>
#include <utils/Log.h>
#include <hardware/hardware.h>
#include <hardware/helloworld.h>
#include <stdio.h>

namespace android
{
	//1. define helloworld_device_ti
	static helloworld_device_t *helloworld_device = NULL;
	//2. implent ini and add value function

	static jboolean helloworld_init(JNIEnv *env, jclass clazz){
		helloworld_module_t *module;
		ALOGI("HelloWorld JNI init");
		if(hw_get_module(HELLOWORLD_HARDWARE_MODULE_ID,
				       	(const struct hw_module_t **)&module)==0){
			if(module->common.methods->open(&(module->common),
				HELLOWORLD_HARDWARE_MODULE_ID,
					(struct hw_device_t **)&helloworld_device)==0){
						return 0;
			}
			return -1;
		}
		return -1;			
	}

	static jint helloworld_AddVal(JNIEnv *env, jobject clazz, jint a, jint b)
	{
		int result;
		if(!helloworld_device){
			return -1;
		}
		helloworld_device->helloworld_add(helloworld_device, a, b, &result);
		ALOGI("HelloWorld JNI Add");
		return result;
	}


	//3. register the function to jni
	static JNINativeMethod sMethods[] = {
		{ "init", "()Z", (void*)helloworld_init },
	    	{ "addValue", "(II)I", (void*)helloworld_AddVal },
	};

	//I for int, B for byte, S for short, J for long, 
	//F for float, D for double, C for char, Z for boolean
	//String for Ljava/lnag/String  "L<fully-qualified-name>"

	int register_android_server_HelloWorldService(JNIEnv *env)
	{
		ALOGI("HelloWorld JNI register");
	   	return jniRegisterNativeMethods(env, "com/android/server/HelloWorldService",
	        	    sMethods, NELEM(sMethods));
	}

};
