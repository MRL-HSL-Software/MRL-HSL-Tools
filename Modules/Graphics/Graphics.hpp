# ifndef MRL_HSL_TOOLS_GRAPHICS
    /**
     * @file Graphics.hpp
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @brief MRL HSL Tools Graphics Module
     * @version 0.1
     * @date 2024-04-28
     */
    # define MRL_HSL_TOOLS_GRAPHICS
    //-- Include OpencCV HighGUI
    # ifndef OPENCV_HIGHGUI_HPP
        # include <opencv4/opencv2/highgui.hpp>
    # endif // OPENCV_HIGHGUI_HPP
    //-- Include OpencCV ImageProc
    # ifndef OPENCV_IMGPROC_HPP
        # include <opencv4/opencv2/imgproc.hpp>
    # endif // OPENCV_IMGPROC_HPP
    //-- Include X11
    # ifndef _X11_XLIB_H_
        # include <X11/Xlib.h>
    # endif // X11_HPP
    //-- Include Configurations
    # ifndef MRL_HSL_TOOLS_MODULES_CONFIGS
        # include "../Configs.hpp"
    # endif // MRL_HSL_TOOLS_MODULES_CONFIGS
    //-- Include Vectors
    # ifndef _GLIBCXX_VECTOR
        # include <vector>
    # endif // _GLIBCXX_VECTOR
    /**
     * @brief Control Window Class Definition
     */
    class ControlWindow {
        public:
            /**
             * @brief Control Window Matrix
             */
            cv::Mat window;
            /**
             * @brief Constructor
             */
            ControlWindow();
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
    /**
     * @brief Graphics Class Definition
     */
    class Graphics {
        public:
            /**
             * @brief Mouse Struct
             */
            struct Mouse {
                int x;
                int y;
                cv::MouseEventTypes event;
            };
            /**
             * @brief Mouse
             * @param event Event of Mouse
             * @param x X Coordinate of Mouse
             * @param y Y Coordinate of Mouse
             */
            Mouse mouse;
            /**
             * @brief Main Window Matrix
             */
            cv::Mat window;
            /**
             * @brief Control Window
             */
            ControlWindow ctrl;
            /**
             * @brief Constructor
             */
            Graphics();
            /**
             * @brief Mouse Callback
             * @param event
             * @param x
             * @param y
             * @param flags
             * @param userdata
             */
            // static void onMouseCallback(int event, int x, int y, int flags, void* userdata);
            /**
             * @brief Mouse Event
             * @param event
             * @param x
             * @param y
             * @param flags
             */
            // void onMouse(int event, int x, int y, int flags);
    };
# endif // MRL_HSL_TOOLS_GRAPHICS