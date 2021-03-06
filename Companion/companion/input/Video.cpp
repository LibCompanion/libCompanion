/*
 * This program is an object recognition framework written with OpenCV.
 * Copyright (C) 2016-2018 Andreas Sekulski, Dimitri Kotlovsky
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Video.h"

Companion::Input::Video::Video(int device)
{
	cv::VideoCapture cap(device);

	if (!cap.isOpened())
	{
		throw Companion::Error::Code::invalid_video_src;
	}

	this->capture = cap;
	this->finished = false;
}


Companion::Input::Video::Video(std::string url)
{
	cv::VideoCapture cap(url);

	if (!cap.isOpened())
	{
		throw Companion::Error::Code::invalid_video_src;
	}

	this->capture = cap;
	this->finished = false;
}

cv::Mat Companion::Input::Video::ObtainImage()
{
	cv::Mat frame;

	if (!this->capture.isOpened() || this->finished)
	{
		this->finished = true;
		return frame;
	}

	// Obtain image frame
	this->capture >> frame;

	if (frame.empty())
	{
		// If frame empty video is finished
		this->finished = true;
	}

	return frame;
}

bool Companion::Input::Video::IsFinished()
{
	return this->finished;
}

void Companion::Input::Video::Finish()
{
	this->finished = true;
}
