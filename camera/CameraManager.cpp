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

#include <memory>
#include <list>
#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include "CameraManager.h"

CameraManager::CameraManager()
{
	std::cout << "Instanciated.\n";
	cv::namedWindow("w", 1);
}

CameraManager::~CameraManager()
{

}

void CameraManager::add_camera()
{
	Camera *camera_item = new Camera("/home/utku/superman/testcontent/single/carvideo.mp4");
	std::cout << "CAMERAITEM : " << &(*camera_item) << std::endl;
	camera_collection.push_front(camera_item);
}

void CameraManager::loop()
{
	cv::Mat frame;
	while(1) {
		std::cout << "Backcover\n";
		for(std::list<Camera*>::iterator it=camera_collection.begin(); it != camera_collection.end(); it++) {
			std::cout << "CAMERAITEM : " << &(*it) << std::endl;
			frame = (*it)->get_camera_frame();
			cv::imshow("w", frame);
			if(cv::waitKey(30) >= 0) break;
		}
	}
}

