#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_aplikasi_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

std::string xor_string(const std::string& input)
{
    std::string xored;
    for (char c : input) {
        xored += c ^ 0x6;
    }

    return xored;
}

std::string rotate_string(const std::string& input, const std::string& ignore)
{
    std::string rotated;
    for (char c : input) {
        if (ignore.find(c) != std::string::npos) {
            rotated += c;
        } else {
            rotated += (c + 13);
        }
    }

    return rotated;
}

std::string base64_encode(const std::string& input)
{
    static const char encodeLookup[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::string encodedString;
    unsigned char temp[3];
    int inputLength = input.size();

    for (int i = 0; i < inputLength; i += 3) {
        temp[0] = input[i];
        temp[1] = (i + 1 < inputLength) ? input[i + 1] : 0;
        temp[2] = (i + 2 < inputLength) ? input[i + 2] : 0;

        encodedString += encodeLookup[temp[0] >> 2];
        encodedString += encodeLookup[((temp[0] & 0x03) << 4) | (temp[1] >> 4)];
        encodedString += (i + 1 < inputLength) ? encodeLookup[((temp[1] & 0x0F) << 2) | (temp[2] >> 6)] : '=';
        encodedString += (i + 2 < inputLength) ? encodeLookup[temp[2] & 0x3F] : '=';
    }

    return encodedString;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_aplikasi_MainActivity_encryptPlainText(JNIEnv *env, jobject thiz, jstring when_yh,
                                                  jstring plain_text) {
    const char* when_yh_str{ env->GetStringUTFChars(when_yh, nullptr) };
    const char* plain_text_str{ env->GetStringUTFChars(plain_text, nullptr) };

    auto rotted = rotate_string(plain_text_str, when_yh_str);
    auto xored = xor_string(rotted);
    auto base64 = base64_encode(xored);

    env->ReleaseStringUTFChars(when_yh, when_yh_str);
    env->ReleaseStringUTFChars(plain_text, plain_text_str);
    return env->NewStringUTF(base64.c_str());
}