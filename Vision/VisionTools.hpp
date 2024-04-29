# ifndef MRL_HSL_VISION_TOOLS
    /**
     * @file VisionTools.hpp
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @brief MRL HSL Vision Tools
     * @version 0.1
     * @date 2024-04-28
     */
    # define MRL_HSL_VISION_TOOLS
    //-- Include Graphics Tools
    # ifndef MRL_HSL_TOOLS_MODULES
        # include "../Modules/Modules.hpp"
    # endif // MRL_HSL_TOOLS_MODULES
    //-- Include Labeling Tools
    # ifndef MRL_HSL_LABELING_TOOLS
        # include "Labeling/Labeling.hpp"
    # endif // MRL_HSL_LABELING_TOOLS
    /**
     * @brief Vision Tools Class
     */
    class VisionTools {
        public:
            /**
             * @brief Modules
             */
            Modules modules;
            /**
             * @brief Labeling
             */
            Labeling labeling;
            /**
             * @brief Construct a new Vision Tools object
             */
            VisionTools();
    };
# endif // MRL_HSL_VISION_TOOLS