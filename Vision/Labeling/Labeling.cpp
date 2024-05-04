# ifndef MRL_HSL_LABELING_TOOLS
    # include "Labeling.hpp"
    cv::Mat use1, use2;
    /**
     * @brief Constructor
     */
    Labeling::Labeling() {
        is_segmenting = false;
        threshold_value = 128;
        window_mode = WINDOW_NORMAL;
        wheel_mode = MOUSE_WHEEL_ZOOM;
        label_mode = LABEL_WITH_POLYGAN;
        zoom.width = DEFAULT_ZOOM_RADIUS;
        zoom.height = DEFAULT_ZOOM_RADIUS;
        cv::setMouseCallback(TOOLS_WINDOW_NAME, onMouseCallback, this);
    }
    // void thresholdCallback(int threshold, void*) {
    //     cv::Mat segmented;
    //     cv::cvtColor(use1, segmented, cv::COLOR_BGR2GRAY);
    //     cv::Mat thresholded;
    //     cv::threshold(segmented, thresholded, threshold, 255, cv::THRESH_BINARY);
    //     cv::imshow("Segmented", thresholded);
    // }

    // // Callback function for Canny threshold trackbars
    // void cannyThresholdCallback(int threshold, void*) {
    //     cv::Mat segmented;
    //     cv::cvtColor(use1, segmented, cv::COLOR_BGR2GRAY);
    //     cv::Mat edges;
    //     cv::Canny(segmented, edges, threshold, threshold * 3);
    //     cv::imshow("Canny", edges);
    // }
    /**
     * @brief Mouse Callback
     * @param event
     * @param x
     * @param y
     * @param flags
     * @param userdata
     */
    void Labeling::onMouseCallback(int event, int x, int y, int flags, void* userdata) {
        Labeling* labeling = (Labeling*)userdata;
        labeling->onMouse(event, x, y, flags);
    }
    /**
     * @brief Mouse Event
     * @param event
     * @param x
     * @param y
     * @param flags
     */
    void Labeling::onMouse(int event, int x, int y, int flags) {
        if (event == cv::EVENT_LBUTTONDOWN) {
            if (label_mode == LABEL_WITH_POLYGAN) {
                //-- Add Point
                modules.graphics.window.copyTo(tmp1);
                points.push_back(cv::Point(x, y));
                cv::circle(tmp1, cv::Point(x, y), 2, cv::Scalar(200, 200, 0), -1);
                if (points.size() > 1) {
                    for (int i = 0; i < points.size() - 1; i++) {
                        cv::line(tmp1, points[i], points[i + 1], cv::Scalar(200, 200, 0), 2);
                    }
                }
                tmp1.copyTo(tmp2);
                //-- Draw Line Between First and Last Points in Convex Hull of Points
                // convexhull_points = points;
                // vision_modules.convexHull.convexHull(convexhull_points);
                if (points.size() > 1) {
                    cv::line(tmp2, points[0], points[points.size() - 1], cv::Scalar(0, 200, 200), 2);
                }
                cv::imshow(TOOLS_WINDOW_NAME, tmp2);
            } else if (label_mode == LABEL_WITH_THRESHOLD) {
            }
        }
        if (event == cv::EVENT_RBUTTONDOWN) {
            if (label_mode == LABEL_WITH_POLYGAN) {
                //-- Remove Last Point
                if (points.size() > 0) {
                    points.pop_back();
                    modules.graphics.window.copyTo(tmp1);
                    for (int i = 0; i < points.size(); i++) {
                        cv::circle(tmp1, points[i], 2, cv::Scalar(200, 200, 0), -1);
                        if (i > 0) {
                            cv::line(tmp1, points[i - 1], points[i], cv::Scalar(200, 200, 0), 2);
                        }
                    }
                    if (points.size() > 0) {
                        tmp1.copyTo(tmp2);
                        cv::line(tmp2, points[points.size() - 1], cv::Point(x, y), cv::Scalar(0, 0, 255), 2);
                    }
                    cv::imshow(TOOLS_WINDOW_NAME, tmp2);
                }
            } else if (label_mode == LABEL_WITH_THRESHOLD) {
            }
        }
        if (event == cv::EVENT_MOUSEWHEEL) {
            if (cv::getMouseWheelDelta(flags) > 0) {
                if (wheel_mode == MOUSE_WHEEL_THRESHOLD) {
                    threshold_value += 1;
                    //-- Control Window
                    std::cout << zoom.width << zoom.height << std::endl;
                    cv::Rect zoomRect(
                        x - zoom.width / 2,
                        y - zoom.height / 2,
                        zoom.width,
                        zoom.height
                    );
                    zoomRect &= cv::Rect(0, 0, modules.graphics.window.cols, modules.graphics.window.rows);
                    cv::Mat zoomedRegion;
                    if (!zoomRect.empty()) {
                        cv::Rect roiRect(
                            ZOOM_WINDOW_X - ZOOM_WINDOW_RADIUS / 2,
                            ZOOM_WINDOW_Y - ZOOM_WINDOW_RADIUS / 2,
                            ZOOM_WINDOW_RADIUS,
                            ZOOM_WINDOW_RADIUS
                        );
                        roiRect &= cv::Rect(0, 0, tmp_ctrl.cols, tmp_ctrl.rows);
                        cv::Mat roi = tmp_ctrl(roiRect);
                        cv::Mat resizedZoomedRegion(roi.size(), modules.graphics.window.type());
                        zoomedRegion = modules.graphics.window(zoomRect).clone();
                        cv::threshold(zoomedRegion, zoomedRegion, threshold_value, 255, cv::THRESH_BINARY);
                        resize(zoomedRegion, resizedZoomedRegion, roi.size());
                        resizedZoomedRegion.copyTo(roi);
                        cv::circle(tmp_ctrl, cv::Point(ZOOM_WINDOW_X, ZOOM_WINDOW_Y), 1, cv::Scalar(0, 0, 255), 2);
                        //-- Draw 4 Lins Around Circle
                        cv::line(tmp_ctrl, cv::Point(ZOOM_WINDOW_X - ZOOM_WINDOW_RADIUS / 2, ZOOM_WINDOW_Y - ZOOM_WINDOW_RADIUS / 2), cv::Point(ZOOM_WINDOW_X + ZOOM_WINDOW_RADIUS / 2, ZOOM_WINDOW_Y - ZOOM_WINDOW_RADIUS / 2), cv::Scalar(0, 0, 255), 1);
                        cv::line(tmp_ctrl, cv::Point(ZOOM_WINDOW_X - ZOOM_WINDOW_RADIUS / 2, ZOOM_WINDOW_Y - ZOOM_WINDOW_RADIUS / 2), cv::Point(ZOOM_WINDOW_X - ZOOM_WINDOW_RADIUS / 2, ZOOM_WINDOW_Y + ZOOM_WINDOW_RADIUS / 2), cv::Scalar(0, 0, 255), 1);
                        cv::line(tmp_ctrl, cv::Point(ZOOM_WINDOW_X + ZOOM_WINDOW_RADIUS / 2, ZOOM_WINDOW_Y - ZOOM_WINDOW_RADIUS / 2), cv::Point(ZOOM_WINDOW_X + ZOOM_WINDOW_RADIUS / 2, ZOOM_WINDOW_Y + ZOOM_WINDOW_RADIUS / 2), cv::Scalar(0, 0, 255), 1);
                        cv::line(tmp_ctrl, cv::Point(ZOOM_WINDOW_X - ZOOM_WINDOW_RADIUS / 2, ZOOM_WINDOW_Y + ZOOM_WINDOW_RADIUS / 2), cv::Point(ZOOM_WINDOW_X + ZOOM_WINDOW_RADIUS / 2, ZOOM_WINDOW_Y + ZOOM_WINDOW_RADIUS / 2), cv::Scalar(0, 0, 255), 1);
                    }
                    cv::imshow(TOOLS_CONTROL_WINDOW_NAME, tmp_ctrl);
                    std::cout << LOG "Threshold Value Changed to : " << threshold_value << std::endl;
                } else if (wheel_mode == MOUSE_WHEEL_ZOOM) {
                    zoom.width += 5;
                    zoom.height += 5;
                    std::cout << LOG "Zoom In (" << zoom.width << ")" << std::endl;
                    tmp1.copyTo(tmp2);
                    cv::circle(tmp2, cv::Point(x, y), zoom.width / sqrt(2), cv::Scalar(170, 170, 0), 1);
                    cv::imshow(TOOLS_WINDOW_NAME, tmp2);
                }
            } else {
                if (wheel_mode == MOUSE_WHEEL_THRESHOLD) {
                    threshold_value -= 1;
                    if (threshold_value < 0) {
                        threshold_value = 0;
                    }
                    //-- Control Window
                    std::cout << zoom.width << zoom.height << std::endl;
                    cv::Rect zoomRect(
                        x - zoom.width / 2,
                        y - zoom.height / 2,
                        zoom.width,
                        zoom.height
                    );
                    zoomRect &= cv::Rect(0, 0, modules.graphics.window.cols, modules.graphics.window.rows);
                    cv::Mat zoomedRegion;
                    if (!zoomRect.empty()) {
                        cv::Rect roiRect(
                            ZOOM_WINDOW_X - ZOOM_WINDOW_RADIUS / 2,
                            ZOOM_WINDOW_Y - ZOOM_WINDOW_RADIUS / 2,
                            ZOOM_WINDOW_RADIUS,
                            ZOOM_WINDOW_RADIUS
                        );
                        roiRect &= cv::Rect(0, 0, tmp_ctrl.cols, tmp_ctrl.rows);
                        cv::Mat roi = tmp_ctrl(roiRect);
                        cv::Mat resizedZoomedRegion(roi.size(), modules.graphics.window.type());
                        zoomedRegion = modules.graphics.window(zoomRect).clone();
                        cv::threshold(zoomedRegion, zoomedRegion, threshold_value, 255, cv::THRESH_BINARY);
                        resize(zoomedRegion, resizedZoomedRegion, roi.size());
                        resizedZoomedRegion.copyTo(roi);
                        cv::circle(tmp_ctrl, cv::Point(ZOOM_WINDOW_X, ZOOM_WINDOW_Y), 1, cv::Scalar(0, 0, 255), 2);
                        //-- Draw 4 Lins Around Circle
                        cv::line(tmp_ctrl, cv::Point(ZOOM_WINDOW_X - ZOOM_WINDOW_RADIUS / 2, ZOOM_WINDOW_Y - ZOOM_WINDOW_RADIUS / 2), cv::Point(ZOOM_WINDOW_X + ZOOM_WINDOW_RADIUS / 2, ZOOM_WINDOW_Y - ZOOM_WINDOW_RADIUS / 2), cv::Scalar(0, 0, 255), 1);
                        cv::line(tmp_ctrl, cv::Point(ZOOM_WINDOW_X - ZOOM_WINDOW_RADIUS / 2, ZOOM_WINDOW_Y - ZOOM_WINDOW_RADIUS / 2), cv::Point(ZOOM_WINDOW_X - ZOOM_WINDOW_RADIUS / 2, ZOOM_WINDOW_Y + ZOOM_WINDOW_RADIUS / 2), cv::Scalar(0, 0, 255), 1);
                        cv::line(tmp_ctrl, cv::Point(ZOOM_WINDOW_X + ZOOM_WINDOW_RADIUS / 2, ZOOM_WINDOW_Y - ZOOM_WINDOW_RADIUS / 2), cv::Point(ZOOM_WINDOW_X + ZOOM_WINDOW_RADIUS / 2, ZOOM_WINDOW_Y + ZOOM_WINDOW_RADIUS / 2), cv::Scalar(0, 0, 255), 1);
                        cv::line(tmp_ctrl, cv::Point(ZOOM_WINDOW_X - ZOOM_WINDOW_RADIUS / 2, ZOOM_WINDOW_Y + ZOOM_WINDOW_RADIUS / 2), cv::Point(ZOOM_WINDOW_X + ZOOM_WINDOW_RADIUS / 2, ZOOM_WINDOW_Y + ZOOM_WINDOW_RADIUS / 2), cv::Scalar(0, 0, 255), 1);
                    }
                    cv::imshow(TOOLS_CONTROL_WINDOW_NAME, tmp_ctrl);
                    std::cout << LOG "Threshold Value Changed to : " << threshold_value << std::endl;
                } else if (wheel_mode == MOUSE_WHEEL_ZOOM) {
                    zoom.width -= 5;
                    zoom.height -= 5;
                    if (zoom.width < 5) {
                        zoom.width = 5;
                        zoom.height = 5;
                    }
                    tmp1.copyTo(tmp2);
                    cv::circle(tmp2, cv::Point(x, y), zoom.width / sqrt(2), cv::Scalar(170, 170, 0), 1);
                    cv::imshow(TOOLS_WINDOW_NAME, tmp2);
                    std::cout << LOG "Zoom Out (" << zoom.width << ")" << std::endl;
                }
            }
        }
        if (event == cv::EVENT_MOUSEMOVE) {
            //-- Control Window
            std::cout << zoom.width << zoom.height << std::endl;
            cv::Rect zoomRect(
                x - zoom.width / 2,
                y - zoom.height / 2,
                zoom.width,
                zoom.height
            );
            zoomRect &= cv::Rect(0, 0, modules.graphics.window.cols, modules.graphics.window.rows);
            cv::Mat zoomedRegion;
            if (!zoomRect.empty()) {
                cv::Rect roiRect(
                    ZOOM_WINDOW_X - ZOOM_WINDOW_RADIUS / 2,
                    ZOOM_WINDOW_Y - ZOOM_WINDOW_RADIUS / 2,
                    ZOOM_WINDOW_RADIUS,
                    ZOOM_WINDOW_RADIUS
                );
                roiRect &= cv::Rect(0, 0, tmp_ctrl.cols, tmp_ctrl.rows);
                cv::Mat roi = tmp_ctrl(roiRect);
                cv::Mat resizedZoomedRegion(roi.size(), modules.graphics.window.type());
                zoomedRegion = modules.graphics.window(zoomRect).clone();
                cv::threshold(zoomedRegion, zoomedRegion, threshold_value, 255, cv::THRESH_BINARY);
                resize(zoomedRegion, resizedZoomedRegion, roi.size());
                resizedZoomedRegion.copyTo(roi);
                cv::circle(tmp_ctrl, cv::Point(ZOOM_WINDOW_X, ZOOM_WINDOW_Y), 1, cv::Scalar(0, 0, 255), 2);
                //-- Draw 4 Lins Around Circle
                cv::line(tmp_ctrl, cv::Point(ZOOM_WINDOW_X - ZOOM_WINDOW_RADIUS / 2, ZOOM_WINDOW_Y - ZOOM_WINDOW_RADIUS / 2), cv::Point(ZOOM_WINDOW_X + ZOOM_WINDOW_RADIUS / 2, ZOOM_WINDOW_Y - ZOOM_WINDOW_RADIUS / 2), cv::Scalar(0, 0, 255), 1);
                cv::line(tmp_ctrl, cv::Point(ZOOM_WINDOW_X - ZOOM_WINDOW_RADIUS / 2, ZOOM_WINDOW_Y - ZOOM_WINDOW_RADIUS / 2), cv::Point(ZOOM_WINDOW_X - ZOOM_WINDOW_RADIUS / 2, ZOOM_WINDOW_Y + ZOOM_WINDOW_RADIUS / 2), cv::Scalar(0, 0, 255), 1);
                cv::line(tmp_ctrl, cv::Point(ZOOM_WINDOW_X + ZOOM_WINDOW_RADIUS / 2, ZOOM_WINDOW_Y - ZOOM_WINDOW_RADIUS / 2), cv::Point(ZOOM_WINDOW_X + ZOOM_WINDOW_RADIUS / 2, ZOOM_WINDOW_Y + ZOOM_WINDOW_RADIUS / 2), cv::Scalar(0, 0, 255), 1);
                cv::line(tmp_ctrl, cv::Point(ZOOM_WINDOW_X - ZOOM_WINDOW_RADIUS / 2, ZOOM_WINDOW_Y + ZOOM_WINDOW_RADIUS / 2), cv::Point(ZOOM_WINDOW_X + ZOOM_WINDOW_RADIUS / 2, ZOOM_WINDOW_Y + ZOOM_WINDOW_RADIUS / 2), cv::Scalar(0, 0, 255), 1);
            }
            cv::imshow(TOOLS_CONTROL_WINDOW_NAME, tmp_ctrl);
            //-- Main Window
            if (label_mode == LABEL_WITH_POLYGAN) {
                if (points.size() > 0) {
                    tmp_points = points;
                    tmp_points.push_back(cv::Point(x, y));
                    tmp1.copyTo(tmp2);
                    cv::fillPoly(tmp2, std::vector<std::vector<cv::Point>>{tmp_points}, cv::Scalar(100, 100, 80));
                    cv::circle(tmp2, cv::Point(x, y), zoom.width / sqrt(2), cv::Scalar(170, 170, 0), 1);
                    cv::line(tmp2, points[points.size() - 1], cv::Point(x, y), cv::Scalar(170, 170, 0), 2);
                    cv::imshow(TOOLS_WINDOW_NAME, tmp2);
                } else {
                    modules.graphics.window.copyTo(tmp1);
                    cv::circle(tmp1, cv::Point(x, y), zoom.width / sqrt(2), cv::Scalar(160, 160, 0), 2);
                    // cv::circle(tmp1, cv::Point(x, y), zoom.width, cv::Scalar(160, 0, 0), 2);
                    cv::circle(tmp1, cv::Point(x, y), 3, cv::Scalar(230, 60, 0), -1);
                    cv::imshow(TOOLS_WINDOW_NAME, tmp1);
                }
            } else if (label_mode == LABEL_WITH_THRESHOLD) {
                if (is_segmenting == true) {
                    modules.graphics.window.copyTo(tmp1);
                    
                } else {

                }
            }
        }
    }
    /**
     * @brief Semantic Labeling
     * @param source_path
     * @param destination_path
     * @param images
     */
    void Labeling::semantic(
        std::string source_path,
        std::string destination_path,
        std::vector<std::string> images
    ) {
        std::cout << LOG "Openning Semantic Labeling Tool ..." << std::endl;
        //-- Set Image Indexes
        int minimum_index = 0;
        int maximum_index = images.size();
        //-- Other Definitions
        cv::Mat edges;
        cv::Mat image;
        cv::Mat segmented;
        modules.graphics.ctrl.window.copyTo(tmp_ctrl);
        //-- Segment
        //-- Iterate Over Images
        while (true) {
            //-- Control Window
            cv::putText(
                tmp_ctrl,
                "File Name : " + images[minimum_index],
                cv::Point(10, 30),
                cv::FONT_HERSHEY_DUPLEX,
                0.5,
                cv::Scalar(170, 170, 0),
                1
            );
            std::string remain = std::to_string(minimum_index + 1) + " / " + std::to_string(images.size());
            std::string file_number = "File Number : " + remain;
            cv::putText(
                tmp_ctrl,
                file_number,
                cv::Point(10, 60),
                cv::FONT_HERSHEY_DUPLEX,
                0.5,
                cv::Scalar(170, 170, 0),
                1
            );
            //-- Tools Window
            modules.graphics.window = cv::imread(source_path + images[minimum_index]);
            cv::resize(modules.graphics.window, modules.graphics.window, cv::Size(TOOLS_WINDOW_WIDTH, TOOLS_WINDOW_HEIGHT), cv::INTER_LINEAR);
            cv::imshow(TOOLS_WINDOW_NAME, modules.graphics.window);
            cv::imshow(TOOLS_CONTROL_WINDOW_NAME, tmp_ctrl);
            //-- Key Switch
            switch(cv::waitKey(0)) {
                //-- Go to Next Image
                case 83: {
                    minimum_index++;
                    modules.graphics.window.copyTo(tmp1);
                    modules.graphics.window.copyTo(tmp2);
                    points.clear();
                    break;
                }
                //-- Go to Previous Image
                case 81: {
                    minimum_index--;
                    modules.graphics.window.copyTo(tmp1);
                    modules.graphics.window.copyTo(tmp2);
                    points.clear();
                    break;
                }
                //-- Exit with ESC Key
                case 27: {
                    cv::destroyAllWindows();
                    return;
                }
                //-- Exit with Q Key
                case int('q'): {
                    cv::destroyAllWindows();
                    return;
                }
                //-- Change Labeling Mode
                case int('m'): {
                    std::cout << LOG "Selecting Mode, Waiting for User Key" << std::endl;
                    switch (cv::waitKey(0)) {
                        case int('1'): {
                            label_mode = LABEL_WITH_POLYGAN;
                            std::cout << TAB SUCCESS "Polygan Mode Selected" << std::endl;
                            break;
                        }
                        case int('2'): {
                            label_mode = LABEL_WITH_THRESHOLD;
                            std::cout << TAB SUCCESS "Threshold Mode Selected" << std::endl;
                            break;
                        }
                    }
                }
                //-- Change Mouse Wheel Mode
                case int('w'): {
                    switch (wheel_mode) {
                        //-- Threshold Mode
                        case (MOUSE_WHEEL_ZOOM): {
                            wheel_mode = MOUSE_WHEEL_THRESHOLD;
                            std::cout << TAB SUCCESS "Threshold Mode Selected" << std::endl;
                            break;
                        }
                        //-- Zoom Mode
                        case (MOUSE_WHEEL_THRESHOLD): {
                            wheel_mode = MOUSE_WHEEL_ZOOM;
                            std::cout << TAB SUCCESS "Zoom Mode Selected" << std::endl;
                            break;
                        }
                    }
                    break;
                }
                case int('c'): {
                    std::cout << LOG "Changing Window to Labeld Image" << std::endl;
                    switch (window_mode) {
                        //-- Segmented Mode
                        case (WINDOW_NORMAL): {
                            modules.graphics.window.copyTo(tmp_main);
                            
                            break;
                        }
                        //-- Normal Window
                        case (WINDOW_SEGMENTED): {
                            break;
                        }
                    }
                    break;
                }
                //-- OK
                case int('o'): {
                    switch (cv::waitKey(0)) {
                        case int('k'): {
                            std::cout << TAB SUCCESS "Image Accepted" << std::endl;
                            break;
                        }
                    }
                    break;
                }
            }
            if (minimum_index < 0) {
                minimum_index = 0;
            }
            if (minimum_index >= maximum_index) {
                minimum_index = maximum_index - 1;
            }
            //-- Segment Image According to Mode
            switch (label_mode) {
                case LABEL_WITH_POLYGAN: {
                    break;
                }
                case LABEL_WITH_THRESHOLD: {
                    // cv::cvtColor(modules.graphics.window, segmented, cv::COLOR_BGR2GRAY);
                    // cv::threshold(segmented, segmented, 200, 255, cv::THRESH_BINARY);
                    // cv::Canny(segmented, edges, 50, 150);
                    // cv::imshow("Canny", edges);
                    // cv::imshow("Segmented", segmented);
                    break;
                }
            }



            //-- Trackbar

            // modules.graphics.window.copyTo(use1);
            // cv::Mat segmented;
            // cv::cvtColor(use1, segmented, cv::COLOR_BGR2GRAY);


            // // Create a window to display the images
            // cv::namedWindow("Original", cv::WINDOW_AUTOSIZE);
            // cv::namedWindow("Trackbars", cv::WINDOW_AUTOSIZE);
            // // Create trackbars for threshold values
            // int thresholdValue = 128;
            // int maxThresholdValue = 255;
            // cv::createTrackbar("Threshold", "Trackbars", &thresholdValue, maxThresholdValue, thresholdCallback);
            // thresholdCallback(thresholdValue, 0); // Initialize threshold

            // // Create trackbars for Canny edge detection thresholds
            // int cannyThreshold1 = 50;
            // int cannyThreshold2 = 150;
            // cv::createTrackbar("Canny Threshold 1", "Trackbars", &cannyThreshold1, 255, cannyThresholdCallback);
            // cv::createTrackbar("Canny Threshold 2", "Trackbars", &cannyThreshold2, 255, cannyThresholdCallback);
            // cannyThresholdCallback(cannyThreshold1, 0); // Initialize Canny thresholds

            // Display the original image
            // cv::imshow("Original", use1);
            
            //-- Reload Control Window
            modules.graphics.ctrl.window.copyTo(tmp_ctrl);
        }
    }
    /**
     * @brief Rect Box
     */
    void Labeling::rectBox() {
        cv::imshow(TOOLS_WINDOW_NAME, modules.graphics.window);
        cv::waitKey(0);
    }
# endif // MRL_HSL_LABELING_TOOLS