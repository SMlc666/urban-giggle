//
// Created by qq103 on 2025/3/2.
//

#pragma once
#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_shenmo_mineraft_toolbox_instance_instance
 * Method:    getManager
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL
Java_com_shenmo_mineraft_1toolbox_instance_instance_getManager(JNIEnv *,
                                                               jobject);

#ifdef __cplusplus
}
#endif
