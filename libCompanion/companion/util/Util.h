/*
 * This program is an image recognition library written with OpenCV.
 * Copyright (C) 2016-2018 Andreas Sekulski
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

#ifndef COMPANION_UTIL_H
#define COMPANION_UTIL_H

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <companion/util/exportapi/ExportAPIDefinitions.h>

namespace Companion
{

    /**
     * Enumeration class for color formats.
     */
    enum class COMP_EXPORTS ColorFormat
    {
        RGB,
        RGBA,
        BGR,
        BGRA,
        GRAY
    };

	/**
	 * Enumeration class for scaling.
	 */
	enum class COMP_EXPORTS SCALING
	{
		SCALE_2048x1152,
		SCALE_1920x1080,
		SCALE_1600x900,
		SCALE_1408x792,
		SCALE_1344x756,
		SCALE_1280x720,
		SCALE_1152x648,
		SCALE_1024x576,
		SCALE_960x540,
		SCALE_896x504,
		SCALE_800x450,
		SCALE_768x432,
		SCALE_640x360,
        SCALE_320x180
	};

    /**
     * Utility class for opencv.
     * @author Andreas Sekulksi
     */
    class COMP_EXPORTS Util
    {

    public:

		/**
		* Cut given image frame from cut area.
		* @param cutArea Area to cut subframe.
		* @return Cutted image.
		*/
		static cv::Mat cutImage(cv::Mat img, cv::Rect cutArea);

		/**
		 * Checks if given image is loaded.
		 * @param img Image to check if it's not null.
		 * @return <code>true</code> if image is loaded, <code>false</code> otherwise
		 */
		static bool isImageLoaded(cv::Mat &img);

        /**
         * Resize given image.
         * @param img Image to resize.
         * @param scaling Scaling factor to resize.
         */
        static void resizeImage(cv::Mat &img, SCALING scaling);

		/**
		 * Resize given image.
		 * @param img Image to resize.
		 * @param size Width and Height in pixel to resize image.
		 */
		static void resizeImage(cv::Mat &img, cv::Size size);

        /**
         * Resize given image to given aspect ratio width.
         * @param width Image width in px.
         * @param size Width and Height in pixel to resize image.
         */
        static void resizeImage(cv::Mat &img, int width);

		/**
		 * Ratio to set new point from scaled frame.
		 * @param point Point to calculate new positions.
		 * @param cWidth Current width.
		 * @param cHeight Current height.
		 * @param nWidth New width.
		 * @param nHeight New height.
		 */
		static void ratioPosition(cv::Point &point, int cWidth, int cHeight, int nWidth, int nHeight);

        /**
         * Validates the rectangular shape of a detected area.
         * @param topRight Top right corner of the detected area.
         * @param bottomLeft Bottom left corner of the detected area.
         * @param topLeft Top left corner of the detected area.
         * @param bottomRight Bottom right corner of the detected area.
         * @param minSidelLength Minimum length of the detected area's sides (in pixels).
         * @param maxSideDeviation Maximum deviation of the sides' lengths.
         * @param maxDiagonalDeviation Maximum deviation of the diagonals' lengths.
         * @return <code>true</code> if the diagonals are long enough and both have a similar length, <code>false</code> otherwise
         */
        static bool validateShape(cv::Point2f topRight, cv::Point2f bottomLeft, cv::Point2f topLeft, cv::Point2f bottomRight, int minSidelLength = 10, float maxSideDeviation = 0.5f, float maxDiagonalDeviation = 0.1f);

        /**
         * Converts an image to the given color format. BGR is expected as source format.
         * @param src Source image.
         * @param dst Destination image.
         * @param colorFormat Color format for the converted image.
         */
        static void convertColor(cv::Mat& src, cv::Mat& dst, ColorFormat colorFormat);

    private:

		/**
		 * Get scaling from given enumeration as point representation.
		 * @param scaling Scaling to obtain point.
		 * @return Scaling as point representation which x is width and y height in px.
		 */
		static cv::Point getScaling(SCALING scaling);

        /**
         * Calculates the deviation between two lengths.
         * @param x first length
         * @param y second length
         * return deviation in percent
         */
        static double getDeviation(double x, double y);
	};

}

#endif //COMPANION_UTIL_H
