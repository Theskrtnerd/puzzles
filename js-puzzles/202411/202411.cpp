#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    const int num_simulations = 1'000'000'000;  // 20 million simulations
    int count1 = 0;

    // Seed the random number generator
    std::srand(std::time(0));

    for (int i = 0; i < num_simulations; ++i) {
        // Generate random points A and B
        double Ax = (double)std::rand() / RAND_MAX;
        double Ay = (double)std::rand() / RAND_MAX;
        double Bx = (double)std::rand() / RAND_MAX;
        double By = (double)std::rand() / RAND_MAX;

        // Identify the nearest side to point B
        double left_distance = Bx;
        double right_distance = 1.0 - Bx;
        double bottom_distance = By;
        double top_distance = 1.0 - By;

        std::string nearest_side;
        double min_distance = left_distance;
        nearest_side = "left";

        if (right_distance < min_distance) {
            min_distance = right_distance;
            nearest_side = "right";
        }
        if (bottom_distance < min_distance) {
            min_distance = bottom_distance;
            nearest_side = "bottom";
        }
        if (top_distance < min_distance) {
            min_distance = top_distance;
            nearest_side = "top";
        }

        // Calculate the midpoint of AB
        double midpoint_x = (Ax + Bx) / 2.0;
        double midpoint_y = (Ay + By) / 2.0;

        // Calculate slope of AB and perpendicular slope
        double perpendicular_slope;
        bool is_vertical = (Bx == Ax);
        if (!is_vertical) {
            double slope_AB = (By - Ay) / (Bx - Ax);
            perpendicular_slope = -1.0 / slope_AB;
        } else {
            perpendicular_slope = 0.0;  // AB is vertical, perpendicular bisector is horizontal
        }

        // Calculate y-intercept of perpendicular bisector
        double c = midpoint_y - perpendicular_slope * midpoint_x;

        // Determine intersection point with the nearest side
        double x_intersect, y_intersect;

        if (nearest_side == "left") {
            x_intersect = 0.0;
            y_intersect = c;
        } else if (nearest_side == "right") {
            x_intersect = 1.0;
            y_intersect = perpendicular_slope * x_intersect + c;
        } else if (nearest_side == "bottom") {
            y_intersect = 0.0;
            x_intersect = (perpendicular_slope != 0) ? (0.0 - c) / perpendicular_slope : midpoint_x;
        } else if (nearest_side == "top") {
            y_intersect = 1.0;
            x_intersect = (perpendicular_slope != 0) ? (1.0 - c) / perpendicular_slope : midpoint_x;
        }

        // Check if the intersection resides within the nearest side boundary
        bool within_boundary = (nearest_side == "left" || nearest_side == "right") ? 
                               (y_intersect >= 0 && y_intersect <= 1) :
                               (x_intersect >= 0 && x_intersect <= 1);

        if (within_boundary) {
            ++count1;  // Intersection is within the side
        }
    }

    // Calculate the probability
    double probability = (double)count1 / num_simulations;
    std::cout << count1 << std::endl;
    std::cout << "Probability: " << probability << std::endl;

    return 0;
}
