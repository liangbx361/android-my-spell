#include <jni.h>
#include <string.h>

#include "../myspell/myspell.hxx"

MySpell *pMySpell;

/**
 * 初始化myspell
 */
JNIEXPORT void JNICALL
Java_com_nd_sdp_android_app_MySpell_init(JNIEnv *env, jobject instance, jstring dicPath_,
                                         jstring affPath_) {
    const char *dicPath = env->GetStringUTFChars(dicPath_, 0);
    const char *affPath = env->GetStringUTFChars(affPath_, 0);

    pMySpell = new MySpell(affPath, dicPath);

    env->ReleaseStringUTFChars(dicPath_, dicPath);
    env->ReleaseStringUTFChars(affPath_, affPath);
}

/**
 * 检测
 */
JNIEXPORT jobjectArray JNICALL
Java_com_nd_sdp_android_app_MySpell_check(JNIEnv *env, jobject instance, jstring words_) {
    const char *words = env->GetStringUTFChars(words_, 0);

    env->ReleaseStringUTFChars(words_, words);
}

/**
 * 建议
 */
JNIEXPORT jobjectArray JNICALL
Java_com_nd_sdp_android_app_MySpell_suggestion(JNIEnv *env, jobject instance, jstring words_) {
    const char *words = env->GetStringUTFChars(words_, 0);

    env->ReleaseStringUTFChars(words_, words);
}

/**
 * 检测并提供建议
 */
JNIEXPORT jobjectArray JNICALL
Java_com_nd_sdp_android_app_MySpell_checkAndSuggestion(JNIEnv *env, jobject instance,
                                                       jstring words_) {
    const char *words = env->GetStringUTFChars(words_, 0);

    env->ReleaseStringUTFChars(words_, words);
}

