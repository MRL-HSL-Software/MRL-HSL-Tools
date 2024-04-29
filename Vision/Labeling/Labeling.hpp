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
    //-- Include Vectors
    # ifndef _GLIBCXX_VECTOR
        # include <vector>
    # endif // _GLIBCXX_VECTOR
    //-- Include String
    # ifndef _GLIBCXX_STRING
        # include <string>
    # endif // _GLIBCXX_STRING
    /**
     * @brief Labeling Class
     */
    class Labeling {
        public:
            /**
             * @brief Modules
             */
            Modules modules;
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
    };
# endif // MRL_HSL_LABELING_TOOLS