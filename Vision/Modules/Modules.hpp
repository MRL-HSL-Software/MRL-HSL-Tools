# ifndef MRL_HSL_VISION_MODULES
    /**
     * @file Modules.hpp
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @brief MRL HSL Vision Modules
     * @version 0.1
     * @date 2024-04-30
     */
    # define MRL_HSL_VISION_MODULES
    //-- Include Bit Plane Slicing Module
    # ifndef MRL_HSL_VISION_BIT_PLANE_SLICING
        # include "BitPlaneSlicing/BPSlicing.hpp"
    # endif // MRL_HSL_VISION_BIT_PLANE_SLICING
    //-- Include Convex Hull Module
    # ifndef MRL_HSL_VISION_CONVEX_HULL
        # include "ConvexHull/ConvexHull.hpp"
    # endif // MRL_HSL_VISION_CONVEX_HULL
    /**
     * @brief Vision Modules Class Definition
     */
    class VisionModules {
        public:
            /**
             * @brief Bit Plane Slicing Module
             */
            BPSlicing bpSlicing;
            /**
             * @brief Convex Hull Module
             */
            ConvexHull convexHull;
            /**
             * @brief Constructor
             */
            VisionModules();
    };
# endif // MRL_HSL_VISION_MODULES