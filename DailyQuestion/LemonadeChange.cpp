/*
* At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills).
* Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.
*
* Note that you do not have any change in hand at first.
*
* Given an integer array bills where bills[n] is the bill the nth customer pays, return true if you can provide every customer with the correct change, or false otherwise.
*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int billsLength = bills.size();

        // Index 0 = $5, Index 1 = $10, Index 2 = $20
        int change[] = {0, 0, 0};

        for (int i = 0; i < billsLength; i++) {
            if (bills[i] == 5) {
                change[0]++;
                continue;
            } else if (bills[i] == 10) {
                if (change[0] < 1) {
                    return false;
                } else {
                    change[1]++;
                    change[0]--;
                    continue;
                }
            } else {
                if (change[0] < 1) {
                    return false;
                } else if (change[1] < 1 && change[0] < 3) {
                    return false;
                }

                if (change[1] < 1) {
                    change[2]++;
                    change[0] = change[0] - 3;
                    continue;
                } else {
                    change[2]++;
                    change[1]--;
                    change[0]--;
                    continue;
                }
            }
        }

        return true;
    }
};
