#include <jni.h>
#include <android/log.h>
#include <string.h>

#include "../myspell/myspell.hxx"

extern "C" {

MySpell *pMySpell;

/**
 * 初始化myspell
 */
JNIEXPORT void JNICALL
Java_com_nd_sdp_android_app_MySpell_init(JNIEnv *env, jobject instance, jstring dicPath_,
                                         jstring affPath_) {
    const char *dicPath = env->GetStringUTFChars(dicPath_, 0);
    const char *affPath = env->GetStringUTFChars(affPath_, 0);

    __android_log_print(ANDROID_LOG_DEBUG, "my-spell-jni", dicPath);
    pMySpell = new MySpell(affPath, dicPath);

    env->ReleaseStringUTFChars(dicPath_, dicPath);
    env->ReleaseStringUTFChars(affPath_, affPath);
}

/**
 * 检测
 */
JNIEXPORT jboolean JNICALL
Java_com_nd_sdp_android_app_MySpell_check(JNIEnv *env, jobject instance, jstring word_) {
    const char *word = env->GetStringUTFChars(word_, 0);

    int result = pMySpell->spell(word);

    env->ReleaseStringUTFChars(word_, word);

    return (jboolean) result;
}

/**
 * 建议
 */
JNIEXPORT jobjectArray JNICALL
Java_com_nd_sdp_android_app_MySpell_suggestion(JNIEnv *env, jobject instance, jstring word_) {
    const char *word = env->GetStringUTFChars(word_, 0);

    char** suggestions;
    int suggestionLength = pMySpell->suggest(&suggestions, word);
    jclass stringClass = env->FindClass("java/lang/String");

    jobjectArray suggestionJavaArray = env->NewObjectArray(suggestionLength, stringClass, 0);
    for(int i=0; i < suggestionLength; i++) {
        env->SetObjectArrayElement(suggestionJavaArray, i, env->NewStringUTF(suggestions[i]));
    }

    env->ReleaseStringUTFChars(word_, word);

    return suggestionJavaArray;
}

}

