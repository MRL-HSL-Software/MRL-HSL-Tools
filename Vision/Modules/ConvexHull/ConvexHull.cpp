# ifndef MRL_HSL_VISION_CONVEX_HULL
    # include "ConvexHull.hpp"
    /**
     * @brief Constructor
     */
    ConvexHull::ConvexHull() {
    }
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
    int ConvexHull::orientation(cv::Point p, cv::Point q, cv::Point r) {
        int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
        if (val == 0) return 0;
        return (val > 0)? 1: 2;
    }
    /**
     * @brief Comparator Function to Sort Points Based on Polar Angle.
     * Formed by the Point p0 and the Points.
     * @param p1
     * @param p2
     * @param p0
     * @return bool
     */
    bool ConvexHull::compare(cv::Point p1, cv::Point p2, cv::Point p0) {
        int o = orientation(p0, p1, p2);
        if (o == 0) {
            return norm(p0 - p1) < norm(p0 - p2);
        }
        return (o == 2);
    }
    /**
     * @brief Convex Hull Method with Graham Scan Algorithm
     * @param points
     * @return std::vector<cv::Point>
     */
    std::vector<cv::Point> ConvexHull::convexHull(std::vector<cv::Point>& points) {
        int n = points.size();
        if (n < 3) {
            std::cout << TAB FAILED "Convex Hull Can Not Implemented on 2 Points" << std::endl;
            return std::vector<cv::Point>();
        }
        //-- Find Bottommost Point
        int ymin = points[0].y, min = 0;
        for (int i = 1; i < n; i++) {
            int y = points[i].y;
            if ((y < ymin) || (ymin == y && points[i].x < points[min].x)) {
                ymin = points[i].y, min = i;
            }
        }
        swap(points[0], points[min]);
        sort(
            points.begin() + 1,
            points.end(),
            [&](cv::Point p1, cv::Point p2) {
                return compare(p1, p2, points[0]);
            });
        int m = 1;
        for (int i = 1; i < n; i++) {
            while (i < n - 1 && orientation(points[0], points[i], points[i + 1]) == 0) {
                i++;
            }
            points[m] = points[i];
            m++;
        }
        //-- Check if Convex Hull is Possible
        if (m < 3) {
            return std::vector<cv::Point>();
        }
        
        convexhull_points.push_back(points[0]);
        convexhull_points.push_back(points[1]);
        convexhull_points.push_back(points[2]);
        for (int i = 3; i < m; i++) {
            while (
                convexhull_points.size() >= 2 &&
                orientation(
                    convexhull_points[convexhull_points.size() - 2],
                    convexhull_points[convexhull_points.size() - 1],
                    points[i]
                ) != 2
            ) {
                convexhull_points.pop_back();
            }
            convexhull_points.push_back(points[i]);
        }

        return convexhull_points;
    }
# endif // MRL_HSL_VISION_CONVEX_HULL