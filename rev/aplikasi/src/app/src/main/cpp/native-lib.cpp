#include <jni.h>
#include <iomanip>
#include <sstream>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_aplikasi_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

std::string rotate_string(const std::string& input, const std::string& ignore)
{
    std::string rotated;
    for (char c : input) {
        if (ignore.find(c) != std::string::npos || (c >= 48 && c <= 57)) {
            rotated += c;
        } else {
            rotated += (c ^ 0xaa);
        }
    }

    return rotated;
}

std::string string_to_hex(const std::string& string) 
{
    std::ostringstream hex_stream;
    for (unsigned char s : string) {
        hex_stream << std::uppercase << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(s) << "";
    }

    return hex_stream.str();
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_aplikasi_MainActivity_encryptPlainText(JNIEnv *env, jobject thiz, jstring when_yh,
                                                  jstring plain_text) {
    const char* when_yh_str{ env->GetStringUTFChars(when_yh, nullptr) };
    const char* plain_text_str{ env->GetStringUTFChars(plain_text, nullptr) };

    auto rotted = rotate_string(plain_text_str, when_yh_str);
    auto hex = string_to_hex(rotted);

    env->ReleaseStringUTFChars(when_yh, when_yh_str);
    env->ReleaseStringUTFChars(plain_text, plain_text_str);
    return env->NewStringUTF(hex.c_str());
}