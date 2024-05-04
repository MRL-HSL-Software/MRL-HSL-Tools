# ifndef MRL_HSL_SOFTWARE_TOOLS
    /**
     * @file Tools.hpp
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @brief MRL HSL Software Team Tools
     * @version 0.1
     * @date 2024-04-28
     */
    # define MRL_HSL_SOFTWARE_TOOLS
    //-- Include Graphics Tools
    # ifndef MRL_HSL_TOOLS_MODULES
        # include "Modules/Modules.hpp"
    # endif // MRL_HSL_TOOLS_MODULES
    //-- Include Vision Tools
    # ifndef MRL_HSL_VISION_TOOLS
        # include "Vision/VisionTools.hpp"
    # endif // MRL_HSL_VISION_TOOLS
    /**
     * @brief Tools Class Definition
     */
    class Tools {
        public:
            /**
             * @brief Modules
             */
            Modules modules;
            /**
             * @brief Vision Tools
             */
            VisionTools visionTools;
            /**
             * @brief Construct a new Tools object
             */
            Tools();
    };
# endif // MRL_HSL_SOFTWARE_TOOLS