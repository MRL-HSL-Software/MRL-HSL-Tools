# ifndef MRL_HSL_TOOLS_GRAPHICS
    # include "Graphics.hpp"
    /**
     * @brief Constructor
     */
    ControlWindow::ControlWindow() {
        TOOLS_CONTROL_WINDOW_NAME;
        TOOLS_CONTROL_WINDOW_WIDTH;
        TOOLS_CONTROL_WINDOW_HEIGHT;
        int color[] = TOOLS_CONTROL_WINDOW_BACKGROUND_COLOR;
        //-- Generate Control Window
        window = cv::Mat(
            TOOLS_CONTROL_WINDOW_HEIGHT,
            TOOLS_CONTROL_WINDOW_WIDTH,
            CV_8UC3,
            cv::Scalar(
                color[0],
                color[1],
                color[2]
            )
        );
        //-- Find Center Pixel of Screen
        Display* disp = XOpenDisplay(NULL);
        Screen* scrn = DefaultScreenOfDisplay(disp);
        //-- Show Created Window Next to Main Window
        cv::namedWindow(TOOLS_CONTROL_WINDOW_NAME);
        cv::imshow(TOOLS_CONTROL_WINDOW_NAME, window);
        cv::moveWindow(
            TOOLS_CONTROL_WINDOW_NAME,
            TOOLS_WINDOW_WIDTH / 2 + scrn->width / 2,
            scrn->height / 2 - window.rows / 2
        );
        //-- Set Mouse Callback
        cv::setMouseCallback(TOOLS_CONTROL_WINDOW_NAME, onMouseCallback, this);
        //-- Close Display
        XCloseDisplay(disp);
    }
    /**
     * @brief Mouse Callback
     * @param event
     * @param x
     * @param y
     * @param flags
     * @param userdata
     */
    void ControlWindow::onMouseCallback(int event, int x, int y, int flags, void* userdata) {
        ControlWindow* control = (ControlWindow*)userdata;
        control->onMouse(event, x, y, flags);
    }
    /**
     * @brief Mouse Event
     * @param event
     * @param x
     * @param y
     * @param flags
     */
    void ControlWindow::onMouse(int event, int x, int y, int flags) {
        if (event == cv::EVENT_LBUTTONDOWN) {
            cv::circle(window, cv::Point(x, y), 10, cv::Scalar(0, 0, 255), -1);
            cv::imshow(TOOLS_CONTROL_WINDOW_NAME, window);
        } else if (event == cv::EVENT_MOUSEMOVE) {
            // cv::circle(window, cv::Point(x, y), 10, cv::Scalar(0, 255, 0), -1);
            // cv::imshow(TOOLS_CONTROL_WINDOW_NAME, window);
        }
    }
    /**
     * @brief Constructor
     */
    Graphics::Graphics() {
        int color[] = TOOLS_WINDOW_BACKGROUND_COLOR;
        //-- Generate Main Window
        window = cv::Mat(
            TOOLS_WINDOW_HEIGHT,
            TOOLS_WINDOW_WIDTH,
            CV_8UC3,
            cv::Scalar(
                color[0],
                color[1],
                color[2]
            )
        );
        //-- Find Center Pixel of Screen
        Display* disp = XOpenDisplay(NULL);
        Screen* scrn = DefaultScreenOfDisplay(disp);
        //-- Show Created Window
        cv::namedWindow(TOOLS_WINDOW_NAME);
        cv::moveWindow(
            TOOLS_WINDOW_NAME,
            scrn->width / 2 - window.cols / 2,
            scrn->height / 2 - window.rows / 2
        );
        //-- Set Mouse Callback
        // cv::setMouseCallback(TOOLS_WINDOW_NAME, onMouseCallback, this);
        // cv::imshow(TOOLS_WINDOW_NAME, window);
        // cv::waitKey(0);
        //-- Close Display
        XCloseDisplay(disp);
    }
    /**
     * @brief Mouse Callback
     * @param event
     * @param x
     * @param y
     * @param flags
     * @param userdata
     */
    // void Graphics::onMouseCallback(int event, int x, int y, int flags, void* userdata) {
    //     Graphics* graphics = (Graphics*)userdata;
    //     graphics->onMouse(event, x, y, flags);
    // }
    /**
     * @brief Mouse Event
     * @param event
     * @param x
     * @param y
     * @param flags
     */
    // void Graphics::onMouse(int event, int x, int y, int flags) {
    //     if (event == cv::EVENT_LBUTTONDOWN) {
    //         mouse.x = x;
    //         mouse.y = y;
    //         mouse.event = cv::EVENT_LBUTTONDOWN;
    //         // cv::circle(window, cv::Point(x, y), 10, cv::Scalar(0, 0, 255), -1);
    //         // cv::imshow(TOOLS_WINDOW_NAME, window);
    //     } else if (event == cv::EVENT_MOUSEMOVE) {
    //         // cv::circle(window, cv::Point(x, y), 10, cv::Scalar(0, 255, 0), -1);
    //         // cv::imshow(TOOLS_WINDOW_NAME, window);
    //     }
    // }
# endif // MRL_HSL_TOOLS_GRAPHICS