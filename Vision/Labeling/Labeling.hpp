# ifndef MRL_HSL_LABELING_TOOLS
    /**
     * @file Labeling.hpp
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @brief MRL HSL Labeling Tools
     * @version 0.1
     * @date 2024-04-28
     */
    # define MRL_HSL_LABELING_TOOLS
    //-- Include Modules
    # ifndef MRL_HSL_TOOLS_MODULES
        # include "../../Modules/Modules.hpp"
    # endif // MRL_HSL_TOOLS_MODULES
    //-- Include Vision Modules
    # ifndef MRL_HSL_VISION_MODULES
        # include "../Modules/Modules.hpp"
    # endif // MRL_HSL_VISION_MODULES
    //-- Include Vectors
    # ifndef _GLIBCXX_VECTOR
        # include <vector>
    # endif // _GLIBCXX_VECTOR
    //-- Include String
    # ifndef _GLIBCXX_STRING
        # include <string>
    # endif // _GLIBCXX_STRING
    //-- Include CMath
    # ifndef _GLIBCXX_CMATH
        # include <cmath>
    # endif // _GLIBCXX_CMATH
    /**
     * @brief Labeling Modes
     */
    enum ENUM_LABELING_MODES {
        LABEL_WITH_POLYGAN,
        LABEL_WITH_THRESHOLD
    };
    /**
     * @brief Mouse Wheel Modes
     */
    enum ENUM_MOUSE_WHEEL_MODES {
        MOUSE_WHEEL_THRESHOLD,
        MOUSE_WHEEL_ZOOM
    };
    /**
     * @brief Window Display Modes
     */
    enum ENUM_WINDOW_DISPLAY_MODE {
        WINDOW_SEGMENTED,
        WINDOW_NORMAL
    };
    /**
     * @brief Labeling Class
     */
    class Labeling {
        public:
            /**
             * @brief Window Mode
             */
            int window_mode;
            /**
             * @brief is Segmenting Status
             */
            bool is_segmenting;
            /**
             * @brief Label Mode
             */
            int label_mode;
            /**
             * @brief Mouse Wheel Mode
             */
            int wheel_mode;
            /**
             * @brief Threshold Value
             */
            int threshold_value;
            /**
             * @brief Points
             */
            std::vector<cv::Point> points;
            /**
             * @brief Temporary Points
             */
            std::vector<cv::Point> tmp_points;
            /**
             * @brief Convex Hull Points
             */
            std::vector<cv::Point> convexhull_points;
            /**
             * @brief Temporary Matrices
             */
            cv::Mat tmp1, tmp2, tmp_ctrl, tmp_main;
            /**
             * @brief Segmented Temporary Matrix
             */
            cv::Mat segmented_tmp;
            /**
             * @brief Segmented Images
             */
            std::vector<cv::Point> segmented_images;
            /**
             * @brief Zoom
             * @param x
             * @param y
             * @param width
             * @param height
             * @param zoom
             */
            struct Zoom {
                int x, y;
                int width, height;
                int zoom;
            };
            /**
             * @brief Modules
             */
            Zoom zoom;
            /**
             * @brief Modules
             */
            Modules modules;
            /**
             * @brief Vision Modules
             */
            VisionModules vision_modules;
            /**
             * @brief Construct a new Labeling object
             */
            Labeling();
            /**
             * @brief Semantic Labeling Method
             * @param source_path
             * @param destination_path
             * @param images
             */
            void semantic(
                std::string source_path,
                std::string destination_path,
                std::vector<std::string> images
            );
            /**
             * @brief Rect Box Labeling Method
             */
            void rectBox();
            /**
             * @brief Mouse Callback
             * @param event
             * @param x
             * @param y
             * @param flags
             * @param userdata
             */
            static void onMouseCallback(int event, int x, int y, int flags, void* userdata);
            /**
             * @brief Mouse Event
             * @param event
             * @param x
             * @param y
             * @param flags
             */
            void onMouse(int event, int x, int y, int flags);
    };
# endif // MRL_HSL_LABELING_TOOLS