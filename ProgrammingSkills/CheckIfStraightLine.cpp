/*
* Result:
*
* Runtime: 6 ms
* Beats: 61.42%
*
* Memory: 13.37 MB
* Beats: 35.76%
*
* Problem:
*
* You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point.
* 
* Check if these points make a straight line in the XY plane.
*/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int coordLength = coordinates.size();

        if (coordLength <= 2) {
            return true;
        }

        // Point to first coordinate for repeated reference
        int* originX = &coordinates[0][0];
        int* originY = &coordinates[0][1];

        // First check for straight lines in X, then in Y, then handle diagonals
        if (*originX == coordinates[1][0]) {
            int xValue = *originX;

            for (int i = 2; i < coordLength; i++) {
                if (coordinates[i][0] != xValue) {
                    return false;
                }
            }
        } else if (*originY == coordinates[1][1]) {
            int yValue = *originY;

            for (int i = 2; i < coordLength; i++) {
                if (coordinates[i][1] != yValue) {
                    return false;
                }
            }
        } else {
            float xDiff =
                static_cast<float>(diffValue(*originX, coordinates[1][0]));

            if (xDiff == 0) {
                return false;
            }

            float yDiff =
                static_cast<float>(diffValue(*originY, coordinates[1][1]));

            if (yDiff == 0) {
                return false;
            }

            float gradient = yDiff / xDiff;

            for (int i = 2; i < coordLength; i++) {
                float newXDiff =
                    static_cast<float>(diffValue(*originX, coordinates[i][0]));

                if (xDiff == 0) {
                    return false;
                }

                float newYDiff =
                    static_cast<float>(diffValue(*originY, coordinates[i][1]));

                if (yDiff == 0) {
                    return false;
                }

                float newGradient = newYDiff / newXDiff;

                if (newGradient != gradient) {
                    return false;
                }
            }
        }

        return true;
    }

    int diffValue(int a, int b) { return a - b; }
};
