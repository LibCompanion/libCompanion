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

#ifndef COMPANION_HASHING_H
#define COMPANION_HASHING_H

#include <companion/algo/recognition/Recognition.h>
#include <companion/draw/Frame.h>
#include <companion/model/result/RecognitionResult.h>
#include <companion/model/processing/ImageHashModel.h>

namespace Companion {
	namespace Algorithm {
		namespace Recognition {
			namespace Hashing
			{
				/**
				 * Interface class to create hashing algorithms for object recognition, for example Locality Sensitive Hashing (LSH).
				 * @author Andreas Sekulski, Dimitri Kotlovsky
				 */
				class COMP_EXPORTS Hashing : public Recognition
				{

				public:

					/**
					 * Ranking method to sort pairs.
					 */
					struct SortRank {

						/**
						 * Operator overloading method to sort pairs.
						 */
						bool operator()(const std::pair<int, int>& left, const std::pair<int, int>& right) {
							return left.second < right.second;
						}
					};

					/**
					 * Specific algorithm implementation for a hashing process.
					 * @param model Image hash model to compare.
					 * @param query Query image to compare with hash model.
					 * @param roi Region of interest to check.
					 * @return Nullptr if no matching success otherwise a recognition result.
					 */
					virtual PTR_RESULT_RECOGNITION ExecuteAlgorithm(PTR_MODEL_IMAGE_HASHING model,
						cv::Mat query, PTR_DRAW_FRAME roi) = 0;

					/**
					 * Indicator if this algorithm uses cuda.
					 * @return True if cuda will be used otherwise false for CPU/OpenCL usage.
					 */
					virtual bool IsCuda() const = 0;
				};
			}
		}
	}
}

#endif //COMPANION_HASHING_H
