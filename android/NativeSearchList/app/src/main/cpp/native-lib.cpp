#include <jni.h>
#include <string>
#include <android/log.h>

#define  LOG_TAG    "MY_NATIVE_APP"

#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#include "ArraysStrings.h"

extern "C" JNIEXPORT jboolean JNICALL
Java_com_example_nativesearchlist_MainActivity_IsTypo(JNIEnv *env, jobject, jstring str1, jstring str2) {

    LOGD("Java_com_example_nativesearchlist_MainActivity_IsTypo - Entry");
    const char *c_str1 = env->GetStringUTFChars(str1, 0);
    const char *c_str2 = env->GetStringUTFChars(str2, 0);

    std::string str1_cpy(c_str1);
    std::string str2_cpy(c_str2);

    //    env->ReleaseStringUTFChars(str1, c_str1);
    //    env->ReleaseStringUTFChars(str2, c_str1);

    jboolean isTypo = static_cast<jboolean>(util::ArraysString::is_typo(str1_cpy, str2_cpy));
    return isTypo;
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_example_nativesearchlist_MainActivity_IsPartialPermutation(JNIEnv *env, jobject, jstring str1, jstring str2) {
    LOGD("Java_com_example_nativesearchlist_MainActivity_IsPartialPermutation - Entry");
    auto c_str1 = env->GetStringUTFChars(str1, 0);
    auto c_str2 = env->GetStringUTFChars(str2, 0);

    std::string str1_cpy(c_str1);
    std::string str2_cpy(c_str2);

//    env->ReleaseStringUTFChars(str1, c_str1);
//    env->ReleaseStringUTFChars(str2, c_str1);

    jboolean isPartialPermutation = static_cast<jboolean>(util::ArraysString::is_partial_permutation(str1_cpy, str2_cpy));
    return isPartialPermutation;
}
