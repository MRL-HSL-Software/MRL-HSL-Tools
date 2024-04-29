# ifndef MRL_HSL_LABELING_TOOLS
    # include "Labeling.hpp"
    /**
     * @brief Constructor
     */
    Labeling::Labeling() {}
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
        //-- Set Image Indexes
        int minimum_index = 0;
        int maximum_index = images.size();
        //-- Other Definitions
        cv::Mat image;
        cv::Mat tmp_ctrl;
        modules.graphics.ctrl.window.copyTo(tmp_ctrl);
        //-- Iterate Over Images
        while (true) {
            //-- Control Window
            cv::putText(
                tmp_ctrl,
                "File Name : " + images[minimum_index],
                cv::Point(10, 30),
                cv::FONT_HERSHEY_TRIPLEX,
                0.5,
                cv::Scalar(170, 170, 0),
                2
            );
            cv::putText(
                tmp_ctrl,
                "File Name : " + images[minimum_index],
                cv::Point(10, 70),
                cv::FONT_HERSHEY_PLAIN,
                0.5,
                cv::Scalar(170, 170, 0),
                2
            );
            cv::imshow(TOOLS_CONTROL_WINDOW_NAME, tmp_ctrl);
            //-- Tools Window
            modules.graphics.window = cv::imread(source_path + images[minimum_index]);
            cv::resize(modules.graphics.window, modules.graphics.window, cv::Size(TOOLS_WINDOW_WIDTH, TOOLS_WINDOW_HEIGHT), cv::INTER_LINEAR);
            cv::imshow(TOOLS_WINDOW_NAME, modules.graphics.window);
            int key = cv::waitKey(0);
            switch(key) {
                case 27: {
                    break;
                }
                case 83: {
                    minimum_index++;
                    break;
                }
                case 81: {
                    minimum_index--;
                    break;
                }
                case int('q'): {
                    cv::destroyAllWindows();
                    return;
                }
            }
            if (key == 83) {
                minimum_index++;
            } else if (key == 81) {
                minimum_index--;
            }
            if (minimum_index < 0) {
                minimum_index = 0;
            }
            if (minimum_index >= maximum_index) {
                minimum_index = maximum_index - 1;
            }
            if (key == 27) {
                break;
            }
            //-- Reload Control Window
            modules.graphics.ctrl.window.copyTo(tmp_ctrl);
        }
        // for (int i = 0; i < images.size(); i++) {
        //     modules.graphics.window = cv::imread(source_path + images[i]);
        //     cv::imshow(TOOLS_WINDOW_NAME, modules.graphics.window);
        //     cv::waitKey(1000);
        // }
    }
    /**
     * @brief Rect Box
     */
    void Labeling::rectBox() {
        cv::imshow(TOOLS_WINDOW_NAME, modules.graphics.window);
        cv::waitKey(0);
    }
# endif // MRL_HSL_LABELING_TOOLS