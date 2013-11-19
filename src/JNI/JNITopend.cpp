/*
 * JNIEXPORT.cpp
 *
 *  Created on: Nov 17, 2013
 *      Author: zhengli
 */

#include "JNITopend.h"
#include <iostream>
using namespace std;

JNITopend::JNITopend(JNIEnv *env, jobject caller) {
	m_jniEnv = env;
	m_javaCaller = caller;
	jclass jniClass = m_jniEnv->GetObjectClass(m_javaCaller);
	    if (jniClass == NULL) {
	    	cout<<"No jniClass found!!!"<<endl;
	        m_jniEnv->ExceptionDescribe();
	        //throw std::exception;
	    }

	    m_reportActionMID =
	            m_jniEnv->GetMethodID(
	                    jniClass,
	                    "reportAction",
	                    "(I)I");
	    if (m_reportActionMID == NULL) {
	    	cout<<"No MID found!!!"<<endl;
	        m_jniEnv->ExceptionDescribe();
	        //throw std::exception;
	    }
}

JNITopend::~JNITopend() {
	// TODO Auto-generated destructor stub
}

int JNITopend::reportAction(int action) {
	return m_jniEnv->CallIntMethod(m_javaCaller, m_reportActionMID, action);
}

JNIEnv* JNITopend::getJNIEnv() {
	return this->m_jniEnv;
}

jobject JNITopend::getJavaCaller() {
	return this->m_javaCaller;
}

jmethodID JNITopend::getActionMID() {
	return this->m_reportActionMID;
}

