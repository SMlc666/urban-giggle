//
// Created by qq103 on 2025/3/2.
//

#include "jni_Instance.hpp"
#include "Instance/Instance.hpp"
#ifdef __cplusplus
extern "C" {
#endif
JNIEXPORT jlong JNICALL
Java_com_shenmo_mineraft_1toolbox_instance_instance_getManager(JNIEnv *env,
                                                               jobject obj) {
  return reinterpret_cast<jlong>(&Instance::getManager());
}

#ifdef __cplusplus
}
#endif
