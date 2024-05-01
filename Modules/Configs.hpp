# ifndef MRL_HSL_TOOLS_MODULES_CONFIGS
    /**
     * @file Modules.hpp
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @brief MRL HSL Tools Modules Configurations
     * @version 0.1
     * @date 2024-04-28
     */
    # define MRL_HSL_TOOLS_MODULES_CONFIGS
    // ----------------------------------- //
    // -- Terminal Color Configurations -- //
    // ----------------------------------- //
    /**
     * @brief Warning Termianl Report
     */
    # define WARNING "\033[38;2;255;255;0m[WARNING] \033[0m"
    /**
     * @brief Success Termianl Report
     */
    # define SUCCESS "\033[38;2;0;200;0m[SUCCESS] \033[0m"
    /**
     * @brief Fail Termianl Report
     */
    # define FAILED "\033[38;2;255;0;0m[FAILED] \033[0m"
    /**
     * @brief Log Termianl Report
     */
    # define LOG "\033[38;2;173;173;173m[LOG] \033[0m"
    /**
     * @brief Cyan Terminal Report
     */
    # define CYAN "\033[38;2;0;255;255m"
    /**
     * @brief Dark Cyan Terminal Report
     */
    # define DARK_CYAN "\033[38;2;0;170;170m"
    /**
     * @brief Reset Terminal Report
     */
    # define RESET "\033[0m"
    /**
     * @brief Tab Space
     */
    # define TAB "   "
    // ----------------------------- //
    // -- Graphics Configurations -- //
    // ----------------------------- //
    /**
     * @brief Window Width
     */
    # define TOOLS_WINDOW_WIDTH 1200
    /**
     * @brief Window Height
     */
    # define TOOLS_WINDOW_HEIGHT 850
    /**
     * @brief Window Name
     */
    # define TOOLS_WINDOW_NAME "MRL HSL Tools"
    /**
     * @brief Window Background Color
     * @note Format is BGR 
     */
    # define TOOLS_WINDOW_BACKGROUND_COLOR {37, 26, 5}
    // ----------------------------------- //
    // -- Control Window Configurations -- //
    // ----------------------------------- //
    /**
     * @brief Control Window Width
     */
    # define TOOLS_CONTROL_WINDOW_WIDTH 450
    /**
     * @brief Control Window Height
     */
    # define TOOLS_CONTROL_WINDOW_HEIGHT 850
    /**
     * @brief Control Window Name
     */
    # define TOOLS_CONTROL_WINDOW_NAME "Control Window"
    /**
     * @brief Control Window Background Color
     * @note Format is BGR 
     */
    # define TOOLS_CONTROL_WINDOW_BACKGROUND_COLOR {13, 5, 0}
    /**
     * @brief Zoom Radius
     */
    # define DEFAULT_ZOOM_RADIUS 40
    /**
     * @brief Zoom Window X Position
     */
    # define ZOOM_WINDOW_X (TOOLS_CONTROL_WINDOW_WIDTH / 2)
    /**
     * @brief Zoom Window X Position
     */
    # define ZOOM_WINDOW_Y (TOOLS_CONTROL_WINDOW_HEIGHT * 0.8)
    /**
     * @brief Zoom Window Radius Size
     */
    # define ZOOM_WINDOW_RADIUS (TOOLS_CONTROL_WINDOW_WIDTH * 0.4)
    // ----------------------------- //
    // -- Labeling Configurations -- //
    // ----------------------------- //
    /**
     * @brief Source Images Input Path
     */
    # define TOOLS_LABELING_SOURCE_IMAGES_PATH "../Data/SourceImages/"
    /**
     * @brief Labeled Images Output Path
     */
    # define TOOLS_LABELING_LABELED_IMAGES_PATH "../Data/LabeledImages/"
# endif // MRL_HSL_TOOLS_MODULES_CONFIGS