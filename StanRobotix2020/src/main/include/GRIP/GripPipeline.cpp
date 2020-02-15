#include "GripPipeline.h"

namespace grip {

GripPipeline::GripPipeline() {
}
/**
* Runs an iteration of the pipeline and updates outputs.
*/
void GripPipeline::Process(cv::Mat& source0){
	//Step CV_resize0:
	//input
	cv::Mat cvResizeSrc = source0;
	cv::Size cvResizeDsize(0, 0);
	double cvResizeFx = 1.25;  // default Double
	double cvResizeFy = 1.25;  // default Double
    int cvResizeInterpolation = cv::INTER_LINEAR;
	cvResize(cvResizeSrc, cvResizeDsize, cvResizeFx, cvResizeFy, cvResizeInterpolation, this->cvResizeOutput);
	//Step HSV_Threshold0:
	//input
	cv::Mat hsvThresholdInput = cvResizeOutput;
	double hsvThresholdHue[] = {14.568345323741006, 180.0};
	double hsvThresholdSaturation[] = {0.0, 16.74242424242424};
	double hsvThresholdValue[] = {238.4892086330935, 255.0};
	hsvThreshold(hsvThresholdInput, hsvThresholdHue, hsvThresholdSaturation, hsvThresholdValue, this->hsvThresholdOutput);
	//Step Find_Lines0:
	//input
	cv::Mat findLinesInput = hsvThresholdOutput;
	findLines(findLinesInput, this->findLinesOutput);
	//Step Filter_Lines0:
	//input
	std::vector<Line> filterLinesLines = findLinesOutput;
	double filterLinesMinLength = 27.0;  // default Double
	double filterLinesAngle[] = {129.49640287769785, 256.96969696969694};
	filterLines(filterLinesLines, filterLinesMinLength, filterLinesAngle, this->filterLinesOutput);
}

/**
 * This method is a generated getter for the output of a CV_resize.
 * @return Mat output from CV_resize.
 */
cv::Mat* GripPipeline::GetCvResizeOutput(){
	return &(this->cvResizeOutput);
}
/**
 * This method is a generated getter for the output of a HSV_Threshold.
 * @return Mat output from HSV_Threshold.
 */
cv::Mat* GripPipeline::GetHsvThresholdOutput(){
	return &(this->hsvThresholdOutput);
}
/**
 * This method is a generated getter for the output of a Find_Lines.
 * @return LinesReport output from Find_Lines.
 */
std::vector<Line>* GripPipeline::GetFindLinesOutput(){
	return &(this->findLinesOutput);
}
/**
 * This method is a generated getter for the output of a Filter_Lines.
 * @return LinesReport output from Filter_Lines.
 */
std::vector<Line>* GripPipeline::GetFilterLinesOutput(){
	return &(this->filterLinesOutput);
}
	/**
	 * Resizes an Image.
	 * @param src The image to resize.
	 * @param dSize size to set the image.
	 * @param fx scale factor along X axis.
	 * @param fy scale factor along Y axis.
	 * @param interpolation type of interpolation to use.
	 * @param dst output image.
	 */
	void GripPipeline::cvResize(cv::Mat &src, cv::Size &dSize, double fx, double fy, int interpolation, cv::Mat &dst) {
		cv::resize(src, dst, dSize, fx, fy, interpolation);
	}

	/**
	 * Segment an image based on hue, saturation, and value ranges.
	 *
	 * @param input The image on which to perform the HSL threshold.
	 * @param hue The min and max hue.
	 * @param sat The min and max saturation.
	 * @param val The min and max value.
	 * @param output The image in which to store the output.
	 */
	void GripPipeline::hsvThreshold(cv::Mat &input, double hue[], double sat[], double val[], cv::Mat &out) {
		cv::cvtColor(input, out, cv::COLOR_BGR2HSV);
		cv::inRange(out,cv::Scalar(hue[0], sat[0], val[0]), cv::Scalar(hue[1], sat[1], val[1]), out);
	}

	/**
	 * Finds all line segments in an image.
	 *
	 * @param input The image on which to perform the find lines.
	 * @param lineList The output where the lines are stored.
	 */
	void GripPipeline::findLines(cv::Mat &input, std::vector<Line> &lineList) {
		cv::Ptr<cv::LineSegmentDetector> lsd = cv::createLineSegmentDetector(LSD_REFINE_STD);
		std::vector<cv::Vec4i> lines;
		lineList.clear();
		if (input.channels() == 1) {
			lsd->detect(input, lines);
		} else {
			// The line detector works on a single channel.
			cv::Mat tmp;
			cv::cvtColor(input, tmp, cv::COLOR_BGR2GRAY);
			lsd->detect(tmp, lines);
		}
		// Store the lines in the LinesReport object
		if (!lines.empty()) {
			for (int i = 0; i < lines.size(); i++) {
				cv::Vec4i line = lines[i];
				lineList.push_back(Line(line[0], line[1], line[2], line[3]));
			}
		}
	}

	/**
	 * Filters out lines that do not meet certain criteria.
	 *
	 * @param inputs The lines that will be filtered.
	 * @param minLength The minimum length of a line to be kept.
	 * @param angle The minimum and maximum angle of a line to be kept.
	 * @param outputs The output lines after the filter.
	 */
	void GripPipeline::filterLines(std::vector<Line> &inputs, double minLength, double angle[], std::vector<Line> &outputs) {
	outputs.clear();
	for (Line line: inputs) {
		if (line.length()>abs(minLength)) {
			if ((line.angle() >= angle[0] && line.angle() <= angle[1]) ||
					(line.angle() + 180.0 >= angle[0] && line.angle() + 180.0 <=angle[1])) {
				outputs.push_back(line);
			}
		}
	}
	}



} // end grip namespace

