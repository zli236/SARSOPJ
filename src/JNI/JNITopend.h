/*
 * JNIEXPORT.h
 *
 *  Created on: Nov 17, 2013
 *      Author: zhengli
 */
#include <jni.h>
#ifndef JNIEXPORT_H_
#define JNIEXPORT_H_

class JNITopend {
public:
	JNITopend(JNIEnv *env, jobject obj);
	virtual ~JNITopend();

	int reportAction(int action);
	JNIEnv* getJNIEnv();
	jobject getJavaCaller();
	jmethodID getActionMID();

private:
    JNIEnv *m_jniEnv;

    /**
     * JNI object corresponding to this engine. for callback functions.
     * if this is NULL, VoltDBEngine will fail to call sendDependency().
    */
    jobject m_javaCaller;
    jmethodID m_reportActionMID;
};

#endif /* JNIEXPORT_H_ */
