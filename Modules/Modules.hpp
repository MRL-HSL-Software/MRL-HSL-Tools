# ifndef MRL_HSL_TOOLS_MODULES
    /**
     * @file Modules.hpp
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @brief MRL HSL Tools Modules
     * @version 0.1
     * @date 2024-04-28
     */
    # define MRL_HSL_TOOLS_MODULES
    //-- Include Graphics Module
    # ifndef MRL_HSL_TOOLS_GRAPHICS
        # include "Graphics/Graphics.hpp"
    # endif // MRL_HSL_TOOLS_GRAPHICS
    //-- Include Files Module
    # ifndef MRL_HSL_TOOLS_FILES
        # include "Files/Files.hpp"
    # endif // MRL_HSL_TOOLS_FILES
    //-- Include Datetime Module
    # ifndef MRL_HSL_TOOLS_DATETIME
        # include "Datetime/Datetime.hpp"
    # endif // MRL_HSL_TOOLS_DATETIME
    /**
     * @brief Module Class
     */
    class Modules {
        public:
            /**
             * @brief Graphics Module
             */
            Graphics graphics;
            /**
             * @brief Files Module
             */
            Files files;
            /**
             * @brief Datetime Module
             */
            Datetime datetime;
            /**
             * @brief Construct a new Modules object
             */
            Modules();
    };
# endif // MRL_HSL_TOOLS_MODULES