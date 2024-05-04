# ifndef MRL_HSL_VISION_CONVEX_HULL
    /**
     * @file ConvexHull.hpp
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @brief MRL HSL Vision Convex Hull Module
     * @version 0.1
     * @date 2024-04-30
     */
    # define MRL_HSL_VISION_CONVEX_HULL
    //-- Include Graphics Module
    # ifndef MRL_HSL_TOOLS_GRAPHICS
        # include "../../../Modules/Graphics/Graphics.hpp"
    # endif // MRL_HSL_TOOLS_GRAPHICS
    //-- Include Vectors
    # ifndef _GLIBCXX_VECTOR
        # include <vector>
    # endif // _GLIBCXX_VECTOR
    //-- Include IOStream
    # ifndef _GLIBCXX_IOSTREAM
        # include <iostream>
    # endif // _GLIBCXX_IOSTREAM
    /**
     * @brief Convex Hull Class Definition
     */
    class ConvexHull {
        public:
            /**
             * @brief Convex Hull Points
             */
            std::vector<cv::Point> convexhull_points;
            /**
             * @brief Constructor
             */
            ConvexHull();
            /**
             * @brief Function to find orientation of ordered triplet (p, q, r).
             * @param p colinear
             * @param q colinear
             * @param r colinear
             * @note The Function Returns the Following Values:
             * @note 0 --> p, q, and r are Colinear
             * @note 1 --> Clockwise
             * @note 2 --> Counterclockwise
             * @return int
             */
            int orientation(cv::Point p, cv::Point q, cv::Point r);
            /**
             * @brief Comparator Function to Sort Points Based on Polar Angle.
             * Formed by the Point p0 and the Points.
             * @param p1
             * @param p2
             * @param p0
             * @return bool
             */
            bool compare(cv::Point p1, cv::Point p2, cv::Point p0);
            /**
             * @brief Convex Hull Method with Graham Scan Algorithm
             * @param points
             * @return std::vector<cv::Point>
             */
            std::vector<cv::Point> convexHull(std::vector<cv::Point>& points);
    };
# endif // MRL_HSL_VISION_CONVEX_HULL