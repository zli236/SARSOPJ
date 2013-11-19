#include "nativetest.h"	/*double quotes tells it to search current directory*/
#include "SimulationEngine.h"
#include "JNITopend.h"
//#define JNICALL
//#define JNIEXPORT
JNIEXPORT jint JNICALL Java_nativetest_startSimulator
  (JNIEnv *env, jobject caller, jshort Cnt, jobjectArray stringArray)
{
	cout<<"In JNIEXPORT jint JNICALL Java_nativetest_startSimulator";
	const int len = env->GetArrayLength(stringArray);
	const char *param[8];
	for (int i=0; i<len; i++) {
		jstring string = (jstring) env->GetObjectArrayElement(stringArray, i);
		param[i] = env->GetStringUTFChars(string, NULL);
		// Don't forget to call `ReleaseStringUTFChars` when you're done.
	}
	for(int i=0; i<8; i++){
		cout<<param[i]<<endl;
	}
	JNITopend * jniTopend= new JNITopend(env, caller);
	SimulationEngine * simEngine = new SimulationEngine();
	return simEngine->startSimulator((int)Cnt, (char**)param, jniTopend);
}
