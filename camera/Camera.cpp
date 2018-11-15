/*
 * Copyright 2018 SU Technology Ltd. All rights reserved.
 *
 * MIT License
 *
 * Copyright (c) 2018 SU Technology
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

#include <Camera.h>
#include <iostream>
#include "syslog_cpp.h"

using namespace cv;

Camera::Camera(const std::string &filename) : filename(filename) {
	init_camera();
}
Camera::~Camera() {
}
Camera::Camera(Camera *camera) {
	(void)camera;
}
int Camera::init_camera()
{
	logger << syslog::level::debug << "Opening file : " << filename.c_str() << std::endl	;
	capture.open(filename);
	if ( !capture.isOpened	() ) {
		throw "Error opening file.\n";
	}
	return 0;
}
int Camera::get_camera_handle()
{
	return 0;
}
cv::Mat& Camera::get_camera_frame()
{
	try {
		capture >> frame;
	} catch(cv::Exception ex) {
		std::cout << ex.what() << std::endl;
	} catch(...) {
		std::cout << "Unknown exception" << std::endl;
	}
	logger << syslog::level::debug << "Frame resolution : " << frame.rows << "x" << frame.cols << std::endl;
	return frame;
}
